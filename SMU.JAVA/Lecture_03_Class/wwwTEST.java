import java.util.*;

public class wwwTEST {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
		
		System.out.println("���ڿ��� �Է��ϼ��� : ");
		
		String add;
		
		add=Input.nextLine();
		
		char[] arr = new char[4];
		

		if(add.equals("quit")==true) {
			System.out.println("���α׷��� �����մϴ�.");
		}else {
			for(int i=0;i<3;i++) {
				if(add.charAt(i)!='w') {
					System.out.println("www�� �������� �ʽ��ϴ�.");
					return;
				}
			}
			System.out.println("www�� �����մϴ�.");
		}
	}
}
