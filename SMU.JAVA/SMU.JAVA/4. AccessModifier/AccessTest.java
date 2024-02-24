package ex5;
import java.util.*;

public class AccessTest {

	public static void main(String[] args) {
		Access my=new Access();
		ControlClass age=new ControlClass();
		Scanner input=new Scanner(System.in);
		String s;
		s=input.nextLine();
		my.setName(s);
		
		my.setBalance(100000);
		
		age.setAge(10);
		
		System.out.println("이름은 "+my.getName()+" 이고"+" 통장의 잔고는 "
				+ my.getBalance()+"원 입니다.");
		
		
	}
}
