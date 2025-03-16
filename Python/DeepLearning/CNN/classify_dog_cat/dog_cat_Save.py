import os
import tensorflow as tf
import matplotlib.pyplot as plt

train_dir='CNN/classify_dog_cat/dataset'
test_dir='CNN/classify_dog_cat/test'
trained_keras_dir='CNN/classify_dog_cat/trained_keras/model_jun_1.keras'
trained_weight_dir='CNN/classify_dog_cat/checkPoint/mnist.weights.h5'
train_ds=tf.keras.preprocessing.image_dataset_from_directory(
     directory=train_dir,
     image_size=(64,64),
     batch_size=64,
     subset='training',
     validation_split=0.2,
     seed=1234
)

val_ds=tf.keras.preprocessing.image_dataset_from_directory(
     directory=train_dir,
     image_size=(64,64),
     batch_size=64,
     subset='validation',
     validation_split=0.2,
     seed=1234
)

def 전처리함수(i, 정답):
     i=tf.cast(i/255.0,tf.float32)
     return i,정답

train_ds=train_ds.map(전처리함수)
val_ds=val_ds.map(전처리함수)

model = tf.keras.Sequential([
     tf.keras.layers.Conv2D( 32, (3,3),padding="same", activation="relu",input_shape=(64,64,3) ),
     tf.keras.layers.MaxPooling2D((2,2)),
     tf.keras.layers.Conv2D( 64, (3,3),padding="same", activation="relu"),
     tf.keras.layers.MaxPooling2D((2,2)),
     tf.keras.layers.Dropout(0.2),
     tf.keras.layers.Flatten(),
     tf.keras.layers.Dense(128, activation="relu"),
     tf.keras.layers.Dropout(0.2),
     tf.keras.layers.Dense(1, activation="sigmoid"),
])

콜백함수 = tf.keras.callbacks.ModelCheckpoint(
    filepath=trained_weight_dir,        # 저장 directory
    monitor='val_acc',      
    mode='max',        # 모니터링을 하며 val_acc가 max인 것만 저장
    save_weights_only=True,     # w (가중치) 저장
    save_freq='epoch'       # epoch이 끝날 때 마다 저장
)

model.summary()

model.compile( loss="binary_crossentropy",optimizer="adam",metrics=['accuracy'])
model.fit(train_ds,validation_data=val_ds,epochs=5,callbacks=[콜백함수])     # 콜백함수까지 적용

model.save(trained_keras_dir)     # 모델 저장

# 결과 : 정확성 약 0.8
# 데이터의 양 or 질을 늘려서 모델 정확성을 늘려야 함
