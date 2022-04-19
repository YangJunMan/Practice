import java.util.*;
public class ManagerTest {
	public static void main(String[] args) {
		
		Manager tt=new Manager("준혁","서울",1000000,123456,50000);
		System.out.println(tt);
		tt.test();
		
	}
}
/*	
 * +는 퍼블릭
 * address는 string으로
 * -는 private
 *	#는 protected
 * Employee
 * +name : String
 *	address : String
 *	#salary : int
 *	-rrn:int
 *
 *	---
 *
 *	+toString():String
 *	
 *	
 *	Manager
 *	-bonus:int
 *+test():void
 * 
 */
