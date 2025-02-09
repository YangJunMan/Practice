package Basic.review.ExerciseCal;

public class Tennis extends Excercise implements CalorieInterface{
    int numMatches;
    private Match match;

    public Tennis(double consumedCalories, int numMatches, Match match) {
        super(consumedCalories);
        this.match = match;
        this.numMatches = numMatches;
    }
    // 테니스
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
    // 테니스 칼로리 계산.. n매치당 n*m세트, n*m*l경기
    @Override
    public void calcuateCalories() {
        setConsumedCalories(match.getCaloriePerDistance() * match.getNumSets() * numMatches);
    }

}
