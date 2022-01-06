function $(a) {
    return document.getElementById(a);
}

var po = $("fz").offsetTop;

$("fz").style.position = "fixed";
$("fz").style.top = $("logo").offsetHeight + "px";

function stay(ss) {
    var objY = $("fz").offsetTop;
    var objS = $("fz").style;
    if (ss >= $("logo").offsetHeight) {
        objS.top = 0;
        objS.zIndex = 3;
        $("fz").classList.add("shadow");
    } else {
        objS.top = -1 * ss + $("logo").offsetHeight - 2 + "px";
        $("fz").classList.remove("shadow");
    }

    // console.log(objY);
}

window.addEventListener("scroll", function () {
    var top = window.pageYOffset || 0;
    window.requestAnimationFrame(function () {
        stay(top);
        ticking = false;
    });
});

var info = {
    1: {
        1: {
            price: 120,
            name: "清明上和园全票",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553740968787.jpg",
        },
    },
    2: { null: null },
    3: {
        1: {
            price: 298,
            name: "孙羊正店五人套餐",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1566546587722.jpg",
        },
        2: {
            price: 238,
            name: "孙羊正店四人套餐",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1566546587722.jpg",
        },
        3: {
            price: 168,
            name: "孙羊正店三人套餐",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1566546587722.jpg",
        },
    },
    4: {
        1: {
            price: 60,
            name: "成人文化衫",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553741893222.jpg",
        },
        2: {
            price: 8,
            name: "软胶钥匙扣",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553741995349.jpg",
        },
        3: {
            price: 5,
            name: "清明娃钥匙扣挂件",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553742128475.jpg",
        },
        4: {
            price: 15,
            name: "Q版纪念挂件",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553742233770.jpg",
        },
        5: {
            price: 35,
            name: "Q版纪念摆件",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553742314799.jpg",
        },
        6: {
            price: 40,
            name: "清明娃摆件",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553742384305.jpg",
        },
        7: {
            price: 45,
            name: "儿童文化衫",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553742485926.jpg",
        },
        8: {
            price: 10,
            name: "马克杯",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553742570181.jpg",
        },
        9: {
            price: 20,
            name: "清园特色明信片",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553742798670.jpg",
        },
        10: {
            price: 100,
            name: "清明上河园手工草编",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553742943269.jpg",
        },
    },
    5: {
        1: {
            price: 4000,
            name: "宋式婚礼",
            url: "https://console.qmsyun.com/admin/uploadfile/mall/2/2-1553743289804.jpg",
        },
        2: {
            price: 0,
            name: "免费穿宋服",
            url: "http://www.qingmings.com/uploadfile/shop/SHOP20190410.jpg",
        },
    },
};

function addItem(box, page) {
    var str = "";
    for (var i in info[page]) {
        // console.log(info[page][i]);

        if (i == "null") {
            box.innerHTML = "<div id='blank'></div>";
            return;
        } else {
            str += "<div class='box'>";
            str +=
                "<div class='price'><p>" +
                info[page][i].price +
                "</p>RMB</div>";
            str += "<img src='" + info[page][i].url + "'>";
            str +=
                "<div class='name'><h3>" +
                info[page][i].name +
                "</h3><a href=''>立即购买</a>";
            str += "</div></div>";
        }
    }
    // console.log(info[page][1].name);

    // console.log(box);

    box.innerHTML = str;
}

var ani = ()=>{
    var item = document.getElementsByClassName("box");
    // window.requestAnimationFrame(()=>{
    for(let i = 0; i < item.length; i++){
        item[i].onmouseover = ()=>{
            item[i].style.transform = "scale(1.1)";
            item[i].style.borderRadius = "8px";
        }
        item[i].onmouseout = ()=>{
            item[i].style.transform = "scale(1)";
            item[i].style.borderRadius = "0px";
        }
    };
}

var visible = [1, 0, 0, 0, 0, 0];

function shop(op) {
    var opi = parseInt(op);
    var obj = document.querySelector("#shop" + opi);
    var objs = document.querySelector(".selected");

    objs.classList.remove("selected");
    obj.classList.add("selected");

    let tar;
    for (let i = 0; i < visible.length; i++) {
        if (visible[i]) tar = i;
    }
    tar++;
    document.querySelector("#s" + tar).classList.add("hide");
    document.querySelector("#s" + op).classList.remove("hide");
    for (let i = 0; i < visible.length; i++) {
        if (i == op - 1) visible[i] = 1;
        else visible[i] = 0;
    }

    // console.log(visible);

    if (op == 6) {
        document.querySelector(".s").classList.remove("hide");
        for (let i = 0; i < visible.length; i++) {
            if (i == op - 1) visible[i] = 1;
            else visible[i] = 0;
        }
    } else addItem(document.querySelectorAll(".s")[op - 1], op);
    ani();
}

addItem(document.querySelectorAll(".s")[0], 1);
document.getElementById("shop1").classList.add("selected");
ani();

setInterval(() => {
    if(window.innerWidth < 1184){
        var uls = document.querySelectorAll("ul");
        for(let i = 1; i < 7; i++){
            uls[i].style.paddingLeft = 0 + "px";
            uls[i].style.backgroundImage = "";
        }
    }else{
        var uls = document.querySelectorAll("ul");
        for(let i = 1; i < 7; i++){
            uls[i].style.paddingLeft = 80 + "px";
            uls[i].style.backgroundImage = "url(http://www.qingmings.com/images/icon_menu.png)";
        }
    }
}, 100);
