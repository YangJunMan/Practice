musical_score_dir='RNN/musical_score.txt'

text=open(musical_score_dir,'r').read()
print(text)

# set으로 문자 보기 [문자 주머니로 바꾸기 (Bag of words)]
uniq_text=list(set(text))
uniq_text.sort()

print(uniq_text)

# 딥러닝은 모든 데이터를 숫자로 변환한 후 계산한다.. <->
text_to_num={}
num_to_text={}

for i, data in enumerate(uniq_text):    # 데이터마다 숫자 부여
    text_to_num[data]=i
    num_to_text[i]=data
    
# print(text_to_num)
    
numbering_text=[]   # 딕셔너리

for i in text:  # 악보data 
    numbering_text.append(text_to_num[i])   # 기존 악보 data 들을 숫자로 변환 후 출력

    
# print(numbering_text)

# sequence를 일정길이 넣으면 다음 단어를 예측해주는 모델?  
# num_data : [ 5 17 8 5 4 6 ] 이 있다면, (5 17 8 5 4)가 trainX, 6을 trainY로 설정
# 즉, trainX다음엔 trainY라는 답이 나오도록 학습시킨다.

trainX=[]
trainY=[]
for i in range(0,len(numbering_text)-25):
    trainX.append(numbering_text[i:i+25])
    trainY.append(numbering_text[i+25])


# print(trainX[0:5])
# print(trainY[0:5])

import numpy as np
import tensorflow as tf
# print(np.array(trainX).shape)

# one hot encoding
trainX=tf.one_hot(trainX,31)    # musical_score.txt에 있는 문자의 가짓수 : 31개
trainY=tf.one_hot(trainY,31)
print(trainX[0:3])

model=tf.keras.models.Sequential([
    tf.keras.layers.LSTM(100,input_shape=(25,31)),
    tf.keras.layers.Dense(31, activation="softmax") # 31개의 카테고리 출력
])

model.compile(loss='categorical_crossentropy',optimizer='adam')  # sparse는 원 핫 인코딩이 안되어있을 때 사용

model.fit(trainX,trainY,batch_size=64,epochs=30,verbose=2)  # 64개의 데이터 확인 후에도 w(가중치)값을 업데이트 하고 싶을 경우 batchsize 설정
# verbose는 학습 중 출력되는 정보들을 줄임

model.save('RNN/trained_keras/model_jun_1.keras')