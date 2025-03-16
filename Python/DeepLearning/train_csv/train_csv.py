import pandas as pd

data = pd.read_csv("train_csv/train.csv")
print(data.isnull().sum())

평균=data['Age'].mean() # 빈 age값에는 평균을 임의 삽입
print("평균 : ",평균)

data['Age'].fillna(value=30, inplace=True)

print(data['Embarked'].mode())

data['Embarked'].fillna(value='S', inplace=True)    # 빈 Embarked 값에는 최빈값 삽입

import tensorflow as tf

정답 = data.pop('Survived')
ds=tf.data.Dataset.from_tensor_slices((dict(data),정답))    # data는 Feature Dictionary로, 정답은 라벨(Tensor)로
print(ds)

# 각 열의 data들을 어떻게 다룰지 설정
# PassengerId,Survived,Pclass,Name,Sex,Age,SibSp,Parch,Ticket,Fare,Embarked

# 생존 확률 수치화에 필요 없는 제외할 것 PID , Name

# 숫자만 집어넣어야 하는 것 Fare Parchg SibSp : numberic_column
# 뭉퉁그려 넣을 것  Age : bucketized_column
# 기존 카테고리 데이터 Sex Embarked Pclass : indicater_column
# 종류가 너무 많은 카테고리 Ticket : embedding_column

feature_columns=[]
tf.feature_column.numeric_column('Fare')
tf.feature_column.numeric_column('Parch')
tf.feature_column.numeric_column('SibSp')
tf.feature_column.numeric_column('Age')
