타이타닉 생존자 list data set입니다.
data set의 몇몇 데이터를 이용해서 일부 승객의 생존 여부를 예측해봅니다

Survived : 생존 여부
Pclass : n등석
이름 
성별
SibSp : 형제자매 합석 여부
Parch : 자식여부
Ticket : 티켓번호
Fare : 요금

각 열의 data들을 어떻게 다룰지 설정해줍니다
PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Embarked

데이터의 전 처리를 해주도록 합니다

생존 확률 수치화에 필요 없는 제외할 것 PID , Name
숫자만 집어넣어야 하는 것 Fare Parchg SibSp : numberic_column
뭉퉁그려 넣을 것  Age : bucketized_column
기존 카테고리 데이터 Sex Embarked Pclass : indicater_column
종류가 너무 많은 카테고리 Ticket : embedding_column

또한 빈 칸의 경우도 어떻게 처리할 지 전처리 합니다