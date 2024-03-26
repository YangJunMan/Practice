package ex5;

public class OverLoading {
	private int number;
	private String name;
	private int age;

	OverLoading(){
		number=100;
		name="New Student";
		age=18;
	}
	
	OverLoading(int number,String name,int age){
		this.number=number;
		this.name=name;
		this.age=age;
	}
	
	public void print() {
		System.out.println(number);
	}
	
	public String toString() {
		return "Student[number="+number+",name="+name+",age="+age+"]";
	}


}
