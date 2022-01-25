var tesObj = document.getElementsByTagName("label");

for(var i=0; i < tesObj.length; i++){
    if(tesObj[i].textContent.indexOf("优秀")>0){
        tesObj[i].childNodes[1].checked = true;
    }
}

document.getElementsByTagName("textarea")[0].value = "教师认真负责，上课充满热情，耐心答疑，积极引导教育学生学习。"