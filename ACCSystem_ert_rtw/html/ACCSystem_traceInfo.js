function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Scope */
	this.urlHashMap["ACCSystem:148"] = "msg=rtwMsg_SimulationReducedBlock&block=ACCSystem/Scope";
	/* <S1>/controller */
	this.urlHashMap["ACCSystem:1"] = "ACCSystem.c:22,451,651,739&ACCSystem.h:48,49,56,57,60,61,62,63";
	/* <S2>/Enable Switch Off */
	this.urlHashMap["ACCSystem:183"] = "ert_main.c:75&ACCSystem.c:400&ACCSystem.h:119";
	/* <S2>/Enable Switch On */
	this.urlHashMap["ACCSystem:182"] = "ert_main.c:78&ACCSystem.c:401&ACCSystem.h:122";
	/* <S2>/EnableSwitch Selector */
	this.urlHashMap["ACCSystem:163"] = "ert_main.c:81&ACCSystem.c:399,409&ACCSystem.h:125";
	/* <S2>/Pedal Flag Off */
	this.urlHashMap["ACCSystem:204"] = "ert_main.c:69&ACCSystem.c:412&ACCSystem.h:113";
	/* <S2>/Pedal Flag On */
	this.urlHashMap["ACCSystem:205"] = "ert_main.c:72&ACCSystem.c:413&ACCSystem.h:116";
	/* <S2>/Pedal Flag Selector */
	this.urlHashMap["ACCSystem:206"] = "ert_main.c:84&ACCSystem.c:411,421&ACCSystem.h:128";
	/* <S2>/Pulse
Generator1 */
	this.urlHashMap["ACCSystem:240"] = "ert_main.c:42,45,48,51&ACCSystem.c:423,434,699&ACCSystem.h:58,86,89,92,95";
	/* <S2>/Random
Number */
	this.urlHashMap["ACCSystem:243"] = "ert_main.c:33,36,39&ACCSystem.c:444,664,712,737&ACCSystem.h:54,59,77,80,83";
	/* <S2>/Reset Switch Off */
	this.urlHashMap["ACCSystem:209"] = "ert_main.c:63&ACCSystem.c:628&ACCSystem.h:107";
	/* <S2>/Reset Switch On */
	this.urlHashMap["ACCSystem:210"] = "ert_main.c:66&ACCSystem.c:623&ACCSystem.h:110";
	/* <S2>/Reset Switch Selector */
	this.urlHashMap["ACCSystem:208"] = "ert_main.c:87&ACCSystem.c:453,622,627&ACCSystem.h:131";
	/* <S2>/Sample
and Hold1 */
	this.urlHashMap["ACCSystem:241"] = "ACCSystem.c:436,449,702,706&ACCSystem.h:68";
	/* <S3>:1 */
	this.urlHashMap["ACCSystem:1:1"] = "ACCSystem.c:465,469,496,619";
	/* <S3>:3 */
	this.urlHashMap["ACCSystem:1:3"] = "ACCSystem.c:474,486,489,499,637";
	/* <S3>:17 */
	this.urlHashMap["ACCSystem:1:17"] = "ACCSystem.c:510,516,553,570";
	/* <S3>:41 */
	this.urlHashMap["ACCSystem:1:41"] = "ACCSystem.c:478,549,641";
	/* <S3>:39 */
	this.urlHashMap["ACCSystem:1:39"] = "ACCSystem.c:492,502,561,566";
	/* <S3>:19 */
	this.urlHashMap["ACCSystem:1:19"] = "ACCSystem.c:537,576,598";
	/* <S3>:20 */
	this.urlHashMap["ACCSystem:1:20"] = "ACCSystem.c:526,582,592";
	/* <S3>:11 */
	this.urlHashMap["ACCSystem:1:11"] = "ACCSystem.c:506,614";
	/* <S3>:6 */
	this.urlHashMap["ACCSystem:1:6"] = "ACCSystem.c:471";
	/* <S3>:2 */
	this.urlHashMap["ACCSystem:1:2"] = "ACCSystem.c:462";
	/* <S3>:12 */
	this.urlHashMap["ACCSystem:1:12"] = "ACCSystem.c:616";
	/* <S3>:7 */
	this.urlHashMap["ACCSystem:1:7"] = "ACCSystem.c:488";
	/* <S3>:15 */
	this.urlHashMap["ACCSystem:1:15"] = "ACCSystem.c:634";
	/* <S3>:13 */
	this.urlHashMap["ACCSystem:1:13"] = "ACCSystem.c:498";
	/* <S3>:43 */
	this.urlHashMap["ACCSystem:1:43"] = "ACCSystem.c:475,638";
	/* <S3>:42 */
	this.urlHashMap["ACCSystem:1:42"] = "ACCSystem.c:550";
	/* <S3>:33 */
	this.urlHashMap["ACCSystem:1:33"] = "ACCSystem.c:513";
	/* <S3>:45 */
	this.urlHashMap["ACCSystem:1:45"] = "ACCSystem.c:533";
	/* <S3>:24 */
	this.urlHashMap["ACCSystem:1:24"] = "ACCSystem.c:522";
	/* <S3>:40 */
	this.urlHashMap["ACCSystem:1:40"] = "ACCSystem.c:565";
	/* <S3>:31 */
	this.urlHashMap["ACCSystem:1:31"] = "ACCSystem.c:579";
	/* <S3>:32 */
	this.urlHashMap["ACCSystem:1:32"] = "ACCSystem.c:595";
	/* <S4>/In */
	this.urlHashMap["ACCSystem:241:1"] = "ACCSystem.c:443&ACCSystem.h:47";
	/* <S4>/Trigger */
	this.urlHashMap["ACCSystem:241:2"] = "ACCSystem.c:437";
	/* <S4>/  */
	this.urlHashMap["ACCSystem:241:3"] = "ert_main.c:30&ACCSystem.c:703&ACCSystem.h:74";
	/* <S5>/Data Store
Memory */
	this.urlHashMap["ACCSystem:104"] = "ert_main.c:60&ACCSystem.c:708&ACCSystem.h:55,104";
	/* <S5>/Data Store
Read */
	this.urlHashMap["ACCSystem:105"] = "ACCSystem.c:452";
	/* <S5>/Data Store
Read1 */
	this.urlHashMap["ACCSystem:107"] = "ACCSystem.c:654";
	/* <S5>/Data Store
Write */
	this.urlHashMap["ACCSystem:106"] = "ACCSystem.c:653";
	/* <S5>/Data Type Conversion */
	this.urlHashMap["ACCSystem:114"] = "ACCSystem.c:655";
	/* <S5>/Data Type Conversion1 */
	this.urlHashMap["ACCSystem:117"] = "ACCSystem.c:656";
	/* <S5>/Gain1 */
	this.urlHashMap["ACCSystem:247"] = "ert_main.c:54&ACCSystem.c:657&ACCSystem.h:98";
	/* <S5>/Gain2 */
	this.urlHashMap["ACCSystem:128"] = "ert_main.c:57&ACCSystem.c:658&ACCSystem.h:101";
	/* <S5>/Sum */
	this.urlHashMap["ACCSystem:109"] = "ACCSystem.c:659";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "ACCSystem"};
	this.sidHashMap["ACCSystem"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "ACCSystem:138"};
	this.sidHashMap["ACCSystem:138"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "ACCSystem:165"};
	this.sidHashMap["ACCSystem:165"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "ACCSystem:1"};
	this.sidHashMap["ACCSystem:1"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "ACCSystem:241"};
	this.sidHashMap["ACCSystem:241"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "ACCSystem:122"};
	this.sidHashMap["ACCSystem:122"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<Root>/ACC_Controller"] = {sid: "ACCSystem:138"};
	this.sidHashMap["ACCSystem:138"] = {rtwname: "<Root>/ACC_Controller"};
	this.rtwnameHashMap["<Root>/Enable Switch"] = {sid: "ACCSystem:158"};
	this.sidHashMap["ACCSystem:158"] = {rtwname: "<Root>/Enable Switch"};
	this.rtwnameHashMap["<Root>/Pedal Flag"] = {sid: "ACCSystem:221"};
	this.sidHashMap["ACCSystem:221"] = {rtwname: "<Root>/Pedal Flag"};
	this.rtwnameHashMap["<Root>/Reset Switch"] = {sid: "ACCSystem:230"};
	this.sidHashMap["ACCSystem:230"] = {rtwname: "<Root>/Reset Switch"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "ACCSystem:148"};
	this.sidHashMap["ACCSystem:148"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Testbench"] = {sid: "ACCSystem:165"};
	this.sidHashMap["ACCSystem:165"] = {rtwname: "<Root>/Testbench"};
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
	this.rtwnameHashMap["<S2>/Go"] = {sid: "ACCSystem:232"};
	this.sidHashMap["ACCSystem:232"] = {rtwname: "<S2>/Go"};
	this.rtwnameHashMap["<S2>/Stop"] = {sid: "ACCSystem:233"};
	this.sidHashMap["ACCSystem:233"] = {rtwname: "<S2>/Stop"};
	this.rtwnameHashMap["<S2>/Enable Switch Off"] = {sid: "ACCSystem:183"};
	this.sidHashMap["ACCSystem:183"] = {rtwname: "<S2>/Enable Switch Off"};
	this.rtwnameHashMap["<S2>/Enable Switch On"] = {sid: "ACCSystem:182"};
	this.sidHashMap["ACCSystem:182"] = {rtwname: "<S2>/Enable Switch On"};
	this.rtwnameHashMap["<S2>/EnableSwitch Selector"] = {sid: "ACCSystem:163"};
	this.sidHashMap["ACCSystem:163"] = {rtwname: "<S2>/EnableSwitch Selector"};
	this.rtwnameHashMap["<S2>/Pedal Flag Off"] = {sid: "ACCSystem:204"};
	this.sidHashMap["ACCSystem:204"] = {rtwname: "<S2>/Pedal Flag Off"};
	this.rtwnameHashMap["<S2>/Pedal Flag On"] = {sid: "ACCSystem:205"};
	this.sidHashMap["ACCSystem:205"] = {rtwname: "<S2>/Pedal Flag On"};
	this.rtwnameHashMap["<S2>/Pedal Flag Selector"] = {sid: "ACCSystem:206"};
	this.sidHashMap["ACCSystem:206"] = {rtwname: "<S2>/Pedal Flag Selector"};
	this.rtwnameHashMap["<S2>/Pulse Generator1"] = {sid: "ACCSystem:240"};
	this.sidHashMap["ACCSystem:240"] = {rtwname: "<S2>/Pulse Generator1"};
	this.rtwnameHashMap["<S2>/Random Number"] = {sid: "ACCSystem:243"};
	this.sidHashMap["ACCSystem:243"] = {rtwname: "<S2>/Random Number"};
	this.rtwnameHashMap["<S2>/Reset Switch Off"] = {sid: "ACCSystem:209"};
	this.sidHashMap["ACCSystem:209"] = {rtwname: "<S2>/Reset Switch Off"};
	this.rtwnameHashMap["<S2>/Reset Switch On"] = {sid: "ACCSystem:210"};
	this.sidHashMap["ACCSystem:210"] = {rtwname: "<S2>/Reset Switch On"};
	this.rtwnameHashMap["<S2>/Reset Switch Selector"] = {sid: "ACCSystem:208"};
	this.sidHashMap["ACCSystem:208"] = {rtwname: "<S2>/Reset Switch Selector"};
	this.rtwnameHashMap["<S2>/Sample and Hold1"] = {sid: "ACCSystem:241"};
	this.sidHashMap["ACCSystem:241"] = {rtwname: "<S2>/Sample and Hold1"};
	this.rtwnameHashMap["<S2>/Speed Simulator"] = {sid: "ACCSystem:122"};
	this.sidHashMap["ACCSystem:122"] = {rtwname: "<S2>/Speed Simulator"};
	this.rtwnameHashMap["<S2>/Enable Switch"] = {sid: "ACCSystem:176"};
	this.sidHashMap["ACCSystem:176"] = {rtwname: "<S2>/Enable Switch"};
	this.rtwnameHashMap["<S2>/Pedal Flag"] = {sid: "ACCSystem:207"};
	this.sidHashMap["ACCSystem:207"] = {rtwname: "<S2>/Pedal Flag"};
	this.rtwnameHashMap["<S2>/Reset Switch"] = {sid: "ACCSystem:211"};
	this.sidHashMap["ACCSystem:211"] = {rtwname: "<S2>/Reset Switch"};
	this.rtwnameHashMap["<S2>/Computed Speed"] = {sid: "ACCSystem:231"};
	this.sidHashMap["ACCSystem:231"] = {rtwname: "<S2>/Computed Speed"};
	this.rtwnameHashMap["<S2>/Casual Distance"] = {sid: "ACCSystem:236"};
	this.sidHashMap["ACCSystem:236"] = {rtwname: "<S2>/Casual Distance"};
	this.rtwnameHashMap["<S3>:1"] = {sid: "ACCSystem:1:1"};
	this.sidHashMap["ACCSystem:1:1"] = {rtwname: "<S3>:1"};
	this.rtwnameHashMap["<S3>:3"] = {sid: "ACCSystem:1:3"};
	this.sidHashMap["ACCSystem:1:3"] = {rtwname: "<S3>:3"};
	this.rtwnameHashMap["<S3>:17"] = {sid: "ACCSystem:1:17"};
	this.sidHashMap["ACCSystem:1:17"] = {rtwname: "<S3>:17"};
	this.rtwnameHashMap["<S3>:41"] = {sid: "ACCSystem:1:41"};
	this.sidHashMap["ACCSystem:1:41"] = {rtwname: "<S3>:41"};
	this.rtwnameHashMap["<S3>:39"] = {sid: "ACCSystem:1:39"};
	this.sidHashMap["ACCSystem:1:39"] = {rtwname: "<S3>:39"};
	this.rtwnameHashMap["<S3>:19"] = {sid: "ACCSystem:1:19"};
	this.sidHashMap["ACCSystem:1:19"] = {rtwname: "<S3>:19"};
	this.rtwnameHashMap["<S3>:20"] = {sid: "ACCSystem:1:20"};
	this.sidHashMap["ACCSystem:1:20"] = {rtwname: "<S3>:20"};
	this.rtwnameHashMap["<S3>:11"] = {sid: "ACCSystem:1:11"};
	this.sidHashMap["ACCSystem:1:11"] = {rtwname: "<S3>:11"};
	this.rtwnameHashMap["<S3>:6"] = {sid: "ACCSystem:1:6"};
	this.sidHashMap["ACCSystem:1:6"] = {rtwname: "<S3>:6"};
	this.rtwnameHashMap["<S3>:2"] = {sid: "ACCSystem:1:2"};
	this.sidHashMap["ACCSystem:1:2"] = {rtwname: "<S3>:2"};
	this.rtwnameHashMap["<S3>:12"] = {sid: "ACCSystem:1:12"};
	this.sidHashMap["ACCSystem:1:12"] = {rtwname: "<S3>:12"};
	this.rtwnameHashMap["<S3>:7"] = {sid: "ACCSystem:1:7"};
	this.sidHashMap["ACCSystem:1:7"] = {rtwname: "<S3>:7"};
	this.rtwnameHashMap["<S3>:15"] = {sid: "ACCSystem:1:15"};
	this.sidHashMap["ACCSystem:1:15"] = {rtwname: "<S3>:15"};
	this.rtwnameHashMap["<S3>:13"] = {sid: "ACCSystem:1:13"};
	this.sidHashMap["ACCSystem:1:13"] = {rtwname: "<S3>:13"};
	this.rtwnameHashMap["<S3>:43"] = {sid: "ACCSystem:1:43"};
	this.sidHashMap["ACCSystem:1:43"] = {rtwname: "<S3>:43"};
	this.rtwnameHashMap["<S3>:42"] = {sid: "ACCSystem:1:42"};
	this.sidHashMap["ACCSystem:1:42"] = {rtwname: "<S3>:42"};
	this.rtwnameHashMap["<S3>:33"] = {sid: "ACCSystem:1:33"};
	this.sidHashMap["ACCSystem:1:33"] = {rtwname: "<S3>:33"};
	this.rtwnameHashMap["<S3>:45"] = {sid: "ACCSystem:1:45"};
	this.sidHashMap["ACCSystem:1:45"] = {rtwname: "<S3>:45"};
	this.rtwnameHashMap["<S3>:24"] = {sid: "ACCSystem:1:24"};
	this.sidHashMap["ACCSystem:1:24"] = {rtwname: "<S3>:24"};
	this.rtwnameHashMap["<S3>:40"] = {sid: "ACCSystem:1:40"};
	this.sidHashMap["ACCSystem:1:40"] = {rtwname: "<S3>:40"};
	this.rtwnameHashMap["<S3>:31"] = {sid: "ACCSystem:1:31"};
	this.sidHashMap["ACCSystem:1:31"] = {rtwname: "<S3>:31"};
	this.rtwnameHashMap["<S3>:32"] = {sid: "ACCSystem:1:32"};
	this.sidHashMap["ACCSystem:1:32"] = {rtwname: "<S3>:32"};
	this.rtwnameHashMap["<S4>/In"] = {sid: "ACCSystem:241:1"};
	this.sidHashMap["ACCSystem:241:1"] = {rtwname: "<S4>/In"};
	this.rtwnameHashMap["<S4>/Trigger"] = {sid: "ACCSystem:241:2"};
	this.sidHashMap["ACCSystem:241:2"] = {rtwname: "<S4>/Trigger"};
	this.rtwnameHashMap["<S4>/ "] = {sid: "ACCSystem:241:3"};
	this.sidHashMap["ACCSystem:241:3"] = {rtwname: "<S4>/ "};
	this.rtwnameHashMap["<S5>/Go"] = {sid: "ACCSystem:123"};
	this.sidHashMap["ACCSystem:123"] = {rtwname: "<S5>/Go"};
	this.rtwnameHashMap["<S5>/Stop"] = {sid: "ACCSystem:124"};
	this.sidHashMap["ACCSystem:124"] = {rtwname: "<S5>/Stop"};
	this.rtwnameHashMap["<S5>/Data Store Memory"] = {sid: "ACCSystem:104"};
	this.sidHashMap["ACCSystem:104"] = {rtwname: "<S5>/Data Store Memory"};
	this.rtwnameHashMap["<S5>/Data Store Read"] = {sid: "ACCSystem:105"};
	this.sidHashMap["ACCSystem:105"] = {rtwname: "<S5>/Data Store Read"};
	this.rtwnameHashMap["<S5>/Data Store Read1"] = {sid: "ACCSystem:107"};
	this.sidHashMap["ACCSystem:107"] = {rtwname: "<S5>/Data Store Read1"};
	this.rtwnameHashMap["<S5>/Data Store Write"] = {sid: "ACCSystem:106"};
	this.sidHashMap["ACCSystem:106"] = {rtwname: "<S5>/Data Store Write"};
	this.rtwnameHashMap["<S5>/Data Type Conversion"] = {sid: "ACCSystem:114"};
	this.sidHashMap["ACCSystem:114"] = {rtwname: "<S5>/Data Type Conversion"};
	this.rtwnameHashMap["<S5>/Data Type Conversion1"] = {sid: "ACCSystem:117"};
	this.sidHashMap["ACCSystem:117"] = {rtwname: "<S5>/Data Type Conversion1"};
	this.rtwnameHashMap["<S5>/Gain1"] = {sid: "ACCSystem:247"};
	this.sidHashMap["ACCSystem:247"] = {rtwname: "<S5>/Gain1"};
	this.rtwnameHashMap["<S5>/Gain2"] = {sid: "ACCSystem:128"};
	this.sidHashMap["ACCSystem:128"] = {rtwname: "<S5>/Gain2"};
	this.rtwnameHashMap["<S5>/Sum"] = {sid: "ACCSystem:109"};
	this.sidHashMap["ACCSystem:109"] = {rtwname: "<S5>/Sum"};
	this.rtwnameHashMap["<S5>/Out1"] = {sid: "ACCSystem:125"};
	this.sidHashMap["ACCSystem:125"] = {rtwname: "<S5>/Out1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
