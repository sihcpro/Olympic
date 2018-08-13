/*
- validation: Cho hàm, nhận biến a (g), xử lý trả về true hoặc false, trả về false thì từ chối dịch.
- value: Cho một mảng, mỗi phần tử trong mảng là một mảng gồm hai phần tử, phần tử đầu quyết định option có default (vd [#BOX] thì có phần tử đầu là BOX), phần thứ hai quyết định property của option có default.
*/
var credit = "This bbcode system is exclusively designed for the GensokyoVN forum; unauthorized uses elsewhere are prohibited.";
//Emobox
$(function() {
    if ($('#i_icon_mini_logout').length == 0) {
        $('.emo-box').hide();
    }
});
//console.log('u_module and post_parsing is ready. Call gskbb for shorthand.');
var debug = $('.top-stick').eq(0);
//Disable log if not admin user
window.log = function(a) {
    if ($('img[title="Thoát [ mr.equal ]"]').length !== 0 || $('img[title="Thoát [ ronglun227 ]"]').length !== 0) {
        var b = $('.top-stick');
        if (b.length) b[0].innerHTML = b[0].innerHTML + a + '<br>';
    }
};
//id jump for tab
var idjump = function(input) {
    var hash, target_tab, first_match_value, first_match, third_match, z, len;
    var value = true;
    //Extract hash id
    hash = /#(.*)/.exec(input);
    //If the id is insde the page itself, prevent page changing
    if (hash !== null) {
        if (window.location.pathname === input.replace('#' + hash[1], '')) value = false;
        hash = hash[1];
        first_match = $('#' + hash);
        third_match = $('#tab' + hash); //Button have special id
        //If not found any id, return
        if (first_match.length || third_match.length) first_match = first_match.eq(0);
        else return value;
        first_match_value = first_match.attr('value');
        //Active bluebox for in-page toolentip
        if (first_match_value === 'tipin') {
            $('span[value="tipin"]').css({
                'border-bottom': '0px solid blue',
                'padding': '0px'
            });
            first_match.css({
                'border-bottom': '4px double blue',
                'padding': '1px'
            });
        }
        //Deactive bluebox
        if (first_match_value === 'tipout' && first_match.hasClass('customid')) {
            $('span[value="tipin"]').css({
                'border-bottom': '0px solid blue',
                'padding': '0px'
            });
        }
        //For normal tab
        //If normal tab has id, open it
        var group = first_match.attr('data-tab-group'),
            index = first_match.attr('data-tab-index');
        $('.basictabbutton[data-tab-button-group="' + group + '"][data-tab-button-index="' + index + '"]').trigger('click');
        //If link contain hash id is inside a closed tab and the id has property force, open it
        var second_match;
        if (first_match_value === 'force') {
            second_match = first_match.parents('.basictab').eq(0);
            if (second_match.length) {
                group = second_match.attr('data-tab-group');
                index = second_match.attr('data-tab-index');
                $('.basictabbutton[data-tab-button-group="' + group + '"][data-tab-button-index="' + index + '"]').trigger('click');
            }
        }
        //For itab
        //Try searching id
        var temp_key;
        //If found
        //Try searching for itab
        first_match_value = first_match.attr('data-tab');
        //If not, try searching for id that have force property
        //If found, get the tab that contain it
        if (first_match_value === undefined) {
            if (first_match.attr('value') === 'force' && first_match.hasClass('customid') === true) {
                //Check if cannot found any tab contain it
                second_match = first_match.parents('.tab');
                if (second_match.length === 0) console.log('Not found');
                else {
                    second_match = second_match.eq(0);
                    group = second_match.attr('data-tab');
                    index = second_match.attr('data-key').split(',')[1]; //Bypass the first key, which is empty
                    temp_key = ',' + group + '#' + index + ',';
                    $('.button[data-button="' + group + '"][data-key*="' + temp_key + '"]').eq(0).trigger('click');
                }
            }
        } //If found
        else {
            group = first_match.attr('data-tab');
            index = first_match.attr('data-key').split(',')[1]; //Bypass the first key, which is empty
            temp_key = ',' + group + '#' + index + ',';
            $('.button[data-button="' + group + '"][data-key*="' + temp_key + '"]').eq(0).trigger('click');
        }
        //Try searching ibut
        if (third_match.length) {
            third_match.eq(0).trigger('click');
        }
    }
    //Final return to prevent page changing
    return value;
};
//Validator, change all additional class into authority class
var u_validator = function(input_class, authority) {
    authority = authority + '_'; //Format matching
    var cla, e, class_string, len;
    //Test for input
    for (;
        /#<#/.test(input_class) === true;) {
        e = '';
        class_string = /#<#(.[^>]* )#>#/.exec(input_class);
        class_splited = class_string[1].split(' '), len = class_splited.length;
        //Start compiling from the second class, the first element is blank
        for (var i = 1; i < len; i++) {
            cla = class_splited[i];
            if (cla !== '') e = e + authority + cla + ' ';
        }
        //Replace
        input_class = input_class.replace(class_string[0], e);
    }
    return input_class;
};
//Global variable
var globalstyle = '',
    u_t = 0;
u_time = {};
var bbcode = [ //Precode
	{
        //Wiki usage - Tool
        'name': 'tipout',
        'single': true,
        'replace': '[id="cr[#TIPOUT]" type="tipout"][tip="#ob#[#TIPOUT]#cb#" link="#ct[#TIPOUT]" type="center" class="tip"][import="ct[#TIPOUT]"][/tip][/id]',
        'value': [
            ['TIPOUT', '0']
        ]
    }, {
        //Wiki usage - Tip
        'name': 'tipin',
        'replace': '[id="ct[#TIPIN]" type="tipin"]<span class="tipin tipin[#TIPIN]"></span> [export="ct[#TIPIN]"][#CONTENT][/export][/id]',
        'value': [
            ['TIPIN', '0']
        ]
    },  //Basic BBCode
	{
        'name': 'b',
        'replace': '<strong>[#CONTENT]</strong>'
    }, {
        'name': 'i',
        'replace': '<i>[#CONTENT]</i>'
    }, {
        'name': 'u',
        'replace': '<u>[#CONTENT]</u>'
    }, {
        'name': 'left',
        'replace': '<div align="left">[#CONTENT]</div>'
    }, {
        'name': 'right',
        'replace': '<div align="right">[#CONTENT]</div>'
    }, {
        'name': 'center',
        'replace': '<div align="center">[#CONTENT]</div>'
    }, {
        'name': 'justify',
        'replace': '<div align="justify">[#CONTENT]</div>'
    }, {
        'name': 'hr',
        'single': true,
        'replace': '<hr>'
    }, {
        'name': 'url',
        'replace': '<a href="[#%URL]" target="_blank" rel="nofollow" onclick="idjump($(this).attr(&quot;href&quot;))">[#CONTENT]</a>'
    }, {
        'name': 'size',
        'replace': '<span style="font-size: [#%SIZE]px; line-height: normal">[#CONTENT]</span>'
    }, {
        'name': 'font',
        'replace': '<font face="[#%FONT]">[#CONTENT]</font>'
    }, {
        'name': 'color',
        'replace': '<font color="[#%COLOR]">[#CONTENT]</font>'
    }, {
        'name': 'img',
        'replace': '<img src="[#CONTENT]">'
    }, {
        'name': 'table',
        'replace': '<table align="[#ALIGN]" bgcolor="[#BGCOLOR]" cellpadding="[#CELLPADDING]" cellspacing="[#CELLSPACING]" frame="[#FRAME]" rules="[#RULES]" summary="[#SUMMARY]" width="[#WIDTH]" border="[#BORDER]" style="[#STYLE]" class="none [#CLASS]" id="[#ID]"><tbody>[#CONTENT]</tbody></table>'
    }, {
        'name': 'tr',
        'replace': '<tr align="[#ALIGN]" bgcolor="[#BGCOLOR]" char="[#CHAR]" charoff="[#CHAROFF]" valign="[#VALIGN]" style="[#STYLE]" class="none [#CLASS]" id="[#ID]">[#CONTENT]</tr>'
    }, {
        'name': 'td',
        'replace': '<td abbr="[#ABBR]" align="[#ALIGN]" axis="[#AXIS]" bgcolor="[#BGCOLOR]" char="[#CHAR]" charoff="[#CHAROFF]" headers="[#HEADERS]" height="[#HEIGHT]" scope="[#SCOPE]" valign="[#VALIGN]" width="[#WIDTH]" colspan="[#COLSPAN]" rowspan="[#ROWSPAN]" style="[#STYLE]" class="none [#CLASS]" id="[#ID]">[#CONTENT]</td>'
    }, { //Advance BBCode
        //Create div
        'name': 'box',
        'replace': '<div style="[#BOX]; [#STYLE]" class="#<# [#CLASS] #># brclearall">[#CONTENT]</div>',
        'validation': u_validator
    }, {
        //New line
        'name': 'br',
        'single': true,
        'replace': '<br>'
    }, {
        //Invisible box
        'name': 'metabox',
        'replace': '<div style="display: none">[#CONTENT]</div>'
    }, {
        //Create span
        'name': 'ibox',
        'replace': '<span style="[#IBOX];[#STYLE]" class="#<# [#CLASS] #>#">[#CONTENT]</span>',
        'validation': u_validator
    }, {
        //BBcode usage - Code box
        'name': 'cbox',
        'replace': '<div class="cbox brclear">[#CONTENT]</div>'
    }, {
        //Striking text
        'name': 's',
        'replace': '<strike>[#CONTENT]</strike>'
    }, {
        //Overline text
        'name': 'o',
        'replace': '<span style="text-decoration: overline">[#CONTENT]</span>'
    }, {
        //Upper tip
        'name': 'upp',
        'replace': '<ruby><rb>[#CONTENT]</rb><rp>(</rp><rt>[#UPP]</rt><rp>)</rp></ruby>'
    }, {
        //Hash id
        'name': 'id',
        'replace': '<span class="customid" id="[#ID]" value="[#TYPE]">[#CONTENT]</span>'
    }, {
        //Set title
        'name': 'title',
        'replace': '<span title="[#TITLE]" class="title_span">[#CONTENT]</span>'
    }, {
        //Space
        'name': 'space',
        'single': true,
        'replace': '<span style="padding: 0px [#SPACE] 0px 0px"></span>',
        'value': [
            ['SPACE', '30px']
        ]
    }, {
        //Indent
        'name': 'indent',
        'replace': '<div class="brclear" style="padding: 0px ' + '[#INDENT];">[#CONTENT]</div>',
        'value': [
            ['INDENT', '30px']
        ]
    }, {
        //Clear
        'name': 'clear',
        'single': true,
        'replace': '<div style="clear: both"></div>'
    }, {
        //Header 1
        'name': 'hs1',
        'replace': '<div class="hs1x"><span class="hs1" id="[#ID]" value="[#AT]_[#TOC]_head"><strong>※ [#CONTENT]</strong></span></div>',
        'value': [
            ['ID', 'header']
        ]
    }, {
        //Header 2
        'name': 'hs2',
        'replace': '<span class="hs2" id="[#ID]" value="[#AT]_[#TOC]_head"><strong>≫ [#CONTENT]</strong></span>',
        'value': [
            ['ID', 'header']
        ]
    }, {
        //Header 3
        'name': 'hs3',
        'replace': '<span class="hs3" id="[#ID]" value="[#AT]_[#TOC]_head"><strong>&gt;</strong> <u>[#CONTENT]</u></span>',
        'value': [
            ['ID', 'header']
        ]
    }, {
        //Header 4
        'name': 'hs4',
        'replace': '<span class="hs4" id="[#ID]" value="[#AT]_[#TOC]_head"><strong>&gt;</strong> <u>[#CONTENT]</u> <strong>&lt;</strong></span>',
        'value': [
            ['ID', 'header']
        ]
    }, {
        //Table of content
        'name': 'toc',
        'single': true,
        'replace': '<div class="tableofcontent" value="[#AT]_[#TOC]"></div>'
    }, {
        //Weak hide
        'name': 'ihide',
        'replace': '<div class="noguest">[#CONTENT]</div>'
    }, {
        //Jump
        'name': 'j',
        'replace': '<a href="[#J]" onclick="idjump($(this).attr(&#34;href&#34;))">[#CONTENT]</a>',
        'value': [
            ['J', '#']
        ]
    }, {
        //Wiki usage - Current link
        'name': 'current',
        'single': true,
        'replace': '<span class="current" data-hash="[#ID]"></span>'
    }, {
        //Wiki usage - Reference
        'name': 'r',
        'replace': '<a class="unlink" data-hash="[#P]" title="Trang chưa được viết" value="[#R]" targer="_blank" rel="nofollow">[#CONTENT]</a>'
    }, {
        //Wiki usage - Gallery image
        'name': 'igal',
        'replace': '<span class="wgal" value="[#IGAL]"><span class="wimage"><a  href="[#LINK]" target="_blank" rel="nofollow"><img src="[#IMG]"></a></span><span class="wtext">[#CONTENT]</span></span>',
        'value': [
            ['LINK', '#'],
            ['IGAL', 'u_0']
        ]
    }, {
        //Wiki usage - Gallery box
        'name': 'gallery',
        'single': true,
        'replace': '<div style="width: 100%" class="wikigallery" value="[#GALLERY]"></div>',
        'value': [
            ['GALLERY', 'u_0']
        ]
    }, {
        //Wiki usage - Database
        'name': 'wikibase',
        'single': true,
        'replace': '<div class="wikimain" type=[#WIKIBASE]></div>',
        'value': [
            ['WIKIBASE', '0']
        ]
    }, {
        //Custom style
        'name': 'style',
        'replace': '.[#AT]_[#STYLE] {[#CONTENT]}',
        'validation': function(input_style) {
            var b = input_style.match(/{|}/g);
            if (b !== null && b.length > 2) return input_style = false;
            input_style = input_style.replace(/<[^<>]*br[^<>]*>/g, ' ').replace(/<a[^<>]*>/g, '').replace(/<\/a[^<>]*>/g, '');
            globalstyle = globalstyle + input_style;
            return input_style = '';
        }
    }, {
        //Custom table style
        'name': 'tablestyle',
        'replace': 'table.[#TABLESTYLE] {[#CONTENT]}',
        'validation': function(input_style) {
            var b = input_style.match(/{|}/g);
            if (b !== null && b.length > 2) return input_style = false;
            input_style = input_style.replace(/<[^<>]*br[^<>]*>/g, ' ').replace(/<a[^<>]*>/g, '').replace(/<\/a[^<>]*>/g, '');
            globalstyle = globalstyle + input_style;
            return input_style = '';
        }
    }, {
        //Wiki color style
        'name': 'wikistyle',
		'single': true,
        'replace': '<div class="wikistyle">[#WIKISTYLE]</div>',
		'value': [
			['WIKISTYLE', 'blue']
		]
    }, {
        //Export content
        'name': 'export',
        'replace': '<div class="exportdiv" value="[#AT]_[#EXPORT]" title="[#TYPE]">[#CONTENT]</div>'
    }, {
        //Import content
        'name': 'import',
        'single': true,
        'replace': '<div class="importdiv" value="[#AT]_[#IMPORT]"></div>'
    }, { //Tip
        'name': 'tip',
        'replace': '<div style ="[#STYLE]" class="brclear tip normaltip tipstore #<# [#CLASS] #>#" value="[#TIP]" data-link="[#LINK]" data-type="[#TYPE]" data-tip-key=",[#AT]_[#KEY]," [##CLICK]>[#CONTENT]</div>',
        'value': [
            ['LINK', '#'],
            ['TIP', '(?)'],
            ['KEY', '!']
        ],
        'validation': u_validator
    }, { //Tool
        'name': 'tool',
        'replace': '<div class="brclear tip tipbox">[#CONTENT]</div>'
    }, { //Itip
        'name': 'tips',
        'replace': '<div class="brclear GSKtip" data-link="[#LINK]" data-tip-key=",[#AT]_[#KEY]," [##CLICK]>[#CONTENT]</div>',
        'value': [
            ['LINK', '#'],
            ['KEY', '!']
        ]
    }, {
        //Soundcloud
        'name': 'soundcloud',
        'single': true,
        'replace': '<object height="[#HEIGHT]" width="[#WIDTH]"><param name="movie" value="http://player.soundcloud.com/player.swf?url=[#SOUNDCLOUD]&amp;g=bb"></param><param name="allowscriptaccess" value="always"></param><embed allowscriptaccess="always" height="81" src="http://player.soundcloud.com/player.swf?url=[#SOUNDCLOUD]&amp;g=bb" type="application/x-shockwave-flash" width="100%"></embed></object>',
        'value': [
            ['WIDTH', '250px'],
            ['HEIGHT', '81px']
        ]
    }, {
        //Itab button
        'name': 'ibut',
        'replace': '<div class="brclearall brclear button #<# [#CLASS] #># {{ butoff }} " style="[#STYLE]; style-switch;  ;style-switch;" data-authority="[#AT]" data-status="off" [##COLLAPSE] data-button="[#AT]_[#IBUT]" data-key=",[#KEY]," data-style-on="[#STYLE-ON]" data-style-off="[#STYLE-OFF]" data-class-on="buton #<# [#CLASS-ON] #>#" data-class-off="butoff #<# [#CLASS-OFF] #>#" id="tab[#ID]" [##DISABLE]>[#CONTENT]</div>',
        'validation': u_validator
    }, {
        //Itab tab
        'name': 'itab',
        'replace': '<div class="brclearall brclear tab tabdeact #<# [#CLASS] #>#" data-authority="[#AT]" data-status="off" data-open="[#OPEN]" style="[#STYLE]" data-key=",[#KEY]," data-tab="[#AT]_[#ITAB]" id="[#ID]">[#CONTENT]</div>',
        'validation': u_validator
    }, {
        //Normal tab
        'name': 'tab',
        'replace': '<div class="brclearboth basictab" data-tab-name="[#TAB]" id="[#ID]" style="position: relative; z-index: 1">[#CONTENT]</div>',
        'value': [
            ['TAB', '---']
        ]
    }, {
        //Normal tab box
        'name': 'tabs',
        'replace': '<div class="basictabs"><div class="brclear basictablist" style="position: relative; z-index: 2; top: 1px"></div><div class="basictabcontent">[#CONTENT]</div></div>'
    }, {
        //Remove profile
        'name': 'noprofile',
        'single': true,
        'replace': '<div style="display: none" class="noprofile"></div>'
    }, {
        //Load html
        'name': 'load',
        'replace': '<div class="bbcode_load" id="load[#PERMALINK]" value="[#SOURCE] [#ID] [#AT]" data-load-type="[#TYPE]" data-load-key="[#KEY]" [##AUTO] [##IFRAME] [##EXPIRE]>[#CONTENT]</div>',
        'value': [
            ['PERMALINK', 'load'],
            ['SOURCE', 'blank']
        ]
    },{
		//For permalink
		'name': 'permalink',
		'single': true,
		'replace': '<textarea class="bbcode_load_update" style="[#STYLE]" class="#<# [#CLASS] #>#"></textarea>',
		'validation': u_validator
	}, {
        //List indicator
        'name': 'b1',
        'single': true,
        'replace': '•'
    }, {
        //List indicator
        'name': 'b2',
        'single': true,
        'replace': '◦'
    }, {
        //List indicator
        'name': 'b3',
        'single': true,
        'replace': '‣'
    }, {
        //Style - [
        'name': 'ob',
        'single': true,
        'replace': '['
    }, {
        //Style - ]
        'name': 'cb',
        'single': true,
        'replace': ']'
    }, {
        //Game - Map
        'name': 'map',
        'single': true,
        'replace': '<div class="map" value="[#MAP]"></div>'
    }, {
        //Game - Player
        'name': 'player',
        'single': true,
        'replace': '<table class="cell player brclear" value="[#PLAYER]-[#ID]-[#POS]"></table>'
    }
];
var bblength = bbcode.length;
//Quick compare
var comparearray = [];
var u_compare = function(a) {
    var u = comparearray.length;
    for (var i = 0; i < u; i++) {
        if (a === comparearray[i]) return false;
    }
    comparearray.push(a);
    return true;
};
//Parse
var u_parse = function(prop_string, content, bbcode_object, authority) {
    var pattern, data_name, len, i;
    var reg_prop = /([\w-]*)="([^\]\["]*)"(\s)*/gi,
        reg_data;
    var output = bbcode_object.replace, //Get the form
        default_data = bbcode_object.value; //Get default data
    validator = bbcode_object.validation; //Get the validator
    //Fill basic bbcode property
    var reg_prop3 = /([\w-]*)=([^"]*)[\s|\]]/gi;
    for (; data_name = reg_prop3.exec(prop_string);) {
        if (data_name[0] !== undefined) {
            data_name[1] = data_name[1].toUpperCase();
            pattern = '\\[#%' + data_name[1] + '\\]';
            reg_data = new RegExp(pattern, 'gi');
            output = output.replace(reg_data, data_name[2]);
            prop_string.replace(data_name[0], '');
        }
    }
    //Fill single property
    var reg_prop2 = /([\w-]*)[\s|\]]/gi;
    for (; data_name = reg_prop2.exec(prop_string);) {
        if (data_name[0] !== undefined) {
            data_name[1] = data_name[1].toUpperCase();
            pattern = '\\[##' + data_name[1] + '\\]';
            reg_data = new RegExp(pattern, 'gi');
            output = output.replace(reg_data, 'data-' + data_name[1].toLowerCase() + '="true"');
            prop_string.replace(data_name[0], '');
        }
    }
    //Fill each normal property with respective data
    for (; data_name = reg_prop.exec(prop_string);) {
        if (data_name[0] !== undefined) {
            data_name[1] = data_name[1].toUpperCase();
            pattern = '\\[#' + data_name[1] + '\\]';
            reg_data = new RegExp(pattern, 'gi');
            //Replace entity [, ], ", :
            data_name[2] = data_name[2].replace(/#ob#/gi, '[').replace(/#cb#/gi, ']').replace(/#qu#/gi, '"').replace(/#cl#/gi, ':').replace(/\/#/gi, '#');
            output = output.replace(reg_data, data_name[2]);
            prop_string.replace(data_name[0], '');
        }
    }
    //Fill empty property with default data
    if (default_data !== undefined) {
        len = default_data.length;
        for (i = 0; i < len; i++) {
            pattern = '\\[#' + default_data[i][0] + '\\]';
            reg_data = new RegExp(pattern, 'gi');
            output = output.replace(reg_data, default_data[i][1]);
        }
    }
    //Fill content, authority and remove any other empty/error/undefined property
    output = output.replace(/\[#CONTENT\]/g, content).replace(/\[#AT\]/g, authority).replace(/\[#[A-Z0-9-]*\]/g, '');
    output = validator === undefined ? output : validator(output, authority);
    return output;
};
//Catching url and add idjump
var u_url_catch = function(parsing_post, mode) {
    var content, href;
    var i, target, ouput, p, q, len;
    var pattx = /(#link#)(https:\/\/[^<> \[\]"]*)/i;
    var patty = /(#link#)(http:\/\/[^<> \[\]"]*)/i;
    if (mode == 1) {
        parsing_post.find('a[title^="See all tagged"]').contents().unwrap();
    }
    target = parsing_post.find('a');
    len = target.length;
    //Check matching between href and content
    for (i = 0; i < len; i++) {
        content = target[i].textContent || target[i].innerText;
        href = target.eq(i).attr('href').replace('>', '&gt;').replace('<', '&lt;');
        //If matched, temporarily change
        if (content === href) {
            q = target.eq(i).text().replace(/http:\/\//g, '#link#http:\/\/').replace(/https:\/\//g, '#link#https:\/\/');
            target.eq(i).text(q);
            target.eq(i).contents().unwrap();
        }
        //If not, adding idjump
        else {
            target.eq(i).attr('onClick', 'idjump($(this).attr("href"))');
        }
    }
    //Replacement
    ouput = parsing_post.html();
    for (; pattx.test(ouput) === true;) {
        p = pattx.exec(ouput);
        ouput = ouput.replace(p[0], '<a href="' + p[2] + '" onClick="idjump($(this).attr(\'href\'))">' + p[2] + '</a>')
    }
    for (; patty.test(ouput) === true;) {
        p = patty.exec(ouput);
        ouput = ouput.replace(p[0], '<a href="' + p[2] + '" onClick="idjump($(this).attr(\'href\'))">' + p[2] + '</a>')
    }
    return ouput = ouput.replace(/[\r\n]*</g, '<');
};
//Remove line break
var u_unbr = function(parsing_post) {
    var target = parsing_post.find('.brclear');
    var i, o, len = target.length;
    var current_target;
    for (i = 0; i < len; i++) {
        current_target = target.eq(i);
        o = current_target.first();
        if (o.prop('tagName') === 'BR') o.remove();
        o = current_target.next();
        if (o.prop('tagName') === 'BR') o.remove();
        //current_target.removeClass('brclear');
    }
    target = parsing_post.find('.brclearboth');
    len = target.length;
    for (i = 0; i < len; i++) {
        current_target = target.eq(i);
        o = current_target.first();
        if (o.prop('tagName') === 'BR') o.remove();
        o = current_target.last();
        if (o.prop('tagName') === 'BR') o.remove();
        o = current_target.next();
        if (o.prop('tagName') === 'BR') o.remove();
        o = current_target.prev();
        if (o.prop('tagName') === 'BR') o.remove();
        //current_target.removeClass('brclearboth');
    }
	/*
    target = parsing_post.find('.brclearall');
    len = target.length;
    var j;
    for (i = 0; i < len; i++) {
        current_target = target.eq(i).children();
        j = 0;
        while (1) {
            o = current_target.eq(j);
            j++;
            if (o.prop('tagName') === 'BR') o.remove();
            else break;
        }
        current_target.removeClass('brclearall');
    }
	*/
};
//Emoticon
var u_emo = function(a) {
    var i, regex, pattern;
    var alice = ["7KFew9hl", "QtrHMqVo", "13xb8AFA", "uqWh5mnf", "EGRg0IKK", "dtbi0bKw", "U6KyY49B", "QbKTYxTX", "avEdQhvs", "jpk2tSo9", "JHZD5fx3", "8RNb8UTo", "sY3jG79k", "FB4ROyKL", "6DX9lVxL", "p3HAtZRf", "URFBOVVl", "fYtkP31p", "058mpVab", "bgeTX1nY"],
        l1 = alice.length;
    for (i = 1; i <= l1; i++) {
        pattern = ':alice' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + alice[i - 1] + '.jpg">')
    }
    var maribel = ["s9ydYuyg", "IdWFV9so", "y2Jp810r", "yXddLUL8", "8P9xnBF9", "xQh9i1wY", "xjFekUrR", "veTYwfN1", "3pGU56Tn", "J4ouJfsK", "b9GgolPe", "UxBByBnK", "iLVL2KqL", "iDxhVR4r", "kXH5hTkX", "rJUC0xpD", "AXHkinp9", "I8RFwcGA", "JQsAufAH", "LrTVnKQb", "uam8VK9c", "sFMX2A7k", "7CbZF2PG", "t3visfpq", "WPrR5abf", "9pCBcKTP", "EkkNPu38", "naiExnZw", "45dJtFio", "nYVqrAc7", "ARGKA7xF", "Wx7OvMIw"],
        l2 = maribel.length;
    for (i = 1; i <= l2; i++) {
        pattern = ':maribel' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + maribel[i - 1] + '.jpg">')
    }
    var myon = ["EHEGan58", "MK8OYLKK", "WCwOxsuB", "6pl89VFE", "lucJmLmI", "b022wE6k", "K3PdVzHf", "ik2lE5Ah", "B4E5vYbO", "eyH0nSgn", "vYuXNT8f", "0oECPGbi", "ftKfXNMd", "CR5IsBKi", "xQNvzQVa", "v2lqXzTZ", "udVD7c87", "A9njI7hw", "NmBeFJdB", "XVBanN2L", "XujETqAW", "wFaxdBPr", "AubfX3TU", "9ulVExb7", "LljsT9gy", "2oZyg8sq", "QP6GECgy", "Fx9motOC", "vRKAOAJV", "A30eKjpp", "u0xRHZhR", "OcvghHPc", "gKuNJQJ7", "pJgHHchU", "UBiPVMwY"],
        l3 = myon.length;
    for (i = 1; i <= l3; i++) {
        pattern = ':myon' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + myon[i - 1] + '.jpg">')
    }
    var renko = ["F8T1Dfml", "SIdb87d0", "xMqEem85", "nmgjeSiG", "Eny2CksP", "CCllMLWE", "INh9VIJr", "xNWVoCkD", "qufxCFyI", "VkG99mkm", "9t03Qa8c", "qLgRQRY8", "mAn9KHLf", "Ainffk9j", "EA25awvR", "8iMSm6o1", "iyDU4LNU", "XC7WOfmX", "dvW438Ya", "YnoxXcx3", "ILFSHGTl", "P5R19736", "pTZ5qYbA", "uUoeow38", "sFwajvsV", "9OHTxzdy", "sxLBHUNc", "wQBKBYPc", "puqAnM23", "4dgTiSQl", "BD9ET7qI", "9POlgtqm"],
        l4 = renko.length;
    for (i = 1; i <= l4; i++) {
        pattern = ':renko' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + renko[i - 1] + '.jpg">')
    }
    var shou = ["XWrgnt9n", "ik7wpHnL", "A1jE16Eo", "tDiSLMxI", "BgNFgGTv", "t0G68Nti", "Fws59hqR", "sPz5TSnZ", "fnL6El3v", "KQ2l9zEe", "tpM83dBS", "taA9GfsQ", "KbFCvzNv", "sQLuIOkA", "QF1llXVo", "gzoYkySO", "ahBmdit5", "YYm5ZJGI", "9970HR1P", "e6Z5etbA", "Qt5m6ZBU", "8dUwcv3G", "X8vkaj8U", "ZM1gvp6X", "ECGmgqt5", "3BwEmlRi", "2wFHxNWz", "QAbOhSHY", "EI6iVuCa", "Ax5ZAVxm"],
        l5 = shou.length;
    for (i = 1; i <= l5; i++) {
        pattern = ':shou' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + shou[i - 1] + '.jpg">')
    }
    var garena = ["HUOHgWQy", "agt9UhqD", "Rbc6wpjQ", "IwAXAJCd", "TEXqxYvS", "XTDUpUvR", "zqxLbM0R", "f1A2V0B5", "Hk71L23S", "hRwtjvgZ", "lDYnX5hf", "O0B8C4KG", "qpZQhEAz", "oRgNvhqC", "Wc2mo3yz", "yg6EUFzm", "qK4gydNn", "PVhNXBzf", "sIR1YQr3", "jRaEiAYv", "f4EDiuld", "plrs7Q22", "LWYcocWK", "MoRUava2", "dbCyvgnn", "QBJDdleV", "TnZX9pT6", "LGNHwGhe", "PGdDd7m2", "51VJndOk", "4fWTSxti", "E1jrUOzX", "Dghin1sp", "xXODvkMW", "pHaJEHeP", "6LuQSDCQ", "UGlSKiAF", "cope758E", "FkNPXHSl", "QftLVRk9", "34Q8zuFP", "V1bbKWBn", "xiDBk0fs", "JzXh5BUa", "CmXbNTB4", "bTv2UOTt", "ityQD3QG", "8K317BtZ", "2ITdE4RD", "YySA9Rxh", "vrYlo3md", "P0gRFXst", "2oLntCCG", "fOSHi8NA", "LjdlQCQj"],
        l6 = garena.length;
    for (i = 1; i <= l6; i++) {
        pattern = ':g' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + garena[i - 1] + '.jpg">')
    }
    var tewi = ["ngUtJEv3", "vk2QLHF2", "7kkPQWoR", "WKQIBLe9", "9HRUFqrX", "5nGTSjve", "fc7wmDaF", "3PZ8P99a", "1MqWUR2W", "hdhAAj9f", "smUcJG4u", "AGRQOk8j", "dcDHojG7", "Dq48XYfi", "PunOAXq9", "fhssZG8E", "Wg6fDqT9", "UEVlSveA", "sBiyvf9m", "3fcVSSGK", "mz3NINsB", "VsbV9yBK", "ilCifJTV", "lRaJ91zn", "SRO6MFGM", "klB2jW1m", "RkR4ZRwY", "v3OfYMpF", "NhhzvM6s", "VVv7y7rL", "CN5euVP1", "viN87A2W", "deZ4my7D", "opn7smPq", "ro13wf0g"],
        l7 = tewi.length;
    for (i = 1; i <= l7; i++) {
        pattern = ':tewi' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + tewi[i - 1] + '.jpg">')
    }
    var xtewi = ["Ha5gxOJp", "F2dkWoBc", "hm3GI2la", "qrX1czpV", "ay0ZX1FT", "GvR974zT", "2FdSQrw0", "Y5BeYdvv", "SZzQcnio", "pPPIRDoI", "gz4ka3yv", "2DTnUUUa", "70g9esmi", "aCNUYoPf", "qdTnBC77", "lfDd922j", "IVoh2HhF", "IcjVcoaw", "p4bRSUG8", "WZfpjmh0", "RLuQwCck", "tQIWB8HX", "aHaSDAtg", "03h0ehXt", "d5vuWfgW", "88fXvvJV", "glVwvHOT", "0DgvUawK", "6FBDBcOb", "wI0RxCKP", "okqHMeY9", "DY89PSEp", "EqWXpQ43"],
        l8 = xtewi.length;
    for (i = 1; i <= l8; i++) {
        pattern = ':xtewi' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + xtewi[i - 1] + '.jpg">')
    }
    var youmu = ["xXol8wJ1", "MVuqjbSd", "6cW93Fz6", "stKp8ui4", "6eYVJwUw", "8FyS5xiQ", "mNsnR0qI", "h1p52MIz", "vqm45rkM", "tj6RjNHD", "aSTmqzyr", "RzCouRqu", "jqjxFWoE", "8I51jukA", "CcvL0VP8", "PmyBLiOj", "ABTkDSfU", "8Beknvr7", "Zsjl3ee9", "F0rY2UpJ", "MNNrBCVf", "5yL6q6m5", "31xKYEuI", "vTfysRcJ", "KsfRC08S", "D2HFWYXS", "8v7HrDBO", "oWh01TzH", "0SVUlCAX", "ZfKn1xZk", "htYCUkYC", "IQAeskrr", "egyymzhc", "IMG8wBzz", "WdAZgemg"],
        l9 = youmu.length;
    for (i = 1; i <= l9; i++) {
        pattern = ':youmu' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + youmu[i - 1] + '.jpg">')
    }
    var yuuka = ["i9uqbjxJ", "xURx8Pmy", "RrPVfsaI", "zG1PRgbu", "Tjb05Ndq", "BidxQp5e", "IqZF6aA1", "dHqcRbjl", "ztQ3eT7a", "kZUtRnvd", "oaWodar0", "qi4hUHii", "gPrEzSyc", "zIkZZH4o", "fqcldP5O", "FH7JMTi8", "7zgkB9gk", "VCLEICtd", "QYcXlKt9", "sHEeWYiJ", "fccD1Rmz", "CNc14sOZ", "7WjnwOMm", "3Q8lHx9T", "zjNKmqkf", "Af20x9Gn", "yWLVB45S", "qRmzS55J", "YF6ck6rQ", "CvOUNcQE", "yoH66gMf"],
        l10 = yuuka.length;
    for (i = 1; i <= l10; i++) {
        pattern = ':yuuka' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + yuuka[i - 1] + '.jpg">')
    }
    var other = ["Mj38oJRU", "3dXPK03u", "8OGzM5p2", "A69q7WsQ", "PtC0hVEE", "jAxTRigj", "rHKNOzMK", "jBjmZ9hY", "jgN2MS0o", "1m4VtODV", "ZyIcH0XU", "aRnQB0m0", "yOxrM5I3", "rYX74j8F", "j7x6pUZV", "cu69Kv5j", "qlgozIAM", "DA7nh7gu", "AjwETLXa"],
        l11 = other.length;
    for (i = 1; i <= l11; i++) {
        pattern = ':th' + i + ':';
        regex = new RegExp(pattern, 'gi');
        a = a.replace(regex, '<img src="http://i.imgbox.com/' + other[i - 1] + '.jpg">')
    }
    return a;
};
//Jump tab by hash
var u_jumptab = function(key) {
    //Main key: A key defining a group of tab
    //Weak key: A key defining an index of many group of tab
    var tab = $('.buton[value="' + key + '"]'),
        s_matched_weak_tab, weak_tab, main_key, len, weak_key, u, matched_weak_tab;
    //Get primary key
    main_key = /([^,]*,)/.exec(key)[1];
    weak_tab = $('.buton[value^="' + main_key + '"]');
    //If found, toggle that tab
    if (tab.length) {
        tab.eq(0).trigger('click');
    } else if (weak_tab.length) {
        weak_key = key.replace(main_key, ',') + ',';
        len = weak_tab.length;
        //Find in another tabs with the same primary key, toggle the first matched
        for (var i = 0; i < len; i++) {
            matched_weak_tab = weak_tab.eq(i);
            u = matched_weak_tab.attr('value') + ',';
            if (u.search(weak_key) !== -1) {
                matched_weak_tab.trigger('click');
                break
            }
        }
        //Find in another tabs contain the same primary key, toggle the first matched
        main_key = key.replace(/(_[^,_]*,)/.exec(key)[1], '#');
        s_matched_weak_tab = $('.buton[value*=",' + main_key + ',"]');
        if (s_matched_weak_tab.length) {
            s_matched_weak_tab.eq(0).trigger('click')
        }
        //Find in another tabs end with the same primary key, toggle the first matched
        else {
            s_matched_weak_tab = $('.buton[value$=",' + main_key + '"]');
            if (s_matched_weak_tab.length) {
                s_matched_weak_tab.eq(0).trigger('click')
            }
        }
    }
};
//Load bbcode
var bbcode_load_by_hash = function(hash) {
    var des = $('#load' + hash.substring(1, hash.length)).eq(0);
    if (des.length === 0) return;
    des.trigger('click');
	des.children('.button').eq(0).trigger('click');
};
var bbcode_load_by_param = function() {
    var target = param['load'];
	var type = param['type'];
	var key = param['key'];
	if(target !== undefined || key !== undefined || type !== undefined) {
    	var des = $('#load' + target).eq(0);
    	if (des.length === 0) {
			var des = $('.bbcode_load[data-load-key="' + key + '"][data-load-type="' + type + '"]').eq(0);
			if (des.length === 0) return;
			else {
				des.trigger('click');
				des.children('.button').eq(0).trigger('click');
			}
		}
	}
};
var bbcode_load_update = function(target){
	var value, key, type;
	key = target.attr('data-load-key');
	type = target.attr('data-load-type');
	if(key.length !== 0 || key !== undefined){
		$('.bbcode_load_update').val(window.location.protocol + '\/\/' + window.location.hostname + window.location.pathname + '?key=' + key + '&type=' + type + '#wikimain');
	} else {
		value = target.attr('id');
		value = value.substring(4,value.length);	
		$('.bbcode_load_update').val(window.location.protocol + '\/\/' + window.location.hostname + window.location.pathname + '?load=' + value + '#wikimain');
	}
};
var bbcode_recursive = function(key, root, content){
    setTimeout(function(){
		if(bbcode_recursive_in > 0){
			bbcode_recursive_in++;
			if(bbcode_recursive_in > 6){
				content.html('<div style="text-align: center; font-size: 20px; font-weight: bold">Không tải được dữ liệu</div>');
				return;
			}
            if(root !== undefined) root = root[key];
            if (root !== undefined) {
				bbcode_recursive_in = 0;
                content.html(root);
                gskbb(content);
            } else bbcode_recursive(key, root, content);
		}
   },500);
};
var bbcode_recursive_in = 0;
var bbcode_load = function(target) {
	if(target.attr('data-expire') === 'true'){
		target.attr('data-expire','false');
	} else if(target.attr('data-expire') === 'false') return;
	bbcode_load_update(target);
    var content, t = target.attr('value').split(' ');
    var des = $('#' + t[1]),
        len = des.length;
    for (var i = 0; i < len; i++) {
        content = des.eq(i);
        if (t[2] !== 'u16' && t[2] !== 'u1') {
            content.html('<div align="center">Bạn không có quyền thực hiện lệnh này.</div>');
            return;
        }
        content.html('<div align="center"><img src="http:\/\/i.imgbox.com\/9C7jzlzN.gif"></div>');
    }
    var type = target.attr('data-load-type');
    var key = target.attr('data-load-key');
    var root;
    if (type.length !== 0) {
        root = window[type];
        if (root !== undefined) {
			if(bbcode_recursive_in === 0){
				bbcode_recursive_in = 1;
				bbcode_recursive(key, root, content);
			}
        }
    } else {
        if (target.attr('data-iframe') === 'true') {
            content.html('<iframe style="width: 100%; height: 100%; border-width: 0px" src="' + t[0] + '">Trình duyệt không hỗ trợ</iframe>');
        } else $.get(t[0]).done(function(data) {
            content.html(data);
        }).fail(function(data) {
            content.html('<div align="center" style="font-weight: bold">Lỗi không tải được dữ liệu</div>');
        });
    }
};
//Main gskbb
var post_parsing = function(target, postmode) {
    var content = '';
    //Get authority
    var authority = target.parents('.post').find('a.profile-icon').eq(0).attr('href');
    if (authority === undefined) authority = 'u1';
    else authority = authority.substring(1, authority.length);
    //Store content in 'code' tag
    var code = [];
    var tag_code = target.find('code'),
        tag_code_length = tag_code.length;
    for (var stack_count = 0; stack_count < tag_code_length; stack_count++) {
        code.push(tag_code[stack_count].innerHTML);
        tag_code[stack_count].innerHTML = '';
    }
    //Catch link
    content = u_url_catch(target, postmode);
    //Replace space entity
    content = content.replace(/&#160;/gi, ' ');
    //Bbcode adding
    var code_name = '';
    var stack_index, in_use, matched;
    var tag_count = 0;
    stack_count = 0;
    var stack = [],
        tag_catched = [];
    var pattern, pattern2, regex, regex2;
    stack_index = undefined;
    //Start parsing for each bbcode
    for (var i1 = 0; i1 < bblength; i1++) {
        tag_count = stack_count = 0;
        tag_catched = [];
        in_use = bbcode[i1];
        code_name = in_use.name;
        //If double
        if (in_use.single !== true) {
            //Generate regex
            pattern = '(\\[' + code_name + '=[^\\]]*\\])|(\\[' + code_name + '\\])|(\\[' + code_name + ' +[^\\]]*\\])|(\\[\\/' + code_name + '\\])';
            regex = new RegExp(pattern, 'i');
            //Loop until no match found
            for (; regex.test(content) === true;) {
                matched = regex.exec(content);
                //If tag found is closing tag
                if (matched[0].substring(0, 2) == '[/') {
                    stack_index = stack[stack.length - 1];
                    //If no more tag found in stack, return error tag, if have, insert space and index
                    if (stack_index === undefined) content = content.replace(matched[0], '[/error-' + code_name + ']');
                    else {
                        content = content.replace(matched[0], '[/' + stack_index + '&#160;' + code_name + ']');
                    }
                    //Pop out
                    stack.pop();
                } //If tag found is opening tag
                else {
                    //Insert space and index
                    content = content.replace(matched[0], '[' + stack_count + '&#160;' + code_name + ']');
                    //Push into index stack and content stack
                    tag_catched.push(matched[0]);
                    stack.push(stack_count);
                    //Increase stack index
                    stack_count++;
                    tag_count++;
                }
            }
            //Work with exceeding tag
            //Remove exceeding opening tag and replace by an error one
            for (stack_count = 0; stack_count < stack.length; stack_count++) {
                stack_index = stack[stack_count];
                stack.pop();
                content = content.replace('\[' + stack_index + '&#160;' + code_name + '\]', '[error-' + code_name + ']');
            }
            //Pass to html replacement
            for (stack_count = 0; stack_count < tag_count; stack_count++) {
                pattern2 = '\\[' + stack_count + '&#160;' + code_name + '\\]([^]*)\\[\\/' + stack_count + '&#160;' + code_name + '\\]';
                regex2 = new RegExp(pattern2, 'gi');
                matched = regex2.exec(content); //matched 1 contain inner content, matched 0 contain the whole content (code tag + inner content)
                if (matched !== null) content = content.replace(matched[0], u_parse(tag_catched[stack_count], matched[1], in_use, authority));
            }
        } //If single
        else {
            //Generate regex
            pattern = '(\\[' + code_name + '=[^\\]]*\\])|(\\[' + code_name + '\\])|(\\[' + code_name + ' +[^\\]]*\\])';
            regex = new RegExp(pattern, 'i');
            //Loop until no match found
            for (; regex.test(content) === true;) {
                matched = regex.exec(content);
                //Insert space and index
                content = content.replace(matched[0], '[' + stack_count + '&#160;' + code_name + ']');
                //Push into content stack
                tag_catched.push(matched[0]);
                tag_count++;
                stack_count++;
            }
            //Transfer
            for (stack_count = 0; stack_count < tag_count; stack_count++) {
                pattern2 = '(\\[' + stack_count + '&#160;' + code_name + '\\])';
                regex2 = new RegExp(pattern2, 'gi');
                matched = regex2.exec(content);
                if (matched !== null) content = content.replace(matched[0], u_parse(tag_catched[stack_count], ' ', in_use, authority));
            }
        }
    }
    //Set emoticon
    content = u_emo(content);
    //Completing
    target.html(content);
    //Insert back code
    tag_code = target.find('code');
    if (tag_code.length === code.length) {
        for (stack_count = 0; stack_count < tag_code.length; stack_count++) {
            tag_code[stack_count].innerHTML = code[stack_count]
        }
    } //Exceeding code return error
    else {
        for (stack_count = 0; stack_count < tag_code.length; stack_count++) {
            tag_code[stack_count].innerHTML = 'error'
        }
    }
    //Unbr
    u_unbr(target);
};
//Main starter
$(function() {
    //    u_time._1_start = performance.now();
    var blacklist = [],
        len_bl = blacklist.length,
        postmode = 0;
    var path = window.location.pathname;
    //When in post preview mode, hashtag is disabled
    if (path == '/post') postmode = 1;
    var group = $('.content, .signature_div');
    var len_target = group.length;
    //Deny execution if target is in blacklist
    for (var i1 = 0; i1 < len_bl; i1++)
        if (blacklist[i1] === path) throw new Error("GSKBB is denied!");
    for (i2 = 0; i2 < len_target; i2++) {
        target = group.eq(i2);
        //Execution: Parsing
        post_parsing(target, postmode);
    }
    $(resize_images({
        'selector': '.post .content',
        'max_width': 760,
        'max_height': 1500
    }));
    //    u_time._2_end_parsing = performance.now() - u_time._1_start;
});
//Other Bbcode
var module_other = function() {
    //Current
    var current = $('.current'),
        len = current.length;
    var target;
    var href;
    for (var i = 0; i < len; i++) {
        target = current.eq(i);
        if (target.attr('data-hash').length === 0) {
            href = window.location.protocol + '\/\/' + window.location.hostname + window.location.pathname;
            target.html('<a href="' + href + '" onClick="idjump($(this).attr(&quot;href&quot;))">' + href + '</a>');
        } else {
            href = window.location.protocol + '\/\/' + window.location.hostname + window.location.pathname + '#' + target.attr('data-hash');
            target.html('<a href="' + href + '" onClick="idjump($(this).attr(&quot;href&quot;))">' + href + '</a>');
        }
    }
	//Permalink
	$('.bbcode_load_update').on('focus',function(){
		$(this).select();
	}).on('mouseup',function(){
		return false;
	});
	//Title
	var title = $('.title_span'),
	    len = title.length;
	for (var i = 0; i < len; i++) {
		target = title.eq(i);
		if (target.attr('title').length === 0) target.attr('title', target.text());
	}
};
//Export and Import
var module_io = function() {
    var i, j, import_content, imp_val, exp_val;
    var imp = $('.importdiv'),
        imp_len = imp.length;
    var exp = $('.exportdiv'),
        exp_len = exp.length;
    for (var i = 0; i < imp_len; i++) {
        imp_val = imp.eq(i).attr('value');
        for (j = 0; j < exp_len; j++) {
            exp_val = exp.eq(j).attr('value');
            if (exp_val === imp_val) {
                import_content = exp.eq(j).html();
                imp.eq(i).html(import_content).removeClass('importdiv').css('display', 'inline-block');
                if (exp.eq(i).attr('title') === 'move') exp.eq(i).html('');
            }
        }
    }
};
//Weak hide
$(function() {
    var a = $('.noguest');
    var b = $('#i_icon_mini_login').parent().attr('href');
    if (!document.getElementById('logout')) {
        a.html('<div style="border: 2px solid black; align: center;">Xin hãy <a href="' + b + '">đăng nhập</a> hoặc <a href="/register">đăng ký</a> để xem nội dung ẩn</a></div>');
    }
});
//Load html
var module_load = function() {
    var a = $('.bbcode_load'),
        u, l = a.length;
    var t, per;
    for (var i = 0; i < l; i++) {
        u = a.eq(i);
        t = u.attr('value').split(' ');
        per = u.parents('.post').find('a.profile-icon').eq(0).attr('href');
        if (per === '\/u1' || per === '\/u16') {
            if (/^https?:\/\/www.gensokyovn.net/.test(t[0]) || /^https?:\/\/www.gskvn.forumvi.com/.test(t[0]) || t[0] === 'blank') {
                u.attr('onClick', 'bbcode_load($(this))');
            }
        }
        if (u.attr('data-auto') === 'true' && u.attr('data-load-type').length === 0) u.trigger('click');
    }
};
//No profile
$(function() {
    var a = $('.content'),
        target, len = a.length;
    for (var i = 0; i < len; i++) {
        target = a.eq(i);
        if (target.find('.noprofile').length == 0) continue;
        else {
            target = target.parents('.post');
            target.find('.postprofile').eq(0).hide();
            target.find('.postbody').eq(0).css('width', '100%');
        }
    }
});
//Database
var pmiss = {};
var sopm = {};
var database = function() {
    var b = $('.custom_css');
    if (b.length === 0) $('head').eq(0).append('<style type="text/css" class="custom_css">' + globalstyle + '</style>');
    else b.eq(0).html(globalstyle);
    var a = $('.wikimain[type="0"]');
    if (a.length > 0) {
        a.attr('id', 'wikimain');
        if ($('.custom_script[value="0"]').length === 0) $('head').eq(0).append('<script src="http://gskvn.forumvi.com/35737.js" value="0" type="text/javascript" class="custom_script"></script>');
    }
    a = $('.wikimain[type="1"]');
	var key, content;
    if (a.length > 0) {
        $.get('http://www.gensokyovn.net/h20-page').done(function(data) {
            var got = data.split('@@'),
                glen = got.length;
            for (var i = 0; i < glen;) {
				pmiss[got[i]] = got[i + 1];
                i = i + 2;
            }
        });
    }
    a = $('.wikimain[type="2"]');
    if (a.length > 0) {
        $.get('http://www.gensokyovn.net/h22-page').done(function(data) {
            var got = data.split('@@'),
                glen = got.length;
            for (var i = 0; i < glen;) {
				sopm[got[i]] = got[i + 1];
                i = i + 2;
            }
        });
    }
};
//Gallery
var module_gallery = function(target) {
    var target_value, gallery_img, per_row, content, row_determine, j,
        string, des_count, img_count;
    //Row determine: 0 - img, 1 -text
    row_determine = img_count = des_count = 0;
    content = '<table style="width: 100%; padding: 2px" border="0"><tbody><tr>';
    target_value = target.attr('value');
    gallery_img = $('.wgal[value="' + target_value + '"]');
    len_img = gallery_img.length;
    per_row = (Math.floor(len_img / 4) + 1) * 8;
    for (j = 0; j < per_row; j++) {
        //Adding image
        if (row_determine % 2 === 0) {
            if (img_count < len_img) {
                string = gallery_img.eq(img_count).find('.wimage').eq(0).html();
                img_count++;
            } else string = '';
            content = content + '<td style="width: 25%" align="center">' + string + '</td>';
        }
        //Adding description
        if (row_determine % 2 === 1) {
            if (des_count < len_img) {
                string = gallery_img.eq(des_count).find('.wtext').eq(0).html();
                des_count++;
            } else string = '';
            content = content + '<td style="vertical-align: top" align="center">' + string + '</td>';
        }
        //Adding row break
        if ((j + 1) % 4 === 0) {
            content = content + '</tr>';
            row_determine++;
            if (j < per_row) {
                content = content + '<tr>'
            }
        }
    }
    content = content + '</tbody></table>';
    target.html(content);
};
//Wiki title
var idarr = [{
    'name': 'GIỚI THIỆU',
    'id': 'general'
}, {
    'name': 'THÔNG TIN',
    'id': 'info'
}, {
    'name': 'NGHI VẤN VÀ GIẢ THUYẾT',
    'id': 'theory'
}, {
    'name': 'THIẾT KẾ',
    'id': 'design'
}, {
    'name': 'QUÁ KHỨ',
    'id': 'back'
}, {
    'name': 'CÁC MỐI QUAN HỆ',
    'id': 'relation'
}, {
    'name': 'CÁC MỐI QUAN HỆ NHỎ',
    'id': 'mrelation'
}, {
    'name': 'SPELL CARD',
    'id': 'spellcard'
}, {
    'name': 'CÁC ĐÒN ĐÁNH',
    'id': 'skill'
}, {
    'name': 'BÊN LỀ',
    'id': 'adinfo'
}, {
    'name': 'FANDOM',
    'id': 'fandom'
}, {
    'name': 'THÔNG TIN CÁ NHÂN',
    'id': 'profile'
}, {
    'name': 'THƯ VIỆN ẢNH',
    'id': 'gallery'
}, {
    'name': 'NGUỒN VÀ LIÊN KẾT',
    'id': 'source'
}, {
    'name': 'VAI TRÒ',
    'id': 'story'
}];
//Get id corresponding with title
var u_getid = function(a, b) {
    var id, len = idarr.length;
    for (var i = 0; i < len; i++) {
        if (idarr[i].name === a) {
            return a = idarr[i].id;
        }
    }
    return a = (b + 1).toString();
};
//Table of content
var module_toc = function(target, count) {
    var len_title = 0;
    var target_title, selected, selected_content, selected_id, selected_class, title_id, content, toc_value, output = '',
        x1 = 0,
        x2 = 0,
        x3 = 1;
    content = output = '';
    toc_value = target.attr('value');
    target_title = $('[value="' + toc_value + '_head"]');
    len_title = target_title.length;
    for (var i = 0; i < len_title; i++) {
        selected = target_title.eq(i);
        selected_content = target_title[i].textContent || target_title[i].innerText;
        selected_content = selected_content.substring(2, selected_content.length);
        selected_id = selected.attr('id');
        selected_class = selected.attr('class');
        if (selected_class === 'hs1') {
            x2 = x3 = 0;
            if (selected_id === 'header') {
                content = selected_content.toUpperCase();
                title_id = u_getid(content, x1);
                selected.attr('id', title_id);
            }
            x1++;
            content = '<div style="padding: 0px"><a href=#' + selected.attr('id') + '>' + x1 + ' ' + selected_content + '</a></div>';
        } else if (selected_class === 'hs2') {
            x2++;
            x3 = 0;
            if (selected_id === 'header') {
                selected.attr('id', title_id + '_' + toc_value + '_' + x2);
            }
            content = '<div style="padding: 0px 0px 0px 10px"><a href=#' + selected.attr('id') + '>' + x1 + '.' + x2 + ' ' + selected_content + '</a></div>';
        } else if (selected_class === 'hs3') {
            x3++;
            if (selected_id === 'header') {
                selected.attr('id', title_id + '_' + toc_value + '_' + x2 + '_' + x3);
            }
            content = '<div style="padding: 0px 0px 0px 20px"><a href=#' + selected.attr('id') + '>' + x1 + '.' + x2 + '.' + x3 + ' ' + selected_content + '</a></div>';
        } else if (selected_class === 'hs4') {
            if (selected_id === 'header') {
                selected.attr('id', 'spellinfo');
            }
            selected_content = selected_content.substring(0, selected_content.length - 2);
            content = '<div style="padding: 0px 0px 0px 20px"><a href=#' + selected.attr('id') + '>' + x1 + '.' + x2 + '.' + 'S' + ' ' + selected_content + '</a></div>';
        }
        output = output + content;
    }
    target.attr('id', 'table' + count);
    target.html(output);
	//Hs
	var wikistyle = $('.wikistyle');
	if(wikistyle.length === 0) $('span.hs1,.hs1x').addClass('blue');
	else $('span.hs1,.hs1x').addClass(wikistyle.eq(0).text());
};
//Basic tab
var module_tab = function(target, count) {
    var tab_list = target.find('.basictablist'); //Tab list
    var tab_cont = target.find('.basictabcontent'); //Tab content
    var current_index = 'u' + count;
    //Set tab count
    target.attr('data-tab-group-index', current_index);
    var selected;
    var tab = tab_cont.find('.basictab'),
        tab_len = tab.length;
    var content = '';
    for (var i = 0; i < tab_len; i++) {
        selected = tab.eq(i);
        //Set index
        selected.attr('data-tab-group', current_index);
        selected.attr('data-tab-index', i);
        //Add button
        content = content +
            '<div class="basictabbutton" data-tab-button-index="' +
            i +
            '" data-tab-button-group="' +
            current_index +
            '">' + selected.attr('data-tab-name') + '</div>';
    }
    tab_list.html(content);
    var butt = tab_list.find('.basictabbutton');
    butt_len = butt.length;
    for (i = 0; i < butt_len; i++) {
        butt.eq(i).on('click', function() {
            var current = $(this);
            var group_index = current.attr('data-tab-button-group'),
                tab_index = current.attr('data-tab-button-index');
            //Tab
            $('.basictab[data-tab-group="' + group_index + '"]').hide();
            $('.basictab[data-tab-group="' + group_index + '"][data-tab-index="' + tab_index + '"]').css('display', 'block');
            //Button
            $('.basictabbutton[data-tab-button-group="' + group_index + '"]').css({
                'background-color': '',
                'cursor': 'pointer'
            });
            current.css({
                'background-color': '#fff',
                'cursor': 'default'
            })
        });
    }
    //Trigger
    butt.eq(0).trigger('click');
};
//Itab
var u_button_switch = function(a, sta) {
    //0: Toggle unclickable - off
    //1: Toggle clickable - on
    if (sta) {
        //Firstly, switch tab status
        a.attr('data-status', 'on');
        //Secondly, switch tab class and style
        var cla = a.attr('class');
        a.attr('class', cla.replace(/({{ [^{}]* }})/gi, '{{ ' + a.attr('data-class-on')) + ' }}');
        var sty = a.attr('style');
        a.attr('style', sty.replace(/(style-switch; [^{}]* ;style-switch;)/gi, 'style-switch; ' + a.attr('data-style-on')) + ' ;style-switch;');
    } else {
        a.attr('data-status', 'off');
        var cla = a.attr('class');
        a.attr('class', cla.replace(/({{ [^{}]* }})/gi, '{{ ' + a.attr('data-class-off')) + ' }}');
        var sty = a.attr('style');
        a.attr('style', sty.replace(/(style-switch; [^{}]* ;style-switch;)/gi, 'style-switch; ' + a.attr('data-style-off')) + ' ;style-switch;');
    }
};
var u_tab_switch = function(a, sta) {
    //0: Toggle off (show)
    //1: Toggle on (hide)
    if (sta) {
        //Firstly, switch tab status
        a.attr('data-status', 'on');
        //Show tab
        a.removeClass('tabdeact').addClass('tabactive');
    } else {
        a.attr('data-status', 'off');
        //Hide tab
        a.removeClass('tabactive').addClass('tabdeact');
    }
};
/*
data-authority="[#AT]"
data-status="off"
data-collapse="[#COLLAPSE]"
data-button="[#AT]_[#IBUT]"
data-key="[#KEY]"
data-style-on="[#STYLE-ON]"
data-style-off="[#STYLE-OFF]"
data-class-on="buton #<# [#CLASS-ON] #>#"
data-class-off="butoff #<# [#CLASS-OFF] #>#"
id="tab[#ID]
*/
var module_itab = function() {
    //Set default key for tab and button
    //Tab
    comparearray = [];
    var tab_group = $('.tab'),
        tlen = tab_group.length;
    var but_group = $('.button'),
        blen = but_group.length;
    var filtered, filtered_len;
    var value;
    var selected;
    var i, j;
    for (i = 0; i < tlen; i++) {
        selected = tab_group.eq(i);
        value = selected.attr('data-tab'); //Filter
        if (u_compare(value) === false) continue;
        //If selected tab pass the filter, start adding key
        filtered = $('.tab[data-tab="' + value + '"][data-key=",,"]');
        filtered_len = filtered.length;
        for (j = 0; j < filtered_len; j++) {
            filtered.eq(j).attr('data-key', ',' + j + ',');
        }
    }
    //Store tab to active lately
    var tab_value = comparearray.slice();
    tab_value.push(tab_group.attr('data-authority') + '_'); //Some tab maybe dont have specific group, that mean it's group is empty
    //renew array
    comparearray = [];
    for (i = 0; i < blen; i++) {
        selected = but_group.eq(i);
        //Remove id first
        if (selected.attr('id') === 'tab') selected.attr('id', '');
        value = selected.attr('data-button'); //Filter
        if (u_compare(value) === false) continue;
        //If selected button pass the filter, start adding key
        filtered = $('.button[data-button="' + value + '"][data-key=",,"]');
        filtered_len = filtered.length;
        for (j = 0; j < filtered_len; j++) {
            filtered.eq(j).attr('data-key', ',' + j + ',');
        }
    }
    //Separate adding key and adding event to prevent some bug
    //Set button
    var target, selected;
    var key, group, authority;
    var new_key = '';
    var j;
    for (i = 0; i < blen; i++) {
        new_key = ',';
        target = but_group.eq(i);
        group = target.attr('data-button');
        key = target.attr('data-key').split(',');
        authority = target.attr('data-authority');
        klen = key.length;
        //Key setting, adding obsoleted group
        for (j = 0; j < klen; j++) {
            selected = key[j];
            if (key[j].length === 0) continue;
            if (/#/.test(selected)) {
                new_key = new_key + authority + '_' + key[j];
            } else {
                new_key = new_key + group + '#' + key[j];
            }
            new_key = new_key + ',';
        }
        target.attr('data-key', new_key);
        target.on('click', function() {
            //Prevent change if user is selecting text inside button
            var sel = window.getSelection().toString();
            if (sel.length !== 0) return 0;
            var a = $(this);
			//Prevent change if button is disabled
			if (a.attr('data-disable') === 'true') return 0;
            //Retrieve the key, split it, push it to stack
            var key = a.attr('data-key').split(','),
                klen = key.length;
            var group = a.attr('data-button');
            var authority = a.attr('data-authority');
            var sta = a.attr('data-status') === 'on' ? 1 : 0;
            var collapse = a.attr('data-collapse') === 'true' ? 1 : 0;
            var stack = [],
                selected;
            var important, relative, main;
            for (var i = 0; i < klen; i++) {
                selected = key[i].split('#');
                stack.push({
                    'group': selected[0],
                    'key': selected[1],
                    'fullpath': key[i]
                });
            }
            //Now execute for each key
            var slen = stack.length - 1; //Bypass final value, which is undefined
            //Close all relative button
            var relative_butt = $('.button[data-button="' + group + '"]').not(a),
                rlen = relative_butt.length;
            for (i = 0; i < rlen; i++) u_button_switch(relative_butt.eq(i), 0);
            //Open targetted button
            if (sta) {
                if (collapse) u_button_switch(a, 0);
            } else u_button_switch(a, 1);
            //Now execute for each key
            var target;
            var j, k;
            var relative_tab, tlen;
            //First close all relative tab
            //Bypass first value, which is undefined
            for (j = 1; j < slen; j++) {
                target = stack[j];
                relative_tab = $('.tab[data-tab="' + target.group + '"]'), tlen = relative_tab.length;
                for (i = 0; i < tlen; i++) u_tab_switch(relative_tab.eq(i), 0);
            }
            //Now open targeted tab
            //Bypass first value, which is undefined
            var target_tab, ttlen;
            for (j = 1; j < slen; j++) {
                target = stack[j];
                target_tab = $('.tab[data-tab="' + target.group + '"][data-key*=",' + target.key + ',"]'), ttlen = relative_tab.length;
                //If collapse property is true and the button is opened, do no thing (which mean close it)
                if (collapse && sta) return;
                for (i = 0; i < ttlen; i++) u_tab_switch(target_tab.eq(i), 1);
            }
        });
    }
    //Button parsing is complete, now execute button
    var tlen = tab_value.length;
    var tester;
    var temp_group, temp_key;
    for (i = 0; i < tlen; i++) {
        target = tab_value[i];
        //Force close if tab have close property
        tester = $('.tab[data-tab="' + target + '"][data-open="false"]');
        if (tester.length) continue;
        //Force open if tab have open property
        tester = $('.tab[data-tab="' + target + '"][data-open="true"]');
        if (tester.length) {
            //First value is undefined, so get the second
            temp_key = ',' + target + '#' + tester.eq(0).attr('data-key').split(',')[1] + ',';
            $('.button[data-button="' + target + '"][data-key*="' + temp_key + '"]').eq(0).trigger('click');
            continue;
        }
        //Default
        tester = $('.tab[data-tab="' + target + '"]');
        if (tester.length) {
            temp_key = ',' + target + '#' + tester.eq(0).attr('data-key').split(',')[1] + ',';
            $('.button[data-button="' + target + '"][data-key*="' + temp_key + '"]').eq(0).trigger('click');
        }
    }
};
//Itip module
var module_itip = function(target, index) {
    //Inside itip only contain tipbox or normaltip, only 1 tipbox is allowed
    var tipbox = target.children('.tipbox');
    if (tipbox.length === 0) target.prepend('<div class="tip tipbox">(?)<img class="tip-indicator" src="http://i.imgbox.com/cwqD5Cgb.png"></div>');
    else tipbox = tipbox.eq(0);
    var tipnor = target.children('.normaltip'),
        tlen = tipnor.length;
    //Remove anything else from itip
    target.children().not('.tip').remove();
    var target = '';
    for (var i = 0; i < tlen; i++) {
        //Remove unnecessary property
        target = tipnor.eq(i);
        target.attr('value', '');
        target.removeClass('normaltip');
        //Wrap inside formal tipbox
        target.wrap('<div class="tipalterbox"></div>');
    }
};
//Tip module
var module_tip = function(target, index) {
    //Convert single tip to itip
    target.wrap('<div class="GSKtip" data-click="' + target.attr('data-click') + '" data-tip-key="' + target.attr('data-tip-key') + '" data-link="' + target.attr('data-link') + '"></div>');
    target.before('<div class="tip tipbox">' + target.attr('value') + '<img class="tip-indicator" src="http://i.imgbox.com/cwqD5Cgb.png"></div>');
    target.removeClass('normaltip').wrap('<div class="tipalterbox"></div>');
};
//Tip convert
var module_tip_convert = function(target, index) {
    var tipbox = target.children('.tipbox').eq(0);
    var tipnor = target.children('.tipalterbox'),
        tlen = tipnor.length;
    //Convert normal tip into formal tip
    var selected, value = '',
        new_value = '',
        cleft, ctop;
    var click = target.attr('data-click');
    //Remove tip indicator if find click value
    if (click === 'true') tipbox.children('.tip-indicator').remove();
    //Add link from the first tip only
    tipbox.contents().wrapAll('<a onClick="idjump($(this).attr(&quot;href&quot;))" href="' + target.attr('data-link') + '"></a>');
    for (var i = 0; i < tlen; i++) {
        new_value = '';
        //Remove unnecessary property
        selected = tipnor.eq(i).children('.tipstore').eq(0);
        //Add invisible class to prevent tip active by hover
        if (click === 'true') selected.addClass('tipinvisible');
        //If the tip is empty, hide it
        if (selected.html().length === 0) selected.css('display', 'none');
        selected.attr('value', '');
        //Parsing value
        value = ',' + selected.attr('data-type') + ',';
        if (/,center,/.test(value) === true) {
            if (/,left,/.test(value) === true) new_value = 'cl';
            else if (/,right,/.test(value) === true) new_value = 'cr';
            else if (/,bot,/.test(value) === true) new_value = 'cb';
            else new_value = 'ct';
        } else {
            if (/,left,/.test(value) === true) new_value = new_value + 'l';
            else new_value = new_value + 'r';
            if (/,bot,/.test(value) === true) new_value = new_value + 'b';
            else new_value = new_value + 't';
            if (/,ver,/.test(value) === true) new_value = new_value + 'v';
            else new_value = new_value + 'h';
        }
        selected.attr('data-type', new_value);
        if (/,no-arrow,/.test(value) === false) {
            selected.append('<div class="arrow"></div>');
            cleft = selected.css('left');
            if (cleft === 'auto' || cleft === '0px') cleft = '10px';
            switch (new_value) {
                case 'rbv':
                    selected.css('left', cleft);
                    break;
                case 'cr':
                    selected.css('left', cleft);
                    break;
                case 'rtv':
                    selected.css('left', cleft);
                    break;
                case 'rbh':
                    selected.css('top', cleft);
                    break;
                case 'cb':
                    selected.css('top', cleft);
                    break;
                case 'lbh':
                    selected.css('top', cleft);
                    break;
            }
        }
    }
    //Adding event to tip
    target.on('mouseenter', function() {
        var a = $(this);
        var tipbox = a.children('.tipbox').eq(0);
        var tipnor = a.children('.tipalterbox'),
            tlen = tipnor.length;
        var target, tipstore;
        for (var i = 0; i < tlen; i++) {
            target = tipnor.eq(i);
            tipstore = target.children('.tipstore');
            tip_behavior[tipstore.attr('data-type')](target, tipstore, tipbox, tipstore.children('.arrow'));

        }
    });
    target.on('mouseleave', function() {
        var a = $(this);
        var tipnor = a.children('.tipalterbox'),
            tlen = tipnor.length;
        var target, tipstore;
        var value;
        for (var i = 0; i < tlen; i++) {
            target = tipnor.eq(i);
            target.css({
                'width': '0px',
                'height': '0px'
            });
        }
    });
    //Click event
    if (click === 'true') {
        tipbox.on('click', function() {
            var a = $(this).parent();
            var value = a.attr('data-tip-key').split(','),
                vlen = value.length;
            var target, tlen;
            var key;
            var i, j, k;
            var alterbox, alen;
            var selected;
            if (a.attr('data-tip-status') !== 'on') {
                a.attr('data-tip-status', 'on');
                for (i = 0; i < vlen; i++) {
                    key = value[i];
                    if (/!/.test(key) === true) {
                        a.trigger('mouseenter');
                        alterbox = a.children('.tipalterbox'), alen = alterbox.length;
                        for (k = 0; k < alen; k++) {
                            alterbox.eq(k).children('.tipstore').removeClass('tipinvisible').addClass('tipvisible');
                        }
                        break;
                    }
                    target = $('.tipstore[data-tip-key*=",' + key + ',"]');
                    tlen = target.length;
                    for (j = 0; j < tlen; j++) {
                        selected = target.eq(j);
                        selected.addClass('tipvisible');
                        if (selected.hasClass('tipinvisible')) selected.removeClass('tipinvisible').addClass('neutralvisible');
                        selected.parents('.GSKtip').eq(0).trigger('mouseenter');
                    }
                }
            } else {
                a.attr('data-tip-status', 'off');
                for (i = 0; i < vlen; i++) {
                    key = value[i];
                    if (/!/.test(key) === true) {
                        a.trigger('mouseleave');
                        alterbox = a.children('.tipalterbox'), alen = alterbox.length;
                        for (k = 0; k < alen; k++) {
                            alterbox.eq(k).children('.tipstore').removeClass('tipvisible').addClass('tipinvisible');
                        }
                        break;
                    }
                    target = $('.tipstore[data-tip-key*=",' + key + ',"]');
                    tlen = target.length;
                    for (j = 0; j < tlen; j++) {
                        selected = target.eq(j);
                        selected.removeClass('tipvisible');
                        if (selected.hasClass('neutralvisible')) selected.removeClass('neutralvisible').addClass('tipinvisible');
                        selected.parents('.GSKtip').eq(0).trigger('mouseleave');
                    }
                }
            }
            return false //Prevent href visiting
        });
    }
    //Now trigger mouseover for the first time
    target.trigger('mouseenter');
    target.trigger('mouseleave');
};
//Tip behavior
var tip_behavior = {
    //Formal arrow distance - 4px
    rbh: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-top').css({
                'border-color': 'transparent transparent ' + tipstore.css('border-top-color') + ' transparent',
                'top': '-8px',
                'left': '4px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': (h2) + 'px',
            'left': -(0) + 'px',
            'height': (h1 + extend) + 'px',
            'width': w1 + 'px'
        });
    },
    cb: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-top').css({
                'border-color': 'transparent transparent ' + tipstore.css('border-top-color') + ' transparent',
                'top': '-8px',
                'right': (w1 - 16) / 2 + 'px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': (h2) + 'px',
            'left': -(w1 - w2) / 2 + 'px',
            'height': (h1 + extend) + 'px',
            'width': w1 + 'px'
        });
    },
    lbh: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-top').css({
                'border-color': 'transparent transparent ' + tipstore.css('border-top-color') + ' transparent',
                'top': '-8px',
                'right': '4px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': (h2) + 'px',
            'left': -(w1 - w2) + 'px',
            'height': (h1 + extend) + 'px',
            'width': w1 + 'px'
        });
    },
    rbv: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-left').css({
                'border-color': 'transparent ' + tipstore.css('border-right-color') + ' transparent transparent',
                'top': '4px',
                'left': '-8px'
            });

            extend = 10;

        }
        tipalterbox.css({
            'top': (0) + 'px',
            'height': (h1) + 'px',
            'width': (extend + w1) + 'px',
            'left': (w2) + 'px'
        });
    },
    cr: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-left').css({
                'border-color': 'transparent ' + tipstore.css('border-right-color') + ' transparent transparent',
                'bottom': (h1 - 16) / 2 + 'px',
                'left': '-8px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': -(h1 - h2) / 2 + 'px',
            'height': (h1) + 'px',
            'width': (extend + w1) + 'px',
            'left': (w2) + 'px'
        });
    },
    rtv: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-left').css({
                'border-color': 'transparent ' + tipstore.css('border-right-color') + ' transparent transparent',
                'bottom': '4px',
                'left': '-8px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': -(h1 - h2) + 'px',
            'height': (h1) + 'px',
            'width': (extend + w1) + 'px',
            'left': (w2) + 'px'
        });
    },
    rth: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-bot').css({
                'border-color': tipstore.css('border-bottom-color') + ' transparent transparent transparent',
                'bottom': '-8px',
                'left': '4px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': -(h1 + extend) + 'px',
            'height': (h1 + extend) + 'px',
            'width': w1 + 'px'
        });
    },
    ct: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-bot').css({
                'border-color': tipstore.css('border-bottom-color') + ' transparent transparent transparent',
                'bottom': '-8px',
                'left': (w1 - 16) / 2 + 'px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': -(h1 + extend) + 'px',
            'left': -(w1 - w2) / 2 + 'px',
            'height': (h1 + extend) + 'px',
            'width': w1 + 'px'
        });
    },
    lth: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-bot').css({
                'border-color': tipstore.css('border-bottom-color') + ' transparent transparent transparent',
                'bottom': '-8px',
                'right': '4px'
            });


            extend = 10;
        }
        tipalterbox.css({
            'top': -(h1 + extend) + 'px',
            'left': -(w1 - w2) + 'px',
            'height': (h1 + extend) + 'px',
            'width': w1 + 'px'
        });
    },
    ltv: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-right').css({
                'border-color': 'transparent transparent transparent' + tipstore.css('border-left-color'),
                'bottom': '4px',
                'right': '-8px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': -(h1 - h2) + 'px',
            'height': (h1) + 'px',
            'width': (extend + w1) + 'px',
            'left': -(w1 + extend) + 'px'
        });
    },
    cl: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {

            extend = 10;
            arrow.addClass('arrow-right').css({
                'border-color': 'transparent transparent transparent' + tipstore.css('border-left-color'),
                'bottom': (h1 - 16) / 2 + 'px',
                'right': '-8px'
            });
        }
        tipalterbox.css({
            'top': -(h1 - h2) / 2 + 'px',
            'height': (h1) + 'px',
            'width': (extend + w1) + 'px',
            'left': -(w1 + extend) + 'px'
        });
    },
    lbv: function(tipalterbox, tipstore, tipbox, arrow) {
        var h1 = tipstore.outerHeight(),
            h2 = tipbox.outerHeight(),
            w1 = tipstore.outerWidth(),
            w2 = tipbox.outerWidth();
        var extend = 0;
        if (arrow.length) {
            arrow.addClass('arrow-right').css({
                'border-color': 'transparent transparent transparent' + tipstore.css('border-left-color'),
                'top': '4px',
                'right': '-8px'
            });

            extend = 10;
        }
        tipalterbox.css({
            'top': -(0) + 'px',
            'height': (h1) + 'px',
            'width': (extend + w1) + 'px',
            'left': -(w1 + extend) + 'px'
        });
    }
};
var module_id = function(){
	//Wiki only
	//Tipout
	var id = $('.customid[id^="cr"]'), ilen = id.length;
	var target_id, target_new_id;
	var target, target2;
	var id2, ilen2;
	for(var i = 0, j; i < ilen; i++){
		target = id.eq(i);
		if(target.attr('data-order') !== undefined) continue;
		target_id = target.attr('id');
		id2 = $('.customid[id="' + target_id + '"]');
		ilen2 = id2.length;
		//For the first match
		target2 = id2.eq(0);
		target2.attr('data-order',0).attr('id',target_id + '_' + 0);
		//For the following match
		for(j = 1; j < ilen2; j++){
			target2 = id2.eq(j);
			target_new_id = target_id.substring(2,target_id.length);
			target2.attr('data-order',j).attr('id',target_id + '_' + j);
			target2.find('.tipbox').children().html('[' + target_new_id + '.' + j + ']<img class="tip-indicator" src="http://i.imgbox.com/cwqD5Cgb.png" style="display:inline">');
		}
	}
	//Tipin
	var target_order;
	id = $('.customid[value="tipin"][id^="ct"]'), ilen = id.length;
	for(i = 0; i < ilen; i++){
		target = id.eq(i);
		span = target.children('.tipin');
		target_id = target.attr('id');
		target_id = target_id.substring(2,target_id.length);
		id2 = $('.customid[id^="cr' + target_id + '_"]');
		ilen2 = id2.length;
		//For the first match
		span.append('<a onClick="idjump($(this).attr(&quot;href&quot;))" href="#cr' + target_id + '_0">↑' + target_id + '</a>.');
		//For the following match
		for(j = 1; j < ilen2; j++){
			target2 = id2.eq(j);
			target_order = target2.attr('data-order');
			target_new_id = 'cr' + target_id + '_' + target_order;
			span.append('<sup><a onClick="idjump($(this).attr(&quot;href&quot;))" href="#' + target_new_id + '">↑' + target_id + '.' + target_order + '</a>.</sup> ');
		}
	}
};
//Module Caller
var u_module = function(a) {
	module_load();
    module_other();
    database();
    module_io();
    var target;
    var gallery = a.find('.wikigallery'),
        len = gallery.length;
    for (var i = 0; i < len; i++) {
        target = gallery.eq(i);
        module_gallery(target);
    }
    var toc = a.find('.tableofcontent');
    len = toc.length;
    for (i = 0; i < len; i++) {
        target = toc.eq(i);
        module_toc(target, i);
    }
    var tab = a.find('.basictabs');
    len = tab.length;
    for (i = 0; i < len; i++) {
        target = tab.eq(i);
        module_tab(target, i);
    }
    module_itab();
    var itip = a.find('.GSKtip');
    len = itip.length;
    for (i = 0; i < len; i++) {
        target = itip.eq(i);
        module_itip(target, i);
    }
    var tip = a.find('.normaltip');
    len = tip.length;
    for (i = 0; i < len; i++) {
        target = tip.eq(i);
        module_tip(target, i);
    }
    var gtip = a.find('.GSKtip');
    len = gtip.length;
    for (i = 0; i < len; i++) {
        target = gtip.eq(i);
        module_tip_convert(target, i);
    }
    var arrow = a.find('.arrow');
    len = arrow.length;
    for (i = 0; i < len; i++) {
        arrow.eq(i).on('click', function() {
            var a = $(this).parents('.GSKtip').eq(0);
            if (a.attr('data-click') === 'true') {
                a.children('.tipbox').trigger('click');
            }
        });
    }
	module_id();
    //Remove temp hide
    var group = a.find('.temp_hide');
    len = group.length;
    for (i = 0; i < len; i++) {
        group.eq(i).contents().unwrap();
    }
    refing(1);
};

function refing(a) {
    if (typeof(u_ref) === 'function') {
        u_ref($('#main-content'));
        a = 0;
    };
    if (a === 1) setTimeout(refing(1), 500);
};
var gskbb = function(a) {
    post_parsing(a, 0);
    u_module(a);
};
$(function() {
    u_module($('#main-content'));
});
//Game
$(function() {
    $.get('http://www.gensokyovn.net/h15-page').done(function(data) {
        var got = data,
            mapbase, mapcode = [],
            lb, lc;
        mapbase = got.split('^');
        lb = mapbase.length;
        for (var i = 0; i < lb;) {
            mapcode.push({
                'name': mapbase[i],
                'codex': mapbase[i + 1]
            });
            i = i + 2;
        }
        lc = mapcode.length;
        setTimeout(function() {
            var u, m, n, v, vx, lv, z, y, ly, t, w1, w2;
            var ax = $('.map'),
                lx = ax.length;
            for (i = 0; i < lx; i++) {
                u = ax.eq(i);
                n = u.attr('value');
                for (var l = 0; l < lc; l++)
                    if (n === mapcode[l].name) u.html(mapcode[l].codex);
                vx = u.parents('.postbody').find('table.player'), lv = vx.length;
                for (var j = 0; j < lv; j++) {
                    z = vx.eq(j);
                    m = z.attr('value').split('-');
                    if (n === m[0]) {
                        t = '<tr><td class="player ' + m[0] + 'p' + m[1] + '"><span style="color: #fff; text-align: center">Id ' + m[1] + '<\/span><\/td><\/tr>';
                        y = m[2].split(','), ly = y.length;
                        for (var k = 0; k < ly; k++) {
                            w1 = u.find('.active[value="' + y[k] + '"],.finish[value="' + y[k] + '"]').eq(0);
                            if (w1.length !== 0) {
                                w1.after('<div class="ava ' + m[0] + 'playerava' + m[1] + '"></div>');
                                t = t + '<tr><td class="player"><div class="ava">' + k + '</div><\/td><\/tr>';
                            } else if (y[k] === 'X') {
                                t = t + '<tr><td class="player ' + m[0] + 'p' + m[1] + '"><div class="ava ' + m[0] + 'playerava' + m[1] + '"></div><\/td><\/tr>';
                            }
                        }
                        z.html(t);
                    }
                }
            }
        }, 50);
    });
});
var param = {};
//Onload
$(window).load(function() {
    //    u_time._3_onload = performance.now() - u_time._2_end_parsing;
    var e = location.hash;
    idjump(e);
    bbcode_load_by_hash(e);
	//Parameter
	var para, par = window.location.search, plen;
	par = par.substring(1,par.length).split('&');
	plen = par.length;
	var p;
	for(var i = 0; i < plen; i++){
		para = par[i].split('=');
		param[para[0]] = para[1];
	}
	bbcode_load_by_param();
    //    u_time.total = performance.now() - u_time._1_start;
});