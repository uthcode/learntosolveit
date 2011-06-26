// Copyright 2006 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

// Returns a wrapper around the given DOM element that makes the given
// element draggable. If opt_contain is true, we prevent the element from
// being dragged beyond the bounds of its container.
function Dragger(element, opt_contain, opt_dragElement) {
  this.element_ = element;
  this.contain_ = opt_contain;

  // Capture mouse events to stop and start the drag
  var dragger = opt_dragElement || element;
  Event.addListener(dragger, "mousedown", callback(this, this.onMouseDown_));

  // Text selection interferes with dragging, so disable by default
  disableSelection(dragger);

  // In browsers like IE that support mouse capture, we can track mouse
  // movement using our element. In browsers like Firefox, we track mouse
  // movement over the entire window so that we will still capture mouse
  // events when the user is moving the mouse really fast. We also cancel
  // the drag when the mouse leaves the window to avoid bugs when the user
  // releases the left mouse button outside of the browser window.
  if (dragger.setCapture) {
    this.mouseTarget_ = dragger;
  } else {
    this.mouseTarget_ = window;
    // TODO: Mozilla continues dragging becuase it does not support mouse
    // capture, but this particular fix introduces bugs
    //Event.addListener(window, "mouseout", callback(this, this.cancelDrag));
  }
  Event.addListener(this.mouseTarget_, "mouseup",
                    callback(this, this.onMouseUp_));
}

// The number of pixels we allow the mouse to quiver and still consider it a
// click vs. a drag.
Dragger.QUIVER_PIXELS = 2;

// The maximum amount of time before we allow for a single click.
Dragger.MAX_CLICK_TIME = 500;

// Returns the DOM element that we are making draggable.
Dragger.prototype.element = function() {
    return this.element_;
}

// Disables dragging for our element.
Dragger.prototype.disable = function() {
  this.cancelDrag();
  this.disabled_ = true;
}

// Enables dragging for our element.
Dragger.prototype.enable = function() {
  this.disabled_ = false;
}

// Returns true if dragging is enabled for our element.
Dragger.prototype.enabled = function() {
  return !this.disabled_;
}

// Returns true if our element is currently being dragged.
Dragger.prototype.dragging = function() {
  return !!this.mouseListener_;
}

// Stops the current drag if we are currently dragging.
Dragger.prototype.cancelDrag = function() {
  if (this.mouseListener_) {
    Event.removeListener(this.mouseListener_);
    this.mouseListener_ = null;
    if (document.releaseCapture) {
      document.releaseCapture();
    }
    Event.trigger(this, "dragend");
  }
}

// Starts the drag if the user clicked the left mouse button and we are not
// already dragging (which can only happen if there are bugs in our detection
// of mouse up events).
Dragger.prototype.onMouseDown_ = function(e) {
  // Only respond to the left mouse button
  if (this.disabled_ || this.mouseListener_ || !this.isLeftMouseButton_(e)) {
    return;
  }

  // Our parent needs to be positioned for our offsetLeft and offsetTop
  // values to have predictable meanings
  var element = this.element_;
  if (element.parentNode.style.position != "absolute") {
    element.parentNode.style.position = "relative";
  }

  // The first time we are dragged, we have to make ourselves absolutely
  // positioned, which may change the layout of the page. Preserve the
  // position and size of this element at least.
  if (element.style.position != "absolute") {
    // TODO: These are the wrong measurements when there is a border
    // or padding
    var left = element.offsetLeft;
    var top = element.offsetTop;
    var width = element.offsetWidth;
    var height = element.offsetHeight;
    element.style.left = left + "px";
    element.style.top = top + "px";
    element.style.width = width + "px";
    element.style.height = height + "px";
    element.style.position = "absolute";
  }

  this.screenX_ = e.screenX;
  this.screenY_ = e.screenY;

  // Start our click timer so we can distinguish between clicks and drags
  this.startTime_ = (new Date()).getTime();
  this.startX_ = e.screenX;
  this.startY_ = e.screenY;

  var target = this.mouseTarget_;
  if (target.setCapture) {
    target.setCapture(true);
  }

  this.mouseListener_ =
    Event.addListener(target, "mousemove", callback(this, this.onMouseMove_));
  Event.trigger(this, "dragstart");
}

// Fire a click event if the user didn't drag too far, and cancel the current
// drag.
Dragger.prototype.onMouseUp_ = function(e) {
  this.cancelDrag();
  var now = (new Date()).getTime();
  if (now - this.startTime_ <= Dragger.MAX_CLICK_TIME &&
      Math.abs(this.startX_ - e.screenX) <= Dragger.QUIVER_PIXELS &&
      Math.abs(this.startY_ - e.screenY) <= Dragger.QUIVER_PIXELS) {
    Event.trigger(this, "click", e);
  }
}

// Move the element based on the distance the mouse has moved since our last
// mousemove event. This method is only registered on the mousemove event
// in the mousedown event, so we can assume we are dragging when this method
// is called.
Dragger.prototype.onMouseMove_ = function(e) {
  var dx = e.screenX - this.screenX_;
  var dy = e.screenY - this.screenY_;
  this.screenX_ = e.screenX;
  this.screenY_ = e.screenY;

  var element = this.element_;
  var newLeft = element.offsetLeft + dx;
  var newTop = element.offsetTop + dy;

  if (this.contain_) {
    var maxLeft = element.parentNode.offsetWidth - element.offsetWidth;
    var maxTop = element.parentNode.offsetHeight - element.offsetHeight;
    newLeft = Math.max(0, Math.min(newLeft, maxLeft));
    newTop = Math.max(0, Math.min(newTop, maxTop));
  }

  element.style.left = newLeft + "px";
  element.style.top = newTop + "px";

  Event.trigger(this, "drag");
}

// Returns true if the left mouse button is being pressed according to the
// given browser event instance.
Dragger.prototype.isLeftMouseButton_ = function(e) {
  if (Browser.instance().isGeckoBased()) return e.button == 0;
  return e.button == 1;
}
