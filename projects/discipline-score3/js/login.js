// Make sure that the error state element is hidden
$(".ui-state-error").hide();

// Call the button widget method on login button to format it.
$("#btnLogin").button()

// Now bind a click event to handle the login of the form
$("#btnLogin").bind("click", function() {
    if ($("#username").val() != "script" && $("#password").val() != "junkie") {
        $(".ui-state-error").show();
        $("#login section").effect("shake", 150);
    } else {
        document.location = "todo.html";
    }
    return false;
});
