
public class Car {
	
	String color;
	int gear;
	int speed=0;

	void changeColor(String ch) {
		color=ch;
	}
	void changeGear(int ch) {
		gear=ch;
	}
	void speedUp(int ch) {
		speed=speed+ch;
	}
	void speedDown(int ch) {
		speed=speed-ch;
	}
	
	public String toString() {
	return "Car [color=" + color + ", speed=" + speed + ", gear=" + gear + "]";
	}
	
	
}


