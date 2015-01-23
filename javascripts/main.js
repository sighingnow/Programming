/**
 * This would be the main JS file.
 **/

var currentpage = "page_1";
var currentIndex = 0;
var topRange = 17;

(function(){
    window.onload = function() {
        $("a.page_number").attr("href", "javascript:void(0);");
        $("a.page_number").click(function() {
            var schedule = setTimeout(function() {
                $("#loading_model").modal("show");
                $("#loading_pic").show();
            }, 500);
            var problemid = this.id;
            var index = parseInt(this.id, 10);
            if(index > topRange) {
                index = topRange;
            }
            var filename = "html/" + getId(index.toString()) + '.html';
            var widget = "div#";
            if(currentpage === "page_1") {
                widget = widget + "page_2";
                currentpage = "page_2";
            }
            else {
                widget = widget + "page_1";
                currentpage = "page_1";
            }
            $(widget).load(filename, function(responseTxt,statusTxt,xhr){
                if(statusTxt=="success") {
                    $(widget).html(responseTxt);
                    MathJax.Hub.Queue(["Typeset", MathJax.Hub, document.getElementById(widget)]);
                    clearTimeout(schedule);
                    $("#loading_model").modal("hide");
                    $("#loading_pic").hide();
                    if(currentIndex >= index) {
                        $('.carousel').carousel('prev');
                    }
                    else {
                        $('.carousel').carousel('next');
                    }
                    currentIndex = index;
                }
            });
        });
        $("a#prev_group").click(function() {
            var range = parseInt($("a.page_number")[0].id, 10);
            if(range > 10) {
                $("a.page_number").each(function() {
                    var prevtext = getId(parseInt($(this).attr("id"), 10)-10);
                    $(this).attr("id", prevtext).html(prevtext);
                });
            }
        });
        $("a#next_group").click(function() {
            var range = parseInt($("a.page_number")[0].id, 10);
            if(range < 11) {
                $("a.page_number").each(function() {
                    var nexttext = getId(parseInt($(this).attr("id"), 10)+10);
                    $(this).attr("id", nexttext).html(nexttext);
                });
            }
        });
        $("li#previouspage").click(function() {
            if(currentIndex % 10 === 1) {
                $("a#prev_group").click();
            }
            $("a#"+getId(currentIndex-1)).click();
        });
        $("li#nextpage").click(function() {
            if(currentIndex % 10 === 0) {
                $("a#next_group").click();
            }
            $("a#"+getId(currentIndex+1)).click();
        });
    };
})();

function getId(number) {
    if(number < 10) {
        return "00"+number.toString();
    }
    else if(number >= 10 && number < 99) {
        return "0"+number.toString();
    }
    else {
        return number.toString();
    }
} 