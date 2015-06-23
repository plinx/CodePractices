function cleanDiv()
{
	var topDiv = document.getElementsByClassName('zu-top')[0];
	//alert(topDiv);
	topDiv.style.opacity = 0.2;
	topDiv.style.position = "absolute";
	var ctx = document.getElementsByClassName('zu-main-content-inner')[0];
	ctx.style.margin = "0px";
	var backtop = document.getElementsByClassName('zh-backtotop')[0];
	backtop.style.marginLeft = "36%";

	document.getElementsByClassName('zu-main-sidebar')[0].remove();
	document.getElementById('zh-footer').remove();
	document.getElementById('zh-question-meta-wrap').remove();
	document.getElementsByClassName('zh-answers-title clearfix')[0].remove();
	document.getElementById('zh-question-answer-form-wrap').remove();
	document.getElementsByClassName('zm-meta-panel')[0].remove();
	document.getElementById('zh-question-collapsed-link').remove();

}

cleanDiv();
