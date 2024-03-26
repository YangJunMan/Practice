package text1;
import java.util.Scanner;
import java.util.Arrays;

public class Arrayssort {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int[] a= {5,9,1,7,2,5};
		int[][] b=
			{
					{10,11,9,8},
					{6,5,4,3},
					{10,6,11,3}
			};
		
Arrays.sort(a);

System.out.print("a");
System.out.println();

		for(int i=0;i<6;i++) {
			
			System.out.print(a[i]+" ");
			
}
		
System.out.println();

Arrays.sort(b[1]);
	
System.out.print("b");
System.out.println();
		for(int i=0;i<3;i++) {
	for(int j=0;j<4;j++) {

		System.out.print(b[i][j]+" ");

		}
	System.out.println();
	}
		
}
}
