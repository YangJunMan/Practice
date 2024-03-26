
public class CallByValueTest {

	public static void main(String[] args) {
		CallByValue nc=new CallByValue();
		System.out.println("Call By Value의 Value값 = "+nc.value);
		//void cb 실행
		nc.cb(nc);
		System.out.println("Call By Value의 Value값 = "+nc.value);
	}

}
