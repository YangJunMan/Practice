import java.util.Scanner;


public class QuadraticEq {

	public static void main(String[] args) {
		Scanner 입력받기=new Scanner(System.in);
		
		System.out.println("2차방정식에서 b값과 c값을 입력해주세요.");
		float fb=입력받기.nextFloat();
		float fc=입력받기.nextFloat();
		
		float floot=(float)Math.sqrt(fb*fb-4*1*fc);
		float fresult1=(float)(-fb+floot)/2;
		float fresult2=(float)(-fb-floot)/2;
		
		System.out.println("b가 -3이고, c가 2인 2차방정식의 해는"+fresult1+"와"+fresult2+"입니다");
		
	}

}
