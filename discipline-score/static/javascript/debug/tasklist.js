// Copyright 2007 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

// A single task. We know how to draw ourselves in the DOM and support the
// dragging/reordering operations on tasks.
function Task(listKey, key, description, completed) {
  this.listKey_ = listKey;
  this.key_ = key;
  this.description_ = description;
  this.completed_ = completed;
}

// Returns this task's datastore key.
Task.prototype.key = function() {
  return this.key_;
}

// Parses a list of tasks of the form:
//
//   [[listKey, key, description, completed]*]
//
// Specifically, the list should be an array of arrays representing arguments
// to the Task constructor.
Task.parseList = function(list) {
  var result = [];
  function wrapper() {}
  wrapper.prototype = Task.prototype;
  for (var i = 0; i < list.length; i++) {
    var task = new wrapper();
    Task.apply(task, list[i]);
    result.push(task);
  }
  return result;
}

// Attaches this task to the given element container, creating the DOM
// elements representing this task.
Task.prototype.attach = function(container) {
  var element = this.createElement_("div", container, "task");
  if (this.completed_) {
    cssAddClass(element, "completed");
  }
  element.style.position = "relative";

  var table = this.createElement_("table", element);
  var tbody = this.createElement_("tbody", table);
  var tr = this.createElement_("tr", tbody);

  // Create the checkbox
  var checkboxCell = this.createElement_("td", tr, "checkbox");
  var checkbox;
  try {
    checkbox = document.createElement('<input type="checkbox"/>');
    checkboxCell.appendChild(checkbox);
  } catch (e) {
    checkbox = this.createElement_("input", checkboxCell)
    checkbox.type = "checkbox";
  }
  checkbox.name = "task";
  checkbox.value = this.key_;
  checkbox.checked = this.completed_;
  Event.addListener(checkbox, "click", callback(this, this.onCheck_));

  // Prevent dragging through the checkbox
  Event.addListener(checkbox, "mousedown", stopEvent);

  var descriptionCell = this.createElement_("td", tr, "description");
  this.descriptionContainer_ = this.createElement_("div", descriptionCell);
  this.descriptionContainer_.style.position = "relative";
  this.resetDescriptionText_();

  // Enable drag positioning of this task
  var dragger = new Dragger(element, true);
  Event.addListener(dragger, "dragstart", callback(this, this.onDragStart_));
  Event.addListener(dragger, "dragend", callback(this, this.onDragEnd_));
  Event.addListener(dragger, "drag", callback(this, this.onDrag_));
  Event.addListener(dragger, "click", callback(this, this.edit));

  this.checkbox_ = checkbox;
  this.element_ = element;
  return element;
}

// Send the AJAX task completed request when our check state changes.
Task.prototype.onCheck_ = function() {
  // Update the user interface
  if (this.checkbox_.checked) {
    cssAddClass(this.element_, "completed");
  } else {
    cssRemoveClass(this.element_, "completed");
  }

  // Serialize the change to the server
  var args = [
      "id=" + encodeURIComponent(this.key_)
  ];
  if (this.checkbox_.checked) {
    args.push("completed=1");
  }
  download("/settaskcompleted.do", null, {
    post: true,
    body: args.join("&")
  });
}

// Turns this task to edit mode, which replaces our text with a INPUT box
// for editing the task description. We go back to view mode automatically
// when the text box loses focus or the user hits Return/Escape.
Task.prototype.edit = function() {
  // Only edit if we are not already editing
  if (this.textBox_) return;

  var textBox;
  try {
    textBox = document.createElement('<input type="text"/>');
  } catch (e) {
    textBox = this.createElement_("input")
    textBox.type = "text";
  }
  textBox.style.position = "absolute";
  textBox.style.left = this.descriptionContainer_.offsetLeft - 3 + "px";
  textBox.style.top = this.descriptionContainer_.offsetTop - 3 + "px";
  textBox.style.width = this.descriptionContainer_.offsetWidth + "px";
  textBox.style.border = "1px solid silver";
  textBox.style.padding = "2px";
  textBox.style.margin = "0";
  textBox.style.zIndex = 1;
  textBox.value = this.description_;
  enableSelection(this.element_);

  Event.addListener(textBox, "keypress", callback(this, this.onEditKeyPress_));
  Event.addListener(textBox, "blur", callback(this, this.saveEdit_));
  Event.addListener(textBox, "mousedown", stopEvent);

  this.descriptionContainer_.parentNode.appendChild(textBox);
  this.descriptionContainer_.style.display = "none";
  textBox.focus();

  this.textBox_ = textBox;
}

// Check for Return/Escape key press events to stop editing. We save the
// edit on Return, cancel the edit on escape.
Task.prototype.onEditKeyPress_ = function(e) {
  if (e.keyCode == 13) {
    cancelEvent(e);
    this.saveEdit_();
  } else if (e.keyCode == 27) {
    cancelEvent(e);
    this.cleanUpEdit_();
  }
}

// Puts this task back into view mode from edit mode.
Task.prototype.cleanUpEdit_ = function() {
  this.textBox_.parentNode.removeChild(this.textBox_);
  this.textBox_ = null;
  this.descriptionContainer_.style.display = "";
  disableSelection(this.element_);
}

// Save the results of this edit to the server.
Task.prototype.saveEdit_ = function() {
  var changed = this.textBox_.value != this.description_;
  if (changed) {
    this.description_ = this.textBox_.value;
    this.resetDescriptionText_();
  }
  this.cleanUpEdit_();
  if (changed) {
    this.save();
  }
}

// Resets the task description text based on the current value of
// this.description_.
Task.prototype.resetDescriptionText_ = function() {
  this.descriptionContainer_.innerHTML = '&nbsp;';
  var descriptionText = this.createElement_("span", null, "text");
  descriptionText.appendChild(document.createTextNode(this.description_));
  this.descriptionContainer_.insertBefore(
      descriptionText, this.descriptionContainer_.firstChild);
}

// Saves this task to the datastore on the server with an AJAX request.
Task.prototype.save = function() {
  var args = [
      "list=" + encodeURIComponent(this.listKey_),
      "description=" + encodeURIComponent(this.description_)
  ];
  if (this.key_) {
    args.push("task=" + encodeURIComponent(this.key_));
  }
  download("/edittask.do", callback(this, this.onSave_), {
    post: true,
    body: args.join("&")
  });
}

// Called when the save task AJAX request finishes.
Task.prototype.onSave_ = function(text, status) {
  if (status >= 200 && status < 300) {
    this.key_ = text;
  }
}

// Let the user drag this task up and down. We remove our element from the
// DOM and replace it with a placeholder so the user can see where the
// task will snap into place when it is dropped.
Task.prototype.onDragStart_ = function() {
  var placeholder = document.createElement("div");
  placeholder.style.width = this.element_.offsetWidth + "px";
  placeholder.style.height = this.element_.offsetHeight + "px";
  this.element_.parentNode.insertBefore(placeholder, this.element_);
  setOpacity(this.element_, 0.5);
  this.placeholder_ = placeholder;
}

// Reposition our placeholder based on the current position of the task
// being dragged.
Task.prototype.onDrag_ = function() {
  var container = this.element_.parentNode;
  var top = this.element_.offsetTop;
  var bottom = this.element_.offsetTop + this.element_.offsetHeight;

  for (var sibling = container.firstChild; sibling != null;
       sibling = sibling.nextSibling) {
    if (sibling == this.element_ || sibling == this.placeholder_) continue;

    var siblingTop = sibling.offsetTop;
    var siblingBottom = sibling.offsetTop + sibling.offsetHeight;
    var siblingMiddle = (siblingTop + siblingBottom) / 2;

    if (siblingTop > bottom) continue;
    if (siblingBottom < top) continue;

    if (siblingTop < top && top < siblingMiddle) {
      if (this.placeholder_.nextChild != sibling) {
        container.removeChild(this.placeholder_);
        container.insertBefore(this.placeholder_, sibling);
        return;
      }
    }

    if (bottom > siblingMiddle) {
      if (sibling.nextChild != this.placeholder_) {
        container.removeChild(this.placeholder_);
        container.insertBefore(this.placeholder_, sibling.nextSibling);
        return;
      }
    }
  }
}

// Place our task back into the task list DOM and get rid of the placeholder.
Task.prototype.onDragEnd_ = function() {
  if (!this.placeholder_) return;
  var container = this.element_.parentNode;
  container.removeChild(this.element_);
  this.element_.style.position = "relative";
  this.element_.style.width = "auto";
  this.element_.style.height = "auto";
  this.element_.style.left = "auto";
  this.element_.style.top = "auto";
  setOpacity(this.element_, 1);
  container.insertBefore(this.element_, this.placeholder_);
  container.removeChild(this.placeholder_);
  this.placeholder_ = null;
  Event.trigger(this, "positionchanged");
}

// Creates a DOM element with the given name, parent, and class name.
Task.prototype.createElement_ = function(name, opt_parent, opt_className) {
  var element = document.createElement(name);
  if (opt_className) {
    element.className = opt_className;
  }
  if (opt_parent) {
    opt_parent.appendChild(element);
  }
  return element;
}

// A task list, which is just a collection of tasks.
function TaskList(key, tasks) {
  this.key_ = key;
  this.tasks_ = tasks;
}

// Draws this task list in the given container.
TaskList.prototype.attach = function(container) {
  var element = document.createElement("div");
  element.className = "tasklist";
  element.style.position = "relative";
  container.appendChild(element);
  this.element_ = element;
  var order = [];
  for (var i = 0; i < this.tasks_.length; i++) {
    var task = this.tasks_[i];
    order.push(task.key());
    var taskElement = task.attach(element);
    taskElement.task = task;
    Event.addListener(task, "positionchanged",
                      callback(this, this.savePositions_));
  }
  this.order_ = order;
}

// Serializes the order of all of the tasks in this list to the server so
// the order will be preserved on refresh.
TaskList.prototype.savePositions_ = function() {
  // Determine the task order based on the positions of the DIVs
  var order = [];
  for (var child = this.element_.firstChild; child != null;
       child = child.nextSibling) {
    if (child.task) {
      order.push(child.task.key());
    }
  }

  // Only save the order to the server if it has changed
  var changed = false;
  for (var i = 0; i < order.length; i++) {
    if (order[i] != this.order_[i]) {
      changed = true;
      break;
    }
  }
  if (!changed) return;
  this.order_ = order;

  // Save the order to the server
  var body = "tasks=" + encodeURIComponent(order.join(","));
  download("/settaskpositions.do", null, {
    post: true,
    body: body
  });
}

// Creates a new task in this list
TaskList.prototype.newTask = function() {
  var task = new Task(this.key_, null, "", false);
  this.tasks_.push(task);
  var taskElement = task.attach(this.element_);
  taskElement.task = task;
  Event.addListener(task, "positionchanged",
                    callback(this, this.savePositions_));
  task.edit();
}

// Export our API symbols
function exportSymbol(name, symbol) {
  window[name] = symbol;
}
exportSymbol("Task", Task);
exportSymbol("TaskList", TaskList);
exportSymbol("DialogBox", DialogBox);
exportSymbol("download", download);
