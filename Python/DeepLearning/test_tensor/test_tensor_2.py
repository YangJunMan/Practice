import tensorflow as tf

# 딥러닝?
#1. 모델 만들어놓기
#2. 학습시키기

train_x=[1,2,3,4,5,6,7]
train_y=[3,5,7,9,11,13,15]

a=tf.Variable(0.1)
b=tf.Variable(0.1)


# 값을 입력했을 때, y값은 얼마가 나오는가? 예측해보자.
# 정수문제 : mean squared error를 자주 사용한다


def 손실함수():
    예측_y=train_x * a +b       # train_x가 리스트이지만, 각각 식을 계산
    return tf.keras.losses.mse(train_y,예측_y)      # 줄여서 mse

opt=tf.keras.optimizers.Adam(learning_rate=0.01)        # 변화가 너무 적은 것 같아? rate(조정 매개변수)를 크게
for i in range(1000):
    with tf.GradientTape() as tape:
        loss=손실함수()
    gradients=tape.gradient(loss,[a,b])
    opt.apply_gradients(zip(gradients,[a,b]))
    
    print(f"Step {i+1}: Loss = {loss.numpy()}, a = {a.numpy()}, b = {b.numpy()}")
    
# 실행 결과, loss값은 점점 줄어들고 a는 2, b는 1에 수렴      

# 이러한 과정을 거쳐서 결과를 출력하게 될 때! 그걸 딥러닝이라고 한다.