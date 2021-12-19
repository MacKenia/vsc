[toc]

- 修复:
  - 你的img大小被我的CSS修改
  - 导航栏的类更改为id
  - 单边框颜色修改
  - 版权所有高度修改
  - 字体更改为微软雅黑
- 新增:
  - 导航栏固定JS(未采用官网版本)

**新建javascript.js将js内容放进去**

# HTML

```html
<!DOCTYPE html>
<html lang="zh-CN">
<head>
	<meta charset="utf-8">
	<title>清明上河园</title>
	<link rel="shortcut icon" href="http://www.qingmings.com/favicon.ico">
	<link rel="stylesheet" href="style.css">
</head>

<body id="body">
	
	<div id="logo"></div>

	<div id="fz">
		<ul id="navigate">
			<li><a href="#">首页</a></li>
			<li><a href="#">清明上河园</a></li>
			<li><a href="#">大宋·东京梦华</a></li>
			<li><a href="#">旅游服务</a></li>
			<li><a href="#">在线游园</a></li>
			<li><a href="#" class="now">预定</a></li>
			<li><a href="#">新闻&活动</a></li>
			<li><a href="#">商家平台</a></li>
		</ul>
	</div>

	<div id="banner"></div>

	<div id="center">

        <div id="container" style="height: 30vh;">
            <!-- 你的内容 -->
            <h1>你的内容</h1>
        </div>

		<div id="bottom">
			<ul id="contact">
				<li>景区地址:河南省开封市龙亭西路5号</li>
				<li>咨询电话：0371-25663819（郑州）</li>
				<li>售票电话：0371-25664874</li>
				<li>电子邮箱：qingmings@qingmings.com</li>
			</ul>
			<div id="inform">
				<p id="call">0371-25664874</p>
				<p id="wtime">周一至周日AM8：30-PM22：00</p>
			</div>
			<div id="royal">
				<img src="http://www.qingmings.com/images/icon_honor.png">
			</div>
		</div>
	</div>

	<div id="sign"><small>简体中文(中国)&nbsp;&nbsp;中国开封清明上河园股份有限公司版权所有 &nbsp;&nbsp;CopyRight 2009-2017 All Rights
			reserved.&nbsp;&nbsp;<a href="http://beian.miit.gov.cn">备案许可证号 豫ICP备11006380号-1</a></small>
	</div>
	<script src="javascript.js"></script>
</body>
</html>
```

# CSS

```css
* {
    font-family: "Microsoft YaHei";
    padding: 0;
    margin: 0;
}

body {
    width: 100%;
    display: flex;
    flex-direction: column;
    align-items: center;
}

#logo {
    background-image: url(http://www.qingmings.com/images/logo.png);
    background-repeat: no-repeat;
    background-position: center center;
    background-size: contain;
    height: 15vh;
    width: 100vw;
    transform: scale(0.6);
}

#center {
    width: 76vw;
    display: flex;
    flex-direction: column;
    align-items: center;
}

::selection {
    background-color: #ab8c40;
    color: #fff;
}

#royal>img {
    width: 100%;
    overflow: hidden;
}

ul {
    list-style: none;
}

a {
    text-decoration: none;
    color: #000;
}

a:hover {
    color: #ab8c40;
}

.now {
    color: #ab8c40;
}

#fz {
    border-top: 2px solid #ddd;
    width: 100vw;
    display: flex;
    justify-content: center;
}

#navigate {
    font-weight: bold;
    font-size: 2vh;
    padding: 1vh 0 1vh 0;
    width: 56vw;
    display: flex;
    justify-content: space-between;
}

#banner {
    height: 28vh;
    background-image: url(http://www.qingmings.com/images/banner_sm.jpg);
    background-position: center center;
    background-repeat: no-repeat;
    width: 100vw;
    overflow: hidden;
}

#container {
    display: flex;
    align-items: center;
    justify-content: center;
    flex-direction: column;
}

#bottom {
    width: 90vw;
    display: flex;
    justify-content: space-between;
    align-items: center;
}

#contact {
    font-size: 10px;
}

#sign{
    padding-top: 1vh;
    border-top: 2px solid #ddd;
    display: flex;
    justify-content: center;
    width: 100vw;
    margin-bottom: 3vh;
}

#sign::before {
    content: "\e135";
    margin-right: 1vw;
}

#inform {
    height: 100%;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: space-around;
}

#call {
    font-size: 28px;
}

#wtime {
    font-size: 13px;
    padding: 7px;
    border: 2px solid #000;
    border-radius: 6px;
}

```

# JS

```javascript
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
    console.log(objY);
}

window.addEventListener("scroll", function () {
    var top = window.pageYOffset || 0;
    window.requestAnimationFrame(function () {
        stay(top);
        ticking = false;
    });
});

```