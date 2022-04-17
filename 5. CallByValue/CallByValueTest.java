
public class CallByValueTest {

	public static void main(String[] args) {
		CallByValue nc=new CallByValue();
		System.out.println("기존 값 = "+nc.value);
		nc.cb(nc);
		System.out.println("전달 후 값 = "+nc.value);
	}

}
