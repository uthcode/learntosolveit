// S5 1.3beta7 (18-Apr-2007) advanced version by C. Effenberger 
// Please see http://s5.netzgesta.de/ for more information
// based on S5 v1.2a1 slides.js -- released into the Public Domain
// Please see http://www.meyerweb.com/eric/tools/s5/credits.html for information 
// about all the wonderful and talented contributors to this code!
// audio extension: soundmanager2 is NOT Public Domain
// Please see http://www.schillmania.com/projects/soundmanager2/ for information

var undef;
var slideCSS = '';
var snum = 0;
var smax = 1;
var incpos = 0;
var number = undef;
var firstTime = 1;
var s5mode = true;
var helpmode = false;
var defaultView = 'slideshow'; //outline
var controlVis = 'visible';

// scalable images extension
var empx = 0;
var images = new Array();
var canvas = new Array();
var medias = new Array();
var piecharts = new Array(); 
var barcharts = new Array();
var linecharts = new Array();  
// scalable images extension

// transition extension
var tranSitions = false;
var fadeModus = false;
var fadeDuration = 500;
var incrDuration = 250;
var opac = 1;
var cid = '';
var nid = '';
var tid = '';
var jl = '';
// transition extension

// autoplay extension
var autoMatic = false;
var playLoop = false;
var playPause = false;
var autoRun = false;
var playDelay = 5000;
var remainDer = 0;
var incrDelay = 0;
// autoplay extension

// audio extension
var sound = new Array();
var audioSupport = false;
var audioVolume = 100;
var audioError = false;
var swfUnloaded = true;
var bgSoundItem = 9999;
var curSoundID = -1;
// audio extension

// panel extension
var highLight = "rgb(255, 204, 0)";
// panel extension

// canvas chart extension
var canvasSupport = false;
var ChartData = new Array();
var colorSlice = new Array();
var font = document.createElement("img");
font.setAttribute("src", "ui/graphic_support/numeric.png");
signs = {
	'0': {sx: 0, sy: 0, sw: 48, sh: 64},
	'1': {sx: 48, sy: 0, sw: 48, sh: 64},
	'2': {sx: 96, sy: 0, sw: 48, sh: 64},
	'3': {sx: 144, sy: 0, sw: 48, sh: 64},
	'4': {sx: 192, sy: 0, sw: 48, sh: 64},
	'5': {sx: 240, sy: 0, sw: 48, sh: 64},
	'6': {sx: 288, sy: 0, sw: 48, sh: 64},
	'7': {sx: 336, sy: 0, sw: 48, sh: 64},
	'8': {sx: 384, sy: 0, sw: 48, sh: 64},
	'9': {sx: 432, sy: 0, sw: 48, sh: 64},
	'%': {sx: 480, sy: 0, sw: 48, sh: 64},
	'.': {sx: 528, sy: 0, sw: 24, sh: 64}
};
var colorNames= new Array(); 
colorNames["black"]="#000000"; colorNames["maroon"]="#800000";colorNames["green"]="#008000"; colorNames["olive"]="#808000";colorNames["navy"]="#000080"; colorNames["purple"]="#800080";colorNames["teal"]="#008080"; colorNames["gray"]="#808080";colorNames["silver"]="#C0C0C0"; colorNames["red"]="#FF0000";colorNames["lime"]="#00FF00"; colorNames["yellow"]="#FFFF00";colorNames["blue"]="#0000FF"; colorNames["fuchsia"]="#FF00FF";colorNames["aqua"]="#00FFFF"; colorNames["white"]="#FFFFFF";colorNames["aliceblue"]="#F0F8FF"; colorNames["antiquewhite"]="#FAEBD7";colorNames["aquamarine"]="#7FFFD4"; colorNames["azure"]="#F0FFFF";colorNames["beige"]="#F5F5DC"; colorNames["blueviolet"]="#8A2BE2";colorNames["brown"]="#A52A2A"; colorNames["burlywood"]="#DEB887";colorNames["cadetblue"]="#5F9EA0"; colorNames["chartreuse"]="#7FFF00";colorNames["chocolate"]="#D2691E"; colorNames["coral"]="#FF7F50";colorNames["cornflowerblue"]="#6495ED"; colorNames["cornsilk"]="#FFF8DC";colorNames["crimson"]="#DC143C"; colorNames["darkblue"]="#00008B";colorNames["darkcyan"]="#008B8B"; colorNames["darkgoldenrod"]="#B8860B";colorNames["darkgray"]="#A9A9A9"; colorNames["darkgreen"]="#006400";colorNames["darkkhaki"]="#BDB76B"; colorNames["darkmagenta"]="#8B008B";colorNames["darkolivegreen"]="#556B2F"; colorNames["darkorange"]="#FF8C00";colorNames["darkorchid"]="#9932CC"; colorNames["darkred"]="#8B0000";colorNames["darksalmon"]="#E9967A"; colorNames["darkseagreen"]="#8FBC8F";colorNames["darkslateblue"]="#483D8B"; colorNames["darkslategray"]="#2F4F4F";colorNames["darkturquoise"]="#00CED1"; colorNames["darkviolet"]="#9400D3";colorNames["deeppink"]="#FF1493"; colorNames["deepskyblue"]="#00BFFF";colorNames["dimgray"]="#696969"; colorNames["dodgerblue"]="#1E90FF";colorNames["firebrick"]="#B22222"; colorNames["floralwhite"]="#FFFAF0";colorNames["forestgreen"]="#228B22"; colorNames["gainsboro"]="#DCDCDC";colorNames["ghostwhite"]="#F8F8FF"; colorNames["gold"]="#FFD700";colorNames["goldenrod"]="#DAA520"; colorNames["greenyellow"]="#ADFF2F";colorNames["honeydew"]="#F0FFF0"; colorNames["hotpink"]="#FF69B4";colorNames["indianred"]="#CD5C5C"; colorNames["indigo"]="#4B0082";colorNames["ivory"]="#FFFFF0"; colorNames["khaki"]="#F0E68C";colorNames["lavender"]="#E6E6FA"; colorNames["lavenderblush"]="#FFF0F5";colorNames["lawngreen"]="#7CFC00"; colorNames["lemonchiffon"]="#FFFACD";colorNames["lightblue"]="#ADD8E6"; colorNames["lightcoral"]="#F08080";colorNames["lightcyan"]="#E0FFFF"; colorNames["lightgoldenrodyellow"]="#FAFAD2";colorNames["lightgreen"]="#90EE90"; colorNames["lightgrey"]="#D3D3D3";colorNames["lightpink"]="#FFB6C1"; colorNames["lightsalmon"]="#FFA07A";colorNames["lightseagreen"]="#20B2AA"; colorNames["lightskyblue"]="#87CEFA";colorNames["lightslategray"]="#778899"; colorNames["lightsteelblue"]="#B0C4DE";colorNames["lightyellow"]="#FFFFE0"; colorNames["limegreen"]="#32CD32";colorNames["linen"]="#FAF0E6"; colorNames["mediumaquamarine"]="#66CDAA";colorNames["mediumblue"]="#0000CD"; colorNames["mediumorchid"]="#BA55D3";colorNames["ediumpurple"]="#9370D"; colorNames["mediumseagreen"]="#3CB371";colorNames["mediumslateblue"]="#7B68EE"; colorNames["mediumspringgreen"]="#00FA9A";colorNames["mediumturquoise"]="#48D1CC"; colorNames["mediumvioletred"]="#C71585";colorNames["midnightblue"]="#191970"; colorNames["mintcream"]="#F5FFFA";colorNames["mistyrose"]="#FFE4E1"; colorNames["moccasin"]="#FFE4B5";colorNames["navajowhite"]="#FFDEAD"; colorNames["oldlace"]="#FDF5E6";colorNames["olivedrab"]="#6B8E23"; colorNames["orange"]="#FFA500";colorNames["orangered"]="#FF4500"; colorNames["orchid"]="#DA70D6";colorNames["palegoldenrod"]="#EEE8AA"; colorNames["palegreen"]="#98FB98";colorNames["paleturquoise"]="#AFEEEE"; colorNames["palevioletred"]="#DB7093";colorNames["papayawhip"]="#FFEFD5"; colorNames["peachpuff"]="#FFDAB9";colorNames["peru"]="#CD853F"; colorNames["pink"]="#FFC0CB";colorNames["plum"]="#DDA0DD"; colorNames["powderblue"]="#B0E0E6";colorNames["rosybrown"]="#BC8F8F"; colorNames["royalblue"]="#4169E1";colorNames["saddlebrown"]="#8B4513"; colorNames["salmon"]="#FA8072";colorNames["sandybrown"]="#F4A460"; colorNames["seagreen"]="#2E8B57";colorNames["seashell"]="#FFF5EE"; colorNames["sienna"]="#A0522D";colorNames["skyblue"]="#87CEEB"; colorNames["slateblue"]="#6A5ACD";colorNames["slategray"]="#708090"; colorNames["snow"]="#FFFAFA";colorNames["springgreen"]="#00FF7F"; colorNames["steelblue"]="#4682B4";colorNames["tan"]="#D2B48C"; colorNames["thistle"]="#D8BFD8";colorNames["tomato"]="#FF6347"; colorNames["turquoise"]="#40E0D0";colorNames["violet"]="#EE82EE"; colorNames["wheat"]="#F5DEB3";colorNames["whitesmoke"]="#F5F5F5"; colorNames["yellowgreen"]="#9ACD32";
var canvas_bgcolor = "";
var canvas_width = 200;
var canvas_height = 200;
var canvas_noshade = 0;
var canvas_nofill = 0;
var canvas_noshadow = 0;
var canvas_htmltext = 0;
var canvas_imgtext = 0;
var canvas_notext = 0;
// canvas chart extension

var s5NotesWindow;
var s5NotesWindowLoaded = false;
var previousSlide = 0;
var presentationStart = new Date();
var slideStart = new Date();

var countdown = {
	timer: 0,
	state: 'pause',
	start: new Date(),
	end: 0,
	remaining: 0
};

var isIE = navigator.appName == 'Microsoft Internet Explorer' && navigator.userAgent.indexOf('Opera') < 1 ? 1 : 0;
if(isIE) var notIE7 = parseInt(navigator.appVersion) < 7 ? 1 : 0;
var isOp = navigator.userAgent.indexOf('Opera') > -1 ? 1 : 0;
var isGe = navigator.userAgent.indexOf('Gecko') > -1 && navigator.userAgent.indexOf('Safari') < 1 ? 1 : 0;
var isS2 = navigator.userAgent.indexOf('Safari') >= 2 ? 1 : 0;

function hasClass(object, className) {
	if (!object.className) return false;
	return (object.className.search('(^|\\s)' + className + '(\\s|$)') != -1);
}

function hasValue(object, value) {
	if (!object) return false;
	return (object.search('(^|\\s)' + value + '(\\s|$)') != -1);
}

function removeClass(object,className) {
	if (!object || !hasClass(object,className)) return;
	object.className = object.className.replace(new RegExp('(^|\\s)'+className+'(\\s|$)'), RegExp.$1+RegExp.$2);
}

function addClass(object,className) {
	if (!object || hasClass(object, className)) return;
	if (object.className) {
		object.className += ' '+className;
	} else {
		object.className = className;
	}
}

function changeClass(object,className) {
	if (!object) return;
	object.firstChild.className = className;
}

function GetElementsWithClassName(elementName,className) {
	var allElements = document.getElementsByTagName(elementName);
	var elemColl = new Array();
	for (var i = 0; i< allElements.length; i++) {
		if (hasClass(allElements[i], className)) {
			elemColl[elemColl.length] = allElements[i];
		}
	}
	return elemColl;
}

function isParentOrSelf(element, id) {
	if (element == null || element.nodeName=='BODY') return false;
	else if (element.id == id) return true;
	else return isParentOrSelf(element.parentNode, id);
}

function nodeValue(node) {
	var result = "";
	if (node.nodeType == 1) {
		var children = node.childNodes;
		for (var i = 0; i < children.length; ++i) {
			result += nodeValue(children[i]);
		}		
	}
	else if (node.nodeType == 3) {
		result = node.nodeValue;
	}
	return(result);
}

function slideLabel() {
	var slideColl = GetElementsWithClassName('*','slide');
	var list = document.getElementById('jumplist');
	smax = slideColl.length;
	for (var n = 0; n < smax; n++) {
		var obj = slideColl[n];
		var did = 'slide' + n.toString();
		obj.setAttribute('id',did);
		var otext = '';
		var menu = obj.firstChild;
		if (!menu) continue; // to cope with empty slides
		while (menu && menu.nodeType == 3) {
			menu = menu.nextSibling;
		}
	 	if (!menu) continue; // to cope with slides with only text nodes
		var menunodes = menu.childNodes;
		for (var o = 0; o < menunodes.length; o++) {
			otext += nodeValue(menunodes[o]);
		}
		list.options[list.length] = new Option(n + ' : '  + otext, n);
	}
}

function currentSlide() {
	var cs, at, fd, ss;
	if (document.getElementById) {
		cs = document.getElementById('currentSlide');
	} else {
		cs = document.currentSlide;
	}
	fd = fadeModus?"F":"&ndash;";
	ss = audioSupport?"S":"&ndash;";  
	at = (autoMatic?(playPause?"||":(playLoop?"&gt;0":"&gt;|")):"&ndash;&ndash;");
	cs.innerHTML = '<div id="plink" nowrap="nowrap">' + 
	'<span id="csFade">[' + fd + ss + ']<\/span>&nbsp;' +
	'<span id="csHere"><strong>' + snum + '<\/strong><\/span>' + 
	'<span id="csSep">\/<\/span>' + 
	'<span id="csTotal">' + (smax-1) + '<\/span>&nbsp;' +
	'<span id="csAuto">[' + at + ']<\/span>' +
	'<\/div>';
		
	if (snum == 0) {
		cs.style.visibility = 'hidden';
	} else {
		cs.style.visibility = 'visible';
	}
}

function go(step) {
	if (document.getElementById('slideProj').disabled || step == 0) return;
	jl = document.getElementById('jumplist');
	cid = 'slide' + snum;
	var ce = document.getElementById(cid);
	if (incrementals[snum].length > 0) {
		for (var i = 0; i < incrementals[snum].length; i++) {
			removeClass(incrementals[snum][i], 'current');
			removeClass(incrementals[snum][i], 'incremental');
		}
	}
	if (step != 'j') {
		snum += step;
		lmax = smax - 1;
		if (snum > lmax) snum = lmax;
		if (snum < 0) snum = 0;
	}else {
		snum = parseInt(jl.value);
	}	
	nid = 'slide' + snum;
	var ne = document.getElementById(nid);
	if (!ne) {
		ne = document.getElementById('slide0');
		nid = 'slide0';
		snum = 0;
	}
	if (step < 0) {
		incpos = incrementals[snum].length
	}else {
		incpos = 0;
	}
	if (incrementals[snum].length > 0 && incpos == 0) {
		for (var i = 0; i < incrementals[snum].length; i++) {
			if (hasClass(incrementals[snum][i], 'current')) {
				incpos = i + 1;
			}else {
				addClass(incrementals[snum][i], 'incremental');
			}
		}
	}
	if (incrementals[snum].length > 0 && incpos > 0) {
		addClass(incrementals[snum][incpos - 1], 'current');
	}
	var guru = document.getElementById('guru');
	if(guru && snum==0) {
		guru.style.visibility = 'visible';
	}else if(guru && snum>0) {
		guru.style.visibility = 'hidden';
	}	
	if(tranSitions && s5mode && fadeModus) {
		if(curSoundID != getSoundID(nid)) {
			if(curSoundID == bgSoundItem && !sound[getSoundID(nid)]) {
			}else {fadeoutSound(curSoundID,true); } // audio support
		}		
		changeOpac(0,nid);
		changeOpac(100,cid);
		ce.style.visibility = 'visible';
		shiftOpacity(cid,fadeDuration);
		window.setTimeout("changeSlides()",fadeDuration);
	}else {
		if(curSoundID != getSoundID(nid)) {
			if(curSoundID == bgSoundItem && !sound[getSoundID(nid)]) {
			}else {stopSound(curSoundID); } // audio support 
		}
		ce.style.visibility = 'hidden';
		if (isOp) location.hash = nid;
		ne.style.visibility = 'visible';
		finishSlides();		
	}
}

function changeSlides() {
	if(nid != cid) changeOpac(100,cid);
	document.getElementById(cid).style.visibility = 'hidden';
	document.getElementById(nid).style.visibility = 'visible';
	if (isOp) location.hash = nid;
	shiftOpacity(nid,fadeDuration);
	window.setTimeout("finishSlides()",fadeDuration);
}

function finishSlides() {
	jl.selectedIndex = snum;
	currentSlide();
	loadNote();
	permaLink();
	number = undef;
	if(sound[getSoundID(nid)]) {
		playSound(nid); // audio support
	}else if(sound[bgSoundItem] && curSoundID != bgSoundItem) {
		playSound(bgSoundItem); // audio support
	}
}

function goTo(target) {
	if (target >= smax || target == snum) return;
	go(target - snum);
}

function subgo(step) {
	if (step > 0) {
		removeClass(incrementals[snum][incpos - 1],'current');
		removeClass(incrementals[snum][incpos], 'incremental');
		if(tranSitions && s5mode && fadeModus) { 			
			if(!incrementals[snum][incpos].id) {
				var tmp = new Date(); tid = "inc" + String(tmp.getTime());
				incrementals[snum][incpos].id = tid;
			}else {
				tid = incrementals[snum][incpos].id;
			}	
			if(typeof(incrementals[snum][incpos].src) != "undefined" || incrementals[snum][incpos].getContext) {
				changeOpac(0,tid);		
				addClass(incrementals[snum][incpos],'current');
				shiftOpacity(tid,incrDuration);
				setTimeout("nextInc()",incrDuration);
			}else {
				addClass(incrementals[snum][incpos],'current');
				nextInc();
			}	
		}else {
			addClass(incrementals[snum][incpos],'current');
			nextInc();
		}
	} else {
		incpos--;
		removeClass(incrementals[snum][incpos],'current');
		addClass(incrementals[snum][incpos], 'incremental');
		addClass(incrementals[snum][incpos - 1],'current');
		loadNote();
	}
}

function nextInc() {
	incpos++;
	loadNote();
}

function toggle() {
	var slideColl = GetElementsWithClassName('*','slide');
	var slides = document.getElementById('slideProj');
	var outline = document.getElementById('outlineStyle');
	var guru = document.getElementById('guru');
	if (!slides.disabled) {
		stopPlay();
		if(audioSupport && !swfUnloaded) stopAllSounds();
		slides.disabled = true;
		outline.disabled = false;
		s5mode = false;
		fontSize(1,'em');
		for (var n = 0; n < smax; n++) {
			var slide = slideColl[n];
			slide.style.visibility = 'visible';
		}
		if(guru) guru.style.visibility = 'hidden';
	} else {
		slides.disabled = false;
		outline.disabled = true;
		s5mode = true;
		fontScale();
		for (var n = 0; n < smax; n++) {
			var slide = slideColl[n];
			slide.style.visibility = 'hidden';
		}
		slideColl[snum].style.visibility = 'visible';
		if(guru && snum==0) guru.style.visibility = 'visible';
	}
}

function showHide(action) {
	var obj = GetElementsWithClassName('*','hideme')[0];
	switch (action) {
	case 's': 
		obj.style.visibility = 'visible'; 
		break;
	case 'h':
		obj.style.visibility = 'hidden'; 
		break;
	case 'k':
		if (obj.style.visibility != 'visible') {
			obj.style.visibility = 'visible';
		} else {
			obj.style.visibility = 'hidden';
		}
	break;
	}
}

function keys(key) {
	if (!key) {
		key = event;
		key.which = key.keyCode;
	}
	if (helpmode) {
		dumpHelpReq();
		return;
	}
	if (key.which == 84 && !isOp) {
		toggle();
		return;
	}
	if (s5mode) {
		if (autoMatic) {
			switch (key.which) {
			case 70: // f/ading on/off
				switchFade();
				break;
			case 83: // s/ound on/off
				toggleSounds();
				break;	
			case 67: // c
				showHide('k');
				break;
			case 65: // a/utoplay on/off
				stopPlay();
				break;
			case 76: // l/ooping on/off
				switchLoop();
				break;
			case 80: // p/ause
			case 32: // spacebar
				pausePlay();
				break;
			}
		}else {
			switch (key.which) {
			case 8: // backspace = HELP
				createHelpReq();
				break;								
			case 10: // return
			case 13: // enter
				if (window.event && isParentOrSelf(window.event.srcElement, 'controls')) return;
				if (key.target && isParentOrSelf(key.target, 'controls')) return;
				if(number != undef) {
					goTo(number);
					break;
				}
			case 32: // spacebar
			case 34: // page down
			case 39: // rightkey
			case 40: // downkey
				if(number != undef) {
					go(number);
				} else if (!incrementals[snum] || incpos >= incrementals[snum].length) {
					go(1);
				} else {
					subgo(1);
				}
				break;
			case 33: // page up
			case 37: // leftkey
			case 38: // upkey
				if(number != undef) {
					go(-1 * number);
				} else if (!incrementals[snum] || incpos <= 0) {
					go(-1);
				} else {
					subgo(-1);
				}
				break;
			case 65: // a/utoplay
				startPlay();
				break;				
			case 72: // h
			case 36: // home
				goTo(0);
				break;
			case 69: // e
			case 35: // end
				goTo(smax-1);
				break;
			case 70: // f/ade transitions on/off
				switchFade();
				break;
			case 76: // l/ooping on/off
				switchLoop();
				break;
			case 83: // s/ound support on/off
				toggleSounds();
				break;					
			case 27: // escape
			case 81: // q
				if(!isOp) byby();
				break;
			case 67: // c
				showHide('k');
				break;
			case 78: // n
				createNotesWindow();
				break;
			}
			if (key.which < 48 || key.which > 57) {
				number = undef;
			} else {
				if (window.event && isParentOrSelf(window.event.srcElement, 'controls')) return;
				if (key.target && isParentOrSelf(key.target, 'controls')) return;
				number = (((number != undef) ? number : 0) * 10) + (key.which - 48);
			}
		}
	}
	return false;
}

function clicker(e) {
	number = undef;
	var target;
	if (window.event) {
		target = window.event.srcElement;
		e = window.event;
	} else {
		target = e.target;
	}
	if (target.href != null || hasValue(target.rel, 'external') || isParentOrSelf(target, 'controls') || isParentOrSelf(target,'embed') || isParentOrSelf(target,'object')) return true;
	if (!helpmode) {
		if (!e.which || e.which == 1) {
			if (!incrementals[snum] || incpos >= incrementals[snum].length) {
				go(1);
			} else {
				subgo(1);
			}
		}
	} else {
		dumpHelpReq();  
	}
}

function findSlide(hash) {
	var target = null;
	var slides = GetElementsWithClassName('*','slide');
	for (var i = 0; i < slides.length; i++) {
		var targetSlide = slides[i];
		if ( (targetSlide.name && targetSlide.name == hash)
		 || (targetSlide.id && targetSlide.id == hash) ) {
			target = targetSlide;
			break;
		}
	}
	while(target != null && target.nodeName != 'BODY') {
		if (hasClass(target, 'slide')) {
			return parseInt(target.id.slice(5));
		}
		target = target.parentNode;
	}
	return null;
}

function slideJump() {
	if (window.location.hash == null) return;
	var sregex = /^#slide(\d+)$/;
	var matches = sregex.exec(window.location.hash);
	var dest = null;
	if (matches != null) {
		dest = parseInt(matches[1]);
	} else {
		dest = findSlide(window.location.hash.slice(1));
	}
	if (dest != null)
		go(dest - snum);
}

function fixLinks() {
	var thisUri = window.location.href;
	thisUri = thisUri.slice(0, thisUri.length - window.location.hash.length);
	var aelements = document.getElementsByTagName('A');
	for (var i = 0; i < aelements.length; i++) {
		var a = aelements[i].href;
		var slideID = a.match('\#slide[0-9]{1,2}');
		if ((slideID) && (slideID[0].slice(0,1) == '#')) {
			var dest = findSlide(slideID[0].slice(1));
			if (dest != null) {
				if (aelements[i].addEventListener) {
					aelements[i].addEventListener("click", new Function("e",
						"if (document.getElementById('slideProj').disabled) return;" +
						"go("+dest+" - snum); " +
						"if (e.preventDefault) e.preventDefault();"), true);
				} else if (aelements[i].attachEvent) {
					aelements[i].attachEvent("onclick", new Function("",
						"if (document.getElementById('slideProj').disabled) return;" +
						"go("+dest+" - snum); " +
						"event.returnValue = false;"));
				}
			}
		}
	}
}

function externalLinks() {
	if (!document.getElementsByTagName) return;
	var anchors = document.getElementsByTagName('a');
	for (var i=0; i<anchors.length; i++) {
		var anchor = anchors[i];
		if (anchor.getAttribute('href') && hasValue(anchor.rel, 'external')) {
			anchor.target = '_blank';
			addClass(anchor,'external');
		}
	}
}

function permaLink() {
	document.getElementById('plink').href = window.location.pathname + '#slide' + snum;
}

function createControls() {
	var controlsDiv = document.getElementById("controls");
	if (!controlsDiv) return;
	var hider = ' onmouseover="showHide(\'s\');" onmouseout="showHide(\'h\');"';
	var hideDiv, hideList = '';
	if (controlVis == 'hidden') {
		hideDiv = hider;
	} else {
		hideList = hider;
	}
	if(isOp) {
		var str = '';
	}else {
		var str = '<a accesskey="t" id="sheet" title="toggle CSS" href="javascript:toggle();">&plusmn;<\/a>';
	}	
	if(isIE) {
		var tmp = "move around&xA0;until the color&xA0;change to red!";
	}else if(isS2) {
		var tmp = "move around\r\nuntil the color\r\nchange to red!";
	}else {
		var tmp = "move around until color change to red!";
	}
	if(isIE) {
		controlsDiv.innerHTML = str + '<form action="#" id="controlForm"' + hideDiv + '>' +
		'<div id="navLinks" title="press [backspace] for keyboard help!" style="background-image: none;">' +
		'<a accesskey="n" id="show-notes" title="show Notes" href="javascript:createNotesWindow();">i<\/a>' +
		'<a accesskey="t" id="toggle" title="toggle CSS" href="javascript:toggle();">&plusmn;<\/a>' +
		'<a accesskey="h" id="zero" title="goto Start Slide" href="javascript:goTo(0);">|&lt;<\/a>' +
		'<a accesskey="y" id="prev" title="previous Slide" href="javascript:go(-1);">&lt;<\/a>' +
		'<a accesskey="x" id="next" title="next Slide" href="javascript:go(1);">&gt;<\/a>' +
		'<a accesskey="e" id="last" title="goto Last Slide" href="javascript:goTo(smax-1);">&gt;|<\/a>' +
		'<br \/><div class="subLinks" id="autoLinks" style="margin-left:0.25em;">' +
		'<a accesskey="a" id="auto" title="Auto Play" href="javascript:togglePlay();">&gt;<\/a>&nbsp;' +
		'<a style="font-weight: bold;" accesskey="p" id="pause" title="Pausing" href="javascript:pausePlay();">||<\/a>&nbsp;' +
		'<a style="font-weight: bold;" accesskey="l" id="loop" title="Looping" href="javascript:switchLoop();">&infin;<\/a>&nbsp;&nbsp;' +
		'<a title="5 Sec. Delay" href="javascript:setDelay(5);">5<\/a>&middot;' +
		'<a title="10 Sec. Delay" href="javascript:setDelay(10);">10<\/a>&middot;' + 
		'<a title="15 Sec. Delay" href="javascript:setDelay(15);">15<\/a>&middot;' + 
		'<a title="30 Sec. Delay" href="javascript:setDelay(30);">30<\/a>&middot;' + 
		'<a title="60 Sec. Delay" href="javascript:setDelay(60);">60<\/a>' +
		'<\/div><select id="jumplist" style="position: absolute; left: -9999px;"><\/select><\/div><\/form>';
	}else {
		controlsDiv.innerHTML =  str +
		'<form action="#" id="controlForm"' + hideDiv + '>' +
		'<div id="navLinks" title="press [backspace] or double click this area for keyboard help!" ondblclick="createHelpReq();">' +
		'<a accesskey="q" id="exit" title="exit Show" href="javascript:byby();">&times;<\/a>' +
		'<a accesskey="n" id="show-notes" title="show Notes" href="javascript:createNotesWindow();">&#x274f;<\/a>' +
		'<a accesskey="t" id="toggle" title="toggle CSS" href="javascript:toggle();">&plusmn;<\/a>' +
		'<a accesskey="h" id="zero" title="goto Start Slide" href="javascript:goTo(0);">|&lt;<\/a>' +
		'<a accesskey="y" id="prev" title="previous Slide" href="javascript:go(-1);">&lt;<\/a>' +
		'<a accesskey="x" id="next" title="next Slide" href="javascript:go(1);">&gt;<\/a>' +
		'<a accesskey="e" id="last" title="goto Last Slide" href="javascript:goTo(smax-1);">&gt;|<\/a>' +
		'<a id="list" style="cursor:wait;" title="' + tmp + '">&Xi;<\/a>' +
		'<select id="jumplist" title="select named Slide" onchange="go(\'j\');"><\/select>' +
		'<br \/><div class="subLinks" id="fadeLinks">' +
		'<a style="font-weight: bold;" accesskey="f" id="fade" title="Transions" href="javascript:switchFade();">&#x25a8;<\/a>&nbsp;' +
		'<\/div><div class="subLinks" id="audioLinks" style="margin-left:0.25em;">' +
		'<a accesskey="s" id="audio" title="Sound" href="javascript:toggleSounds();">&#x266b;<\/a>&nbsp;' +
		'<a id="volume" style="cursor:wait;" title="' + tmp + '">&#x25e2;<\/a>' +
		'<select id="volumelist" title="select Volume" onchange="setVolume();"><option value="100">100</option>' +
		'<option value="90">90</option><option value="80">80</option>' +
		'<option value="70">70</option><option value="60">60</option>' +
		'<option value="50">50</option><option value="40">40</option>' +
		'<option value="30">30</option><option value="20">20</option>' +
		'<option value="10">10</option><option value="0">0</option>' +
		'<\/select>' +
		'<\/div><div class="subLinks" id="autoLinks" style="margin-left:0.25em;">' +
		'<a accesskey="a" id="auto" title="Auto Play" href="javascript:togglePlay();">&#x25b6;<\/a>&nbsp;' +
		'<a style="font-weight: bold;" accesskey="p" id="pause" title="Pausing" href="javascript:pausePlay();">||<\/a>&nbsp;' +
		'<a style="font-weight: bold;" accesskey="l" id="loop" title="Looping" href="javascript:switchLoop();">&infin;<\/a>&nbsp;&nbsp;' +
		'<a title="5 Sec. Delay" href="javascript:setDelay(5);">5<\/a>&middot;' +
		'<a title="10 Sec. Delay" href="javascript:setDelay(10);">10<\/a>&middot;' + 
		'<a title="15 Sec. Delay" href="javascript:setDelay(15);">15<\/a>&middot;' + 
		'<a title="30 Sec. Delay" href="javascript:setDelay(30);">30<\/a>&middot;' + 
		'<a title="60 Sec. Delay" href="javascript:setDelay(60);">60<\/a>' +
		'<\/div><\/div><\/form>';
	}
	if (controlVis == 'hidden') {
		var hidden = document.getElementById('navLinks');
	} else {
		var hidden = document.getElementById('jumplist');
	}
	addClass(hidden,'hideme');
}

function fontScale() {  // causes layout problems in FireFox that get fixed if browser's Reload is used; same may be true of other Gecko-based browsers
	if (!s5mode && !isOp) return false;
	var hScreen = screen.width; var vScreen = screen.height;
	var vWindow = window.outerHeight; var hWindow = window.outerWidth;
	if (isOp && s5mode && defaultView=='slideshow' && ((hScreen != hWindow) || (vScreen != vWindow))) {
		toggle();
		return false;
	}
	if (isOp && !s5mode && ((hScreen != hWindow) || (vScreen != vWindow))) return false;
	if (isOp && !s5mode && (hScreen == hWindow) && (vScreen == vWindow)) toggle();
	var vScale = 48;  // both yield 16 (the usual browser default) at 1024x768
	var hScale = 64;  // perhaps should auto-calculate based on theme's declared value?
	if (window.innerHeight) {
		var vSize = window.innerHeight;
		var hSize = window.innerWidth;
	} else if (document.documentElement.clientHeight) {
		var vSize = document.documentElement.clientHeight;
		var hSize = document.documentElement.clientWidth;
	} else if (document.body.clientHeight) {
		var vSize = document.body.clientHeight;
		var hSize = document.body.clientWidth;
	} else {
		var vSize = 700;  // assuming 1024x768, minus chrome and such equals 8:5
		var hSize = 1024; // these do not account for kiosk mode or Opera Show
	}
	var newSize = Math.min(Math.round(vSize/vScale),Math.round(hSize/hScale));
	extendImgSizes(newSize); // scalable images extension
	extendCanSizes(newSize); // scalable canvas extension
	extendObjSizes(newSize); // scalable object extension
	fontSize(newSize,"px");
	if(!isS2 || firstTime==0) {
		generateCanvas(); // dynamic canvas extension
	}
	if (isGe) {  // hack to counter incremental reflow bugs
		var obj = document.getElementsByTagName('body')[0];
		obj.style.visibility = 'hidden';
		obj.style.display = 'none';
		obj.style.display = 'block';
		obj.style.visibility = 'visible';
		changeOpac(100,'slide' + snum);
		shiftOpacity('slide' + snum,10);
		window.setTimeout("fixReflow()",10);
	}else {
		setListPos(); // invisible select extension
	}
}

function fixReflow() {
	shiftOpacity('slide' + snum,10);
	window.setTimeout("finishReflow()",10);
}
function finishReflow() {
	setListPos(); // invisible select extension
}

function fontSize(val,fmt) {
	var value = val + fmt;
	if (!(s5ss = document.getElementById('s5ss'))) {
		if (!document.createStyleSheet) {
			document.getElementsByTagName('head')[0].appendChild(s5ss = document.createElement('style'));
			s5ss.setAttribute('media','screen, projection');
			s5ss.setAttribute('id','s5ss');
		} else {
			document.createStyleSheet();
			document.s5ss = document.styleSheets[document.styleSheets.length - 1];
		}
	}
	if (!(document.s5ss && document.s5ss.addRule)) {
		while (s5ss.lastChild) s5ss.removeChild(s5ss.lastChild);
		s5ss.appendChild(document.createTextNode('html {font-size: ' + value + ' !important;}'));
	} else {
		document.s5ss.addRule('html','font-size: ' + value + ' !important;');
	}
}

function windowChange() {
	fontScale();
}

function notOperaFix() {
	slideCSS = document.getElementById('slideProj').href;
	var slides = document.getElementById('slideProj');
	var outline = document.getElementById('outlineStyle');
	slides.setAttribute('media','screen');
	outline.disabled = true;
	if (isGe) {
		slides.setAttribute('href','null');   // Gecko fix
		slides.setAttribute('href',slideCSS); // Gecko fix
	}
	if ((isIE && notIE7) && document.styleSheets && document.styleSheets[0]) {
		document.styleSheets[0].addRule('img', 'behavior: url(ui/graphic_support/iepngfix.htc)');
		document.styleSheets[0].addRule('div', 'behavior: url(ui/graphic_support/iepngfix.htc)');
		document.styleSheets[0].addRule('.slide', 'behavior: url(ui/graphic_support/iepngfix.htc)');
	}
}

function getIncrementals(obj) {
	var incrementals = new Array();
	if (!obj) 
		return incrementals;
	var children = obj.childNodes;
	for (var i = 0; i < children.length; i++) {
		var child = children[i];
		if (hasClass(child, 'incremental')) {
			if (child.nodeName == 'OL' || child.nodeName == 'UL') {
				removeClass(child, 'incremental');
				for (var j = 0; j < child.childNodes.length; j++) {
					if (child.childNodes[j].nodeType == 1) {
						addClass(child.childNodes[j], 'incremental');
					}
				}
			} else {
				incrementals[incrementals.length] = child;
				removeClass(child,'incremental');
			}
		}
		if (hasClass(child, 'show-first')) {
			if (child.nodeName == 'OL' || child.nodeName == 'UL') {
				removeClass(child, 'show-first');
				if (child.childNodes[isGe].nodeType == 1) {
					removeClass(child.childNodes[isGe], 'incremental');
				}
			} else {
				incrementals[incrementals.length] = child;
			}
		}
		incrementals = incrementals.concat(getIncrementals(child));
	}
	return incrementals;
}

function createIncrementals() {
	var incrementals = new Array();
	for (var i = 0; i < smax; i++) {
		incrementals[i] = getIncrementals(document.getElementById('slide'+i));
	}
	return incrementals;
}

function trap(e) {
	if (!e) {
		e = event;
		e.which = e.keyCode;
	}
	try {
		modifierKey = e.ctrlKey || e.altKey || e.metaKey;
	}
	catch(e) {
		modifierKey = false;
	}
	return modifierKey || e.which == 0;
}

// notes extension
function noteLabel() { // Gives notes id's to match parent slides
	var notes = GetElementsWithClassName('div','notes');
	for (var i = 0; i < notes.length; i++) {
		var note = notes[i];
		var id = 'note' + note.parentNode.id.substring(5);
		note.setAttribute('id',id);
	}
	resetElapsedSlide();
	resetRemainingTime();
	window.setInterval('updateElaspedTime()', 1000);
}

function createNotesWindow() { // creates a window for our notes
	if (!s5NotesWindow || s5NotesWindow.closed) { // Create the window if it doesn't exist
		s5NotesWindowLoaded = false;
		// Note: Safari has a tendency to ignore window options preferring to default to the settings of the parent window, grr.
		s5NotesWindow = window.open('ui/s5-notes.html', 's5NotesWindow', 'top=0,left=0');
	}
	if (s5NotesWindowLoaded) { // Load the current note if the Note HTML has loaded
		loadNote();
	} else { // Keep trying...
		window.setTimeout('createNotesWindow()', 50);
	}
}

function loadNote() {
// Loads a note into the note window
	var notes = nextNotes = '<em class="disclaimer">There are no notes for this slide.</em>';
	if (document.getElementById('note' + snum)) {
		notes = document.getElementById('note' + snum).innerHTML;
	}
	if (document.getElementById('note' + (snum + 1))) {
		nextNotes = document.getElementById('note' + (snum + 1)).innerHTML;
	}
	
	var jl = document.getElementById('jumplist');
	var slideTitle = jl.options[jl.selectedIndex].text.replace(/^\d+\s+:\s+/, '') + ((jl.selectedIndex) ? ' (' + jl.selectedIndex + '/' + (smax - 1) + ')' : '');
	if (incrementals[snum].length > 0) {
		slideTitle += ' <small>[' + incpos + '/' + incrementals[snum].length + ']</small>';
	}
	if (jl.selectedIndex < smax - 1) {
		var nextTitle = jl.options[jl.selectedIndex + 1].text.replace(/^\d+\s+:\s+/, '') + ((jl.selectedIndex + 1) ? ' (' + (jl.selectedIndex + 1) + '/' + (smax - 1) + ')' : '');
	} else {
		var nextTitle = '[end of slide show]';
	}
	
	if (s5NotesWindow && !s5NotesWindow.closed && s5NotesWindow.document) {
		s5NotesWindow.document.getElementById('slide').innerHTML = slideTitle;
		s5NotesWindow.document.getElementById('notes').innerHTML = notes;
		s5NotesWindow.document.getElementById('next').innerHTML = nextTitle;
		s5NotesWindow.document.getElementById('nextnotes').innerHTML = nextNotes;
	}
	resetElapsedSlide();
}

function minimizeTimer(id) {
	var obj = s5NotesWindow.document.getElementById(id);
	if (hasClass(obj,'collapsed')) {
		removeClass(obj,'collapsed');
	} else {
		addClass(obj,'collapsed');
	}
}

function resetElapsedTime() {
	presentationStart = new Date();
	slideStart = new Date();
	updateElaspedTime();
}

function resetElapsedSlide() {
	if (snum != previousSlide) {
		slideStart = new Date();
		previousSlide = snum;
		updateElaspedTime();
	}
}

function updateElaspedTime() {
	if (!s5NotesWindowLoaded || !s5NotesWindow || s5NotesWindow.closed) return;
	var now = new Date();
	var ep = s5NotesWindow.document.getElementById('elapsed-presentation');
	var es = s5NotesWindow.document.getElementById('elapsed-slide');
	ep.innerHTML = formatTime(now.valueOf() - presentationStart.valueOf());
	es.innerHTML = formatTime(now.valueOf() - slideStart.valueOf());
}

function resetRemainingTime() {
	if (!s5NotesWindowLoaded || !s5NotesWindow || s5NotesWindow.closed) return;
	var startField = s5NotesWindow.document.getElementById('startFrom');
	startFrom = readTime(startField.value);
	countdown.remaining = startFrom * 60000;  // convert to msecs
	countdown.start = new Date().valueOf();
	countdown.end = countdown.start + countdown.remaining;
	var tl = s5NotesWindow.document.getElementById('timeLeft');
	var timeLeft = formatTime(countdown.remaining);
	tl.innerHTML = timeLeft;
}

function updateRemainingTime() {
	if (!s5NotesWindowLoaded || !s5NotesWindow || s5NotesWindow.closed) return;
	var tl = s5NotesWindow.document.getElementById('timeLeft');
	var now = new Date();
	if (countdown.state == 'run') {
		countdown.remaining = countdown.end - now;
	}
	tl.style.color = '';
	tl.style.backgroundColor = '';
	if (countdown.remaining >= 0) {
		var timeLeft = formatTime(countdown.remaining);
		removeClass(tl,'overtime');
		if (countdown.remaining < 300000) {
			tl.style.color = 'rgb(' + (255-Math.round(countdown.remaining/2000)) + ',0,0)';
			tl.style.backgroundColor = 'rgb(255,255,' + (Math.round(countdown.remaining/2000)) + ')';
		}
	} else {
		var timeLeft = '-' + formatTime(-countdown.remaining);
		addClass(tl,'overtime');
	}
	tl.innerHTML = timeLeft;
}

function toggleRemainingTime() {
	if (countdown.state == 'pause') countdown.state = 'run'; else countdown.state = 'pause';
	if (countdown.state == 'pause') {
		window.clearInterval(countdown.timer);
	}
	if (countdown.state == 'run') {
		countdown.start = new Date().valueOf();
		countdown.end = countdown.start + countdown.remaining;
		countdown.timer = window.setInterval('updateRemainingTime()', 1000);
	}
}

function alterRemainingTime(amt) {
	var change = amt * 60000;  // convert to msecs
	countdown.end += change;
	countdown.remaining += change;
	updateRemainingTime();
}

function formatTime(msecs)  {
	var time = new Date(msecs);
	
	var hrs = time.getUTCHours() + ((time.getUTCDate() -1) * 24); // I doubt anyone will spend more than 24 hours on a presentation or single slide but just in case...
	hrs = (hrs < 10) ? '0'+hrs : hrs;
	if (hrs == 'NaN' || isNaN(hrs)) hrs = '--';
	
	var min = time.getUTCMinutes();
	min = (min < 10) ? '0'+min : min;
	if (min == 'NaN' || isNaN(min)) min = '--';
	
	var sec = time.getUTCSeconds();
	sec = (sec < 10) ? '0'+sec : sec;
	if (sec == 'NaN' || isNaN(sec)) sec = '--';

	return hrs + ':' + min + ':' + sec;
}

function readTime(val) {
	var sregex = /:/;
	var matches = sregex.exec(val);
	if (matches == null) {
		return val;
	} else {
		var times = val.split(':');
		var hours = parseInt(times[0]);
		var mins = parseInt(times[1]);
		var total = (hours * 60) + mins;
		return total;
	}
}
// notes extension

// startup process
function createSlideShow() {
	defaultCheck();	
	if(!isIE) createDetector(); // (degrade IE) scalable images extension 
	if(opac!=0 || isIE) { // &&!isIE (degrade IE)
		tranSitions = false;
		fadeModus = false;
	}
	if(tranSitions && document.getElementById && document.createElement){
		createProgress();
		var nop=document.getElementById('StartupControl');
		nop.onload = dumpProgress;
	}else {
		startup();
		showAll();
		setListPos(true); // invisible select extension
		panelSetup();
		audioSetup(); // audio extension
		if(isS2 && firstTime>=1) {
			generateCanvas(); // dynamic canvas extension
		} firstTime = 0;
	}
}

function defaultCheck() {
	var allMetas = document.getElementsByTagName('meta');
	for (var i = 0; i< allMetas.length; i++) {
		if (allMetas[i].name == 'defaultView') {
			defaultView = allMetas[i].content;
		}
		if (allMetas[i].name == 'controlVis') {
			controlVis = allMetas[i].content;
		}
		if (allMetas[i].name == 'tranSitions') {
			tranSitions = (allMetas[i].content == "true") ? true : false;
			fadeModus = (tranSitions == true) ? true : false;
		}
		if (allMetas[i].name == 'fadeDuration') {
			var tmp = parseInt(allMetas[i].content);
			fadeDuration = Math.max(200,Math.min(tmp,2000));
		}
		if (allMetas[i].name == 'incrDuration') {
			var tmp = parseInt(allMetas[i].content);
			incrDuration = Math.max(50,Math.min(tmp,500));
		}
		if (allMetas[i].name == 'autoMatic') {
			autoMatic = (allMetas[i].content == "true") ? true : false;
		}
		if (allMetas[i].name == 'playLoop') {
			playLoop = (allMetas[i].content == "true") ? true : false;
		}
		if (allMetas[i].name == 'playDelay') {
			var tmp = parseInt(allMetas[i].content);
			playDelay = Math.max(5,Math.min(tmp,90))*1000;
			playDelay = (fadeModus == true) ? (playDelay+(2*fadeDuration)) : playDelay;
		}
		if (allMetas[i].name == 'audioSupport') {
			audioSupport = (allMetas[i].content == "true") ? true : false;
		}
		if (allMetas[i].name == 'audioVolume') {
			var tmp = parseInt(allMetas[i].content);
			audioVolume = Math.max(0,Math.min(tmp,100));
		}
		if (allMetas[i].name == 'audioError') {
			audioError = (allMetas[i].content == "true") ? true : false;
		}						
	}
}

function createProgress() {
	var obj = document.getElementsByTagName("body")[0].firstChild;
	var pg = document.createElement('div');
	pg.id = "StartupProgress";
	pg.style.position = 'absolute';
	pg.style.left = 0 + 'px';
	pg.style.top = 0 + 'px';
	pg.style.width = 100 + '%';
	pg.style.height = 100 + '%';
	pg.style.margin = 0 + 'px';
	pg.style.padding = 0 + 'px';
	if (isIE) {
		pg.style.filter = "alpha(opacity=100)";	
	}else {
		pg.style.opacity = 1.0;
	}	pg.style.zIndex = 9999;
	pg.style.backgroundColor="rgb(255, 255, 255)";
	pg.style.textAlign = "center";	pg.style.verticalAlign = "middle";
	pg.style.backgroundPosition="center center";
	pg.style.backgroundRepeat="no-repeat";
	pg.style.backgroundImage="url(ui/graphic_support/progress.gif)";
	document.getElementsByTagName("body")[0].insertBefore(pg,obj);

	var im = document.createElement('img');
	im.id = "StartupControl";
	im.src = "ui/graphic_support/blank.gif?" + new Date().valueOf();
	document.getElementsByTagName("body")[0].appendChild(im);
}

function startup() {
	createControls(); // hallvord
	slideLabel();
	incrementals = createIncrementals();
	noteLabel(); // [SI:060104] must follow slideLabel()
	loadNote();
	fixLinks();
	externalLinks();
	fontScale();
	if (!isOp) {
		notOperaFix();
	}else if(isOp) {
		document.getElementById('exit').style.visibility = 'hidden';
		document.getElementById('toggle').style.visibility = 'hidden';
		document.getElementById('list').style.visibility = 'hidden';
		document.getElementById('jumplist').style.visibility = 'hidden';
		document.getElementById('audioLinks').style.display = 'none';
	}
	slideJump();
	if (defaultView == 'outline') toggle();
	document.onkeyup = keys;
	document.onkeypress = trap;
	document.onclick = clicker;
}

function preloadImgages() {
	var temp = '';
	var objects = document.getElementsByTagName('img');
	for (var i=0; i < objects.length; i++) {
		if(objects[i].src != '') {
			temp = new Image(); 
			temp.src = objects[i].src;
		}
	}
}

function showAll() {
	var obj1 = GetElementsWithClassName('div','presentation')[0];
	if(!obj1) var obj1 = GetElementsWithClassName('ol','presentation')[0];
	var obj2 = GetElementsWithClassName('div','layout')[0];
	if(!obj1){}else {obj1.style.display = 'block'};
	if(!obj2){}else {obj2.style.display = 'block'};
}

function dumpProgress() {
	document.body.removeChild(document.getElementById('StartupControl'));
	startup();
	preloadImgages();
	showAll();
	createSoundManagerScript();
	shiftOpacity('StartupProgress',1000);
	window.setTimeout("removeProgress()",1000);}

function removeProgress() {
	document.body.removeChild(document.getElementById('StartupProgress'));
	setListPos(true); // invisible select extension
	panelSetup();
	audioSetup(); // audio extension
	if(isS2 && firstTime>=1) {
		generateCanvas(); // dynamic canvas extension
	} firstTime = 0;
}
function panelSetup() {
	if(playPause) document.getElementById('pause').style.color=highLight;
	if(playLoop) document.getElementById('loop').style.color=highLight;
	if(audioSupport && !isIE && !isOp) document.getElementById('audio').style.color=highLight;
	if(fadeModus && !isIE) document.getElementById('fade').style.color=highLight;
	if(autoMatic) {
		document.getElementById('auto').style.color=highLight; 
		startPlay();
	}
	if(audioVolume && !isIE && !isOp) {
		var idx = 0;
		if(audioVolume >= 95 && audioVolume <= 100) {idx = 0;}
		else if(audioVolume >= 85 && audioVolume < 95) {idx = 1;}
		else if(audioVolume >= 75 && audioVolume < 85) {idx = 2;}
		else if(audioVolume >= 65 && audioVolume < 75) {idx = 3;}
		else if(audioVolume >= 55 && audioVolume < 65) {idx = 4;}
		else if(audioVolume >= 45 && audioVolume < 55) {idx = 5;}
		else if(audioVolume >= 35 && audioVolume < 45) {idx = 6;}
		else if(audioVolume >= 25 && audioVolume < 35) {idx = 7;}
		else if(audioVolume >= 15 && audioVolume < 25) {idx = 8;}
		else if(audioVolume >= 5 && audioVolume < 15) {idx = 9;}
		else {idx = 10;}
		document.getElementById('volumelist').selectedIndex = idx;
	}
}
// startup process

// shutdown process
function byby() {
	stopPlay();
	if(tranSitions && fadeModus && s5mode && !isOp) {
		fadeoutSound(curSoundID,true); // audio support
		var pg = document.createElement('div');
		pg.id = "GoodBy";
		pg.style.position = 'absolute';
		pg.style.left = 0 + 'px';
		pg.style.top = 0 + 'px';
		pg.style.width = 100 + '%';
		pg.style.height = 100 + '%';
		pg.style.margin = 0 + 'px';
		pg.style.padding = 0 + 'px';
		if (isIE) {
			pg.style.filter = "alpha(opacity=0)";	
		}else {
			pg.style.opacity = 0.0;
		}		pg.style.zIndex = 9999;
		pg.style.backgroundColor="rgb(255, 255, 255)";
		pg.style.textAlign = "center";		pg.style.verticalAlign = "middle";
		pg.style.backgroundPosition="center center";
		pg.style.backgroundRepeat="no-repeat";
		pg.style.backgroundImage="url(ui/graphic_support/finish.gif)";		
		document.getElementsByTagName("body")[0].appendChild(pg);
		shiftOpacity('GoodBy',1000);
		window.setTimeout("history.back()",1000);	}else {
		stopSound(curSoundID); 
		history.back();
	}
}
// shutdown process

// scalable images extension
function createDetector() {
	var em = document.createElement('div');
	em.id='EMSizeControl'; em.style.position="absolute"; em.style.left="-999px";
	em.style.width="1em"; em.style.height="1em"; em.style.opacity=0.0;
	document.getElementsByTagName("body")[0].appendChild(em);
	var nop=document.getElementById('EMSizeControl');
	if(!nop||findPosX(nop)!=-999) {}else {
		opac=document.getElementById('EMSizeControl').style.opacity;
		empx=document.getElementById('EMSizeControl').offsetHeight;
		document.body.removeChild(document.getElementById('EMSizeControl'));
		var objects = document.getElementsByTagName('img'); 
		var j = 0; var i = 0; var k = 0; var d; var obj;
		for (i=0; i < objects.length; i++) {
			if(objects[i].className.match(/^scale/i)) {
				images[j] = objects[i];
				++j;
			}
		}		
		var objects = document.getElementsByTagName('canvas'); j = 0; 
		for (i=0; i < objects.length; i++) {
			if(objects[i].className.match(/^scale/i)) {
				canvas[objects[i].id] = objects[i];
				if(j==0) {
					if(objects[i].getContext) {
						canvasSupport = true;
					}
					++j;
				}
			}
		}	
		if(canvasSupport!=true) {
			for (d in canvas) {
				canvas[d].setAttribute("width",1); 
				canvas[d].setAttribute("height",1); 
			} 
		}	
		var objects = document.getElementsByTagName('table'); 
		j = 0; k = 0; l = 0; var w; var h; var tmp; var cnt;
		for (i=0; i < objects.length; i++) {
			if(objects[i].className.match(/^piechart/i)) {
				tmp = objects[i].id;
				cnt = tmp.split("_");
				obj = cnt[0] + "_canvas";
				if(canvas[obj]) {
					w = canvas[obj].getAttribute("width");
					h = canvas[obj].getAttribute("height");
					if(w>0&&h>0) {
						piecharts[j] = objects[i];
						em = piecharts[j].getAttribute("summary");
						if(em != "") em = "," + em;
						piecharts[j].setAttribute("summary", w + "," + h + em);
						++j;
					}
				}
			}
			if(objects[i].className.match(/^barchart/i)) {
				tmp = objects[i].id;
				cnt = tmp.split("_");
				obj = cnt[0] + "_canvas";
				if(canvas[obj]) {
					w = canvas[obj].getAttribute("width");
					h = canvas[obj].getAttribute("height");
					if(w>0&&h>0) {
						barcharts[k] = objects[i];
						em = barcharts[k].getAttribute("summary");
						if(em != "") em = "," + em;
						barcharts[k].setAttribute("summary", w + "," + h + em);
						++k;
					}
				}
			}
			if(objects[i].className.match(/^linechart/i)) {
				tmp = objects[i].id;
				cnt = tmp.split("_");
				obj = cnt[0] + "_canvas";
				if(canvas[obj]) {
					w = canvas[obj].getAttribute("width");
					h = canvas[obj].getAttribute("height");
					if(w>0&&h>0) {
						linecharts[l] = objects[i];
						em = linecharts[l].getAttribute("summary");
						if(em != "") em = "," + em;
						linecharts[l].setAttribute("summary", w + "," + h + em);
						++l;
					}
				}
			}
		}	
		objects = document.getElementsByTagName('object'); j = 0; i = 0;
		for (i=0; i < objects.length; i++) {
			if(objects[i].className.match(/^scale/i)) {
				medias[j] = objects[i]; ++j;
				if(!isIE) {
  					if(objects[i].getAttributeNode("classid")) objects[i].removeAttributeNode(objects[i].getAttributeNode("classid"));
				  	if(objects[i].getAttributeNode("codebase")) objects[i].removeAttributeNode(objects[i].getAttributeNode("codebase"));
				}
			}
		}
	}
}
function extendImgSizes(f) {
	if(empx>0) {
		var q = (f/empx); var w = 0; var h = 0;
		for(var i=0; i < images.length; i++) {
			w=images[i].getAttribute("width",0); 
			h=images[i].getAttribute("height",0);
			if(w>0&&h>0) {
				images[i].style.width=Math.floor(w*q)+"px";				images[i].style.height=Math.floor(h*q)+"px";
			}
		}
	}
}

function extendCanSizes(f) {
	if(empx>0 && canvasSupport) {
		var q = (f/empx); var w = 0; var h = 0; var tmp = ""; var cnt; var obj;
		for(var i=0; i < piecharts.length; i++) {
			if(piecharts[i].getAttribute("summary")) {
				tmp = piecharts[i].getAttribute("summary");
				cnt = tmp.split(",");
				if(cnt[0].match(/^[1-9][0-9]+/)) w = parseInt(cnt[0]);
				if(cnt[1].match(/^[1-9][0-9]+/)) h = parseInt(cnt[1]);
				if(w>0&&h>0) {
					tmp = piecharts[i].id;
					cnt = tmp.split("_");
					obj = cnt[0] + "_canvas";					
					canvas[obj].setAttribute("width",Math.floor(w*q)); 
					canvas[obj].setAttribute("height",Math.floor(h*q));
					canvas[obj].style.width=Math.floor(w*q)+"px";					canvas[obj].style.height=Math.floor(h*q)+"px";
				}
			}
		}
		for(var i=0; i < barcharts.length; i++) {
			if(barcharts[i].getAttribute("summary")) {
				tmp = barcharts[i].getAttribute("summary");
				cnt = tmp.split(",");
				if(cnt[0].match(/^[1-9][0-9]+/)) w = parseInt(cnt[0]);
				if(cnt[1].match(/^[1-9][0-9]+/)) h = parseInt(cnt[1]);
				if(w>0&&h>0) {
					tmp = barcharts[i].id;
					cnt = tmp.split("_");
					obj = cnt[0] + "_canvas";					
					canvas[obj].setAttribute("width",Math.floor(w*q)); 
					canvas[obj].setAttribute("height",Math.floor(h*q));
					canvas[obj].style.width=Math.floor(w*q)+"px";					canvas[obj].style.height=Math.floor(h*q)+"px";
				}
			}
		}
		for(var i=0; i < linecharts.length; i++) {
			if(linecharts[i].getAttribute("summary")) {
				tmp = linecharts[i].getAttribute("summary");
				cnt = tmp.split(",");
				if(cnt[0].match(/^[1-9][0-9]+/)) w = parseInt(cnt[0]);
				if(cnt[1].match(/^[1-9][0-9]+/)) h = parseInt(cnt[1]);
				if(w>0&&h>0) {
					tmp = linecharts[i].id;
					cnt = tmp.split("_");
					obj = cnt[0] + "_canvas";					
					canvas[obj].setAttribute("width",Math.floor(w*q)); 
					canvas[obj].setAttribute("height",Math.floor(h*q));
					canvas[obj].style.width=Math.floor(w*q)+"px";					canvas[obj].style.height=Math.floor(h*q)+"px";
				}
			}
		}
	}
}
function extendObjSizes(f) {
	if(empx>0) {
		var q = (f/empx); var w = 0; var h = 0;
		for(var i=0; i < medias.length; i++) {
			w=medias[i].getAttribute("width",0); 
			h=medias[i].getAttribute("height",0);
			if(w>0&&h>0) {
				medias[i].style.width=Math.floor(w*q)+"px";				medias[i].style.height=Math.floor(h*q)+"px";
			}
		}
	}
}
function findPosX(obj) {
	var posLeft = 0;
	while (obj.offsetParent) {
		posLeft += obj.offsetLeft;
		obj = obj.offsetParent;
	}
	return posLeft;
}
function findPosY(obj) {
	var posTop = 0;
	while (obj.offsetParent) {
		posTop += obj.offsetTop;
		obj = obj.offsetParent;
	}
	return posTop;
}
// scalable images extension

// canvas chart extension
function deg2rad(degrees) {
	return Math.PI *degrees/180;
}
function rad2deg(radians) {
	return 180.0 *radians/Math.PI;
}
function circle_point_x(radians, diameter) {
	var x = Math.cos(radians)*(diameter/2);
	return x;
}
function circle_point_y(radians, diameter) {
	var y = Math.sin(radians)*(diameter/2);
	return y;
}
function roundTo(val,dig) {
	var num = val;
	if (val > 8191 && val < 10485) {
		val = val-5000;
		num = Math.round(val*Math.pow(10,dig))/Math.pow(10,dig);
		num = num+5000;
	} else {
		num = Math.round(val*Math.pow(10,dig))/Math.pow(10,dig);
	}
	return num;
}
function searchColor(value) {
	for (var dat in colorNames) {
		if(dat==value) return colorNames[dat];
    }
    return false;
}
function scanColor(value) {
	if(value.match(/^#[0-9a-f][0-9a-f][0-9a-f]$/i)) {
		var val1 = value.substr(1,1).toLowerCase();
		var val2 = value.substr(2,1).toLowerCase();
		var val3 = value.substr(3,1).toLowerCase();
		value = '#' + val1 + val1 + val2 + val2 + val3 + val3;
	}
	if(!value.match(/^#[0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f]$/i)) {
		var tmp = searchColor(value.toLowerCase());
		if(!tmp) {}else{value = tmp;}
	}
	if(!value.match(/^#[0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f][0-9a-f]$/i)) {
		value = '#000000';
	}
	return value.toLowerCase();
}
function hex2rgb(val,trans) {
	if(val.length==7) {
		var tp1 = Math.max(0,Math.min(parseInt(val.substr(1,2),16),255));
		var tp2 = Math.max(0,Math.min(parseInt(val.substr(3,2),16),255));
		var tp3 = Math.max(0,Math.min(parseInt(val.substr(5,2),16),255));
		return 'rgba(' + tp1 + ',' + tp2 + ',' + tp3 + ',' + trans + ')';
	}
}
function trim(str) {
    return (str.replace(/\s+$/,"").replace(/^\s+/,""));
}
function roundedRect(ctx,x,y,width,height,radius){
	ctx.beginPath();
	ctx.moveTo(x,y+radius);
	ctx.lineTo(x,y+height-radius);
	ctx.quadraticCurveTo(x,y+height,x+radius,y+height);
	ctx.lineTo(x+width-radius,y+height);
	ctx.quadraticCurveTo(x+width,y+height,x+width,y+height-radius);
	ctx.lineTo(x+width,y+radius);
	ctx.quadraticCurveTo(x+width,y,x+width-radius,y);
	ctx.lineTo(x+radius,y);
	ctx.quadraticCurveTo(x,y,x,y+radius);
	ctx.closePath();
}
function drawString(ctx, text, fc, tx, ty) {
	var xp = 0; var c = "";
	ctx.beginPath();
	for (var i = 0; i < text.length; i++) {
		c = text[i];
		ctx.drawImage(font, signs[c].sx, signs[c].sy, signs[c].sw, signs[c].sh, tx+xp, ty, signs[c].sw*fc, signs[c].sh*fc);
		xp += (signs[c].sw*fc);
	}
	ctx.closePath();
}
function strokeString(ctx, txt, col, fh, tx, ty) {
	var fw = fh*0.666666; var lw = fh*0.125;  
	var ls = lw/2; var cr = lw; var xp = 0; 
	ctx.lineCap = "round"; ctx.lineJoin = "round"
	ctx.lineWidth = lw; ctx.strokeStyle = col;
	for (var i = 0; i < txt.length; i++) {
		strokeSymbol(ctx, txt[i], ls, tx+xp, ty, fw, fh);
		xp += (txt[i]!="."?fw+cr:(fw/2)+cr);
	}
}
function strokeSymbol(ctx, symbol, fc, cx, cy, cw, ch) {
	ctx.beginPath();
	switch (symbol) {
		case "0":
			ctx.moveTo(cx+fc,cy+(ch*0.333333));
			ctx.arc(cx+(cw/2),cy+(cw/2),(cw/2)-fc,deg2rad(180),0, false);
			ctx.arc(cx+(cw/2),(cy+ch)-(cw/2),(cw/2)-fc,0,deg2rad(180), false);
			ctx.closePath();
		break;
		case "1":
			ctx.moveTo(cx+(cw*0.1)+fc,cy+ch-fc);
			ctx.lineTo(cx+cw-fc,cy+ch-fc);
			ctx.moveTo(cx+(cw*0.666666),cy+ch-fc);
			ctx.lineTo(cx+(cw*0.666666),cy+fc);
			ctx.lineTo(cx+(cw*0.25),cy+(ch*0.25));
		break;
		case "2":
			ctx.moveTo(cx+cw-fc,cy+(ch*0.8));
			ctx.lineTo(cx+cw-fc,cy+ch-fc);
			ctx.lineTo(cx+fc,cy+ch-fc);
			ctx.arc(cx+(cw/2),cy+(cw*0.425),(cw*0.425)-fc,deg2rad(45),deg2rad(-180), true);
		break;
		case "3":
			ctx.moveTo(cx+(cw*0.1)+fc,cy+fc);
			ctx.lineTo(cx+(cw*0.9)-fc,cy+fc);
			ctx.arc(cx+(cw/2),cy+ch-(cw*0.5),(cw*0.5)-fc,deg2rad(-90),deg2rad(180), false);
		break;
		case "4":
			ctx.moveTo(cx+(cw*0.75),cy+ch-fc);
			ctx.lineTo(cx+(cw*0.75),cy+fc);
			ctx.moveTo(cx+cw-fc,cy+(ch*0.666666));
			ctx.lineTo(cx+fc,cy+(ch*0.666666));
			ctx.lineTo(cx+(cw*0.75),cy+fc);
			ctx.moveTo(cx+cw-fc,cy+ch-fc);
			ctx.lineTo(cx+(cw*0.5),cy+ch-fc);
		break;
		case "5":
			ctx.moveTo(cx+(cw*0.9)-fc,cy+fc);
			ctx.lineTo(cx+(cw*0.1)+fc,cy+fc);
			ctx.lineTo(cx+(cw*0.1)+fc,cy+(ch*0.333333));
			ctx.arc(cx+(cw/2),cy+ch-(cw*0.5),(cw*0.5)-fc,deg2rad(-80),deg2rad(180), false);
		break;
		case "6":
			ctx.moveTo(cx+fc,cy+ch-(cw*0.5)-fc);
			ctx.arc(cx+(cw/2),cy+ch-(cw*0.5),(cw*0.5)-fc,deg2rad(-180),deg2rad(180), false);
			ctx.bezierCurveTo(cx+fc,cy+fc,cx+fc,cy+fc,cx+(cw*0.9)-fc,cy+fc);
			ctx.moveTo(cx+(cw*0.9)-fc,cy+fc);
		break;
		case "7":
			ctx.moveTo(cx+(cw*0.5),cy+ch-fc);
			ctx.lineTo(cx+cw-fc,cy+fc);
			ctx.lineTo(cx+(cw*0.1)+fc,cy+fc);
			ctx.lineTo(cx+(cw*0.1)+fc,cy+(ch*0.25)-fc);
		break;
		case "8":
			ctx.moveTo(cx+(cw*0.92)-fc,cy+(cw*0.59));
			ctx.arc(cx+(cw/2),cy+(cw*0.45),(cw*0.45)-fc,deg2rad(25),deg2rad(-205), true);
			ctx.arc(cx+(cw/2),cy+ch-(cw*0.5),(cw*0.5)-fc,deg2rad(-135),deg2rad(-45), true);
			ctx.closePath();
			ctx.moveTo(cx+(cw*0.79),cy+(ch*0.47));
			ctx.lineTo(cx+(cw*0.21),cy+(ch*0.47));
		break;
		case "9":
			ctx.moveTo(cx+cw-fc,cy+(cw*0.5));
			ctx.arc(cx+(cw/2),cy+(cw*0.5),(cw*0.5)-fc,deg2rad(0),deg2rad(360), false);
			ctx.bezierCurveTo(cx+cw-fc,cy+ch-fc,cx+cw-fc,cy+ch-fc,cx+(cw*0.1)+fc,cy+ch-fc);
		break;
		case "%":
			ctx.moveTo(cx+fc,cy+(ch*0.75));
			ctx.lineTo(cx+cw-fc,cy+(ch*0.25));
			ctx.moveTo(cx+(cw*0.505),cy+(cw*0.3));
			ctx.arc(cx+(cw*0.3),cy+(cw*0.3),(cw*0.3)-fc,deg2rad(0),deg2rad(360), false);
			ctx.moveTo(cx+(cw*0.905),cy+ch-(cw*0.3));
			ctx.arc(cx+(cw*0.7),cy+ch-(cw*0.3),(cw*0.3)-fc,deg2rad(0),deg2rad(360), false);
		break;
		case ".":
			ctx.moveTo(cx+(cw*0.25),cy+ch-fc-fc);
			ctx.arc(cx+(cw*0.25),cy+ch-fc-fc,fc,deg2rad(0),deg2rad(360), false);
			ctx.closePath();
		break;
		default:
		break;
	}	
	ctx.stroke();
}
function drawBar(ctx,x,y,width,height,color,value,textdiv){
	var rw = width/2; var rh = rw/2;
	height = Math.max(height,rw);
	var dh = Math.max(height-(2*rh),0.1); var S2L;	
	var xx = rw/8; var yy = rh/4; 
	var yo = rh/2; y = y - yy;	
	if(canvas_noshadow <= 0 && canvas_noshade <= 0) {
		ctx.save();
		S2L = ctx.createRadialGradient(x+rw+rh,y+height-rw+yy+rh,0,x+rw,y+height-rw+yy,rw);
		S2L.addColorStop(0, 'rgba(0,0,0,0.5)');
		S2L.addColorStop(0.7, 'rgba(0,0,0,0.25)');	
		S2L.addColorStop(0.9, 'rgba(0,0,0,0.1)');	
		S2L.addColorStop(1, 'rgba(0,0,0,0)');	
		ctx.fillStyle = S2L;
		ctx.scale(1,0.5);
		ctx.translate(xx,y+height+yy);
		if(isOp){
			ctx.fillRect(x,y+yy+height-width,width,width);
		}else {
	  		ctx.arc(x+rw,y+yy+height-width,width,0,deg2rad(360), false);
			ctx.fill();	
		}
		ctx.restore();
	}else if(canvas_noshadow <= 0 && canvas_noshade >= 1) {
  		ctx.fillStyle = 'rgba(0,0,0,0.2)';
		ctx.fillRect(x+yo,y+rh+yo+yo,width,dh);
	}

	if(canvas_noshade <= 0) {
		ctx.beginPath();
	  	ctx.moveTo(x,y+rh);
		ctx.lineTo(x,y+rh+dh);
		ctx.bezierCurveTo(x,y+height,x+width,y+height,x+width,y+rh+dh)
		ctx.lineTo(x+width,y+rh);
		ctx.bezierCurveTo(x+width,y,x,y,x,y+rh)
		ctx.closePath();
		ctx.fillStyle = color;
		ctx.fill();
		S2L = ctx.createLinearGradient(x,y+(height/2),x+width,y+(height/2));
		S2L.addColorStop(0, 'rgba(255,255,255,0.75)');
		S2L.addColorStop(0.2, 'rgba(255,255,255,0)');
		S2L.addColorStop(0.3, 'rgba(0,0,0,0)');
		S2L.addColorStop(0.5, 'rgba(0,0,0,0.1)');
		S2L.addColorStop(0.9, 'rgba(0,0,0,0.35)');
		S2L.addColorStop(1, 'rgba(0,0,0,0.3)');
		ctx.beginPath();
	  	ctx.moveTo(x,y+rh);
		ctx.lineTo(x,y+rh+dh);
		ctx.bezierCurveTo(x,y+height,x+width,y+height,x+width,y+rh+dh)
		ctx.lineTo(x+width,y+rh);
		ctx.bezierCurveTo(x+width,y,x,y,x,y+rh)
		ctx.closePath();
		ctx.fillStyle = S2L;
		ctx.fill();
		ctx.beginPath();
		ctx.moveTo(x+width,y+rh);
		ctx.bezierCurveTo(x+width,y,x,y,x,y+rh)
		ctx.bezierCurveTo(x,y+(rh*2),x+width,y+(rh*2),x+width,y+rh)
		ctx.closePath();
		ctx.fillStyle = color;
		ctx.fill();
		S2L = ctx.createLinearGradient(x+rw-(width*0.15),y-2,x+rw+(width*0.15),y+(2.1*rh));
		S2L.addColorStop(0, 'rgba(255,255,255,0.9)');
		S2L.addColorStop(0.5, 'rgba(255,255,255,0)');
		S2L.addColorStop(0.6, 'rgba(0,0,0,0)');
		S2L.addColorStop(1, 'rgba(0,0,0,0.3)');
		ctx.beginPath();
		ctx.moveTo(x+width,y+rh);
		ctx.bezierCurveTo(x+width,y,x,y,x,y+rh)
		ctx.bezierCurveTo(x,y+(rh*2),x+width,y+(rh*2),x+width,y+rh)
		ctx.closePath();
		ctx.fillStyle = S2L;
		ctx.fill();	
		S2L = ctx.createLinearGradient(x+rw-(width*0.15),y-2,x+rw+(width*0.15),y+(2.1*rh));
		S2L.addColorStop(0, 'rgba(255,255,255,0.9)');
		S2L.addColorStop(0.5, 'rgba(255,255,255,0)');
		S2L.addColorStop(0.6, 'rgba(0,0,0,0)');
		S2L.addColorStop(1, 'rgba(0,0,0,0.1)');	
		ctx.beginPath();
		ctx.moveTo(x+width,y+rh);
		ctx.bezierCurveTo(x+width,y,x,y,x,y+rh)
		ctx.bezierCurveTo(x,y+(rh*2),x+width,y+(rh*2),x+width,y+rh)
		ctx.closePath();
		ctx.strokeStyle = S2L;
		ctx.stroke();
	}else {
  		ctx.fillStyle = color;
		ctx.fillRect(x,y+rh+yo,width,dh);
	}
	ctx.lineCap = "butt";
	ctx.lineWidth = 1;
	ctx.fillStyle = 'rgba(255,255,255,0.5)';
	var bw = width; var bh = bw/4; 
	var th = roundTo(bh*0.75,0); var tf = bh/80; 
	var c; var w; 
	if(canvas_notext <= 0) {
		if(canvas_htmltext <= 0) {
			w = '"' + per + '"';
			if(w.indexOf(".")!=-1) {
				c = w.length+0.5;
				w = parseFloat(c-2)*parseFloat(48*tf);
				bw = parseFloat(c-1)*parseFloat(48*tf);
			}else {
				c = w.length;
				w = parseFloat(c-1)*parseFloat(48*tf);
				bw = parseFloat(c)*parseFloat(48*tf);
			}
			roundedRect(ctx,x+(width/2)-(bw/2),y,bw,bh,bh/4);
			ctx.fill();
			if(canvas_imgtext <= 0) {
				strokeString(ctx, value + "%","rgba(48,48,48,1)", th, x+(width/2)-(w/2), y+((bh-th)/2));
			}else {
				drawString(ctx, value + "%", tf, x+(width/2)-(w/2), y+((bh-th)/2.2));
			}
		}else {
			var bh = bw/3; var th = roundTo(bh*0.75,0); 
			roundedRect(ctx,x,y,bw,bh,bh/4);
			ctx.fill();
			var obj = document.createElement('div');
			obj.style.position = "absolute";
			obj.style.overflow = "hidden";
            obj.style.textAlign = "center";
			obj.style.width = bw + "px";
			obj.style.left = x + "px";
			obj.style.top = y+((bh-th)/2.2) + "px";
			obj.appendChild(document.createTextNode(per + "%"));			
			textdiv.appendChild(obj);
		}

	}	
}
function drawLine(ctx,x,y,width,height,dist,array,factor,color,fill){
	if(fill <= 0){
		var style = hex2rgb(color,0.5);
		ctx.lineJoin = "miter";
		ctx.beginPath();
	  	ctx.moveTo(x,y+height);
		for (var i = 0; i < array.length; i++) {
			ctx.lineTo(x+(i*dist),y+height-(array[i]*factor));
		}
		ctx.lineTo(x+width,y+height);
		ctx.lineTo(x,y+height);
		ctx.closePath();
		ctx.fillStyle = style;
		ctx.fill();
	}
	ctx.lineJoin = "round";
	ctx.beginPath();
  	ctx.moveTo(x,y+height-(array[0]*factor));
	for (var i = 0; i < array.length; i++) {
		ctx.lineTo(x+(i*dist),y+height-(array[i]*factor));
	}
	ctx.strokeStyle = color;
	ctx.stroke();
}
function setDataURL(cid) {
	if(cid.toDataURL) {
		var obj = document.getElementById(cid.id + "_link");
		if(obj) {
			obj.setAttribute("title", "To Data URL");
			obj.setAttribute("target", "_blank");
			obj.setAttribute("href", cid.toDataURL());
		}
	}
}
function get_input(dataobj,canvasobj,linechart) {
	var table = document.getElementById(dataobj);
	var canvas = document.getElementById(canvasobj);
	var row; var clm; var cnt = 0; var val = 0; var nme = ""; var col = "";  
	if(canvas.getContext) {
		canvas_width = parseInt(canvas.style.width);
		canvas_height = parseInt(canvas.style.height);
		if(canvas_width >= 16 && canvas_height >= 16) {
			var tmp = table.getAttribute("summary");
			canvas_noshade = 0; canvas_noshadow = 0; 
			canvas_notext = 0; canvas_imgtext = 0;
			canvas_htmltext = 0; canvas_nofill = 0;
			if(tmp.search(/noshadow/) != -1) canvas_noshadow = 1;
			if(tmp.search(/noshade/) != -1) canvas_noshade = 1;
			if(tmp.search(/nofill/) != -1) canvas_nofill = 1;
			if(tmp.search(/notext/) != -1) canvas_notext = 1;
			if(tmp.search(/htmltext/) != -1) canvas_htmltext = 1;
			if(tmp.search(/imgtext/) != -1) canvas_imgtext = 1;
			if(table.getAttribute("bgcolor")) {
				canvas_bgcolor = scanColor(table.getAttribute("bgcolor"));
			}
			ChartData = new Array(); colorSlice = new Array();
			if(table.getElementsByTagName("tr")[0].getElementsByTagName("th")[0]) cnt = 1;
			for(var r = cnt; r < table.getElementsByTagName("tr").length; r++) {
				row = table.getElementsByTagName("tr")[r];
				clm = row.getElementsByTagName("td").length;
				if(row.getElementsByTagName("td")[0].getAttribute("bgcolor")) {	
					col = scanColor(row.getElementsByTagName("td")[0].getAttribute("bgcolor")); val = 0;
					nme = trim(row.getElementsByTagName("td")[1].innerHTML.replace(/<[^>]+>/g,""));
					if(!linechart) {
						if(clm > 3) {
							for(var z = 2; z < clm; z++) {
								val += parseFloat(row.getElementsByTagName("td")[z].innerHTML.replace(/<[^>]+>/g,""));
							}
						}else {
							val = parseFloat(row.getElementsByTagName("td")[2].innerHTML.replace(/<[^>]+>/g,""));
						}
						if(!isNaN(val) && val > 0 && nme != '') {
							colorSlice[r-cnt] = col; ChartData[nme] = Math.abs(val);
						}else {
							break;
						}
					}else {
						val = 0; i = 0;
						if(clm > 3 && nme != '') {
							ChartData[r-cnt] = new Array();
							colorSlice[r-cnt] = col;
							for(var z = 2; z < clm; z++) {
								val = Math.abs(parseFloat(row.getElementsByTagName("td")[z].innerHTML.replace(/<[^>]+>/g,"")));
								if(!isNaN(val) && val >= 0) {
									ChartData[r-cnt][i] = val; i++;
								}else {
									ChartData[r-cnt][i] = 0; i++;
								}							 
							}	
						}else {
							break;
						}			
					}			
				}else {
					break;
				}
			}
		}	
	}
}
function setPieChart(canvasobj,textobj) {
	var cd = (Math.min(canvas_width,canvas_height)/110)*100;
	var cp = cd*0.1; var cr = cd/2;
	var sr = cr*0.93; var cw = cd+cp; var ch = cw;
	var cx = (cd/2)+(cp/2); var cy = cx; var ct = 0;
	for (var data in ChartData) {
		ct += ChartData[data];
	} 
	var poc = ct/100;
	var canvas = document.getElementById(canvasobj);
	if(canvas_htmltext >= 1) {
		if(document.getElementById(textobj)) {
	  		canvas.parentNode.removeChild(canvas.parentNode.lastChild);		
		}
	}	
	if(canvas.getContext) {
		var ctx = canvas.getContext('2d');
		if(canvas_bgcolor != "") {
  			ctx.fillStyle = canvas_bgcolor;
			ctx.fillRect(0,0,cw,ch);
		}else {
			ctx.clearRect(0,0,cw,ch);
		}
		if(canvas_noshadow <= 0) {
			if(!isOp) { 
				ctx.beginPath();
				var B2B = ctx.createRadialGradient(cx+(cr*0.1),cy+(cr*0.1),cr,cx+(cr*0.1),cy+(cr*0.1),sr*0.9);
				B2B.addColorStop(0, 'rgba(0,0,0,0)');
				B2B.addColorStop(1, 'rgba(0,0,0,0.5)');
				ctx.arc(cx+(cr*0.1),cy+(cr*0.1),cr,0,deg2rad(360), false);
				ctx.closePath();
	   			ctx.fillStyle = B2B;
				ctx.fill();
			}else {
				var B2B = ctx.createRadialGradient(cx+(cr*0.1),cy+(cr*0.1),0,cx+(cr*0.1),cy+(cr*0.1),cr);
				B2B.addColorStop(0, 'rgba(0,0,0,0.5)');
				B2B.addColorStop(0.87, 'rgba(0,0,0,0.5)');
				B2B.addColorStop(1, 'rgba(0,0,0,0)');
				ctx.fillStyle = B2B;
				ctx.fillRect(0,0,cw,ch);
			}
		}		
		var val = 0; var deg = 0; var idx = 0; var data;
		for (data in ChartData) {
			val = ChartData[data]; sdeg = deg;
			deg += (val/ct)*deg2rad(360); edeg = deg;
			ctx.beginPath();
  			ctx.moveTo(cx,cy);
			ctx.arc(cx,cy,cr,sdeg,edeg, false);
			ctx.lineTo(cx,cy);
			ctx.closePath();
  			ctx.fillStyle = colorSlice[(idx++)];
			ctx.fill();
		} 
		if(canvas_noshade <= 0) {
			ctx.beginPath();
			var W2T = ctx.createLinearGradient(cp*2,cp*2,cx,cy);
			W2T.addColorStop(0, 'rgba(255,255,255,0.8)');
			W2T.addColorStop(1, 'rgba(255,255,255,0)');
			ctx.moveTo(cx,cy);
			ctx.arc(cx,cy,sr,deg2rad(135),deg2rad(315), false);
			ctx.closePath();
			ctx.fillStyle = W2T;
			ctx.fill();
			ctx.beginPath();
			var T2B = ctx.createLinearGradient(cx,cy,cw-(cp*2),ch-(cp*2));
			T2B.addColorStop(0, 'rgba(0,0,0,0)');
			T2B.addColorStop(1, 'rgba(0,0,0,0.5)');
			ctx.moveTo(cx,cy);
			ctx.arc(cx,cy,sr,deg2rad(-45),deg2rad(135), false);
			ctx.closePath();
			ctx.fillStyle = T2B;
			ctx.fill();
			ctx.beginPath();
			var B2T = ctx.createLinearGradient(cx,cy,cw-(cp*1.9),ch-(cp*1.9));
			B2T.addColorStop(0, 'rgba(0,0,0,0)');
			B2T.addColorStop(1, 'rgba(0,0,0,0.6)');
			ctx.lineWidth = cr*0.07;
			ctx.lineCap = "round";
			ctx.moveTo(cx,cy);
			ctx.arc(cx,cy,cr*0.965,deg2rad(-45),deg2rad(135), false);
			ctx.closePath();
			ctx.strokeStyle = B2T;
			ctx.stroke();
			ctx.beginPath();
			var T2W = ctx.createLinearGradient(cx,cy,(cp*1.9),(cp*1.9));
			T2W.addColorStop(0, 'rgba(255,255,255,0)');
			T2W.addColorStop(1, 'rgba(255,255,255,0.6)');
			ctx.lineWidth = cr*0.07;
			ctx.lineCap = "round";
			ctx.moveTo(cx,cy);
			ctx.arc(cx,cy,cr*0.965,deg2rad(135),deg2rad(315), false);
			ctx.closePath();
			ctx.strokeStyle = T2W;
			ctx.stroke();	
		} 				 			
		ctx.lineCap = "butt";
		ctx.lineWidth = 1;
		ctx.fillStyle = 'rgba(255,255,255,0.5)';
		var mpos = 0; var per = 0; var gx = 0; 
		var gy = 0; var tx = 0; var ty = 0; 
		var obj = ""; var w = 0; var c = 0;
		var bw = cr*0.45; var bh = cr*0.125; 
		var th = roundTo(bh*0.75,0); var tf = bh/80; 
		if(canvas_notext <= 0) {
			if(canvas_htmltext >= 1) {
				bw = (cr*0.365);
				canvas.parentNode.style.position = "relative";
				if(!document.getElementById(textobj)) {
					obj = document.createElement('div');
					obj.id = textobj;
		            obj.style.color = "rgb(0,0,0)";
		            obj.style.fontFamily = "Arial,sans-serif";
					obj.style.fontSize = th + "px";
					obj.style.zIndex = 11;
					canvas.parentNode.appendChild(obj);
				}
				var textdiv = document.getElementById(obj.id);
			}
			for (data in ChartData) {			
				val = ChartData[data];
				sdeg = deg; mpos = deg+(((val/2)/ct)*deg2rad(360));
				deg += (val/ct)*deg2rad(360); edeg = deg;
				per = roundTo(val/poc,2);
				gx = circle_point_x(mpos, cd);
				gy = circle_point_y(mpos, cd);
				tx = parseFloat((cx+(2*Math.floor(cx + gx)))/3);
				ty = (cy+(2*Math.floor(cy + gy)))/3;
				if(canvas_htmltext <= 0) {
					w = '"' + per + '"';
					if(w.indexOf(".")!=-1) {
						c = w.length+0.5;
						w = parseFloat(c-2)*parseFloat(48*tf);
						bw = parseFloat(c-1)*parseFloat(48*tf);
					}else {
						c = w.length;
						w = parseFloat(c-1)*parseFloat(48*tf);
						bw = parseFloat(c)*parseFloat(48*tf);
					}
					roundedRect(ctx,(tx-(bw/2)),ty-(bh/2),bw,bh,bh/4);
					ctx.fill();
					if(canvas_imgtext >= 1) {
						drawString(ctx, per + "%", tf, tx-(w/2), ty-(th/1.8));
					}else {
						strokeString(ctx, per + "%","rgba(48,48,48,1)", th, tx-(w/2), ty-(th/2));
					}
				}else {
					roundedRect(ctx,(tx-(bw/2)),ty-(bh/2),bw,bh,bh/4);
					ctx.fill();
					obj = document.createElement('div');
					obj.style.position = "absolute";
					obj.style.overflow = "hidden";
		            obj.style.textAlign = "center";
					obj.style.width = bw + "px";
					obj.style.left = (tx-(bw/2)) + "px";
					obj.style.top = ty-(th/1.8) + "px";
					obj.appendChild(document.createTextNode(per + "%"));			
					textdiv.appendChild(obj);
				}
			}
		}
	}
}
function setBarChart(canvasobj,textobj) {
	var iw = canvas_width*0.9; var ih = canvas_height*0.9;
	var pw = canvas_width*0.05; var ph = canvas_height*0.05; 
	var cm = 0; var ct = 0;
	for (var data in ChartData) {
		cm = Math.max(cm,ChartData[data]);
		ct += ChartData[data];
	} 
	var hf = ih/cm; var bs = colorSlice.length; 
	var bw = iw/(bs*1.1); var poc = ct/100;
	var th = roundTo((bw/3)*0.75,0);
	var canvas = document.getElementById(canvasobj);
	if(canvas.getContext) {
		var ctx = canvas.getContext('2d');
		if(canvas_bgcolor != "") {
  			ctx.fillStyle = canvas_bgcolor;
			ctx.fillRect(0,0,canvas_width,canvas_height);
		}else {
			ctx.clearRect(0,0,canvas_width,canvas_height);
		}
		if(canvas_htmltext >= 1) {
			if(document.getElementById(textobj)) {
	  			canvas.parentNode.removeChild(canvas.parentNode.lastChild);		
			}
			canvas.parentNode.style.position = "relative";
			if(!document.getElementById(textobj)) {
				var obj = document.createElement('div');
				obj.id = textobj;
	            obj.style.color = "rgb(0,0,0)";
	            obj.style.fontFamily = "Arial,sans-serif";
				obj.style.fontSize = th + "px";
				obj.style.zIndex = 11;
				canvas.parentNode.appendChild(obj);
			}
			var textdiv = document.getElementById(obj.id);
		}		
		var cc = ""; var bh = 0; var idx = 0; var t = 0; per = 0;
		for (var data in ChartData) {
			per = roundTo(ChartData[data]/poc,2);
			bh = ChartData[data]*hf; 
			drawBar(ctx,pw+(t*(bw*1.1)),ph+ih-bh,bw,bh,colorSlice[(idx++)],per,textdiv); 
			t++;
		} 		
	}
}
function setLineChart(canvasobj,textobj) {
	var iw = canvas_width*0.9;
	var ih = canvas_height*0.9;
	var pw = canvas_width*0.05;
	var ph = canvas_height*0.05;
	var cm = 0;
	for (var i = 0; i < ChartData.length; i++) {
		for (var j = 0; j < ChartData[i].length; j++) {
			cm = Math.max(cm,ChartData[i][j]);
		}
	} 
	var hf = (ih*0.95)/cm; var bw = iw;
	var dw = iw/(ChartData[0].length-1)
	var dh = ih/(ChartData[0].length-1)
	var ps = Math.min(pw,ph); lw = ps/4;
	var B2T;
	var canvas = document.getElementById(canvasobj);
	if(canvas.getContext) {
		var ctx = canvas.getContext('2d');
		if(canvas_bgcolor != "") {
  			ctx.fillStyle = canvas_bgcolor;
			ctx.fillRect(0,0,canvas_width,canvas_height);
		}else {
			ctx.clearRect(0,0,canvas_width,canvas_height);
		}
		if(canvas_noshadow <= 0) {
			B2T = ctx.createLinearGradient(pw+ps,ph+ih+1,pw+ps+ps,ph+ih+1);
			B2T.addColorStop(0, 'rgba(0,0,0,0.0)');
			B2T.addColorStop(1, 'rgba(0,0,0,0.5)');
	  		ctx.fillStyle = B2T;
			ctx.beginPath();
	  		ctx.moveTo(pw+ps,ph+ih);
			ctx.lineTo(pw+ps,ph+ih+ps);	
			ctx.lineTo(pw+ps+ps,ph+ih);
			ctx.closePath();			
			ctx.fill();
			B2T = ctx.createLinearGradient(pw+ps+ps,ph+ih,pw+ps+ps,ph+ih+ps);
			B2T.addColorStop(0, 'rgba(0,0,0,0.5)');
			B2T.addColorStop(1, 'rgba(0,0,0,0.0)');
	  		ctx.fillStyle = B2T;
			ctx.beginPath();
	  		ctx.moveTo(pw+ps+ps,ph+ih);
			ctx.lineTo(pw+iw,ph+ih);	
			ctx.lineTo(pw+ps+iw,ph+ih+ps);
			ctx.lineTo(pw+ps,ph+ih+ps);		
			ctx.closePath();			
			ctx.fill();
			var B2T = ctx.createLinearGradient(pw+iw+1,ph+ps,pw+iw+1,ph+ps+ps);
			B2T.addColorStop(0, 'rgba(0,0,0,0.0)');
			B2T.addColorStop(1, 'rgba(0,0,0,0.35)');
	  		ctx.fillStyle = B2T;
			ctx.beginPath();
	  		ctx.moveTo(pw+iw,ph+ps);
			ctx.lineTo(pw+iw,ph+ps+ps);	
			ctx.lineTo(pw+iw+ps,ph+ps);
			ctx.closePath();			
			ctx.fill();
			B2T = ctx.createLinearGradient(pw+iw,ph+ps+ps,pw+iw+ps,ph+ps+ps);
			B2T.addColorStop(0, 'rgba(0,0,0,0.35)');
			B2T.addColorStop(1, 'rgba(0,0,0,0.0)');
	  		ctx.fillStyle = B2T;
			ctx.beginPath();
	  		ctx.moveTo(pw+iw,ph+ps+ps);
			ctx.lineTo(pw+iw,ph+ih);	
			ctx.lineTo(pw+iw+ps,ph+ih+ps);
			ctx.lineTo(pw+iw+ps,ph+ps);		
			ctx.closePath();			
			ctx.fill();
		}	
		ctx.lineCap = "butt";
		ctx.lineWidth = lw/2;
		ctx.strokeStyle = "rgba(255,255,255,0.25)";
		if(canvas_nofill <= 0) {
  			ctx.fillStyle = "rgba(240,240,240,0.8)";
			ctx.strokeStyle = "rgba(255,255,255,1)";
			ctx.fillRect(pw,ph,iw,ih);
		}
		for (var i = 0; i < ChartData[0].length-1; i++) {
		  	ctx.beginPath();
  			ctx.moveTo(pw+(i*dw),ph);
			ctx.lineTo(pw+(i*dw),ph+ih);
			ctx.stroke();
		}
		for (var i = 1; i < ChartData[0].length; i++) {
		  	ctx.beginPath();
  			ctx.moveTo(pw,ph+(i*dh));
			ctx.lineTo(pw+iw,ph+(i*dh));
			ctx.stroke();
		}			
		ctx.lineWidth = lw;
		var cc = ""; var bh = 0; var idx = 0; var t = 0;
		for (var i = 0; i < ChartData.length; i++) {
			for (var j = 0; j < ChartData[i].length; j++) {
				t = Math.max(t,ChartData[i][j]);
			}
			bh = t*hf; cc = colorSlice[(idx++)];
			drawLine(ctx,pw,ph+ih-bh,bw,bh,dw,ChartData[i],hf,cc,canvas_nofill);
		}
  		ctx.beginPath();
  		ctx.moveTo(pw,ph);
		ctx.lineTo(pw,ph+ih);
		ctx.lineTo(pw+iw+(lw/2),ph+ih);
		ctx.strokeStyle = "rgba(48,48,48,1)";
		ctx.stroke();
		ctx.lineWidth = lw/2;
		B2T = ctx.createLinearGradient(pw,ph+ih,pw,ph+ih+ps);
		B2T.addColorStop(0, 'rgba(0,0,0,1)');
		B2T.addColorStop(0.5, 'rgba(0,0,0,1)');
		B2T.addColorStop(1, 'rgba(0,0,0,0)');
  		ctx.strokeStyle = B2T;
		for (var i = 0; i < ChartData[0].length; i++) {
  			ctx.beginPath();
  			ctx.moveTo(pw+(i*dw),ph+ih);
			ctx.lineTo(pw+(i*dw),ph+ih+ps);
			ctx.stroke();
		}
		B2T = ctx.createLinearGradient(pw-ps,ph,pw,ph);
		B2T.addColorStop(0, 'rgba(0,0,0,0)');
		B2T.addColorStop(0.5, 'rgba(0,0,0,1)');
		B2T.addColorStop(1, 'rgba(0,0,0,1)');
  		ctx.strokeStyle = B2T;
  		for (var i = 1; i < ChartData[0].length; i++) {
  			ctx.beginPath();
  			ctx.moveTo(pw-ps,ph+(i*dh));
			ctx.lineTo(pw,ph+(i*dh));
			ctx.stroke();
		}			
	}
}
function generateCanvas() {
	if(canvasSupport) {
		var canvasID; var tdataID; var textID; 
		var tmp; var dat; var i; var j;
		for(i=0; i < piecharts.length; i++) {
			tmp = piecharts[i].id.split("_");
			tdataID = piecharts[i].id;
			canvasID = tmp[0] + "_canvas";
			textID = tmp[0] + "_text";
			if(document.getElementById(tdataID)) {
				get_input(tdataID,canvasID);
				if(colorSlice.length > 0) {
					j = 0; dat = ""; for(dat in ChartData) {j++; }
					if(j > 0 && j == colorSlice.length) {
						setPieChart(canvasID,textID);
					}
				}
			}
		}
		for(i=0; i < barcharts.length; i++) {
			tmp = barcharts[i].id.split("_");
			tdataID = barcharts[i].id;
			canvasID = tmp[0] + "_canvas";
			textID = tmp[0] + "_text";
			if(document.getElementById(tdataID)) {
				get_input(tdataID,canvasID);
				if(colorSlice.length > 0) {
					j = 0; dat = ""; for(dat in ChartData) {j++; }
					if(j > 0 && j == colorSlice.length) {
						setBarChart(canvasID,textID);
					}
				}
			}
		}
		for(i=0; i < linecharts.length; i++) {
			tmp = linecharts[i].id.split("_");
			tdataID = linecharts[i].id;
			canvasID = tmp[0] + "_canvas";
			textID = tmp[0] + "_text";
			if(document.getElementById(tdataID)) {
				get_input(tdataID,canvasID,true);
				if(colorSlice.length > 0) {
					if(ChartData.length == colorSlice.length) {
						setLineChart(canvasID,textID);
					}
				}
			}
		}
	}
}
// canvas chart extension

// invisible select extension
function setListPos(opt) {
	if(!isIE) { //(degrade IE)
		var ref = document.getElementById('list');
		var x = findPosX(ref); var y = findPosY(ref);
		var obj = document.getElementById('jumplist');
		obj.style.position = 'fixed'; obj.style.left = x + 'px'; obj.style.top = y + 'px';	
		var vol = document.getElementById('volumelist');
		ref = document.getElementById('volume');
		x = findPosX(ref); y = findPosY(ref);
		vol.style.position = 'fixed'; vol.style.left = x + 'px'; vol.style.top = y + 'px';	
		var pnl = document.getElementById('navLinks');
	}
	if(opt) {
		if (isIE) {
			//(degrade IE)
			//obj.style.filter = "alpha(opacity=0)";
			//vol.style.filter = "alpha(opacity=0)";
			//pnl.style.filter = "alpha(opacity=90)";	
		}else {
			obj.style.opacity = 0.0;
			vol.style.opacity = 0.0;
			pnl.style.opacity = 0.9;
		}
		if(!isOp && !isIE) {
			vol.onmouseover = function () { document.getElementById('volume').style.color="rgb(255, 0, 0)"; return false; }
			vol.onmouseout  = function () { document.getElementById('volume').style.color=""; return false; }
			obj.onmouseover = function () { document.getElementById('list').style.color="rgb(255, 0, 0)"; return false; }
			obj.onmouseout  = function () { document.getElementById('list').style.color=""; return false; }
		}
	}
}
// invisible select extension

// transition extension
function switchFade() {
	if(tranSitions && s5mode && fadeModus) {
		fadeModus = false; 
		playDelay = playDelay-(2*fadeDuration);
		document.getElementById('fade').style.color="";
	}else if(tranSitions && s5mode && !fadeModus) {
		fadeModus = true; 
		playDelay = playDelay+(2*fadeDuration);
		document.getElementById('fade').style.color=highLight;
	}
	currentSlide();
}
function opacity(ids, opacStart, opacEnd, millisec) {	var speed = Math.round(millisec / 100);	var timer = 0;	if(opacStart > opacEnd) {		for(var i = opacStart; i >= opacEnd; i--) {			window.setTimeout("changeOpac(" + i + ",'" + ids + "')",(timer * speed));			timer++;		}	} else if(opacStart < opacEnd) {		for(var i = opacStart; i <= opacEnd; i++) {			window.setTimeout("changeOpac(" + i + ",'" + ids + "')",(timer * speed));			timer++;		}	}
}function changeOpac(opacity, ids) {	var obj = document.getElementById(ids); 
	if (isIE) {
		obj.style.filter = "alpha(opacity=" + opacity + ")";	} else {		obj.style.opacity = (opacity / 100);	}}function shiftOpacity(ids, millisec) {	if(document.getElementById(ids).style.opacity != '') {		var currentOpac = document.getElementById(ids).style.opacity * 100;
	} else {
		var currentOpac = 0;
	}
	if(currentOpac == 0) {
		opacity(ids, currentOpac, 100, millisec);	} else if(currentOpac > 0) {
		opacity(ids, currentOpac, 0, millisec);	}}
// transition extension

// autoplay extension
function autoPlay() {
	if (s5mode && autoMatic && !playPause) {
		if ((snum >= (smax-1)) && playLoop) {
			goTo(0);
			autoRun = setTimeout('autoPlay();',playDelay);
		}else if ((snum >= (smax-1)) && !playLoop) {
			stopPlay();
		}else {
			if (!incrementals[snum] || incpos >= incrementals[snum].length) {
				go(1);
				if (incrementals[snum].length >0) {
					clearTimeout(autoRun); autoRun = null;
					incrDelay = parseInt(playDelay/(incrementals[snum].length+1));
					remainDer = parseInt(playDelay-(incrDelay*incrementals[snum].length));
					autoRun = setTimeout('autoPlayIncr()',incrDelay);
				}
			} else {
				clearTimeout(autoRun); autoRun = null;
				incrDelay = incrDuration;
				remainDer = parseInt(playDelay-(incrementals[snum].length*incrDuration));
				autoRun = setTimeout('autoPlayIncr()',incrDelay);
			}
			autoRun = setTimeout('autoPlay();',playDelay);
		}  
	}
}
function autoPlayIncr() {
	if (incpos < incrementals[snum].length) {
		subgo(1);
		autoRun = setTimeout('autoPlayIncr();',incrDelay);
	}else {
		autoRun = setTimeout('nop();',remainDer);
	}
}
function nop() {
	// no operation dummy
}
function togglePlay() {
	if (autoRun && s5mode) {
		stopPlay();
	}else if (!autoRun && s5mode) {
		startPlay();
	}
}
function stopPlay() {
	if (autoRun && s5mode) {
		clearTimeout(autoRun); autoRun = null; 
		autoMatic = false; playPause = false;
		document.getElementById('auto').style.color="";
		document.getElementById('pause').style.color="";
		currentSlide();
	}
}
function startPlay() {
	if (!autoRun && s5mode) {
		playPause = false; autoMatic = true;
		document.getElementById('pause').style.color="";
		document.getElementById('auto').style.color=highLight;
		autoRun = setTimeout('autoPlay();',playDelay); 
		currentSlide();
	}
}
function pausePlay() {
	if (s5mode && autoMatic) {
		if (playPause) {
			playPause = false; autoRun = setTimeout('autoPlay();',playDelay);
			document.getElementById('pause').style.color="";
		}else {
			if (autoRun){ 
				clearTimeout(autoRun); autoRun = null; playPause = true;
				document.getElementById('pause').style.color=highLight;
			}
		}
		currentSlide();
	}
}
function switchLoop() {
	if(s5mode) {
		if (playLoop) {
			playLoop = false; document.getElementById('loop').style.color="";
		}else {
			playLoop = true; document.getElementById('loop').style.color=highLight;
		} 
	}
	currentSlide();
}
function setDelay(val) {
	if(s5mode) {
		var delay = Math.max(5,Math.min(val,300));
		playDelay = (fadeModus == true) ? ((delay*1000)+(2*fadeDuration)) : (delay*1000);
	}
}
// autoplay extension

// audio extension
function createSoundManagerScript() {
	if(typeof soundManager=="undefined") {
		onerrorSM2();	
	}else {
		var script=document.createElement('SCRIPT');
		var tx=document.createTextNode("soundManager.createMovie();");
		script.appendChild(tx);
		document.getElementsByTagName("body")[0].appendChild(script);
	}
}
//soundManager.onload = function() {
function onloadSM2() {
	if(!isIE) { //(degrade IE)	
		swfUnloaded = false;
		preloadSounds();
	}
}
//soundManager.onerror = function() {
function onerrorSM2() {
	if(typeof soundManager!="undefined") {
		soundManager.destruct;
		delete soundManager;
	}	
	audioSupport = false; swfUnloaded = true;
	if(audioError && !isIE && !isOp) {
		var dv = document.createElement('div'); dv.id = "guru";
		var d2=document.createElement('div'); dv.appendChild(d2);		var tx=document.createTextNode('Guru Meditation - SoundManager failed to load/initialize!');
		d2.appendChild(tx);	document.getElementById('slide0').appendChild(dv);
	}
}
function audioSetup() {
	if(sound[0]) {
		playSound(0); 
	}else if(sound[bgSoundItem] && !sound[0]) {
		playSound(bgSoundItem); 
	}
}
function fadeoutSound(ids, option) {
	if(curSoundID >= 0  && !swfUnloaded) {
		if(isNaN(ids)) {
			if(ids == "bgSound") {
				var cnum = parseInt(bgSoundItem);
			}else {
				for (var i = 0; i < (sound.length-1); i++) {
					if(sound[i] && ids == sound[i]["id"]) {
						var cnum = i;
						break;
					}
				}
			}
		}else {
			var cnum = ids;
			ids = sound[cnum]["id"];
		}	
		var vol = getMaxVolume(sound[cnum]["volume"]);
		var millisec = fadeDuration;
		var speed = Math.round(millisec / vol);		var timer = 0;		for(var i = vol; i > 0; i--) {			setTimeout("fadeout(" + i + ",'" + ids + "')",(timer * speed));			timer++;		}
		if(option) setTimeout("stopSound('"+ids+"')",millisec);
	}
}
function fadeout(volume, id) {	soundManager.setVolume(id,volume);}
function stopSound(ids) {
	var sid;
	if(isNaN(ids)) {
		sid = ids;
	}else if(sound[ids]) {
		sid = sound[ids]["id"];
	}
	if(sid!='' && curSoundID >= 0) {
		soundManager.stop(sid);
		curSoundID = -1;
	}
}
function toggleSounds() {
	if(audioSupport && !swfUnloaded) {
		stopAllSounds();
	}else if (!audioSupport && !swfUnloaded) {
		allowSounds();
	}
}
function allowSounds() {
	if(!swfUnloaded) {
		audioSupport = true;
		document.getElementById('audio').style.color=highLight;
		currentSlide();
	}
}
function stopAllSounds() {
	if(curSoundID >= 0) {
		stopSound(curSoundID);
	}else {
		soundManager.stopAll();
		curSoundID = -1;
	}
	audioSupport = false;
	document.getElementById('audio').style.color="";
	currentSlide();
}
function playSound(id) {
	if(audioSupport && !swfUnloaded) {
		var url, sid, vol, lps, cnum;
		if(isNaN(id)) {
			sid = id;
			if(sid == "bgSound") {
				cnum = parseInt(bgSoundItem);
			}else {
				cnum = getSoundID(id);
			}
		}else {
			cnum = parseInt(id); 
			if(sound[cnum]) sid = sound[cnum]["id"];
		}		
		if(sound[cnum] && sound[cnum]["url"]!='' && sid!=''){
			url = sound[cnum]["url"];
			vol = (sound[cnum]["volume"]!='')?getMaxVolume(sound[cnum]["volume"]):getMaxVolume(100);
			lps = (sound[cnum]["loops"])?true:false;			
			if(lps) {
				soundManager.play(sid,{volume:vol,onplay:function(){curSoundID=cnum;},onfinish:function(){soundManager.play(sid,{volume:getMaxVolume(sound[cnum]["volume"])});}});
			}else { 
				soundManager.play(sid,{volume:vol,onplay:function(){curSoundID=cnum;},onfinish:function(){curSoundID=-1;}});
			}
		}
	}	
}
function getSoundID(str) {
	for (var i = 0; i < (sound.length-1); i++) {
		if(sound[i] && str == sound[i]["id"]) {
			var id = i;
			break;
		}
	}
	return id;
}
function setVolume() {
	var vol = document.getElementById('volumelist');
	if(audioSupport && !swfUnloaded) {
		audioVolume = parseInt(vol.value);
		if(curSoundID >= 0) {
			if(sound[curSoundID]) {
				var sid = sound[curSoundID]["id"];
				var vid = getMaxVolume(sound[curSoundID]["volume"]);
				soundManager.setVolume(sid,vid);
			}
		}	}	
}
function getMaxVolume(value) {
	if(audioVolume>0) {var factor = audioVolume/100;}else {var factor = 0;}
	return Math.max(0,Math.min(parseInt(value*factor),audioVolume));
}
function preloadSounds() {
	var temp = ''; var parm = ''; var t = ''; var cl = '';
	var objects = document.getElementsByTagName('object');
	for (var i=0; i < objects.length; i++) {
		if(objects[i].type.toLowerCase() == 'audio/mp3' && objects[i].data != '') {
			objects[i].width = 0; objects[i].height = 0;
			if(objects[i].parentNode.tagName == 'DIV') {
				cl = objects[i].parentNode.className.toLowerCase();			
				if(cl == 'presentation' || cl == 'slide') {
					if(cl == 'presentation') {
						t = parseInt(bgSoundItem);
					}else {
						t = parseInt(objects[i].parentNode.id.slice(5, objects[i].parentNode.id.length));
					}	
					sound[t] = new Object();
					if(t < bgSoundItem) {
						sound[t]["id"] = objects[i].parentNode.id;
					}else {
						sound[t]["id"] = "bgSound";
					}	
					sound[t]["url"] = objects[i].data;
					sound[t]["volume"] = 100; sound[t]["loops"] = false;
					if(objects[i].archive != '') {
						parm = objects[i].archive.toLowerCase().split(',');
						for (var j=0; j < parm.length; j++) {
							if(parm[j] == 'loop') sound[t]["loops"] = true;
							if(parm[j].search(/^volume/) != -1) {
								var tmp = parm[j].split(':');
								sound[t]["volume"] = parseInt(tmp[1]);
							}
						}
					}
					soundManager.createSound(sound[t]["id"],sound[t]["url"]);
				}
			}			
		}
	}
}
// audio extension

// help extension
function createHelpReq() {
	if(!document.getElementById("HelpReq")) {
		var obj = document.getElementsByTagName("body")[0].firstChild;
		var pg = document.createElement('div');
		pg.id = "HelpReq";
		if (pg.addEventListener) {
			pg.addEventListener("onclick",dumpHelpReq,false);
		} else if (pg.attachEvent) {
			pg.attachEvent("onclick",dumpHelpReq);
		}	
		pg.style.position = 'absolute';
		pg.style.left = 0 + 'px';
		pg.style.top = 0 + 'px';
		pg.style.width = 100 + '%';
		pg.style.height = 100 + '%';
		pg.style.margin = 0 + 'px';
		pg.style.padding = 0 + 'px';
		if (isIE) {
			pg.style.filter = "alpha(opacity=90)";	
		}else {
			pg.style.opacity = 0.9;
		}		pg.style.zIndex = 9999;
		pg.style.backgroundColor="rgb(64,64,64)";
		pg.style.textAlign = "center";		pg.style.verticalAlign = "middle";
		pg.style.backgroundPosition="center center";
		pg.style.backgroundRepeat="no-repeat";
		pg.style.backgroundImage="url(ui/graphic_support/help.jpg)";
		document.getElementsByTagName("body")[0].insertBefore(pg,obj);
		if(document.getElementById("HelpReq")) {
			helpmode = true;
		}
	}
}
function dumpHelpReq() {
	if(document.getElementById("HelpReq")) {
		document.body.removeChild(document.getElementById('HelpReq'));
		helpmode = false;
	}
}
// help extension

//DEBUG
function ConsoleLog(value) {
	if(window.console) {
		window.console.log(value);
	}	
}
//DEBUG

document.write('<style type="text/css" media="screen" id="blockStyle">.presentation, .layout {display: none; }</style>');

if(!isIE && !isOp) {
	document.write('<script type="text/javascript" src="ui/audio_support/soundmanager2.js"></script>');
	if(typeof soundManager!="undefined") {
		var allMetas = document.getElementsByTagName('meta');
		for (var i = 0; i< allMetas.length; i++) {
			if (allMetas[i].name == 'audioDebug') {
				var audioDebug = (allMetas[i].content == "true") ? true : false;
				soundManager.defaultOptions.debugMode = audioDebug;
			}						
		}
	}
}

window.onload = createSlideShow;
window.onresize = function(){setTimeout('windowChange()',5);}