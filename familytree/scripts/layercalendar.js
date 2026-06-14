//
// Enhanced JavaScript Event Calendar
//
// Author:  Rick Pike
// Website: http://calendar.pikesys.com
// Email: calendar@pikesys.com
//'Version 0.3 - (07-May-2004)
//
// based on an earlier script by Kevin Ilsen (http://calendar.ilsen.net or kevin@ilsen.net)

// Configurable values are set to defaults here; you can override them before calling Calendar( ) from your HTML page
var SpecialDay=1;		// 1=Sunday, 2=Monday, . . . 7=Saturday
var ColorBackground="#ffffcc";
var ColorSpecialDay = "red";
var ColorToday = "green";
var ColorEvent = "blue";
var showAltDate = false;  	// add display of alternate date using results from user supplied "getAltMonth(dy, mo, yr, last)" and "getAltDate(dy, mo, yr)" functions
var showHolidays = false; 	// add display of holidays using result from user supplied "holidays(dy, mo, yr)" function
var showAltHoly = false; 	// add display of alternate holidays using result from user supplied "getAltHoly(dy, mo, yr)" function
var showMsgBox = false; 	// span empty cells (before 1st day and after last) for messageBox use
var showMini = false; 		// add minimonth display of prior and next months if first and/or last boxes are available 
var showNav = true; 		// enable month navigation (might disable for print version)
var showImages = true; 	// enable event images (might disable for print version)
var showLinks = true; 		// enable event hyperlinks (might disable for print version)
var msgBoxColor = "#ffcc99";
var navColor = "#ffff99";
var imageAlign = "left"; 	// default event image alignment
var imageScale = 100;		// percent scale factor for images
var altAlign = true; 		// alternate left/right alignment of event images on same date for readability
var DefaultFormat = "layer"; // for compatibility; set to "layer" to simplify formatting
var ExportPage = ""; 		// name of html page for displaying event text for export
var PrintPage = ""; 		// name of html page for printer-friendly format
var LinkPrefix = "";		// add as prefix to each event link

var thispage;			// current URL
var args = new Object;		// querystring params

// all format codes must have "|" to separate before and after tags
var DateFontSize=3;
var AltDateFormat = "<font color=#999999 size=2>|</font>";
var MonthFormat = "<font size=" + DateFontSize + "><b>|</b></font>";
var AltMonthFormat = "<br><font color=#999999 size=" + DateFontSize/2 + ">|</font>";
var HolidayFormat = "<font color=#999999 size=2><b><center>|</center></b></font>";
var AltHolyFormat = "<font  size=2><b><center>|</center></b></font>";
var DefaultLayerFormat = "<font size=2>|</font>";

var defaultMsgBox = "Note: The information here may not be current; please confirm dates and times.<p>";

// Initialize the range of the calendar to Jan - Dec of the current year.
// Event definitions will change this as needed; or it can be explicitly
// overridden before calling Calendar( ) from the HTML page.

var today = new Date();
var FirstMonth=GetFullYear(today) * 100 + 1;
var LastMonth=FirstMonth + 11;

// Create the array of day and month names (used in various places)
// the following arrays can be redefined in calendarevents.js

var months=['','January','February','March','April','May','June','July','August','September','October','November','December'];
var weekdays=['Sun','Mon','Tue','Wed','Thu','Fri','Sat'];

// oDic object holds text for calendar page. can be modified in calendarevents.js
var oDic = {
'view':'View',
'changes':'Apply changes',
'print':'Printer friendly',
'export':'Export events displayed',
'filter':'Filter events',
'jump':'Jump to month'}

// Layers[] is an array of layer names and default formats. Call DefineLayer( ) to add the
// layer name and corresponding format. New layer names in event definitions will
// be added automatically (watch case and spelling).

var Layers = new Array;
var LayerString = "|";
var layerCount = 0;
var layerChange = false;

// MsgBoxes[] is a SPARSE array; Call AddMsgBox( ) to populate it

var MsgBoxes = new Array;

// Events[] is a SPARSE array; Call AddEvent( ) to populate it or DefineEvent( ) for
// compatibility with existing calendar definition scripts.

var Events = new Array;

// Each event is defined by calling the AddEvent( ) routine with the following parameters:
//
//   AddEvent(Date, Description, Layer, Format, Link, Image, Width, Height, Align, Alt)
//        Date is a numeric value in the format YYYYMMDD
//        Description is a string (may include embedded HTML tags such as <BR>, <strong>, etc.)
//        Layer is an event category whose display on the calendar can be toggled on/off by the user
//        Format specifies the source of the format info for Description. Note that any embedded
//        formats in Description will still be applied; this argument is primarily to provide
//        a more convenient way to specify formats. 
//            "layer" = use default format from layer definition (plus any embedded tags!)
//            "custom" = only use format tags embedded in Description string
//            "<...>|</...>" = series of before and after tags separated by a "|" to wrap around
//               Description (plus any embedded tags!)  
//        Link is the URL of the target page if a hyperlink is desired from this event entry
//        Image is the URL of the image if you want to display an image with this event
//        Width is the width of the image in pixels
//        Height is the height of the image in pixels
//        Align is the alignment of the image such as "left", or "right"
//        Alt is the alternate text of the image (for mouseover or non-graphic browser)

// The function DefineEvent(Date, Description, Link, Image, Width, Height) is used
// for compatibility with previous calendar definition scripts


// Layer constructor
function Layer(format, show) {
	if (format) {	
	   if (format.indexOf("|")>0) {
	      this.format = format;
	   } else {
	      alert("Invalid Calendar Format String: " + format);
	   }
	} else {
	   this.format = DefaultLayerFormat;
	}
	this.show = (show=="false" ? "false" : "true");	// watch boolean vs. string arg
}

function DefineLayer(LayerName, LayerFormat, LayerShow) {
	Layers[LayerName] = new Layer(LayerFormat, LayerShow);
	layerCount++;
}

// Event constructor
function Event(description, layer, format, link, image, width, height, align, alt) {

	this.description = description;
	if (link) this.link = LinkPrefix + link;
	if (image) {
	   this.image = image;
	   if (width) this.width = width;
	   if (height) this.height = height;
	   if (align) this.align = align;
	   if (alt) this.alt = alt;
	   //alert("Event: ("+this.width+","+this.height+")");
	}
	this.layer = (layer ? layer : "default");	 	// must have some associated layer
	// if EventLayer not in Layers, add it
	if (!Layers[this.layer]) DefineLayer(this.layer);
	
	if (format) {
	   if (CheckFormat(format)) this.format = format;
	}
}

// Compatibility function for existing calendar definition scripts
function DefineEvent(Date, Description, Link, Image, Width, Height) {
	AddEvent(Date, Description, "", "", Link, Image, Width, Height, "", "");
}

function AddEvent(Date, Description, Layer, Format, Link, Image, Width, Height, Align, Alt) {
	var i;

	if (!Events[Date]) Events[Date] = new Array;
	i = Events[Date].length;
	Events[Date][i] = new Event(Description, Layer, Format, Link, Image, Width, Height, Align, Alt);

	// Adjust the minimum and maximum month & year to include this date
	tmp = Math.floor(Date / 100);
	if (tmp < FirstMonth) FirstMonth = tmp;
	if (tmp > LastMonth) LastMonth = tmp;

}

// Utility function to populate an array with values
function arr() {
	for (var n=0;n<arr.arguments.length;n++) {
		this[n+1] = arr.arguments[n];
	}
}

// Calendar( ) is the only routine that needs to be called to display the calendar
var pre, post, tmp, gloMo, gloYr, gloYearmonth;
function Calendar( ) {
	var curdy, curmo, yr, mo, dy, firstday, yearmonth, bgn, lastdate, jump;
	var urlparts = window.location.toString().split('?');
	thispage = urlparts[0];
	var myMsgBox = "Put this FREE calendar script on your own site; see <a href=http://calendar.pikesys.com>calendar.pikesys.com</a>.<p>";
	// define default MsgBox messages
	AddMsgBox(0, defaultMsgBox);
	AddMsgBox(0, myMsgBox);
	
	// Save current day and month for comparison
	curdy = today.getDate();
	curmo = today.getMonth()+1;
	
	initCal(curmo);
	mo = gloMo; yr = gloYr; yearmonth = gloYearmonth;
	getLayersVisible(); 		// get layer visibility settings from querystring
	// Create a date object for the first day of the desired month
	bgn = new Date(yr, mo-1, 1);
	// Get the day-of-week of the first day, and the # days in the month
	firstday = (bgn.getDay()-SpecialDay+1)%7;
	lastdate = NumDaysIn(mo,yr);
	lastday = 1+(firstday + lastdate - 1)%7;
	prev = next = "&nbsp;";
	if (showNav) {
		if (yearmonth > FirstMonth)
			prev = '<a class="navlink" href="#" onclick="javascript:GoToMonth('+PrevYearMonth(yearmonth)+');return false;">&lt;-- ' + oDic.view + ' ' +months[PrevMonth(mo)]+'</a>';
		if (yearmonth < LastMonth)
			next += '<a class="navlink" href="#" onclick="javascript:GoToMonth('+NextYearMonth(yearmonth)+');return false;">' + oDic.view + ' ' +months[NextMonth(mo)]+' --&gt;</a>';
	}

	parseFormat(MonthFormat);
	tmp = "<TABLE BORDER=2 BGCOLOR="+ColorBackground+"><TR BORDER=0 BGCOLOR="+navColor+">";
	tmp += "<TH ALIGN=CENTER BGCOLOR="+navColor+">" + prev + "</TH>";
	tmp += "<TH ALIGN=CENTER COLSPAN=5>" + pre + months[mo] + " " + yr + post;
	
	if (showAltDate) {
		parseFormat(AltMonthFormat);
		altMonth = getAltMonth(1, mo, yr, lastdate);
		tmp += pre + (altMonth ? altMonth : "") + post;
	}
	tmp += "</TH><TH ALIGN=CENTER BGCOLOR="+navColor+">" + next + "</TH></TR>";
	document.write(tmp);
	document.write("<TR BGCOLOR="+navColor+">");
	
	for (var i=0;i<=6;i++){
		document.write("<TH ALIGN=CENTER WIDTH=14%><FONT SIZE=2>"+weekdays[(i+SpecialDay-1)%7]+"</FONT></TH>");
	}
	dy = 1;
	document.write("</TR><TR>");

	while (dy <= lastdate) {
		for (var i=0; i<=6; i++) {
			
			// If the day cell is before the first day of the month, print a miniMonth display of previous month in the first cell, 
			// otherwise print a space in this cell of the table.
			if (dy == 1 && i < firstday) {
				if (i == 0) {
					if (showMini) {
						document.write("<TD BGCOLOR="+ColorBackground+">");	
						MiniMonth(PrevYearMonth(yearmonth));
					} else {
						document.write("<TD>&nbsp;");
					}
				} else if (showMsgBox && i==1) { 	// span empty cells to allow messageBox
					msgSpan = firstday - 1;
					document.write("<TH BGCOLOR=" + navColor + " COLSPAN=" + msgSpan +">&nbsp;");
					DoMsgBox(yearmonth, msgSpan);
				} else if (!showMsgBox) {
					document.write("<TD>&nbsp;");
				}
				document.write("</TH>");

			// If the day cell is after the last day of the month, print a miniMonth display of following month in the last cell, 
			// otherwise print a space in this cell of the table.
			} else if (dy > lastdate) {
				if (i == 6) {
					if (showMini) {
						document.write("<TD BGCOLOR="+ColorBackground+">");	
						MiniMonth(NextYearMonth(yearmonth));
					} else {
						document.write("<TD>&nbsp;");
					}
				} else if (showMsgBox && i==(lastday)) { 	// span empty cells to allow messageBox
					msgSpan = 5 - lastday;
					document.write("<TH BGCOLOR=" + navColor + " COLSPAN=" + msgSpan +">&nbsp;");
					DoMsgBox(yearmonth, msgSpan);
				} else if (!showMsgBox) {
					document.write("<TD>&nbsp;");
				}
				document.write("</TH>");

			// Otherwise, write date and the event, if any, in this cell of the table.
			} else {
				document.write("<TD VALIGN=TOP>");
				ShowDate(yr,mo,dy,i+SpecialDay%7,curmo,curdy);
				document.write("</TD>");				
				dy++;
			}
		}
		document.write("</TR>");
	}

	if (showNav) {
		prev = next = "&nbsp;";
		if (yearmonth > FirstMonth)
			prev = '<a class="navlink" href="#" onclick="javascript:GoToMonth('+PrevYearMonth(yearmonth)+');return false;">&lt;-- ' + oDic.view + ' ' +months[PrevMonth(mo)]+'</a>';
		if (yearmonth < LastMonth)
			next += '<a class="navlink" href="#" onclick="javascript:GoToMonth('+NextYearMonth(yearmonth)+');return false;">' + oDic.view + ' ' +months[NextMonth(mo)]+' --&gt;</a>';
		tmp = "<TR BGCOLOR="+navColor+"><TH ALIGN=CENTER BGCOLOR="+navColor+">" + prev + "</TH>";
		tmp += "<TH colspan=5 align=center valign=middle><FORM>";
		if (ExportPage) tmp += '<a class="navlink" href="' + ExportPage + '?'+yearmonth+'">' + oDic['export'] + '</a>&nbsp;&nbsp;|&nbsp;&nbsp;';
		tmp += oDic.jump + ':&nbsp;&nbsp;';
		document.write(tmp);
		BuildSelectionList(yearmonth);
		if (PrintPage) document.write('&nbsp;&nbsp;|&nbsp;&nbsp;<a class="navlink" href="' + PrintPage + '?'+yearmonth+'">' + oDic.Print + '</a>');
		tmp = "</FORM></TH><TH ALIGN=CENTER BGCOLOR="+navColor+">" + next + "</TH>";
		document.write(tmp + "</TR>");
		if (layerCount>1) {
			document.write("<TR BGCOLOR="+navColor+"><TD colspan=7 align=center>");
			ChooseLayers(yearmonth);
			document.write("</TD></TR>");
		}
	}
	document.write("</TABLE>");
}

// Display a date in the appropriate color, with events (if there are any)

function ShowDate(yr, mo, dy, dayofweek, currentmonth, currentday) {

	var ind, DayHighlighted, tmp, event;

	tmp = "<TABLE><TR VALIGN=TOP><TD ALIGN=LEFT WIDTH=10%>";
	tmp += "<FONT SIZE=" + DateFontSize;	// Note open tag!	
	DayHighlighted = false;

	if ((mo == currentmonth) && (dy == currentday)) {
		tmp += " COLOR=" + ColorToday;
		DayHighlighted = true;
	} else if (dayofweek == SpecialDay) {
		tmp += " COLOR=" + ColorSpecialDay;
		DayHighlighted = true;
	}

	ind = (((yr * 100) + mo) * 100) + dy;
	if (Events[ind]) {
		//event = Events[ind];
		if (!DayHighlighted) tmp += " COLOR=" + ColorEvent;
//	} else {
//		event = "&nbsp;<BR>&nbsp;";
	}
	
	tmp += "><B>" + dy + (dy<10 ? "&nbsp;" : "") + "&nbsp;</B></FONT></TD>";	 	// close tag
	document.write(tmp);
	
	if (showAltDate) {
		altDate = getAltDate(dy, mo, yr);
		parseFormat(AltDateFormat);
		document.write("<TD ALIGN=RIGHT>" + pre + altDate + post + "</TD>");
	}
	document.write("</TR></TABLE>");

	if (showAltHoly) {
		tmp = getAltHoly(dy,mo,yr);
		if (tmp) {
			parseFormat(AltHolyFormat);
			document.write(pre + tmp + post + "<BR>");
		}
	}
	
	if (showHolidays) {
		tmp = holidays(dy,mo,yr);
		if (tmp) {
			parseFormat(HolidayFormat);
			document.write(pre + tmp + post + "<BR>");
		}
	}
//	document.write("<P><FONT SIZE=1>" + event + "</FONT>");

	images=0;
	for (j in Events[ind]) {
		ev = Events[ind][j];
		// with(Events[ind][j]) { // greatly improves readability of following
		//for (k in ev) { alert("ev["+k+"]="+ev[k]) }
		//  document.write("Events[" + ind + "][" + j + "][" + k + "] = " + EscapeLtGt(Events[ind][j][k]), "<br>");
		//alert("-> Layers[Events["+ind+"]["+j+"]."+ev.layer+"].show="+Layers[ev.layer].show);
		tmp = "";		
		if (Layers[ev.layer].show == "true") {
			//alert("(+)showing event for "+ind+" in layer "+ev.layer);
			// Build the HTML string for this event
			tmp += (j>0 ? "<br>" : "");
			if (ev.image && showImages) {
				if (ev.align) {
					align = ev.align;
				} else if (altAlign && images>0) {
					align = (lastAlign=="left" ? "right" : "left");
				} else {
					align = imageAlign;
				}
				tmp += '<img src="' + ev.image + 
					   (ev.width ? '"  width="' + ev.width*imageScale/100 : '') +
					   (ev.height ? '" height="' + ev.height*imageScale/100 : '') +
					   (ev.alt ? '" alt="' + ev.alt : '') +					   
					   '" align="' + align + '" valign="top">';
				lastAlign = align;
				images++;
			}
			format = "";
			if (ev.format == "layer") { // use format from layer (and embedded tags)
				format = Layers[ev.layer].format;
			} else if (ev.format == "custom") { // use only embedded tags
				format = "";
			} else if (ev.format) { 	// format string?
				if (CheckFormat(ev.format)) format = ev.format;
			} else if (DefaultFormat == "layer") { // use format from layer if no custom format
				format = Layers[ev.layer].format;
			}
			parseFormat(format);
			//tmp += pre + (ev.link && showLinks ? ev.description.link(ev.link) : ev.description) + post + "<br>";
			tmp += pre + (ev.link && showLinks ? "<a class=\"eventlink " + ev.layer + "\" href="+ev.link+">"+ev.description+"</a>" : ev.description) + post + "<br>";
			
		} else {
			//alert("(-)skipping event for "+ind+" in layer "+ev.layer);
		}
	document.write("<FONT SIZE=1>" + tmp + "</FONT>");
	}
}

function exportCal( ) {
	var curdy, curmo, yr, mo, dy, firstday, yearmonth, lastdate;

	// Save current day and month for comparison
	curdy = today.getDate();
	curmo = today.getMonth()+1;

	initCal(curmo);
	mo = gloMo; yr = gloYr; yearmonth = gloYearmonth;
	getLayersVisible();	
	
	// Create a date object for the first day of the desired month
	lastdate = NumDaysIn(mo,yr);

	tmp = "<textarea NAME=\"txt\"  ROWS=20 COLS=75 WRAP=VIRTUAL>";
	tmp += '"Subject","Start Date","Start Time","End Date","End Time","All day event","Description","Show time as","Location"\n';
	document.write(tmp);
	for (dy=1; dy<=lastdate; dy++) {
		ind = (((yr * 100) + mo) * 100) + dy;
		evdate = mo + "/" + dy + "/" + yr;
		for (j in Events[ind]) {
			ev = Events[ind][j];
			if (Layers[ev.layer].show == "true") {
				//alert("(+)showing event for "+ind+" in layer "+ev.layer);
				tmp = qw(ev.description) + "," + qw(evdate) + ",,,," + qw("true") + ",," + 
					 qw("3") + "," + qw("CalendarScript");
				if (ev.description) document.write(tmp+"\n");
			} else {
				//alert("(-)skipping event for "+ind+" in layer "+ev.layer);
			}
		}
	}
	document.write("</textarea>");
}

function getLayersVisible() {
	// get layer visibility settings from querystring
	if (args.layers) {
	    var layerArgs = args.layers.split("/");
	    for (i=0; i<layerArgs.length; i++) {
	        sep = layerArgs[i].indexOf(":");
		name = layerArgs[i].substring(0, sep);
		value = layerArgs[i].substring(sep+1, layerArgs[i].length);
		if (Layers[name]) Layers[name].show = value;
		//alert("Read layers: "+name+"="+value+" Layers["+name+"]="+Layers[name].show);
	    }
	}
}
function initCal(curmo) {

	// Default to current month and year
	mo = curmo;
	yr = GetFullYear(today);
	yearmonth = (yr * 100) + mo;
	var pos
	args=getArgs(); //get querystring arguments 
	// If querystring month argument (month=YYYYMM;) is present, get the month/year
	if (args.month) {
		yearmonth = parseInt(args.month);
		if ((""+yearmonth).length == 6) {
			mo = yearmonth % 100;
			yr = (yearmonth - mo) / 100;
		}
	}

	// Constrain to the range of months with events
	if (yearmonth < FirstMonth) {
		mo = FirstMonth % 100;
		yr = (FirstMonth - mo) / 100;
		yearmonth = FirstMonth;
	}
	if (yearmonth > LastMonth) {
		mo = LastMonth % 100;
		yr = (LastMonth - mo) / 100;
		yearmonth = LastMonth;
	}
	gloMo = mo; gloYr = yr; gloYearmonth = yearmonth;
}

function qw(string) {
	return "&quot;" + string + "&quot;";
}

// Create a mini display of the desired month

function MiniMonth(yearmonth) {
	var bgn, firstday, lastdate, miniweek;
	var days = new arr("S","M","T","W","T","F","S");

	mo = yearmonth % 100;
	yr = (yearmonth - mo) / 100;
	bgn = new Date(yr, mo-1, 1);
	// Get the day-of-week of the first day, and the # days in the month
	firstday = bgn.getDay();
	lastdate = NumDaysIn(mo,yr);
	document.write("<b><tt><Font Size=2><div align=center>&nbsp;" + months[mo] + "</div></font>");
	miniweek = "<font size=1>&nbsp;<u>";
	for (d in days) { miniweek += "&nbsp;" + days[d] + "&nbsp;"; }
	document.write(miniweek,"</u>");
	dy = 1;
	// Rest of the weeks . . .
	while (dy <= lastdate) {
		miniweek = "<br>";
		for (var i=1;i<=7;i++) {
			// If the day is less than the day of the week of the first day of the month, append spaces
			if (dy == 1 && i <= firstday){
				miniweek += "&nbsp;&nbsp;&nbsp;";
			// End minimonth if the day > last day of the month
			} else if (dy > lastdate) {
				break;
			// Otherwise, append date (w/ extra space for single digits)
			} else {
				miniweek += "&nbsp;" + ( dy<10 ? "&nbsp;" : "" ) +dy;
				dy++;
			}
		}
		document.write(miniweek);
	}
	document.write("</font></tt></b>");
}


// Remaining routines are utilities used above

function NumDaysIn(mo,yr) {
	if (mo==4 || mo==6 || mo==9 || mo==11) return 30;
	else if ((mo==2) && LeapYear(yr)) return 29;
	else if (mo==2) return 28;
	else return 31;
}

function LeapYear(yr) {
	return ( (yr%4 == 0 && yr%100 != 0) || yr % 400 == 0 ? true : false );
}

// fixes a Netscape 2 and 3 bug
function GetFullYear(d) { // d is a date object
	var yr = d.getYear();
	return ( yr < 1000 ? yr + 1900 : yr );
}

function PrevMonth(mth) {
	return ( mth == 1 ? 12 : mth - 1 );
}

function NextMonth(mth) {
	return ( mth == 12 ? 1 : mth + 1 );
}

function PrevYearMonth(yrmth) {
	return ( yrmth%100 == 1 ? yrmth-100+11 : yrmth-1 );
}

function NextYearMonth(yrmth) {
	return ( yrmth%100 == 12 ? yrmth-11+100 : yrmth+1 );
}

function GoToMonth(yrmo) {
	args.month=yrmo;
	document.location= thispage + putArgs(args);
	return false;
}

function JumpTo(calendar) {
	var sel, yrmo;

	sel = calendar.selectedIndex;
	GoToMonth(calendar.form.jumpmonth[sel].value);
}

function BuildSelectionList(current) {
	var mo, yr, yearmonth;

	yearmonth = FirstMonth;
	tmp = "<select name=\"jumpmonth\" size=1 onchange=\"JumpTo(this)\">";
	while (yearmonth <= LastMonth) {
		mo = yearmonth % 100;
		yr = (yearmonth - mo) / 100;
		selected = (yearmonth == current ? " selected" : "");
		tmp += "<option value=" + yearmonth + selected + ">" + months[mo]+" "+yr;
		yearmonth = NextYearMonth(yearmonth);
	}

	document.write(tmp + "</select>");
}

// Create a message box

function DoMsgBox(yearmonth, msgSpan) {
	if (MsgBoxes[yearmonth]) {
		for (j in MsgBoxes[yearmonth]) { 	// find first unshown message for month that fits
			monthlyMsg =MsgBoxes[yearmonth][j];
			if (!monthlyMsg.shown) {
				//document.write("monthlyMsg.minspan = " + monthlyMsg.minspan + "<br>");
				if (!monthlyMsg.minspan || monthlyMsg.minspan <= msgSpan) {
					tmp = "<table border=2 bgcolor=" + msgBoxColor + " align=center>";
					tmp += "<TR><TD>"+ monthlyMsg.message + "</TD></TR></table>";
					document.write(tmp);
					monthlyMsg.shown = true;
					return;
				}
			}
		}
	}
	if (MsgBoxes[0]) { 	// show default MsgBox messages if they exists
		for (j in MsgBoxes[0]) { 	// find first unshown message for month that fits
			monthlyMsg =MsgBoxes[0][j];
			if (!monthlyMsg.shown) {
				//document.write("monthlyMsg.minspan = " + monthlyMsg.minspan + "<br>");
				if (!monthlyMsg.minspan || monthlyMsg.minspan <= msgSpan) {
					tmp = "<table border=2 bgcolor=" + msgBoxColor + " align=center>";
					tmp += "<TR><TD>"+ monthlyMsg.message + "</TD></TR></table>";
					document.write(tmp);
					monthlyMsg.shown = true;
					return;
				}
			}
		}
	}
}

// Utility routines

function escramVal(j,k){var a,b,c,d,e;a='<a href=\"mai';c='\">';a+='lto:';b=j+'@';e='</a>';b+=k;d=b;return(a+b+c+d+e);}

function parseFormat(format) {
	// pre and post are globals
	pre = post = "";
	if (format) {		
		var sep = format.indexOf("|");
		if (sep > 0) {  // split format into pre and post strings
			pre = format.substring(0, sep);
			post= format.substring(1+sep, format.length);
		}
	}
}

function CheckFormat(String) {
	var okay;
	okay =(String == "layer" || String == "custom" || String.indexOf("|")>0);
	if (!okay) alert("Invalid Calendar Format String: " + String);
	return okay;
}
	
// MsgBox constructor
function MsgBox(message,minspan,maxspan) {
	//alert("MsgBox("+message+","+minspan+","+maxspan+")");
	this.message = message;
	this.minspan = (minspan ? minspan : 1);
        if (maxspan) this.maxspan = maxspan;
	//this.shown = false;
}

function AddMsgBox(yearmonth,message,minspan,maxspan) {
	var i;

	if (!MsgBoxes[yearmonth]) MsgBoxes[yearmonth] = new Array;
	i = MsgBoxes[yearmonth].length;
	MsgBoxes[yearmonth][i] = new MsgBox(message,minspan,maxspan);
}

function ChooseLayers(yearmonth) {
	var i, checked;
	tmp = '<form name="layerform"><b>'+oDic.filter+':</b>&nbsp;';
	for (i in Layers) {
		if (i != "default") {
			checked = (Layers[i].show == "true" ? " checked" : "");
			parseFormat(Layers[i].format);
			tmp += pre + '<input type="checkbox" name="' + i + '" value="' + i + '"' +checked + 
				' onClick="ChangeLayer(\''+i+'\')">' + i + "&nbsp;" + post;
		}
 	}
	//if (layerChange) {
	tmp += '&nbsp;<input type="button" name="ApplyChanges" value="' + oDic.changes + '"' +
		'onClick="ApplyLayerChange(\'' + yearmonth + '\')">';
	//}
	
	document.write(tmp + "</form>");
}

function ChangeLayer(layer) {
	layerChange=true;
	Layers[layer].show = document.layerform[layer].checked;
}

function ApplyLayerChange(yearmonth) {
	var layerChange=false, sep='';
	layerString = '';
	for (layer in Layers) {
		if (layer != "default") {
			layerString += sep + layer + ":" + Layers[layer].show;
			sep='/';
		}
	}
	//alert("set layers="+layerString);
	args.layers=layerString;
	document.location = thispage + putArgs(args);
}

function getArgs(  ) {
	// extract arguments from URI querystring

	var args = new Object(  );
	var query = decodeURI(window.location.search.substring(1));     
	// Get query string
	var pairs = query.split(",");
	// Break at comma
	for(var i = 0; i < pairs.length; i++) {
		var pos = pairs[i].indexOf('=');
		// Look for "name=value"
		if (pos == -1) continue;
		// If not found, skip
		var argname = pairs[i].substring(0,pos);
		// Extract the name
		var value = pairs[i].substring(pos+1);
		// Extract the value
		args[argname] = value;
		// Store as a property
	}
	return args;     // Return the object
}

function putArgs(args) {
//	format URI querystring from argument object

	var query = '';
	var sep='';
	for (arg in args) {
		query += sep + arg + '=' + args[arg];
		sep=',';
	}
	return encodeURI(query ? '?' + query : '');
}
			