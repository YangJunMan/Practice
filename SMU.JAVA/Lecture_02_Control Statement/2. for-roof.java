import java.util.Scanner;

public class Lec3Ex2 {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
	int num;
	System.out.print("���ڸ� �Է��ϼ��� : ");
	num=Input.nextInt();
	System.out.print(num+"�� ����� ������ �����ϴ�. \n");
	
	for(int i=2;i<num;i++) {
		if (num%i==0) {
			System.out.print(i+" ");
		}
	}
	
	}

}
