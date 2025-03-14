package Basic.review.ExerciseCal;

public class Badminton extends Excercise implements CalorieInterface {

    int numMatches;
    // 배드민턴
    private Match match;
    public Badminton(double consumedCalories, int numMatches, Match match) {
        super(consumedCalories);
        this.match = match;
        this.numMatches = numMatches;
    }

    // getter, setter
    public Match getMatch() {
        return match;
    }

    public void setMatch(Match match) {
        this.match = match;
    }

    public int getNumMatches() {
        return numMatches;
    }

    public void setNumMatches(int numMatches) {
        this.numMatches = numMatches;
    }

    // 배드민턴 칼로리 계산.. n매치당 n*m세트, n*m*l경기
    @Override
    public void calcuateCalories() {
        setConsumedCalories(match.getCaloriePerDistance() * match.getNumSets() * numMatches);
    }
}
