
function $(a) {
    return document.getElementById(a);
}

var po = $("fz").offsetTop;

$("fz").style.position = "fixed";
$("fz").style.top = $("logo").offsetHeight + "px";

function stay(ss) {
    var objY = $("fz").offsetTop;
    var objS = $("fz").style;
    if (ss >= $("logo").offsetHeight) objS.top = 0;
    else objS.top = -1 * ss + $("logo").offsetHeight - 2 + "px";
    // console.log(objY);
}

window.addEventListener("scroll", function () {
    var top = window.pageYOffset || 0;
    window.requestAnimationFrame(function () {
        stay(top);
        ticking = false;
    });
});
