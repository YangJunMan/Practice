# 한글전처리에는 konly도 있지만 이번엔 전통적인 방법으로 실행

import pandas as pd # 데이터 조작, 분석, 시각화 등
import numpy as np # 데이터 수학연산
import tensorflow as tf
from tensorflow.keras.preprocessing.text import Tokenizer   # 텍스트 데이터를 수치화
from tensorflow.keras.preprocessing.sequence import pad_sequences   # 텍스트 데이터를 패딩하여 길이 고정
from sklearn.model_selection import train_test_split    # 훈련용 데이터셋과 검증용 데이터셋 분리


raw = pd.read_table('clean_comments/naver_shopping.txt',names=['rating','review'])   # 평점은 1~5까지. 악플 선플 라벨링은 없음
# print(raw)

raw['label']=np.where(raw['rating']>3, 1 , 0)   # 악플선플 라벨링. np.where(조건, 참-, 거짓-)
print(raw)

# 한글은 오타도 많고, 띄어쓰기도 정확하지 않는 경우가 많다.

raw['review']=raw['review'].str.replace('[^ㄱ-ㅎㅏ-ㅣ가-힣0-9 ]','',regex=True) # 한글 전처리(정규식). 영어 : A-Za-z []. 이 외 공백처리

print(raw.isnull().sum())
raw.drop_duplicates(subset=['review']) # pandas 중복처리
print(raw)

#bag of words
uniq_words=raw['review'].tolist()  # 리스트
uniq_words=''.join(uniq_words)  # 줄바꿈 되어있는 문장을 한 줄로 변경
uniq_words=list(set(uniq_words)) # 
uniq_words.sort()
print(uniq_words[0:100])



tokenizer=Tokenizer(char_level=True,oov_token='<OOV>')    # 글자 단위로 정수화 할 것. 새로운 신조어 발생 시 <OOV>로 치환

문자리스트=raw['review'].tolist()   # 여기 집어넣은 모든 문자들에 번호를 부여함  
tokenizer.fit_on_texts(문자리스트)  

# print(tokenizer.word_index)

train_seq=tokenizer.texts_to_sequences(문자리스트)    # 문장이 든 리스트를 숫자로 변형
print(train_seq[0:100])



raw['length']=raw['review'].str.len()   # 문장 최대 길이를 파악.

X=pad_sequences(train_seq, maxlen=120)  # 문장 최대 길이 한도 설정
Y=raw['label'].tolist()

# X : 댓글. 
# Y : 악플 여부(0 or 1)

trainX,valX,trainY,valY=train_test_split(X,Y,test_size=0.2,random_state=42)

# Ensure trainX and valX are NumPy arrays
trainX = np.array(trainX)
valX = np.array(valX)

# Ensure trainY and valY are NumPy arrays
trainY = np.array(trainY)
valY = np.array(valY)



# trainX(X)의 shape는 위에서 이미 선언
# model을 통해 나오는 trainY의 shape도 고정 필요

model=tf.keras.models.Sequential([
    tf.keras.layers.Embedding(len(tokenizer.word_index)+1,16,input_length=120),    # 원 핫 인코딩 대체 Embedding 레이어
    # batch_size, sequence_length,embedding_dim 총 3D 텐서 출력
    #글자를 16개의 벡터(행렬)로 변경
    
    tf.keras.layers.Flatten(),  # dense layer 사용을 위해서는 flatten 이용
    tf.keras.layers.Dense(64,activation='relu'),
    tf.keras.layers.Dense(32,activation='relu'),
    tf.keras.layers.Dense(1,activation='sigmoid')
    
])

model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy']) # sparse는 원 핫 인코딩이 안되어있을 때만 사용

# Train the model
model.fit(trainX, trainY, epochs=5, validation_data=(valX, valY))   

