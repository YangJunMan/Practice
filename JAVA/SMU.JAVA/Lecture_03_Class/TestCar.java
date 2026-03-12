import java.util.*;

public class TestCar {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Car mycar=new Car();
		System.out.println("차의 색깔을 입력하세요");
		String color=scan.nextLine();
		mycar.changeColor(color);
		System.out.println("차의 스피드를 얼마나 올릴까요?");
		int speed=scan.nextInt();
		mycar.speedUp(speed);
		System.out.println("차의 기어를 어떻게 바꿀까요?");
		
		int gear=scan.nextInt();
		mycar.changeGear(gear);

		
		System.out.println(mycar.toString());
	}
}

