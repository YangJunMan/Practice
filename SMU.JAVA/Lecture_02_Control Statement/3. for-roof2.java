import java.util.Scanner;

public class Lec3Ex3 {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
	int num;
	int count=0;
	System.out.print("���ڸ� �Է��ϼ��� : ");
	num=Input.nextInt();
	int j;
	
	int two=0;
	
	System.out.print("�Ҽ� : ");
	for(int i=2;i<num;i++) {
		for (j=1;j<num;j++) {
			if(i%j==0) {
				two++;
			}
		}
		if(two==2) {
			System.out.print(i+" ");
		}
		two=0;
	}
}
}
