import java.util.Scanner;

public class Lec2Ex7 {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
	int num;
	int s[]= {0,11,18,29,35,49,62,68,73,88,100};
	System.out.print("���ڸ� �Է��ϼ��� : ");
	num=Input.nextInt();
	for(int i=0;i<10;i++) {
		if(num>s[i]) {
			if(num<s[i+1]) {
				System.out.print(num+"��"+s[i]+"���� ũ��"+s[i+1]+"���� �۽��ϴ�.");
			}
		}
		else if(num==s[i]) {
			System.out.print(s[i]+"�� ��Ĩ�ϴ�.");
		}
		if(num<s[0]||num>s[10]) {
			System.out.print("��� �������� ������ �ʽ��ϴ�.");
			return;
		}
	}

	}
	
}
