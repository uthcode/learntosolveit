// Copyright 2006 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

// Class for parsing the browser user agent. We export a singleton, so
// typical usage looks like this:
//
//   if (Browser.instance().isGeckoBased()) {
//     ...
//   }
//
function Browser() {
  this.type_ = null;
  this.version_ = 0;

  if (!window.RegExp) return;

  var AGENTS = [Browser.OPERA, Browser.IE, Browser.SAFARI, Browser.FIREFOX,
                Browser.NETSCAPE, Browser.MOZILLA];
  var agent = navigator.userAgent.toLowerCase();
  for (var i = 0; i < AGENTS.length; i++) {
    var agentStr = AGENTS[i];
    if (agent.indexOf(agentStr) != -1) {
      this.type_ = agentStr;
      var versionExpr = new RegExp(agentStr + "[ \/]?([0-9]+(\.[0-9]+)?)");
      if (versionExpr.exec(agent) != null) {
        this.version_ = parseFloat(RegExp.$1);
      }
      break;
    }
  }
}

Browser.OPERA = "opera";
Browser.IE = "ie";
Browser.SAFARI = "safari";
Browser.FIREFOX = "firefox";
Browser.NETSCAPE = "netscape";
Browser.MOZILLA = "mozilla";

Browser.instance = function() {
  if (!Browser.instance__) {
    Browser.instance__ = new Browser();
  }
  return Browser.instance__;
}

Browser.prototype.type = function() {
  return this.type_;
}

Browser.prototype.version = function() {
  return this.version_;
}

Browser.prototype.isGeckoBased = function() {
  return (this.type_ == Browser.FIREFOX || this.type_ == Browser.MOZILLA ||
          this.type_ == Browser.NETSCAPE);
}

Browser.prototype.isIEBased = function() {
  return this.type_ == Browser.IE;
}

Browser.prototype.isWebKitBased = function() {
  return this.type_ == Browser.SAFARI;
}
