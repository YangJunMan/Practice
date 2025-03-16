# convolutional layer. (feature map) 입력 레이어에서 중요한 특징을 뽑아 새로운 layer 생성
# 단순 convolutional 만 이용하면 그림의 위치만 바뀌어도 인식을 못한다.
# pooling layer : 중요한 부분만 모아서 layer를 만듦. 예시 : 공백 삭제 및 data 중앙으로 이동
# kernel 디자인. ~~강조 kernel을 통해 이미지를 여러가지 분류한다.

import tensorflow as tf
import numpy as np

# 학습에 사용되는 train_X (숫자로 표현된 이미지), 라벨링 train_Y
# 

(trainX,trainY),(testX,testY)=tf.keras.datasets.fashion_mnist.load_data()       
trainX=trainX/255.0 # 데이터 0~255 값을 0~1로 압축
testX=testX/255.0

# 기존 3차원 (60000*[[28]*28])을 4차원으로 늘림
trainX=trainX.reshape((trainX.shape[0],28,28,1))
testX=testX.reshape((testX.shape[0],28,28,1))

# 레이블 정의
fashion_mnist_labels = ["T-shirt/top",  # 인덱스 0
                        "Trouser",      # 인덱스 1
                        "Pullover",     # 인덱스 2
                        "Dress",        # 인덱스 3
                        "Coat",         # 인덱스 4
                        "Sandal",       # 인덱스 5
                        "Shirt",        # 인덱스 6
                        "Sneaker",      # 인덱스 7
                        "Bag",          # 인덱스 8
                        "Ankle boot"]   # 인덱스 9

model = tf.keras.Sequential([   #레이어 3가지
    #tf.keras.layers.Dense(128,input_shape=(28,28), activation="relu")
    tf.keras.layers.Conv2D( 32, (3,3),padding="same", activation="relu",input_shape=(28,28,1) ), # 컬러사진은(28,28,3) 
    # 32개의 다른 feature를 생성. kernal 가로세로사이즈는 (3,3). 크기 same고정. conv2d는 4차원 데이터까지 가능
    
    tf.keras.layers.MaxPooling2D((2,2)), # 2D사진을 가운데로 모음
    tf.keras.layers.Flatten(),  # 다차원 데이터를 Flatten하여 표현
    tf.keras.layers.Dense(128, activation="relu"),  
    tf.keras.layers.Dense(10, activation="softmax"),
])

model.summary()

model.compile( loss="sparse_categorical_crossentropy",optimizer="adam",metrics=['accuracy']) #loss함수 = 정수로 카테고리 예측
#model.fit(trainX,trainY,epochs=5) # 5회 반복
model.fit(trainX,trainY,validation_data=(testX,testY),epochs=5) # validation_data를 통해 각각의 학습마다 각각의 점수를 낸다.


score=model.evaluate(testX, testY)    # 모델을 작동시켜보며 정확도 측정
print(score)

# epochs의 5번째 정확도 0.94
# 총 결과의 정확도는 0.9; 왜 낮은가? 기존에 있던 데이터들로만 학습을 하여 새로운 데이터에 약할 수 있음