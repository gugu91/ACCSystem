function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <S1>/controller */
	this.urlHashMap["ACCSystem:1"] = "ACC_Controller.c:22,74,303,334&ACC_Controller.h:42,43,44,45,46,47";
	/* <S2>:1 */
	this.urlHashMap["ACCSystem:1:1"] = "ACC_Controller.c:92,97,128,280";
	/* <S2>:3 */
	this.urlHashMap["ACCSystem:1:3"] = "ACC_Controller.c:103,117,120,132,287";
	/* <S2>:17 */
	this.urlHashMap["ACCSystem:1:17"] = "ACC_Controller.c:146,153,199,221";
	/* <S2>:41 */
	this.urlHashMap["ACCSystem:1:41"] = "ACC_Controller.c:108,194,292";
	/* <S2>:39 */
	this.urlHashMap["ACCSystem:1:39"] = "ACC_Controller.c:123,135,209,215";
	/* <S2>:19 */
	this.urlHashMap["ACCSystem:1:19"] = "ACC_Controller.c:180,230,256";
	/* <S2>:20 */
	this.urlHashMap["ACCSystem:1:20"] = "ACC_Controller.c:166,237,249";
	/* <S2>:11 */
	this.urlHashMap["ACCSystem:1:11"] = "ACC_Controller.c:141,274";
	/* <S2>:6 */
	this.urlHashMap["ACCSystem:1:6"] = "ACC_Controller.c:100";
	/* <S2>:2 */
	this.urlHashMap["ACCSystem:1:2"] = "ACC_Controller.c:88";
	/* <S2>:12 */
	this.urlHashMap["ACCSystem:1:12"] = "ACC_Controller.c:276";
	/* <S2>:7 */
	this.urlHashMap["ACCSystem:1:7"] = "ACC_Controller.c:119";
	/* <S2>:15 */
	this.urlHashMap["ACCSystem:1:15"] = "ACC_Controller.c:284";
	/* <S2>:13 */
	this.urlHashMap["ACCSystem:1:13"] = "ACC_Controller.c:131";
	/* <S2>:43 */
	this.urlHashMap["ACCSystem:1:43"] = "ACC_Controller.c:104,288";
	/* <S2>:42 */
	this.urlHashMap["ACCSystem:1:42"] = "ACC_Controller.c:195";
	/* <S2>:33 */
	this.urlHashMap["ACCSystem:1:33"] = "ACC_Controller.c:149";
	/* <S2>:45 */
	this.urlHashMap["ACCSystem:1:45"] = "ACC_Controller.c:175";
	/* <S2>:24 */
	this.urlHashMap["ACCSystem:1:24"] = "ACC_Controller.c:161";
	/* <S2>:40 */
	this.urlHashMap["ACCSystem:1:40"] = "ACC_Controller.c:214";
	/* <S2>:31 */
	this.urlHashMap["ACCSystem:1:31"] = "ACC_Controller.c:233";
	/* <S2>:32 */
	this.urlHashMap["ACCSystem:1:32"] = "ACC_Controller.c:252";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "ACC_Controller"};
	this.sidHashMap["ACC_Controller"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "ACCSystem:138"};
	this.sidHashMap["ACCSystem:138"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "ACCSystem:1"};
	this.sidHashMap["ACCSystem:1"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S1>/EnableSwitch"] = {sid: "ACCSystem:139"};
	this.sidHashMap["ACCSystem:139"] = {rtwname: "<S1>/EnableSwitch"};
	this.rtwnameHashMap["<S1>/PedalFlag"] = {sid: "ACCSystem:140"};
	this.sidHashMap["ACCSystem:140"] = {rtwname: "<S1>/PedalFlag"};
	this.rtwnameHashMap["<S1>/ResetSwitch"] = {sid: "ACCSystem:141"};
	this.sidHashMap["ACCSystem:141"] = {rtwname: "<S1>/ResetSwitch"};
	this.rtwnameHashMap["<S1>/Speed"] = {sid: "ACCSystem:142"};
	this.sidHashMap["ACCSystem:142"] = {rtwname: "<S1>/Speed"};
	this.rtwnameHashMap["<S1>/Distance"] = {sid: "ACCSystem:143"};
	this.sidHashMap["ACCSystem:143"] = {rtwname: "<S1>/Distance"};
	this.rtwnameHashMap["<S1>/controller"] = {sid: "ACCSystem:1"};
	this.sidHashMap["ACCSystem:1"] = {rtwname: "<S1>/controller"};
	this.rtwnameHashMap["<S1>/Led1"] = {sid: "ACCSystem:144"};
	this.sidHashMap["ACCSystem:144"] = {rtwname: "<S1>/Led1"};
	this.rtwnameHashMap["<S1>/Go"] = {sid: "ACCSystem:145"};
	this.sidHashMap["ACCSystem:145"] = {rtwname: "<S1>/Go"};
	this.rtwnameHashMap["<S1>/Stop"] = {sid: "ACCSystem:146"};
	this.sidHashMap["ACCSystem:146"] = {rtwname: "<S1>/Stop"};
	this.rtwnameHashMap["<S2>:1"] = {sid: "ACCSystem:1:1"};
	this.sidHashMap["ACCSystem:1:1"] = {rtwname: "<S2>:1"};
	this.rtwnameHashMap["<S2>:3"] = {sid: "ACCSystem:1:3"};
	this.sidHashMap["ACCSystem:1:3"] = {rtwname: "<S2>:3"};
	this.rtwnameHashMap["<S2>:17"] = {sid: "ACCSystem:1:17"};
	this.sidHashMap["ACCSystem:1:17"] = {rtwname: "<S2>:17"};
	this.rtwnameHashMap["<S2>:41"] = {sid: "ACCSystem:1:41"};
	this.sidHashMap["ACCSystem:1:41"] = {rtwname: "<S2>:41"};
	this.rtwnameHashMap["<S2>:39"] = {sid: "ACCSystem:1:39"};
	this.sidHashMap["ACCSystem:1:39"] = {rtwname: "<S2>:39"};
	this.rtwnameHashMap["<S2>:19"] = {sid: "ACCSystem:1:19"};
	this.sidHashMap["ACCSystem:1:19"] = {rtwname: "<S2>:19"};
	this.rtwnameHashMap["<S2>:20"] = {sid: "ACCSystem:1:20"};
	this.sidHashMap["ACCSystem:1:20"] = {rtwname: "<S2>:20"};
	this.rtwnameHashMap["<S2>:11"] = {sid: "ACCSystem:1:11"};
	this.sidHashMap["ACCSystem:1:11"] = {rtwname: "<S2>:11"};
	this.rtwnameHashMap["<S2>:6"] = {sid: "ACCSystem:1:6"};
	this.sidHashMap["ACCSystem:1:6"] = {rtwname: "<S2>:6"};
	this.rtwnameHashMap["<S2>:2"] = {sid: "ACCSystem:1:2"};
	this.sidHashMap["ACCSystem:1:2"] = {rtwname: "<S2>:2"};
	this.rtwnameHashMap["<S2>:12"] = {sid: "ACCSystem:1:12"};
	this.sidHashMap["ACCSystem:1:12"] = {rtwname: "<S2>:12"};
	this.rtwnameHashMap["<S2>:7"] = {sid: "ACCSystem:1:7"};
	this.sidHashMap["ACCSystem:1:7"] = {rtwname: "<S2>:7"};
	this.rtwnameHashMap["<S2>:15"] = {sid: "ACCSystem:1:15"};
	this.sidHashMap["ACCSystem:1:15"] = {rtwname: "<S2>:15"};
	this.rtwnameHashMap["<S2>:13"] = {sid: "ACCSystem:1:13"};
	this.sidHashMap["ACCSystem:1:13"] = {rtwname: "<S2>:13"};
	this.rtwnameHashMap["<S2>:43"] = {sid: "ACCSystem:1:43"};
	this.sidHashMap["ACCSystem:1:43"] = {rtwname: "<S2>:43"};
	this.rtwnameHashMap["<S2>:42"] = {sid: "ACCSystem:1:42"};
	this.sidHashMap["ACCSystem:1:42"] = {rtwname: "<S2>:42"};
	this.rtwnameHashMap["<S2>:33"] = {sid: "ACCSystem:1:33"};
	this.sidHashMap["ACCSystem:1:33"] = {rtwname: "<S2>:33"};
	this.rtwnameHashMap["<S2>:45"] = {sid: "ACCSystem:1:45"};
	this.sidHashMap["ACCSystem:1:45"] = {rtwname: "<S2>:45"};
	this.rtwnameHashMap["<S2>:24"] = {sid: "ACCSystem:1:24"};
	this.sidHashMap["ACCSystem:1:24"] = {rtwname: "<S2>:24"};
	this.rtwnameHashMap["<S2>:40"] = {sid: "ACCSystem:1:40"};
	this.sidHashMap["ACCSystem:1:40"] = {rtwname: "<S2>:40"};
	this.rtwnameHashMap["<S2>:31"] = {sid: "ACCSystem:1:31"};
	this.sidHashMap["ACCSystem:1:31"] = {rtwname: "<S2>:31"};
	this.rtwnameHashMap["<S2>:32"] = {sid: "ACCSystem:1:32"};
	this.sidHashMap["ACCSystem:1:32"] = {rtwname: "<S2>:32"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
