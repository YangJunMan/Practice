import java.util.*;

public class Lec2Ex1 {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
	int num1;
	int num2;
	System.out.print("ù��° ���ڸ� �Է��ϼ���");
	num1=Input.nextInt();
	System.out.print("�ι�° ���ڸ� �Է��ϼ���");
	num2=Input.nextInt();
	if(num1>num2) {
		System.out.print("ù��° ����("+num1+")�� �ι�° ����("+num2+")���� Ů�ϴ�");
	}
	else {
		System.out.print("�ι�° ����("+num2+")�� ù��° ����("+num1+")���� Ů�ϴ�");
	}
		
		
	}

}
