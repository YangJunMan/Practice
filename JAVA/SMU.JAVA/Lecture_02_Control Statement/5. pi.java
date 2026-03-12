import java.util.Scanner;

public class Lec2Ex5 {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
	int num;
	System.out.print("반복할 횟수를 입력하세요 : ");
	num=Input.nextInt();
	
	double sum=0;
	double A;
	
	for(int i=1;i<=num;i++) {
		
		A=(double)4/(2*i-1);
		if(i%2==0) {
			A=A*(-1);
		}
		sum=sum+A;
		
	}
	System.out.print(num+"번 반복한 파이 구하기: "+(double)sum);
	}
}
