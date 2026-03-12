import java.util.*;
public class Bank {
	double getInterest() {
		return 0.0;
	}
	
	class Abank extends Bank{
		double getInterest() {
			return 10.0;
			}
		}

		class Bbank extends Bank{
		double getInterest() {
			return 5.0;
			}
		}

		class Cbank extends Bank{
		double getInterest() {
			return 3.0;
			}
		}
		
}

