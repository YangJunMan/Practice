개와 고양이 이미지를 학습하여 분류해보는 프로그램을 짜봅니다.

test 데이터에서 일부를 validation 데이터로 사용합니다. 
(기존 train에 사용된 test 데이터를 validation에서 다시 사용하지 않도록 주의합시다)

이미지를 padding처리를 해줍니다
활성화함수(activation) relu를 통해 음수값 (의도하지 않은 값)이 나오지 않도록 합니다
Classification임으로 출력은 sigmoid를 통해 0 과 1의 값을 나타내도록 합니다

각각의 이미지 데이터들을 다양한 모양으로 변형시킨 후 다시 학습시켜보기도 합니다. (데이터 증강)

학습 데이터는.. 하단의 주소에서 개와 고양이 이미지를 다운로드 받습니다.
https://www.kaggle.com/competitions/dogs-vs-cats-redux-kernels-edition/data

