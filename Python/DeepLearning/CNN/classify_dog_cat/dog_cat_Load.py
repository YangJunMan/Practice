import os
import tensorflow as tf
import matplotlib.pyplot as plt

train_dir='CNN/classify_dog_cat/dataset'
test_dir='CNN/classify_dog_cat/test'
trained_keras_dir='CNN/classify_dog_cat/trained_keras/model_jun_1.keras'
# 데이터셋 다시 불러오기 (정확도 측정을 위해)
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

val_ds=val_ds.map(전처리함수)

# 저장된 모델 불러오기
loaded_model = tf.keras.models.load_model(trained_keras_dir)

# 모델 평가
results = loaded_model.evaluate(val_ds)

# 결과 출력
print("Test loss:", results[0])
print("Test accuracy:", results[1])