package Basic.review.BankAccount;

public interface AccountInterface {

// getter, setter
    // 인터페이스의 메소드는 본문을 가질 수 없다. {}괄호를 없애면 오류가 없어진다
    //
    public void deposit(double amount);
    public void withDraw(double amount);
    public void applyInterest();
}
