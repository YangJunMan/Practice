import java.util.Scanner;

public class Lec3Ex2 {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
	int num;
	System.out.print("숫자를 입력하세요 : ");
	num=Input.nextInt();
	System.out.print(num+"의 약수는 다음과 같습니다. \n");
	
	for(int i=2;i<num;i++) {
		if (num%i==0) {
			System.out.print(i+" ");
		}
	}
	
	}

}
