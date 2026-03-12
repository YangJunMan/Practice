import java.util.*;

public class wwwTEST {

	public static void main(String[] args) {
		Scanner Input=new Scanner(System.in);
		
		System.out.println("문자열을 입력하세요 : ");
		
		String add;
		
		add=Input.nextLine();
		
		char[] arr = new char[4];
		

		if(add.equals("quit")==true) {
			System.out.println("프로그램을 종료합니다.");
		}else {
			for(int i=0;i<3;i++) {
				if(add.charAt(i)!='w') {
					System.out.println("www로 시작하지 않습니다.");
					return;
				}
			}
			System.out.println("www로 시작합니다.");
		}
	}
}
