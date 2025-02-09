package Basic.review.ExerciseCal;

public interface CalorieInterface {

	// 추상클래스의 메소드는 추상메소드로 선언. caculate와 getConsumedCalories 이용 가능.
	void calcuateCalories();
	// get ConsumedCalories는 사용하지 않도록 코드 구현이 가능하기도 함. 하지만 저는 사용했어요
	double getConsumedCalories();

}
