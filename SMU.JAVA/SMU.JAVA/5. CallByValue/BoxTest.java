
public class BoxTest {

	public static void main(String[] args) {
		Box box1=new Box(50,30,40);
		Box box2=new Box(50,30,40);
		
		System.out.println("box1과 box2는 같나요? : "+box1.isSameBox(box2));
		
		Box box3=new Box(50,30,40);
		Box box4=new Box(40,30,40);
		
		System.out.println("box3과 box4는 같나요? : "+box3.isSameBox(box4));
		

	}

}
