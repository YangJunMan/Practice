import tensorflow as tf
import matplotlib.pyplot as plt     # 시각화 라이브러리.

# ((입력data,정답data), (test_x,test_y))
# ( (trainX,trainY), () )
# 흑백 사진 데이터


(trainX,trainY),(testX,testY)=tf.keras.datasets.fashion_mnist.load_data()       # tf 기본 쇼핑몰 이미지 데이터셋 가져오기

print(trainX[0])
print(trainX.shape)     #trainX의 이미지 갯수 * 픽셀. 총 60000*[[28]*28] 개의 데이터
print(trainY)       #trainX의 정답 data(라벨 값). 총 6만개의 사진 정답 데이터

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

# trainX에 있는 데이터를 그림으로 보여준다.
plt.imshow(trainX[0])
plt.show()