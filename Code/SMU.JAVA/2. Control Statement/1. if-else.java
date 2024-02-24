import java.util.*;

public class Lec2Ex1 {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
	int num1;
	int num2;
	System.out.print("첫번째 숫자를 입력하세요");
	num1=Input.nextInt();
	System.out.print("두번째 숫자를 입력하세요");
	num2=Input.nextInt();
	if(num1>num2) {
		System.out.print("첫번째 숫자("+num1+")가 두번째 숫자("+num2+")보다 큽니다");
	}
	else {
		System.out.print("두번째 숫자("+num2+")가 첫번째 숫자("+num1+")보다 큽니다");
	}
		
		
	}

}
