package Basic.review.ExerciseCal;

public class Course{
	// 기본 필드값 설정
	double caloriePerDistance;
	double distance;
	
	public Course(double caloriePerDistance, double distance) {
		this.caloriePerDistance = caloriePerDistance;
		this.distance = distance;
	}

	// getter, setter

	public double getCaloriePerDistance() {
		return caloriePerDistance;
	}
	
	public double getDistance() {
		return distance;
	}
	
	public void setCaloriePerDistance(double caloriePerDistance) {
		this.caloriePerDistance = caloriePerDistance;
	}
	
	public void setDistance(double distance) {
		this.distance = distance;
	}

}
