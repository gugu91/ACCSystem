function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>:1 */
	this.urlHashMap["ACCSystem:1:1"] = "controller.c:83,88,106,127";
	/* <S1>:3 */
	this.urlHashMap["ACCSystem:1:3"] = "controller.c:94,100,135";
	/* <S1>:11 */
	this.urlHashMap["ACCSystem:1:11"] = "controller.c:114,121";
	/* <S1>:6 */
	this.urlHashMap["ACCSystem:1:6"] = "controller.c:90";
	/* <S1>:2 */
	this.urlHashMap["ACCSystem:1:2"] = "controller.c:79";
	/* <S1>:12 */
	this.urlHashMap["ACCSystem:1:12"] = "controller.c:123";
	/* <S1>:7 */
	this.urlHashMap["ACCSystem:1:7"] = "controller.c:102";
	/* <S1>:15 */
	this.urlHashMap["ACCSystem:1:15"] = "controller.c:131";
	/* <S1>:13 */
	this.urlHashMap["ACCSystem:1:13"] = "controller.c:110";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "controller"};
	this.sidHashMap["controller"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "ACCSystem:1"};
	this.sidHashMap["ACCSystem:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>:1"] = {sid: "ACCSystem:1:1"};
	this.sidHashMap["ACCSystem:1:1"] = {rtwname: "<S1>:1"};
	this.rtwnameHashMap["<S1>:3"] = {sid: "ACCSystem:1:3"};
	this.sidHashMap["ACCSystem:1:3"] = {rtwname: "<S1>:3"};
	this.rtwnameHashMap["<S1>:11"] = {sid: "ACCSystem:1:11"};
	this.sidHashMap["ACCSystem:1:11"] = {rtwname: "<S1>:11"};
	this.rtwnameHashMap["<S1>:6"] = {sid: "ACCSystem:1:6"};
	this.sidHashMap["ACCSystem:1:6"] = {rtwname: "<S1>:6"};
	this.rtwnameHashMap["<S1>:2"] = {sid: "ACCSystem:1:2"};
	this.sidHashMap["ACCSystem:1:2"] = {rtwname: "<S1>:2"};
	this.rtwnameHashMap["<S1>:12"] = {sid: "ACCSystem:1:12"};
	this.sidHashMap["ACCSystem:1:12"] = {rtwname: "<S1>:12"};
	this.rtwnameHashMap["<S1>:7"] = {sid: "ACCSystem:1:7"};
	this.sidHashMap["ACCSystem:1:7"] = {rtwname: "<S1>:7"};
	this.rtwnameHashMap["<S1>:15"] = {sid: "ACCSystem:1:15"};
	this.sidHashMap["ACCSystem:1:15"] = {rtwname: "<S1>:15"};
	this.rtwnameHashMap["<S1>:13"] = {sid: "ACCSystem:1:13"};
	this.sidHashMap["ACCSystem:1:13"] = {rtwname: "<S1>:13"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
