// Copyright 2007 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

// A singleton class for showing a DIV element as a modal dialog box in the
// center of the page. We prevent the rest of the page from being accessed
// by covering it with a slightly transparent DIV, showing the dialog box
// DIV in the center of the page on top of the slightly transparent cover.
//
// Typical usage:
//
//   <div id="mydialog" style="display: none">This is a dialog box!</div>
//
//   DialogBox.instance().show(document.getElementById("mydialog"));
//
// You can close the dialog with DialogBox.instance().close(), which re-
// inserts the dialog box DIV into the DOM (if it was in the DOM originally).
function DialogBox() {
  Event.addListener(window, "resize", callback(this, this.resize_));
  Event.addListener(window, "scroll", callback(this, this.resize_));
}

// Returns our global DialogBox instance.
DialogBox.instance = function() {
  if (!DialogBox.instance__) {
    DialogBox.instance__ = new DialogBox();
  }
  return DialogBox.instance__;
}

// Shows the given element as a modal dialog box, calling the given callbacks
// after it is displayed and closed, respectively.
DialogBox.prototype.show = function(element, opt_openCallback,
                                    opt_closeCallback) {
  this.close();

  var scrollTop = self.pageYOffset;
  if (typeof(scrollTop) == "undefined") {
    scrollTop = document.documentElement.scrollTop;
  }

  var background = document.createElement("div");
  background.style.position = "absolute";
  background.style.left = "0px";
  background.style.top = scrollTop + "px";
  background.style.width = "100%";
  background.style.height = "100%";
  background.style.zIndex = 10000;
  setOpacity(background, 0.25);
  document.body.appendChild(background);

  // Set the background color after we add to the DOM so IE doesn't flash
  // a solid black background
  background.style.backgroundColor = "black";

  this.element_ = element;
  this.originalParent_ = element.parentNode;
  this.background_ = background;
  this.closeCallback_ = opt_closeCallback;

  // Remove the child from the DOM (e.g., if it is a hidden set of HTML
  // somewhere in the page)
  if (element.parentNode) {
    element.parentNode.removeChild(element);
    element.style.display = "";
  }

  offscreenSize(element, callback(this, function(width, height) {
    this.width_ = width;
    this.height_ = height;
    var container = document.createElement("div");
    container.style.position = "absolute";
    container.style.width = width + "px";
    container.style.height = height + "px";
    container.style.zIndex = 10001;
    container.appendChild(element);
    this.container_ = container;
    this.resize_();

    element.style.display = "";
    document.body.appendChild(container);

    if (opt_openCallback) {
      opt_openCallback();
    }
  }), 0);
}

// Closes the dialog box if it is open.
DialogBox.prototype.close = function() {
  if (this.background_) {
    this.background_.parentNode.removeChild(this.background_);
    this.background_ = null;
  }
  if (this.container_) {
    this.container_.parentNode.removeChild(this.container_);
    this.container_ = null;
  }
  if (this.element_) {
    if (this.element_.parentNode) {
      this.element_.parentNode.removeChild(this.element_);
    }
    if (this.originalParent_) {
      this.element_.style.display = "none";
      this.originalParent_.appendChild(this.element_);
    }
  }
  if (this.closeCallback_) {
    this.closeCallback_();
    this.closeCallback_ = null;
  }
}

// Vertically centers the dialog box when the browser resizes.
DialogBox.prototype.resize_ = function() {
  if (!this.background_ || !this.container_) return;

  var scrollTop = self.pageYOffset;
  if (typeof(scrollTop) == "undefined") {
    scrollTop = document.documentElement.scrollTop;
  }

  var left = Math.floor((this.background_.offsetWidth - this.width_) / 2);
  var top = Math.floor((this.background_.offsetHeight - this.height_) / 2) +
            scrollTop;
  this.background_.style.top = scrollTop + "px";
  this.container_.style.left = left + "px";
  this.container_.style.top = top + "px";
}
