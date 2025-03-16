import tensorflow as tf

# ((입력d,정답d), (test_x,test_y))
# ( (trainX,trainY), () )
# 흑백 사진 데이터

(trainX,trainY),(testX,testY)=tf.keras.datasets.fashion_mnist.load_data()       # tf 기본 쇼핑몰 이미지 데이터셋 가져오기

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

model = tf.keras.Sequential([       #레이어 3가지
    tf.keras.layers.Dense(128,input_shape=(28,28), activation="relu"),      #relu : 음수값은 0으로 설정 
    tf.keras.layers.Dense(64, activation="relu"),       # keras는 input_shape은 작성하지 않아도 알아서 됨
    tf.keras.layers.Flatten(),      #행렬을 1차원으로 나열해서 표현 (사용 주의)
    tf.keras.layers.Dense(10, activation="softmax"),        # 확률 0.0~1.0 까지 출력. 마지막 레이어는 출력해야 하는 카테고리 갯수만큼
])

model.summary()
exit()

model.compile( loss="sparse_categorical_crossentropy",
              optimizer="adam",
              metrics=['accuracy'])        #loss함수 = 정수로 카테고리 예측

model.fit(trainX,trainY,epochs=5)       # 5회 반복


