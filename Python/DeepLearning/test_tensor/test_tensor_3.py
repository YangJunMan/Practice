# csv파일 내용 : admit, gre, gpa, rank
# 성적gre과 학점gpa을 고려했을 때 상위권rank의 학교에 합격admit했는가? admit에 합격 여부가 적혀있다.

# 모델 학습 후 gre와 gpa 기준으로 합격 여부를 예측했을 때, 
# 문서의 admit과 모델이 예측한 합격예측(admit)이 얼마나 차이나는지 테스트하는 프로그램이다


import numpy as np  # numpy : 수학, 과학 연산을 위한 파이썬 패키지
import pandas as pd #pandas : python에서 excel처럼 구조화된 Data를 사용할 때 사용한다.
import tensorflow as tf # 수치 계산과 머신러닝을 위한 오픈소스 라이브러리.

csv_dir="apple/test_tensor/gpascore.csv"

data=pd.read_csv(csv_dir)  #데이터 읽기


#전처리 -- 빈 칸이나 값이 이상한 칸은 어떤 data를 넣을 지 고민해야한다--


data=data.dropna() #빈칸이 있는 행은 drop 한다.


#print(data['gpa'].min()) : 이름이 gpa인 열의 최솟값을 출력한다.


yData=data['admit'].values #admit열의 값들을 'yData'리스트에 저장
xData=[]


for i,rows in data.iterrows(): #pandas의 data를 한 행씩 xData에 추가한다.
    xData.append([rows['gre'],rows['gpa'],rows['rank']])

model = tf.keras.models.Sequential([    #keras를 사용해서 레이어 생성 (레이어의 노드 개수, activation function)
    
    tf.keras.layers.Dense(64,activation='tanh'),    #첫번째 히든레이어
    tf.keras.layers.Dense(128, activation='tanh'),      #두번째 히든레이어
    tf.keras.layers.Dense(1,activation='sigmoid'),      #마지막 히든레이어(출력레이어). sigmoition : 0 또는 1의 값을 출력한다.
])


#model.compile(optimizer=???,loss=???,metrics=???,)
#optimizer를 이용하면 레이어를 지날 때 마다 최적화되는 새로운 w값을 알아서 조정해준다
#optimizer와 loss에 사용되는 func엔 정말 여러가지가 있다


model.compile(optimizer='adam', #대중적인 optimizer func
              loss='binary_crossentropy', #이 func는 0과 1 사이의 분류/확률 문제에서 사용된다
              metrics=['accuracy'])


# model.fit( x data, y data, epochs=n)
#         ( Data1, Data2, n회 반복)
# x = [[a1,b1,c1],[a2,b2,c2],[a3,b3,c3]...]
# y = [[],[],[]...]


model.fit( np.array(xData), np.array(yData), epochs=100) # epochs회만큼 반복하는 결과를 출력


# '실제 결과(admit)'와 비교한 '내가 deeplearning으로 예측한 결과'를 비교해 봤을 때
# 내가 학습시킨 모델의 정확도는 약 0.58(58%)이고, loss는 0.66이다

# 60%는 별로다! 80% 이상은 되어야지..