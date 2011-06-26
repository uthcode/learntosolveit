// Copyright 2006 Google Inc.
// All Rights Reserved
//
// Author: Bret Taylor

// Downloads the given URL, calling the given callback with the results
// and the HTTP response code when the download is complete. The valid
// options are:
//
//   - post - use POST instead of GET
//   - body - POST body (implies options.post)
//   - contentType - POST content type (default x-www-form-urlencoded)
//   - synchronous - block until request completes
//   - username - HTTP Basic Authentication username
//   - password - HTTP Basic Authentication password
//
function download(url, opt_callback, opt_options) {
  var options = opt_options || {};
  var request;

  if (typeof ActiveXObject != 'undefined') {
    request = new ActiveXObject('Microsoft.XMLHTTP');
  } else if (window.XMLHttpRequest) {
    request = new XMLHttpRequest();
  } else {
    throw new Error("XMLHttpRequest not supported");
  }

  if (opt_callback) {
    request.onreadystatechange = function() {
      if (request.readyState == 4) {
        // Call the callback and clean up memory leaks
        opt_callback.call(null, request.responseText, request.status);
        request.onreadystatechange = returnFalse;
      }
    }
  }

  // You have to open the connection before setting the request headers
  var requestType = "GET";
  if (options.post || options.body) {
    requestType = "POST";
  }
  request.open(requestType, url, !options.synchronous);

  if (requestType == "POST") {
    var contentType = options.contentType ||
                      "application/x-www-form-urlencoded";
    request.setRequestHeader("Content-Type", contentType);
  }
  if (options.username || options.password) {
    request.send(options.body, options.username, options.password);
  } else {
    request.send(options.body);
  }

  if (options.synchronous && opt_callback) {
    opt_callback.call(null, request.responseText, request.status);
  }
}
