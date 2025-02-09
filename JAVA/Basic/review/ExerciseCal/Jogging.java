package Basic.review.ExerciseCal;

public class Jogging extends Excercise implements CalorieInterface{
    private Course course;

    // 조깅
    public Jogging(double consumedCalories, Course course) {
        super(consumedCalories);
        this.course = course;
    }


    // getter, setter
    public Course getCourse() {
        return course;
    }

    public void setCourse(Course course) {
        this.course = course;
    }


    @Override
    public void calcuateCalories() {
        setConsumedCalories(course.getCaloriePerDistance() * course.getDistance());
    }
}
