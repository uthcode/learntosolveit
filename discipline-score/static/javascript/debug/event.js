// Copyright 2006 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

var EVENT_LISTENERS_ = "__event_listeners__";
var EVENT_NAME_PREFIX_ = "__event__";

// The Event class exports only static methods, documented below. Internally,
// we use a singleton instance of the Event class to track event handlers so
// that it is easy to globally unregister all event listeners with
// Event.clearAll.
function Event() {
  this.listeners_ = [];
}

// Adds the given event listener function to the given instance for the
// given event name. If the instance is a DOM node, we use the built-in
// browser event handling mechanism to register the event.  Otherwise, we
// assume the instance is a custom class type, so we use our custom event
// registration mechanisms. Custom events can only be triggered with the
// Event.trigger method.
//
// We return a Listener instance that can be used with removeListener to
// unregister the new listener.
Event.addListener = function(instance, eventName, listener) {
  return Event.instance_().addListener_(instance, eventName, listener);
}

// Removes the given listener, which should be an instance that was returned
// by Event.addListener.
Event.removeListener = function(listener) {
  Event.instance_().removeListener_(listener);
}

// Triggers the event with the given name on the given instance. This method
// only works with custom events on custom Objects, not DOM events. We throw
// an exception if this method is used with DOM objects.
Event.trigger = function(instance, eventName, opt_a0, opt_a1, opt_a2) {
  Event.prototype.trigger_.apply(Event.instance_(), arguments);
}

// Clears all events for all elements globally. This should be called in
// the unload event of the document to prevent memory leaks caused by the
// event registration system.
Event.clearAll = function() {
  Event.instance_().clearAll_();
}

// Clears all event listeners for all events for the given instance. To
// reduce memory consumption during the execution of a page, you can call
// this method on DOM nodes before they are discarded or custom object
// instances before they are discarded in addition to calling Event.clearAll
// when the page unloads.
Event.clearElement = function(instance) {
  Event.instance_().clearElement_(instance);
}

// Returns our global Event instance.
Event.instance_ = function() {
  if (!Event.instance__) {
    Event.instance__ = new Event();
  }
  return Event.instance__;
}

// Detect if the instance is a DOM node or some other type and call the
// appropriate registration method. Store a reference to the returned
// token in our global listener list and the list for the given instance
// for Event.clearAll and Event.clearElement, respectively.
Event.prototype.addListener_ = function(instance, eventName, listener) {
  var token;
  if (this.isDomNode_(instance)) {
    token = this.addDomListener_(instance, eventName, listener);
  } else {
    token = this.addCustomListener_(instance, eventName, listener);
  }

  // Store this listener in our global list so the clearAll method can free
  // all listeners globally
  this.listeners_.push(token);

  // Store this listener on the given instance so we can clear all events
  // for this instance later
  var instanceListeners = instance[EVENT_LISTENERS_];
  if (!instanceListeners) {
    instanceListeners = [];
    instance[EVENT_LISTENERS_] = instanceListeners;
  }
  instanceListeners.push(token);

  return token;
}

// Detect if the instance is a DOM node or some other type and call the
// appropriate removal method. Remove the listener from our global and per-
// element listener lists.
Event.prototype.removeListener_ = function(listener) {
  if (this.isDomNode_(listener.instance)) {
    this.removeDomListener_(listener);
  } else {
    this.removeCustomListener_(listener);
  }

  // Clear from our global list of listeners
  arrayRemove(this.listeners_, listener);

  // Clear from this instance's list of listeners
  var instanceListeners = listener.instance[EVENT_LISTENERS_];
  if (instanceListeners) {
    arrayRemove(instanceListeners, listener);
  }
}

// Trigger the given event by getting the event list from the instance.
Event.prototype.trigger_ = function(instance, eventName  /* ... */) {
  if (this.isDomNode_(instance)) {
    throw new Error("Cannot trigger DOM events");
  }
  var property = EVENT_NAME_PREFIX_ + eventName;
  var listeners = instance[property];
  if (!listeners) return;

  var eventArgs = [];
  for (var i = 2; i < arguments.length; i++) {
    eventArgs.push(arguments[i]);
  }
  for (var i = 0; i < listeners.length; i++) {
    listeners[i].apply(instance, eventArgs);
  }
}

// Supports W3C and IE event registration models, but not any older models
// (e.g., not element.on<event> = function).
Event.prototype.addDomListener_ = function(instance, eventName, listener) {
  var callback = listener;
  if (instance.addEventListener) {
    instance.addEventListener(eventName, listener, false);
  } else if (instance.attachEvent) {
    callback = function() {
      listener.call(instance, window.event);
    };
    instance.attachEvent("on" + eventName, callback);
  }
  return { instance: instance, eventName: eventName, callback: callback };
}

// Complementary method for addDomListener_.
Event.prototype.removeDomListener_ = function(listener) {
  var instance = listener.instance;
  if (instance.removeEventListener) {
    instance.removeEventListener(listener.eventName, listener.callback, false);
  } else if (listener.instance.detachEvent) {
    instance.detachEvent("on" + listener.eventName, listener.callback);
  }
}

// Store a list for each named event off of this object using the prefix
// defined above to ensure we don't collide with real properties and
// methods.
Event.prototype.addCustomListener_ = function(instance, eventName, listener) {
  var property = EVENT_NAME_PREFIX_ + eventName;
  var listeners = instance[property];
  if (!listeners) {
    listeners = [];
    instance[property] = listeners;
  }
  listeners.push(listener);
  return { instance: instance, eventName: eventName, callback: callback };
}

// Remove the callback from the list associated with the listener's event.
Event.prototype.removeCustomListener_ = function(listener) {
  var property = EVENT_NAME_PREFIX_ + listener.eventName;
  var listeners = listener.instance[property];
  if (!listeners) return;
  arrayRemove(listeners, listener.callback);
}

// Since removeListener_ removes an element from listeners_, we keep removing
// the first element until the list is empty.
Event.prototype.clearAll_ = function() {
  while (this.listeners_.length > 0) {
    this.removeListener_(this.listeners_[0]);
  }
}

// Since removeListener_ removes an element from the element's event list, we
// keep removing the first element until the list is empty.
Event.prototype.clearElement_ = function(instance) {
  var instanceListeners = instance[EVENT_LISTENERS_];
  if (!instanceListeners) return;
  while (instanceListeners.length > 0) {
    this.removeListener_(instanceListeners[0]);
  }
}

// Returns true if the given instance is a DOM node, the window instance,
// or the window.document instance.
Event.prototype.isDomNode_ = function(instance) {
  return (instance == window || instance == window.document ||
          typeof instance.nodeType != "undefined");
}
