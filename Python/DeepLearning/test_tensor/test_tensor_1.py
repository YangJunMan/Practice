#tensorflow 2.15 
#2.17에선 Adam에 minimize 사용불가

import tensorflow as tf

# 신발=키*w1+w2 라고 했을 때 w1,w2를 구해보자.
# 이때, 변수 w1와 w2를 딥러닝으로 예측함.
# 변수값. (초기값). w1,w2가 좋은 값이 나올 때 까지 
신발=260
키=170

w1=tf.Variable(0.1)
w2=tf.Variable(0.2)


# tf.keras.optimizers 경사하강법
# .adam() : 경사를 조정해주는 알고리즘. ()-> 수치 조절가능

opt=tf.keras.optimizers.Adam(learning_rate=0.1)





def 손실함수(): # return tf.square(실제값 - 예측값) 
    예측값 = 키*w1 + w2
    return tf.square(260-예측값)    #square제곱을 해서 절댓값으로 변경


# 경사하강법
# GradientTape()를 사용 (과거방식 : opt.minimize(손실함수,var_list=[w1,w2]))
# var_list=[w1,w2] : 경사하강법으로 업데이트할 weight Variable 목록
# 경사하강법을 반복해 최적해 구함

for i in range(300):
    with tf.GradientTape() as tape:     #과거방식 : opt.minimize(손실함수,var_list=[w1,w2])
        loss=손실함수()
    gradients=tape.gradient(loss,[w1,w2])       #손실함수에 w1, w2를 넣어가며 경사하강법 실시
    
    opt.apply_gradients(zip(gradients,[w1,w2]))     #과거방식 : opt.minimize(손실함수,var_list=[w1,w2])
    print(f"Step {i+1}: w1 = {w1.numpy()}, w2 = {w2.numpy()}")
    

#실행 결과, 대충 1.52 와 1.62로 수렴
#신발 = 키*w1+w2라고 했을 때, '키'를 입력하면 신발의 값이 얼추 예측된다.
