import tensorflow as tf

musical_score_dir='RNN/musical_score.txt'

text=open(musical_score_dir,'r').read()
print(text)

uniq_text=list(set(text))
uniq_text.sort()

print(uniq_text)

text_to_num={}
num_to_text={}

for i, data in enumerate(uniq_text):
    text_to_num[data]=i
    num_to_text[i]=data
    
# print(text_to_num)
    
numbering_text=[]

for i in text:
    numbering_text.append(text_to_num[i])

# print(numbering_text)

# 0. 첫 입력값 만들기
# 1. predict로 다음문자 예측
# 2. predict한 다음문제 [] 저장하기
# 3. 첫 입력값 앞에 자르기
# 4. 예측한 다음 문자를 뒤에 넣기
# 5. 그 새로운 입력값을 predict 하기

first_input=numbering_text[117:117+25]
first_input=tf.one_hot(first_input,31)  # 원 핫 인코딩. 총 25개의 데이터
first_input=tf.expand_dims(first_input,axis=0)  # dimension 추가

trained_model=tf.keras.models.load_model('RNN/trained_keras/model_jun_1.keras')

import numpy as np

music=[]

for i in range(200):
    
    예측값 = trained_model.predict(first_input) # 예측값 = (확률. 확률. 확률). 25개의 데이터를 갖고 다음 값 예측
    예측값 = np.argmax(예측값[0])   # 예측 확률 중 가장 확률이 높은 데이터의 번호(index)
    # np.random.choice(uniq_text,1,p=예측값[0]) : 예측값[0]의 확률로 예측값을 뽑는다.
    # print(예측값)

    music.append(예측값)    # 인덱스 추가. 추후에 num_to_text를 이용해 변환 예정

    next_input=first_input.numpy()[0][1:]   # 리스트화, 

    one_hot_num=tf.one_hot(예측값,31)
    # print(one_hot_num)

    first_input=np.vstack([next_input,one_hot_num.numpy()])
    first_input=tf.expand_dims(first_input,axis=0) 
    # 다시 첫 입력값을 최신화

music_text=[]
for i in music:
    music_text.append(num_to_text[i])   # 예측된(확률이 높은) index들이 모여있는 music=[]을 text로 다시 변경

print(''.join(music_text))