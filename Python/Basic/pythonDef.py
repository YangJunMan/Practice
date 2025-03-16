# "인사하기" 함수 작성
def 인사하기():
    print("안녕하세요!")
    print("양준혁이에요!")
    
def 감사하기(뭐를):
    print(뭐를)
    
감사하기('먹을 것을 줬어요')

#수 입력하기
def sum(i):
    a=i+1
    return a
    
print(sum(1))
print(sum(2))

scoreAll = 0
students = []
#append뜻 : 리스트에 추가
for i in range(10): ## 1 ##
    students.append((input())) 
#students에 입력받은 값들을 추가 후 출력. 
print(students)
