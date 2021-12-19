function $(id) {
    return document.getElementById(id);
}

function addClass(left,right,lc,rc){
    // console.log("start");
    var Y = $(left).offsetTop;
    var timer = setInterval(function(){
        var top = window.pageYOffset || 0;
        var hei = window.innerHeight;
        // console.log("Y: " + Y + " top: " + top + " hei: " + hei);
        if(Y-top-hei <= 0) {
            $(left).classList.add(lc);
            $(right).classList.add(rc);
            clearInterval(timer);
        }
    },10);
}