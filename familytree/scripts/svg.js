//	Scripts used by the SVG graphics
//
//	HISTORY
//	23-Nov-2005	Ron Prior       	Created
//  12-Oct-2010 Ron Prior        Major changes to zoom & pan for Google Chrome and other webkit browsers
//	Aug 2006 	Ron Prior		Added 'tooltip' code with acknowledgements to
//						Doug Schepers at www.svg-whiz.com
//
	var r, loop, genomap, hammer,loaded = true, map, cSvg, hSvg, wSvg, ocSvg, ohSvg, owSvg, s, panZoom;
	var root = null;
	var svgns = 'http://www.w3.org/2000/svg';
	var xlinkns = 'http://www.w3.org/1999/xlink';
	var toolTip = null;
	var TrueCoords = null;
	var tipBox = null;
	var tipText = null;
	var tipTitle = null;
	var tipDesc = null;

	var lastElement = null;
	
	var titleText = '';
	var titleDesc = '';
	var tipping = false;
	var genopro = null;

	
	function doResize() {
		//var canvas = document.getElementById('svgCanvas'), height = parseInt(getInnerHeight() - 73);
		
		//if (height > 0) canvas.setAttributeNS(null,"height", height + 'px');
		//if (root) root.setAttributeNS(null,"height", parseInt(document.getElementById('svgEmbed').clientHeight) + 'px');
		if (panZoom && !map.Highlight) {
			panZoom.resize();
			panZoom.fit();
			panZoom.center();
		}
	}
	var eventsHandler = {
	  haltEventListeners: ['touchstart', 'touchend', 'touchmove', 'touchleave', 'touchcancel']
	, init: function(options) {
		var instance = options.instance
		  , initialScale = 1
		  , pannedX = 0
		  , pannedY = 0
		// Init Hammer
		// Listen only for pointer and touch events
		this.hammer = Hammer(options.svgElement, {
		  inputClass: Hammer.SUPPORT_POINTER_EVENTS ? Hammer.PointerEventInput : Hammer.TouchInput
		})
		// Enable pinch
		this.hammer.get('pinch').set({enable: true})
		// Handle pan
		this.hammer.on('panstart panmove', function(ev){
		  // On pan start reset panned variables
		  if (ev.type === 'panstart') {
			pannedX = 0
			pannedY = 0
		  }
		  // Pan only the difference
		  instance.panBy({x: ev.deltaX - pannedX, y: ev.deltaY - pannedY})
		  pannedX = ev.deltaX
		  pannedY = ev.deltaY
		})
		// Handle pinch
		this.hammer.on('pinchstart pinchmove', function(ev){
		  // On pinch start remember initial zoom
		  if (ev.type === 'pinchstart') {
			initialScale = instance.getZoom()
			instance.zoom(initialScale * ev.scale)
		  }
		  instance.zoom(initialScale * ev.scale)
		})
		// Prevent moving the page on some devices when panning over SVG
		options.svgElement.addEventListener('touchmove', function(e){ e.preventDefault(); });
		this.hammer.on("hammer.input", function(ev) {
			//console.log(ev);
		});
	  }
	, destroy: function(){
		this.hammer.destroy()
	  }
	}
function svgInit(info)
{
	root = document.getElementById('svgCanvas');
	genomap=document.getElementById("viewport")
	map = info;
	var param = getArgs();
	// normalise coordinates
	var dX = -map.Bounds[0];
	var dY = -map.Bounds[1];
	map.Bounds[2] += dX;
	map.Bounds[3] += dY;
	map.Bounds[0] = 0;
	map.Bounds[1] = 0;
	map.X=(param.x ? parseInt(param.x) + dX : (map.Bounds[2] - map.Bounds[0]) / 2);
	map.Y=(param.y ? parseInt(param.y) + dY : (map.Bounds[3] - map.Bounds[1]) / 2);
	map.Highlight = (param.highlight ? param.highlight=="true" : false);

	panZoom = svgPanZoom('#svgCanvas', {
		viewportSelector: '#viewport',
		zoomEnabled: true,
		maxZoom: 20,
		dblClickZoomEnabled: true,
		fit: !map.Highlight,
		center: !map.Highlight,
		customEventsHandler: eventsHandler
	});
	toolTip = document.getElementById('ToolTip');
	tipBox =  document.getElementById('tipbox');
	tipText = document.getElementById('tipText');
	tipTemp = document.getElementById('tipTemp');
	genopro = document.getElementById('GenoPro');
	
	var hl=document.getElementById("highlight");
	if (map.Highlight) {
		hl.setAttribute("visibility","visible");
		hl.setAttribute("cx", map.X);
		hl.setAttribute("cy", map.Y);
		var tmp = panZoom.getSizes();
		panZoom.pan({x:tmp.width/2-map.X*tmp.realZoom, y:tmp.height/2 - map.Y*tmp.realZoom});
	} else {
		hl.setAttribute("visibility","hidden");
	}
	//doResize();
}
function displaylink(href,target)
{
	try {
		window.open(href,target);
	} catch(e) {
		browserEval('window.open("'+href+'",target="'+target+'")');
	}
}
function getInnerHeight() {
	if (window.innerHeight) { return window.innerHeight; } // netscape behavior
	else if (document.body && document.body.offsetHeight) { return  document.body.offsetHeight; } // IE behavior
	else if (document.documentElement.offsetHeight) { return  document.documentElement.offsetHeight; } // IE behavior
	else { return null; }
}

function getInnerWidth() {
	if (window.innerWidth) { return window.innerWidth; } // netscape behavior
	else if (document.body && document.body.offsetWidth) { return  document.body.offsetWidth; } // IE behavior
	else if (document.documentElement.offsetWidth) { return  document.documentElement.offsetWidth; } // IE behavior
	else { return null; }
}

      

      function HideTooltip( evt )
      {
         if (toolTip) toolTip.setAttributeNS(null, 'visibility', 'hidden');
         children = tipText.childNodes;
         for (var i=0; i<children.length; i++) {
             tipText.removeChild(children.item(i));
         }
         return ! tipText.hasChildNodes;
       };


      function ShowTooltip( evt )
      {
          // there is a problem with Firefox in that occaionally not all tspan elements are removed
          // this hack seems to fix it!
          	 var isEmpty = HideTooltip(evt);
          if ( ! isEmpty ) {
          	isEmpty = HideTooltip(evt);
          }
          if ( ! isEmpty ) {
          	isEmpty = HideTooltip(evt);
          }
          if ( ! isEmpty ) {
          	isEmpty = HideTooltip(evt);
          }
          var tipScale = 1/root.currentScale;

          tipBox.setAttributeNS(null, 'transform', 'scale(' + tipScale + ',' + tipScale + ')' );
          tipText.setAttributeNS(null, 'transform', 'scale(' + tipScale + ',' + tipScale + ')' );


          var titleValue = '';
          var descValue = '';

	        var box = new Object();
    	    box.maxWidth = getInnerWidth();
    	    box.textWidth = 0;
    	    box.lineHeight = 10;

         var targetElement = evt.target;
         if ( lastElement != targetElement )
         {
            var targetTitle = targetElement.getElementsByTagName('title').item(0);
            if ( ! targetTitle ) targetTitle = targetElement.parentNode.getElementsByTagName('title').item(0);

            if ( targetTitle )
            {
               // if there is a 'title' element, use its contents for the tooltip title
               if (targetTitle.hasChildNodes()) titleValue = targetTitle.firstChild.nodeValue;
            }

            var targetDesc = targetElement.getElementsByTagName('desc').item(0);
            if ( ! targetDesc) targetDesc = targetElement.parentNode.getElementsByTagName('desc').item(0);
            if ( targetDesc )
            {
               // if there is a 'desc' element, use its contents for the tooltip desc
               if (targetDesc.hasChildNodes()) descValue = targetDesc.firstChild.nodeValue;

               if ( '' == titleValue )
               {
                  // if there is no 'title' element, use the contents of the 'desc' element for the tooltip title instead
 //                 titleValue = descValue;
 //                 descValue = '';
               }
            }

            // if there is still no 'title' element, use the contents of the 'id' attribute for the tooltip title
            if ( '' == titleValue )
            {
//               titleValue = targetElement.getAttributeNS(null, 'id');
            }

            // selectively assign the tooltip title and desc the proper values,
            //   and hide those which don't have text values
            //

            if ( '' != titleValue ) AddTipText(tipText, titleValue, 'black', box);

            if ( '' != descValue ) AddTipText(tipText, descValue, 'blue', box);
         }

         // if there are tooltip contents to be displayed, adjust the size and position of the box
         if ( tipText.hasChildNodes )
         {
           var p=root.createSVGPoint();
           p.x = evt.clientX;
           p.y = evt.clientY;
 	         p = p.matrixTransform(root.getCTM().inverse());
           var xPos = p.x + (10 * tipScale);
           var yPos = p.y + (10 * tipScale);


            //return rectangle around text as SVGRect object
	          // but getBBox() seems to be broken with Adobe so...
	          box.Height = tipText.childNodes.length * box.lineHeight

          	if (box.Height > 0 && box.textWidth > 0 ) {   
          	    if ((evt.clientX + box.textWidth + 10 ) > getInnerWidth())  xPos = ((getInnerWidth()  - box.textWidth -10)  - root.currentTranslate.x) * tipScale;
          	    if ((evt.clientY + box.Height + 20 ) > getInnerHeight()) yPos = ((getInnerHeight() - box.Height - 10) - root.currentTranslate.y) * tipScale;
          
                      tipBox.setAttributeNS(null, 'width', Number(box.textWidth + 10));
                      tipBox.setAttributeNS(null, 'height', Number(box.Height + 5));
          
                      // update position
                      toolTip.setAttributeNS(null, 'transform', 'translate(' + xPos + ',' + yPos + ')');
                      toolTip.setAttributeNS(null, 'visibility', 'visible');
          	}
         }
      };

function AddTipText(textNode, tip, col, tipbox)
{
	var tipLines = tip.split('\n'), tspanNode, newNode, childNode, len;
	for (var i=0; i<tipLines.length; i++) {
		newNode = document.createElementNS(svgns, 'tspan');
		tspanNode = textNode.appendChild(newNode);
		tspanNode.setAttributeNS(null, 'style', 'fill:'+col+';stroke:none;');
		tspanNode.setAttributeNS(null, 'x', '5');
		tspanNode.setAttributeNS(null, 'dy', Number(tipbox.lineHeight));
		childNode = document.createTextNode(tipLines[i] != ''?tipLines[i]:' ');
// Adobe's getComputedTextLength() returns total length of all tspan elements , so determine max length from each tspan
		newNode = tipTemp.appendChild(childNode);
		len = tipTemp.getComputedTextLength();
		childNode = tipTemp.removeChild(newNode);
		if (len > tipbox.textWidth ) tipbox.textWidth = len;
		newNode = tspanNode.appendChild(childNode);
	}
}

