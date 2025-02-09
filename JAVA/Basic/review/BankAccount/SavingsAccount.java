package Basic.review.BankAccount;

public class SavingsAccount extends Account{
    private double interestRate;

    public SavingsAccount(String accountNumber, double balance, double interestRate) {
        super(accountNumber, balance);
        this.interestRate = interestRate;
    }

    //getters and setters
    public double getInterestRate() {

        return interestRate;
    }

    public void setInterestRate(double interestRate) {

        this.interestRate = interestRate;
    }

    //methods
    @Override
    public void withdraw(double amount) {
    }


    @Override
    public void applyInterest() {
        setBalance(getBalance()+ getBalance() * interestRate/100);
    }

}
