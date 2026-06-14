
		var tocStateToggle;
 		function tocSetToggle(close) {
				var tocOpen = "This frame will stay open after an entry is selected. Click to change";
				var tocClose = "This frame will close after an entry is selected. Click to change"
				var toggle = document.images["tocStateButton"];
				toggle.src = (close ? "images/toc_close.gif" : "images/toc_open.gif");
				toggle.alt =  (close ? tocClose : tocOpen);
				toggle.title =  (close ? tocClose : tocOpen);
		}

		function tocToggle() {
				 tocStateToggle = (tocStateToggle == 'Close' ? 'Open' : 'Close');
				 tocSetToggle(tocStateToggle == 'Close');
		}
		function doResize() {
                 document.getElementById('toc').style.height = parseInt(getInnerHeight() - 110) + 'px';
        };
        $(function () {
					doResize();
					window.onresize=doResize;

					var match,
						pl     = /\+/g,  // Regex for replacing addition symbol with a space
						search = /([^&=]+)=?([^&]*)/g,
						decode = function (s) { return decodeURIComponent(s.replace(pl, " ")); },
						query  = window.location.search.substring(1);

					var urlParams = {};
					while (match = search.exec(query))
					   urlParams[decode(match[1])] = decode(match[2]);
					if ('open' in urlParams) explorerTreeOpenTo(window, "names",urlParams['open'], true, true, "2");
					tocStateToggle = (true || (urlParams.close && urlParams,close == 'Y') ? 'Close' : 'Open')
					tocSetToggle(tocStateToggle == 'Close');
					hidePopUpFrame();
					PageInit(true, '','names');
				});
