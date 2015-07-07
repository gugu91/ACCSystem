function CodeDefine() { 
this.def = new Array();
this.def["controller_M_"] = {file: "ert_main_c.html",line:25,type:"var"};
this.def["controller_M"] = {file: "ert_main_c.html",line:26,type:"var"};
this.def["controller_DW"] = {file: "ert_main_c.html",line:27,type:"var"};
this.def["controller_U_enableSwitch"] = {file: "ert_main_c.html",line:30,type:"var"};
this.def["controller_U_pedalFlag"] = {file: "ert_main_c.html",line:33,type:"var"};
this.def["controller_U_resetSwitch"] = {file: "ert_main_c.html",line:36,type:"var"};
this.def["controller_Y_led1"] = {file: "ert_main_c.html",line:39,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:53,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:92,type:"fcn"};
this.def["controller_step"] = {file: "controller_c.html",line:59,type:"fcn"};
this.def["controller_initialize"] = {file: "controller_c.html",line:147,type:"fcn"};
this.def["controller_terminate"] = {file: "controller_c.html",line:174,type:"fcn"};
this.def["RT_MODEL_controller_T"] = {file: "controller_h.html",line:38,type:"type"};
this.def["DW_controller_T"] = {file: "controller_h.html",line:44,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:82,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:87,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:92,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:99,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:106,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:113,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:120,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:127,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:134,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:152,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["controller_c.html"] = "../controller.c";
	this.html2Root["controller_c.html"] = "controller_c.html";
	this.html2SrcPath["controller_h.html"] = "../controller.h";
	this.html2Root["controller_h.html"] = "controller_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","controller_c.html","controller_h.html","rtwtypes_h.html"];
