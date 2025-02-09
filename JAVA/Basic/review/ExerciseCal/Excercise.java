package Basic.review.ExerciseCal;

// CalorieInterface를 상속받아 추상클래스로 선언.
public abstract class Excercise implements CalorieInterface {
	
	double consumedCalories;

	public Excercise(double consumedCalories) {

		this.consumedCalories = consumedCalories;
	}
	
	// getter, setter
	public double getConsumedCalories() {
		return consumedCalories;
	}

	public void setConsumedCalories(double consumedCalories) {
		this.consumedCalories = consumedCalories;
	}
	
	public void addCourse(Course course) {
		
		
	}

	// 칼로리 계산 override.
	@Override
	public void calcuateCalories() {
	}
	
}
