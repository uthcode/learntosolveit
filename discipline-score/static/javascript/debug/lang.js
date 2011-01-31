// Copyright 2006 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

var INFINITY = Number.MAX_VALUE;

// Inherit the prototype of the given superclass. We create a dummy instance
// to avoid the problem with the traditional JavaScript subclassing paradigm
// when the superclass constructor requires arguments.
function inherit(subclass, superclass) {
  var instance = function() {};
  instance.prototype = superclass.prototype;
  subclass.prototype = new instance();
}

// Returns a function that calls the given method on the given instance.
function callback(instance, method) {
  return function() {
    method.apply(instance, arguments);
  };
}

// Removes the first element in the given array that is equal to the given
// element, returning true if an element is removed.
function arrayRemove(array, elem) {
  for (var i = 0; i < array.length; i++) {
    if (array[i] == elem) {
      array.splice(i, 1);
      return true;
    }
  }
  return false;
}

// Useful function for closing reference loops or canceling events.
function returnFalse() {
  return false;
}
