

public class BankTest {

	public static void main(String[] args) {
		Abank A=new Abank();
		Bbank B=new Bbank();
		Cbank C=new Cbank();
		
		System.out.println(Abank.getInterest());
		System.out.println(Bbank.getInterest());
		System.out.println(Cbank.getInterest());
	}

}
