import java.util.Scanner;

public class Lec2Ex7 {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
	int num;
	int s[]= {0,11,18,29,35,49,62,68,73,88,100};
	System.out.print("숫자를 입력하세요 : ");
	num=Input.nextInt();
	for(int i=0;i<10;i++) {
		if(num>s[i]) {
			if(num<s[i+1]) {
				System.out.print(num+"은"+s[i]+"보다 크고"+s[i+1]+"보다 작습니다.");
			}
		}
		else if(num==s[i]) {
			System.out.print(s[i]+"과 겹칩니다.");
		}
		if(num<s[0]||num>s[10]) {
			System.out.print("어느 범위에도 속하지 않습니다.");
			return;
		}
	}

	}
	
}
