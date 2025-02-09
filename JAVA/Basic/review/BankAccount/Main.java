package Basic.review.BankAccount;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        //기본 Bank의 기본 계좌는 없음으로 null. hashmap도 동일
        Bank bank = new Bank(null,new HashMap<>());
        // 계좌번호의 자리수를 결정하기 위한 NumberFormat
        java.text.NumberFormat nf = new java.text.DecimalFormat("000");

        while (true) {

            System.out.println("-------Bank System-------");
            System.out.println("1. Open Account");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Apply Interest");
            System.out.println("0. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            int countCheckingAccount = 0;
            int countSavingsAccount=0;
            //switch를 이용해 각각의 선택Z지에 따라 실행
            switch (choice) {
                case 1:{
                    System.out.println("1. Create Checking Account");
                    System.out.println("2. Create Savings Account");
                    System.out.print("Choose account type (1:Checking, 2:Savings):");

                    choice = scanner.nextInt();
                    switch(choice){
                        case 1:{

                            // 계좌번호 생성
                            String checkingAccountNumber = "C"+nf.format(countCheckingAccount);
                            // 초기 자본 밑 한도 설정
                            System.out.print("Enter initial balance: ");
                            double checkingInitialBalance = scanner.nextDouble();
                            System.out.print("Enter overdraft limit: ");
                            double overdraftLimit = scanner.nextDouble();
                            // hashmap를 이용해 계좌 정보를 추가 (계좌번호, 계좌정보)
                            bank.addAccount(new CheckingAccount(checkingAccountNumber,
                                    checkingInitialBalance,
                                    overdraftLimit));

                            break;}
                        case 2:{
                            // 계좌번호 생성
                            String savingsAccountNumber = "S"+nf.format(countSavingsAccount);
                            // 초기 자본 밑 한도 설정
                            System.out.print("Enter initial balance: ");
                            double savingsInitialBalance = scanner.nextDouble();
                            System.out.print("Enter interest rate: ");
                            double interestRate = scanner.nextDouble();
                            // hashmap를 이용해 계좌 정보를 추가 (계좌번호, 계좌정보)
                            bank.addAccount(new SavingsAccount(savingsAccountNumber,
                                    savingsInitialBalance,
                                    interestRate));
                            break;}
                    }
                    break;
                }
                case 2:{
                    // deposit 실행. 계좌 종류에 상관 없이 deposit 가능
                    System.out.print("Enter account number: ");
                    String depositAccountNumber = scanner.next();
                    System.out.print("Enter deposit amount: ");
                    double depositAmount = scanner.nextDouble();
                    bank.depositToAccount(depositAccountNumber, depositAmount);
                    break;
                }
                case 3:
                    // withdraw 실행. 계좌 종류에 따라 withdraw 가능 여부가 다름
                    System.out.print("Enter account number: ");
                    String withdrawAccountNumber = scanner.next();
                    System.out.print("Enter withdrawal amount: ");
                    double withdrawalAmount = scanner.nextDouble();
                    bank.withdrawFromAccount(withdrawAccountNumber, withdrawalAmount);
                    break;
                case 4:
                    // applyInterest 실행. SavingsAccount에만 적용 가능
                    System.out.print("Enter account number: ");
                    String interestAccountNumber = scanner.next();
                    bank.applyInterestToAccount(interestAccountNumber);
                    break;
                case 0:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
