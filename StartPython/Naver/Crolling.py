import requests #파이썬으로 html 분석하는 라이브러리
from bs4 import BeautifulSoup #크롤러의 기본

#'변수'에 사이트의 모든 정보가 들어옵니다.
#네이버 증권의 삼성전자 주식 페이지를 가져옵니다.
데이터=requests.get('https://finance.naver.com/item/sise.nhn?code=005930')

#response[200]이면 정상적으로 가져왔다는 뜻
print(데이터)

#content에는 html데이터가 들어있음
#print(데이터.content)을 하면 html을 전부 가져온다.

#가져온 html데이터가 예뻐진다. 그걸 Soup에 넣어준다. parser: html을 분석해줌
Soup=BeautifulSoup(데이터.content,'html.parser')

#print(Soup.find_all('태그명',속성명))
#class는 class_로 써줘야함, id는 그냥 써줘도 됨
#   현재가격
print('strong태그에 nowVal 이라는 id 속성')
print(Soup.find_all('strong',id='_nowVal')) 

#[ ]내부에 있는 내용만 뽑아줘라 ! [0]을 붙인다.
#여러개가 있을 수 있으니까 [0]인지 [1]인지 잘 봐야됨.
#그 안의 text만 뽑아줘라! .text를 붙여라.

print('strong태그에 nowVal 이라는 id 속성+ [0]')
print(Soup.find_all('strong',id='_nowVal')[0].text)

#Chrome에서 우클릭-검사 누르면 html 볼 수 있음
#검사 할 페이지 요소 선택 하면 보임
#   현재가격
print('em태그에 no_down 이라는 class 속성 + [0]')
print(Soup.find_all('em',class_='no_down')[0].text)
#   전일대비
print(Soup.find_all('em',class_='no_down')[1].text)

#class, id 하나도 없는 요소 : select(' ')! css selector로 찾아줌
#class는 . 을 붙이고, id는 # 을 붙인다.
#여러개를 찾아줄때는 그냥 붙여쓰면 된다
#우클릭 - copy selector 하면 바로 복사 가능
print(Soup.select('#content > div.section.inner_sub > table.type2 > tbody > tr:nth-child(4) > td:nth-child(7) > span'))

#이미지는 주로 src 안에 들어있다.
이미지=Soup.select('#chartPrintArea > div.chartContainer.stx-draggable > div.stx-holder.stx-panel-chart > div') 
print(이미지['src'])