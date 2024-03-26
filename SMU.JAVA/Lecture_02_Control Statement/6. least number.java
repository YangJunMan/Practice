import java.util.Scanner;

public class Lec2Ex6 {

	public static void main(String[] args) {
	int s[]= {12,3,19,6,18,8,12,4,1,19};
	int small=s[0];
	
	for (int i=0; i<9;i++) {
		if(s[i]<=s[i+1]) {
			if(small>=s[i]) {
			small=s[i];
			}
		}
		else {
			if(s[i]>=s[i+1]) {
				if(small>=s[i]) {
				small=s[i+1];
				}
			}
		}	
	}
	
	System.out.print("가장 작은 숫자 : "+small);
	
	}

}
