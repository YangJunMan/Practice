import java.util.*;

public class TestCar {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Car mycar=new Car();
		System.out.println("���� ������ �Է��ϼ���");
		String color=scan.nextLine();
		mycar.changeColor(color);
		System.out.println("���� ���ǵ带 �󸶳� �ø����?");
		int speed=scan.nextInt();
		mycar.speedUp(speed);
		System.out.println("���� �� ��� �ٲܱ��?");
		
		int gear=scan.nextInt();
		mycar.changeGear(gear);

		
		System.out.println(mycar.toString());
	}
}

