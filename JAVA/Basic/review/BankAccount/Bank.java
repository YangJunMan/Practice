package Basic.review.BankAccount;

import java.util.*;

public class Bank {
    // account 객체를 생성
    private Account account;

// hashmap을 사용하여 계좌 정보를 저장
// hashmap이란? HashMap은 데이터를 저장할 때 키(Key)와 밸류(Value)가 짝을 이루어 저장된다.
    // 이후 Key에는 Checking account의 경우 C + 000~999 가 KEY로 주어진다.
    private HashMap<String, Account> accounts = new HashMap<>();

    public Bank(Account account, HashMap<String, Account> accounts) {
        this.account = account;
        this.accounts = accounts;
    }

    // addAccount : 계좌 정보를 추가
    public void addAccount(Account account) {
        accounts.put(account.getAccountNumber(), account);
        System.out.println("-------Account Opended-------");
        System.out.println("Account Number: " + account.getAccountNumber());
        System.out.println("Initial Balance: " + account.getBalance());
        // chekingaccount라면
        if (account instanceof CheckingAccount) {
            System.out.println("Overdraft Limit: "
                    + ((CheckingAccount) account).getOverdraftLimit());
        }
        // savingsaccount라면
        else if (account instanceof SavingsAccount) {
            // account에 종속되어있는 savingsaccount의 interestrate를 가져옴.
            System.out.println("Interest Rate(%): " + ((SavingsAccount) account).getInterestRate());
        }
        else{
            System.out.println("Account_type not found");
        }
    }

// getAccount : 계좌 정보를 가져옴

    public void depositToAccount(String accountNumber, double amount) {
        Account account = accounts.get(accountNumber);
            if (account != null) {
                System.out.println("-------Account Deposit-------");
                System.out.println("Account Number: " + account.getAccountNumber());
                System.out.println("Initial Balance: " + account.getBalance());
// deposit 실행
                account.deposit(amount);

                System.out.println("deposited: " + amount);
                System.out.println("New Balance: " + account.getBalance());

            }else{
                System.out.println("Account not found");
            }

    }

    public void withdrawFromAccount(String accountNumber, double amount) {
        Account account = accounts.get(accountNumber);
        if(accountNumber.charAt(0)=='C') {
// 계좌의 balance 양, overdraftlimit 양을 비교하여 withdraw 가능 여부 확인
// account에 종속되어있는 Checking saccount의 OverdraftLimit를 가져옴.
            if (account != null && account.getBalance()>=amount && ((CheckingAccount) account).getOverdraftLimit()>=amount) {
                System.out.println("-------Withdraw Success-------");
                System.out.println("Account Number: " + account.getAccountNumber());
                System.out.println("Initial Balance: " + account.getBalance());

                account.withDraw(amount);

                System.out.println("Withdrawl amount " + amount);
                System.out.println("New Balance: " + account.getBalance());

            }else{
// withdraw 실패
                System.out.println("-------Withdraw Failed-------");
                System.out.println("Invalid withdrawal amount.");
            }

        }
        else{

            System.out.println("-------withdraw Failed-------");
            System.out.println("withdraw not allowed on Savings Account");
        }
    }

    public void applyInterestToAccount(String accountNumber) {
        Account account = accounts.get(accountNumber);
        if(accountNumber.charAt(0)=='S') {
            // 계좌의 balance에 interest를 적용
            if (account != null) {
                System.out.println("-------Apply Interested-------");
                System.out.println("Account Number: " + account.getAccountNumber());
                System.out.println("Initial Balance: " + account.getBalance());


                System.out.println("InterestRate :"
                        + ((SavingsAccount) account).getInterestRate());

                System.out.println("deposited :"
                        + (((SavingsAccount) account).getInterestRate()/100)*account.getBalance());

                // 후반부
                //Interest 적용
                account.applyInterest();
                System.out.println("New Balance: " + account.getBalance());

                System.out.println("-------Interested Applied-------");
                System.out.println("Account Number: " + account.getAccountNumber());
                System.out.println("Initial Balance: " + account.getBalance());

                System.out.println("InterestRate :"
                        + ((SavingsAccount) account).getInterestRate()+"%");

                System.out.println("New Balance: " + account.getBalance());


            }else{
                System.out.println("There are no account with that number");
            }

        }
        else{

            System.out.println("-------Interest Application Failed-------");
            System.out.println("Interest not applied to Checking Account");
        }

    }
}
