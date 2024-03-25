
    
    function updateAll() {

        var n1 = document.getElementById("book1").value;
        var n2 = document.getElementById("book2").value;
        var n3 = document.getElementById("book3").value;
        var n4 = document.getElementById("book4").value;
        var n5 = document.getElementById("book5").value;
        var n6 = document.getElementById("book6").value;
        var n7 = document.getElementById("book7").value;
        var n8 = document.getElementById("book8").value;
        var n9 = document.getElementById("book9").value;
        var n10 = document.getElementById("book10").value;
        var n11 = document.getElementById("book11").value;
        var n12 = document.getElementById("book12").value;
        var p1 = 25000 * n1;
        var p2 = 24000 * n2;
        var p3 = 27000 * n3;
        var p4 = 29000 * n4;
        var p5 = 21000 * n5;
        var p6 = 25000 * n6;
        var p7 = 30000 * n7;
        var p8 = 28000 * n8;
        var p9 = 35000 * n9;
        var p10 = 32000 * n10;
        var p11 = 30000 * n11;
        var p12 = 27000 * n12;
        document.getElementById("book1total").value = p1;
        document.getElementById("book2total").value = p2;
        document.getElementById("book3total").value = p3;
        document.getElementById("book4total").value = p4;
        document.getElementById("book5total").value = p5;
        document.getElementById("book6total").value = p6;
        document.getElementById("book7total").value = p7;
        document.getElementById("book8total").value = p8;
        document.getElementById("book9total").value = p9;
        document.getElementById("book10total").value = p10;
        document.getElementById("book11total").value = p11;
        document.getElementById("book12total").value = p12;
        var totalNumber = parseInt(n1) + parseInt(n2) +
        parseInt(n3)+parseInt(n4) + parseInt(n5) +
        parseInt(n6)+parseInt(n7) + parseInt(n8) +
        parseInt(n9)+parseInt(n10) + parseInt(n11) +
        parseInt(n12);
        document.getElementById("totalNumber").value = totalNumber;
        var totalPrice = p1 + p2 + p3+p4+p5+p6+p7+p8+p9+p10+p11+p12;
        document.getElementById("totalPrice").value = totalPrice;
        }
        
function SaveItem() { // 스토리지에 저장
            var u_name = document.getElementById("username").value;
            if(u_name!=""){
              localStorage.setItem('name1',u_name);
            alert("아이디"+localStorage.getItem('name1')+"가 저장되었습니다.");
            return 0;
        }
            alert("아이디를 입력해주세요.");
            
          }

function order(){
    var n1 = document.getElementById("book1").value;
    var n2 = document.getElementById("book2").value;
    var n3 = document.getElementById("book3").value;
    var n4 = document.getElementById("book4").value;
    var n5 = document.getElementById("book5").value;
    var n6 = document.getElementById("book6").value;
    var n7 = document.getElementById("book7").value;
    var n8 = document.getElementById("book8").value;
    var n9 = document.getElementById("book9").value;
    var n10 = document.getElementById("book10").value;
    var n11 = document.getElementById("book11").value;
    var n12 = document.getElementById("book12").value;
    var book=[];



    book[0] = '컴퓨터와 IT기술의 이해 [개정판-2판]';
    book[1] = '(알기쉬운) 알고리즘';
    book[2] = '선형대수학 Express';
    book[3] = '루비 프로그래밍 언어';
    book[4] = '소셜미디어의 이해와 활용';
    book[5] = '멀티미디어 배움터 2.0';
    book[6] = '네트워크 보안 에센셜(4판)';
    book[7] = '비즈니스 정보 시스템';
    book[8] = '회로이론';
    book[9] = 'Big Java';
    book[10] ='경영학의 이해 (9/e)';
    book[11] = '컴퓨터 배움터';
    var num=[n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12];
    var price=[25000,24000,27000,29000,21000,25000,30000,28000,35000,32000,30000,27000];
    var p1 = 25000 * n1;
    var p2 = 24000 * n2;
    var p3 = 27000 * n3;
    var p4 = 29000 * n4;
    var p5 = 21000 * n5;
    var p6 = 25000 * n6;
    var p7 = 30000 * n7;
    var p8 = 28000 * n8;
    var p9 = 35000 * n9;
    var p10 = 32000 * n10;
    var p11 = 30000 * n11;
    var p12 = 27000 * n12;
    var tprice=[p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12];

var totalNumber = parseInt(n1) + parseInt(n2) +
parseInt(n3)+parseInt(n4) + parseInt(n5) +
parseInt(n6)+parseInt(n7) + parseInt(n8) +
parseInt(n9)+parseInt(n10) + parseInt(n11) +
parseInt(n12);

var totalPrice=p1+p2+p3+p4+p5+p6+p7+p8+p9+p10+p11+p12;

document.write("주문한 아이디 : "+localStorage.getItem('name1')+'<br>');

document.write("<caption>주문한 내용</caption>");
document.write('<table border="1">');
document.write("<tr><th>제목</th><th>가격</th><th>수량</th><th>합계</th></tr>");
    for(i=0;i<12;i++){
    if(num[i]!=0){
        document.write("<tr><td>"+book[i]+"</td><td>"+price[i]+"</td><td>"+num[i]+"</td><td>"+tprice[i]+"</td></tr>");
    }
}

document.write("<tr><th>합계</th><td></td><td>"+totalNumber+"</td><td>"+totalPrice+"</td></tr>")
document.write('</table>');
}



