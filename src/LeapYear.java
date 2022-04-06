import java.util.Scanner;


public class LeapYear {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);  //왜이렇게 길어?
		
		System.out.println("연도를 입력해주세요 : ");
		
		int year=input.nextInt();  
		
		boolean result=((year%4)==0);
		
		System.out.println(year+"년은 윤달인가.. 답은! "+result+"다!!!");
	}
}
