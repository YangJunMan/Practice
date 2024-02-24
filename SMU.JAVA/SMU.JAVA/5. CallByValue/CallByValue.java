import java.util.*;
public class CallByValue {
	int value=0;
	void cb(CallByValue value) {
		this.value=this.value+1;
	}
}
