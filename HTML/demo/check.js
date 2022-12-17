var tesObj = document.getElementsByTagName("label");

for (var i = 0; i < tesObj.length; i++) {
    if (tesObj[i].textContent.indexOf("优秀") > 0) {
        tesObj[i].childNodes[1].checked = true;
    }
}

document.getElementsByTagName("textarea")[0].value =
    "教师认真负责，上课充满热情，耐心答疑，积极引导教育学生学习。";

function buildRequestMap(){
	var xspj_body = $("div.xspj-body");
	var requestMap = {
		"ztpjbl" :$(xspj_body).data("ztpjbl"),
		"jszdpjbl":$(xspj_body).data("jszdpjbl"),
		"xykzpjbl":$(xspj_body).data("xykzpjbl"),
		//教学班ID
		"jxb_id" : $(xspj_body).data("jxb_id"),
		//课程号ID
		"kch_id" : $(xspj_body).data("kch_id"),
		//教工号ID
		"jgh_id" : $(xspj_body).data("jgh_id"),
		//学时代码
		"xsdm"   : $(xspj_body).data("xsdm")
	};
	//循环评价对象
	$("div.panel-pjdx").each(function(i,panel){
		//评价模版名称ID
		var pjmbmcb_id = $(this).data("pjmbmcb_id");
		var pjdxdm = $(this).data("pjdxdm");
		var fxzgf = $(this).data("fxzgf");
		var xspjpykz = $("#xspjpykz").val();
		var zbbtgs = 0;// 指标必填项个数
		var zbypbtgs = 0;// 必填指标已评个数
		if($.founded(pjmbmcb_id)){
			/*评价状态1-已评完;0-未评完*/
			var pjzt =  "0";
			var py = '';
			//评语
			if("1" == xspjpykz){
				py = $("#"+pjmbmcb_id+"_py").val();
			}else if("2" == xspjpykz && "01" == pjdxdm){
				py = $("#js_py").val();
			}					
			requestMap["modelList["+i+"].pjmbmcb_id"] = pjmbmcb_id;
			requestMap["modelList["+i+"].pjdxdm"] = pjdxdm;
			requestMap["modelList["+i+"].fxzgf"] = fxzgf;
			requestMap["modelList["+i+"].py"] = $.founded(py) ? encodeURIComponent(py) : "";
			requestMap["modelList["+i+"].xspfb_id"] = $(this).data("xspfb_id");
			if("10704" == xxdm){
				var pjf = $(panel).find("select[name='pjf']").val();
				requestMap["modelList["+i+"].pjf"] = pjf;
			}
			var j_index = 0;
			//循环学生评价一级指标
			$(panel).find("table.table-xspj").each(function(j,table){
				//循环学生评价二级指标
				var k_index = 0;
				$(table).find("tr.tr-xspj").each(function(k,tr){
					var valid = false;
					var pjzbxm_id = $(tr).data("pjzbxm_id");
					var pfdjdmb_id = $(tr).data("pfdjdmb_id");
					var zsmbmcb_id = $(tr).data("zsmbmcb_id");
					var dtlx = $(tr).data("dtlx");//根据答题类型1：主观题  2：客观题 判断取值
					var sfbt = $(tr).data("sfbt");// 判断是否必填题
					var qzz = $(tr).data("qzz");// 权重值
					zbbtgs += '1' == sfbt ? 1 : 0;
					if(dtlx == '2'){
						//多级别制
						if($(tr).find("div.form-group").size() > 0 ){
							//已选
							var xspf = $("input[name='"+pjmbmcb_id+"_" + pjzbxm_id+"_" + pfdjdmb_id+"']:checked");
							if(xspf.size() > 0 ){
								valid = true;
								//二级评分等级代码项目ID
								requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].pfdjdmxmb_id"] = $(xspf).data("pfdjdmxmb_id");
							}
						}else{
							//已评分
							var xspf = $(tr).find("input.form-control").val();
							xspf = xspf ? xspf : '';
							//评价分
							requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].pjf"] = xspf;
							valid = $.founded(xspf); 
						}
					}else if(dtlx == '1'){
						if($(tr).find("div.form-group").size() > 0 ){
							var zgpj = $(tr).find("textarea.form-control").val();
							requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].zgpj"] = zgpj;
							valid = $.founded(zgpj);
						}
					}
					if($("#xmsfgldj").val()=="1"){
						var zbxmdj2 = [];
						var zbxmdj2List = $("#dj_" + pjzbxm_id).find("input[name='zbxmdj2']");
						var dtlxList = $("#dj_" + pjzbxm_id).find("input[name='zbxmdj2dtlx']");
						var zbxmdj2dtlx = $(dtlxList[0]).val();
						requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].zbxmdtlx"] = zbxmdj2dtlx;
						if (zbxmdj2dtlx == "1") {
							var zbxmdj2zgpj = $(zbxmdj2List[0]).val();
							if(!$.founded(zbxmdj2zgpj)) {
								zbxmdj2zgpj = '~zgpj~';
							}
							requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].zbxmzgpj"] = zbxmdj2zgpj;
						} else {
							if (zbxmdj2List.length > 0) {
								zbxmdj2List.each(function(index2,item2){
									if (item2.checked) {
										zbxmdj2.push($(item2).val());
									}
								}); 
							} else {
								zbxmdj2.push('~zbxmdj~');
							}
							requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].zbxmdj"] = zbxmdj2.join("@");
						}
						
					}
					zbypbtgs += ('1'==sfbt && valid) ? 1 : 0;
					//只有有进行评价才会组织参数
					//二级评价指标项目ID
					requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].pjzbxm_id"] = pjzbxm_id;
					//评分等级代码ID
					requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].pfdjdmb_id"] = pfdjdmb_id;
					//真实模板名称表id
					requestMap["modelList["+i+"].xspjList["+j_index+"].childXspjList["+k_index+"].zsmbmcb_id"] = zsmbmcb_id;				
					k_index ++;
					
				});
				//只有有进行评价才会组织参数
				//一级评价指标项目ID
				requestMap["modelList["+i+"].xspjList["+j_index+"].pjzbxm_id"] = $(table).data("pjzbxm_id");
				j_index ++;		
			});
			pjzt = (zbypbtgs == zbbtgs) ? "1" : "0";
			requestMap["modelList["+i+"].pjzt"] = pjzt;
		}else{
			return false;
		}
	});
	return requestMap;
}

function doTj() {
    //组织参数对象
    var progress_loading = $("#progress_loading");
    var dataMap = buildRequestMap.call(this) || {};
    dataMap["tjzt"] = "1";
    jQuery.ajax({
        url: _path + "/xspjgl/xspj_tjXspj.html",
        type: "post",
        dataType: "json",
        data: dataMap,
        async: false,
        beforeSend: function () {
            inProgress = true;
            // Handle the beforeSend event
            //让进度条 从20% 缓慢/迅速 增长到50%
            progress_loading.attr("aria-valuenow", 50).css("width", "50%");
            $("#btn_xspj_bc").addClass("disabled").prop({ disabled: true });
            $("#btn_xspj_tj").addClass("disabled").prop({ disabled: true });
        },
        success: function (responseText) {
            inProgress = false;
            progress_loading.attr("aria-valuenow", 80).css("width", "80%");

            if ($.type(responseText) == "string") {
                if (responseText.indexOf("整体提交成功") > -1) {
                    progress_loading
                        .attr("aria-valuenow", 100)
                        .css("width", "100%");
                    $.success(responseText, function () {
                        var pjzt_flag = refTab();
                        checkRequestOfZjjspx(pjzt_flag);
                    });
                } else if (responseText.indexOf("成功") > -1) {
                    progress_loading
                        .attr("aria-valuenow", 100)
                        .css("width", "100%");
                    $.success(responseText, function () {
                        var pjzt_flag = refTab();
                        checkRequestOfZjjspx(pjzt_flag);
                    });
                } else if (responseText.indexOf("失败") > -1) {
                    $.error(responseText, function () {});
                } else {
                    $.alert(responseText, function () {
                        refTab();
                    });
                }
                window.setTimeout(function () {
                    progress_loading
                        .attr("aria-valuenow", 0)
                        .css("width", "0%");
                }, 600);
            }
        },
        error: function () {
            inProgress = false;
            progress_loading.attr("aria-valuenow", 0).css("width", "0%");
        },
    });
}

function check() {
    var radios = document.querySelectorAll("input.radio-pjf");
    radios.forEach((radio) => {
        if (radio.attributes["data-dyf"].value == 94) radio.checked = true;
    });
}

function comment() {
    document.querySelector("textarea").value =
        "老师在这一学期已经付出了很多时间和热情，此次课程对他来说可能充满了许多困难，但是他始终能够保持良好的教学状态，不断为学生讲解、感染、鼓励、并探究新的教学理念, 并将这些要求传递给学生。在这一学期中，老师不仅教会了我们重要的课程内容，也让我们明白了一门课程背后所代表的核心思想。在此，我站出来向老师衷心的感谢和真心的敬佩。";
}

function criticize() {
    var cls = document.querySelectorAll("tr.ui-widget-content");
    var i = 0;
    cls.forEach((cl)=>{
        setTimeout(()=>{
            cl.click();
        },i*7000);
        setTimeout(()=>{
            check();
            comment();
        }, i*7000 + 800)
        setTimeout(() => {
            doTj();
        }, i*7000 + 1200);
        setTimeout(()=>{
            document.querySelector("#btn_ok").click();
        },i++*7000 + 600)
    });
}

criticize()
