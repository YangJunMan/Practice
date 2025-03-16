import os 
import tensorflow as tf
import matplotlib.pyplot as plt

# cmd 명령어로 kaggle에 있는 데이터를 가져옵니다.
# kaggle competitions download -c [COMPETITION_NAME]
train_dir='CNN/classify_dog_cat/dataset'
test_dir='CNN/classify_dog_cat/test'

# 디렉터리 구조에서 자동으로 라벨링
train_ds=tf.keras.preprocessing.image_dataset_from_directory(   # ( (x~), (y~) ) 저장. y~부분엔 분류결과 0,1 설정
    directory=train_dir,
    image_size=(64,64),     # 이미지를 64*64 픽셀로 변경.
    batch_size=64,
    subset='training',     # 트레이닝 데이터
    validation_split=0.2,   # validation_Data 를 추가하여 정확도 등 확인
    seed=1234       # 배치를 뽑을 때 랜덤하게 뽑는데, 시드를 정해놔야 똑같이 뽑힘
)

# 전체 데이터의 20%를 검증 데이터로 활용
val_ds=tf.keras.preprocessing.image_dataset_from_directory(   # ( (x~), (y~) ) 저장. y~부분엔 분류결과 0,1 저장
    directory=train_dir,
    image_size=(64,64),     
    batch_size=64,
    subset='validation',   
    validation_split=0.2,
    seed=1234
)

# print(train_ds)
# 25000개의 데이터. 그 중 5000개는 검증데이터

def 전처리함수(i, 정답):
    i=tf.cast(i/255.0,tf.float32)
    return i,정답

train_ds=train_ds.map(전처리함수)   # train_ds의 데이터 숫자들(0~255.0)을 0.~ 로 변경
val_ds=val_ds.map(전처리함수)

# 합성곱 신경망 (CNN) 구조
model = tf.keras.Sequential([
    tf.keras.layers.Conv2D( 32, (3,3),padding="same", activation="relu",input_shape=(64,64,3) ),    # 컬러는 (,3)
    tf.keras.layers.MaxPooling2D((2,2)),
    tf.keras.layers.Conv2D( 64, (3,3),padding="same", activation="relu"),       # input_shape는 한개만
    tf.keras.layers.MaxPooling2D((2,2)),
    tf.keras.layers.Dropout(0.2),       # 학습 데이터를 너무 반복하면 외워짐. 그러면 dropout. 윗 레이러 노드 일부 제거
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(128, activation="relu"),
    tf.keras.layers.Dropout(0.2),  
    tf.keras.layers.Dense(1, activation="sigmoid"),        # 개 or 고양이 두종류. 0~1. binary와 함께 사용
])

model.summary()

from tensorflow.keras.callbacks import TensorBoard 
import time

tensorboard = TensorBoard(log_dir='CNN/classify_dog_cat/logs/{}'.format( '첫모델 :',int(time.time()) ) )

# 이진 교차 엔트로피 손실 함수 사용
model.compile( loss="binary_crossentropy",optimizer="adam",metrics=['accuracy'])

from tensorflow.keras.callbacks import EarlyStopping

es=EarlyStopping(monitor='val_accuracy',patience=5,mode='max') # accuracy의 값이 줄어들기 시작하면 조기종료

model.fit(train_ds,validation_data=val_ds,epochs=5,callbacks=[tensorboard])

# 결과 : 정확성 약 0.8
# 데이터의 양 or 질을 늘려서 모델 정확성을 늘려야 함

# tensorboard 실행 : tensorboard --logdir=CNN/classify_dog_cat/logs/




