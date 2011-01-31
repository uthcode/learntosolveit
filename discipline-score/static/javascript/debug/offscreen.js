// Copyright 2005 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

// Sizes the given HTML element by drawing it offscreen and calculating the
// the actual, rendered size. We call the given callback function with the
// the size of the content element.
//
// Since we draw the content element offscreen, the content element will be
// added to a node offscreen. Therefore, it should not be in the DOM before
// this method is called.
function offscreenSize(contentElem, callback, opt_maxWidth) {
  offscreenSizeMultiple([contentElem], function(sizes) {
    callback(sizes[0][0], sizes[0][1]);
  }, opt_maxWidth);
}

// Like offscreenSize, but sizes the entire array of HTML elements and calls
// a single callback with an array of sizes.
function offscreenSizeMultiple(contentElems, callback, opt_maxWidth) {
  var offscreenArea = document.createElement("div");
  offscreenArea.style.position = "absolute";
  offscreenArea.style.left = -screen.width + "px";
  offscreenArea.style.top = -screen.height + "px";
  var maxWidth = opt_maxWidth || screen.width;
  offscreenArea.style.width = maxWidth + "px";
  offscreenArea.style.height = screen.height + "px";

  var contentContainers = [];
  for (var i = 0; i < contentElems.length; i++) {
    var container = document.createElement("div");
    container.style.position = "absolute";
    container.style.left = "0px";
    container.style.top = "0px";
    offscreenArea.appendChild(container);
    container.appendChild(contentElems[i]);
    contentContainers.push(container);
  }

  document.body.appendChild(offscreenArea);

  window.setTimeout(function() {
    var sizes = [];
    for (var i = 0; i < contentContainers.length; i++) {
      var container = contentContainers[i];
      sizes.push([container.offsetWidth, container.offsetHeight]);
      container.removeChild(contentElems[i]);
      container.parentNode.removeChild(container);
    }
    offscreenArea.parentNode.removeChild(offscreenArea);
    contentContainers = null;
    callback(sizes);
  }, 0);
}
