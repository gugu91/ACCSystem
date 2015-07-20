function CodeDefine() { 
this.def = new Array();
this.def["ACC_Controller_M_"] = {file: "ert_main_c.html",line:25,type:"var"};
this.def["ACC_Controller_M"] = {file: "ert_main_c.html",line:26,type:"var"};
this.def["ACC_Controller_P"] = {file: "ert_main_c.html",line:27,type:"var"};
this.def["ACC_Controller_DW"] = {file: "ert_main_c.html",line:117,type:"var"};
this.def["ACC_Controller_U_EnableSwitch"] = {file: "ert_main_c.html",line:120,type:"var"};
this.def["ACC_Controller_U_PedalFlag"] = {file: "ert_main_c.html",line:123,type:"var"};
this.def["ACC_Controller_U_ResetSwitch"] = {file: "ert_main_c.html",line:126,type:"var"};
this.def["ACC_Controller_U_Distance"] = {file: "ert_main_c.html",line:129,type:"var"};
this.def["ACC_Controller_U_Speed"] = {file: "ert_main_c.html",line:132,type:"var"};
this.def["ACC_Controller_U_CANAlive"] = {file: "ert_main_c.html",line:135,type:"var"};
this.def["ACC_Controller_U_DistanceAlive"] = {file: "ert_main_c.html",line:138,type:"var"};
this.def["ACC_Controller_Y_Go"] = {file: "ert_main_c.html",line:141,type:"var"};
this.def["ACC_Controller_Y_Stop"] = {file: "ert_main_c.html",line:144,type:"var"};
this.def["ACC_Controller_Y_d"] = {file: "ert_main_c.html",line:147,type:"var"};
this.def["ACC_Controller_Y_Led1"] = {file: "ert_main_c.html",line:150,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:164,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:206,type:"fcn"};
this.def["ACC_Controller_step"] = {file: "ACC_Controller_c.html",line:65,type:"fcn"};
this.def["ACC_Controller_initialize"] = {file: "ACC_Controller_c.html",line:472,type:"fcn"};
this.def["ACC_Controller_terminate"] = {file: "ACC_Controller_c.html",line:542,type:"fcn"};
this.def["RT_MODEL_ACC_Controller_T"] = {file: "ACC_Controller_h.html",line:39,type:"type"};
this.def["DW_ACC_Controller_T"] = {file: "ACC_Controller_h.html",line:57,type:"type"};
this.def["P_ACC_Controller_T"] = {file: "ACC_Controller_h.html",line:151,type:"type"};
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
	this.html2SrcPath["ACC_Controller_c.html"] = "../ACC_Controller.c";
	this.html2Root["ACC_Controller_c.html"] = "ACC_Controller_c.html";
	this.html2SrcPath["ACC_Controller_h.html"] = "../ACC_Controller.h";
	this.html2Root["ACC_Controller_h.html"] = "ACC_Controller_h.html";
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
"ert_main_c.html","ACC_Controller_c.html","ACC_Controller_h.html","rtwtypes_h.html"];
