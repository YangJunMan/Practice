package Basic.review.BankAccount;

public class CheckingAccount extends Account{
// 기본 변수
    private double overdraftLimit;
// 기본 생성자
    public CheckingAccount(String accountNumber, double balance, double overdraftLimit) {
        super(accountNumber, balance);
        this.overdraftLimit = overdraftLimit;
    }

    //getters and setters
    public double getOverdraftLimit() {
        return overdraftLimit;
    }

    public void setOverdraftLimit(double overdraftLimit) {
        this.overdraftLimit = overdraftLimit;
    }


    //methods
    @Override
    public void withDraw(double amount) {
        if (getBalance() >= amount) {
            setBalance(getBalance()- amount) ;
        }else{

            System.out.println("-------Withdraw Failed-------");
            System.out.println("Invalied withdrawal amount.");
        }
    }

    @Override
    public void applyInterest() {
    }

}
