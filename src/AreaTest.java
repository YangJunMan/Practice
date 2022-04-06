import java.util.Scanner;


public class AreaTest {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);  //왜이렇게 길어?
		
		System.out.println("반지름을 입력해주세요 : ");
		float radius=input.nextFloat(); //예상이 맞았다! float도 된다!
		
		final float PI=(float)3.141592; //PI값은 불변이지?
		float area=radius*radius*PI;

		System.out.println("반지름이"+radius+"인 원의 면적은"+area+"입니다.");
	}

}
