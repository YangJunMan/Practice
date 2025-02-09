package Basic.review.ExerciseCal;

public class Match{
    // 기본 필드값 설정
    double caloriePerDistance;
    int numSets;

    public Match(double caloriePerDistance, int numSets) {
        this.caloriePerDistance = caloriePerDistance;
        this.numSets = numSets;
    }
    // getter, setter
    public double getCaloriePerDistance() {
        return caloriePerDistance;
    }

    public double getNumSets() {
        return numSets;
    }

    public void setCaloriePerDistance(double caloriePerDistance) {
        this.caloriePerDistance = caloriePerDistance;
    }

    public void setNumSets(int numSets) {
        this.numSets = numSets;
    }

}
