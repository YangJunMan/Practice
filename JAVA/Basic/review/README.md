복습

Interface >> 구현 할 클래스의 기능들의 틀을 잡아줌을 압니다
Extends >> 상속관계의 이해와 Override, super 등 부모와 자식간의 관계를 복습합니다

BankAccount
-> 계좌 생성과 출금, 이자 등을 계산하는 프로그램
- Account에 기본적으로 번호와 잔고를 저장할 수 있는 생성자
- 이때 Checking용Account를 생성할 시 출금(withdraw) 기능을 Override
- Saving용 Account는 withdraw 기능 없음. applyInterest Override로 이자기능 확인가능
- Main에서 계좌 생성 시 생성 순서대로 HashMap의 Key값 부여. (CheckAccount 생성 시 C + 000~ 부터 부여). Save 동일

ExerciseCal
-> 각종 운동 방식과 거리, 횟수 계산을 통해 소모 칼로리를 계산하는 프로그램
- CalorieInterface 라는 Interface를 이용해 추상메소드를 규정
- Excercise에서 Interface를 implements 함으로써 추상메소드를 잇는다
- 하위의 각종 운동동 종목을은 Excercise의 상속을 받은 후 각각 Override를 통해 각각 칼로리를 계산한다
- Course와 Match는 거리별 칼로리 계산 종목과, 매치 횟수별 칼로리 계산을 별도로 계산할 수 있도록 한다.
 
PascalTriangle
-> 파스칼의 삼각형을 나타내고 메모장 형태로 저장할 수 있도록 하는 프로그램
- 버튼 리스너, 파일 입출력 등 기능 이용