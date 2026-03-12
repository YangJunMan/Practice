import java.util.*;

public class Manager extends Employee{
	private int bonus;
	
	//Employee에 있는 name, address, salary, rrn 등 상속
	public Manager(String name, String address, int salary, int rrn, int bonus) {
		super(name, address, salary, rrn);
		this.bonus=bonus;
	}
	
	//Employee를 상속한 Manager클래스 안에 void test() 생성함!
	public void test() {
		System.out.println("name="+name);
		System.out.println("address"+address);
		System.out.println("salary="+salary);

	}



}
