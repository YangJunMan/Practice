package ex5;

public class ControlClass {
	
	public void setAge(int age) {
		if (age<0) {
			System.out.println("false");
		}
		if (age>0) {
			System.out.println("나이는 "+age+" 입니다.");
		}
	}

}
