import os
import tensorflow as tf
import matplotlib.pyplot as plt
from tensorflow.keras.preprocessing.image import ImageDataGenerator

# 데이터 경로
train_dir = 'CNN/classify_dog_cat/dataset'
test_dir = 'CNN/classify_dog_cat/test'

# 이미지 데이터를 다양하게 생성해서 학습
# 데이터 증강 생성기
train_gen = ImageDataGenerator(
    rescale=1./255,
    rotation_range=20,      # 회전
    zoom_range=0.15,        # 확대
    width_shift_range=0.2,  # 가로 이동
    height_shift_range=0.2, # 세로 이동
    shear_range=0.15,       # 굴절
    horizontal_flip=True,   # 가로 반전
    fill_mode="nearest",    # 빈 영역 처리
    validation_split=0.2    # 검증 데이터 분리
)

# 증강이 없는 생성기 (검증용)
val_gen = ImageDataGenerator(
    rescale=1./255,
    validation_split=0.2
)

# 데이터 로드
train_ds = train_gen.flow_from_directory(
    directory=train_dir,
    target_size=(64, 64),
    batch_size=64,
    class_mode='binary',
    subset='training',
    seed=123
)

val_ds = val_gen.flow_from_directory(
    directory=train_dir,
    target_size=(64, 64),
    batch_size=64,
    class_mode='binary',
    subset='validation',
    seed=123
)

# 2. 이미지 증강 후 모델 대입. 이미지를 넣을 때 마다 이미지가 조금씩 변형되며 이미지 증강 
# model = tf.keras.Sequential([           
#   tf.keras.layers.RandomFlip('horizontal'),   # 랜덤으로 뒤집음      
#   tf.keras.layers.RandomRotation(0.1),   # 랜덤으로 돌림      
#   tf.keras.layers.RandomZoom(0.1),    # 랜덤 확대            

model = tf.keras.Sequential([
    tf.keras.layers.Conv2D(32, (3, 3), padding="same", activation="relu", input_shape=(64, 64, 3)),
    tf.keras.layers.MaxPooling2D((2, 2)),
    tf.keras.layers.Conv2D(64, (3, 3), padding="same", activation="relu"),
    tf.keras.layers.MaxPooling2D((2, 2)),
    tf.keras.layers.Dropout(0.2),
    tf.keras.layers.Flatten(),
    tf.keras.layers.Dense(128, activation="relu"),
    tf.keras.layers.Dropout(0.2),
    tf.keras.layers.Dense(1, activation="sigmoid"),
])

# 모델 요약
model.summary()

# 모델 컴파일
model.compile(
    loss="binary_crossentropy",
    optimizer="adam",
    metrics=['accuracy']
)

# 모델 훈련
model.fit(
    train_ds,
    validation_data=val_ds,
    epochs=5
)
