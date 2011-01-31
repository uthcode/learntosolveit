// Copyright 2006 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

// Disables text selection for the given element.
function disableSelection(element) {
  element.onselectstart = returnFalse;
  element.unselectable = "on";
  element.style.MozUserSelect = "none";
  element.style.cursor = "default";
}

// Enables text selection for the given element.
function enableSelection(element) {
  element.onselectstart = null;
  element.unselectable = "off";
  element.style.MozUserSelect = "";
}

// Sets the opacity of the given element to the given value (between 0 and 1)
function setOpacity(element, opacity) {
  if (Browser.instance().isIEBased()) {
    element.style.filter = "alpha(opacity=" + Math.round(opacity * 100) + ")";
  } else {
    element.style.opacity = opacity;
  }
}

// Stops propagation of the event, but leaves the default action enabled.
function stopEvent(e) {
  if (e.stopPropagation) {
    e.stopPropagation();
  } else {
    e.cancelBubble = true;
  }
}

// Cancels the default action of the given event.
function cancelEvent(e) {
  if (!e) e = window.event;
  if (e.preventDefault) {
    e.preventDefault();
  } else {
    e.returnValue = false;
  }
}

// Disables the right click context menu
function disableContextMenu(e) {
  e.oncontextmenu = function() {
    return false;
  }
}

// Adds the given CSS class name to the given element.
function cssAddClass(element, className) {
  cssClassManipulate(element, className, true);
}

// Removes the given CSS class name to the given element.
function cssRemoveClass(element, className) {
  cssClassManipulate(element, className, false);
}

// Adds or removes the given CSS class name to the given element.
function cssClassManipulate(element, className, add) {
  var classes = element.className.split(" ");
  var newClasses = [];
  for (var i = 0; i < classes.length; i++) {
    if (classes[i] != className) {
      newClasses.push(classes[i]);
    }
  }
  if (add) {
    newClasses.push(className);
  }
  element.className = newClasses.join(" ");
}
