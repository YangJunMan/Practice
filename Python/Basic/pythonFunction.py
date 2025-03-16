
#print 출력
print('안녕 세상아!')
이름='홍길동'
print(이름)

#List 대괄호는 리스트
test_List=[1,'양준혁',30,'24세',5]
print(test_List[1])

#Dictionary 중괄호는 딕셔너리
test_Dictionary={'in_00':2,
                 '이름' :'홍길동',
                 'in_02':20,
                 '나이' :'99세'}
print(test_Dictionary['이름'])
test_Dictionary['이름']='척준경'
print(test_Dictionary['이름'])

#If 조건문
#파이썬은 들여쓰기 주의
재고량=10
if(재고량>5):
    print('현재 재고량은 5개 이상입니다.')

if '양준혁' in test_List:
    print('양준혁이 리스트에 있습니다.')
else:  
    print('양준혁이 리스트에 없습니다.')
    
if '척준경' in test_Dictionary['이름']:
    print('이름이 척준경이 맞습니다.')
else:
    print('이름이 척준경이 아닙니다.')

#파이썬 파일 만들기. 없으면 'w'로 생성
Text=open('test_text.txt','w')
Text.write('Hello Python!')
Text.close()
#append하면 파일에 추가
Text=open('test_text.txt','a')
Text.write('.. and Hello World!')
Text.close()
#read하면 이제 파이썬에서 파일을 읽을 수 있음
Text=open('test_text.txt','r')
print(Text.read())
#파일을 열었으면, 다시 닫아주자.
Text.close()

#액셀형식 파일 만들기.
Excel=open('test_csv.csv','w')
Excel.write('이름,나이,성별\n준혁,24,남')
Excel.close()

#for문 in range, List
for i in range(5):
    print(i)
for i in test_List:
    print(i)
for i in test_List:
    print('안녕')
    
#for 국룰. 구구단 만들기
for i in range(9):
    for j in range(9):
        print(i+1,'*',j+1,'=',(i+1)*(j+1))

