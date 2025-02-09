package Basic.Method;

public class ComputerExample {
    public static void main(String[] args) {
        Computer mycp = new Computer();
        int[] values = {1,2,3,14};
        int result1=mycp.sum1(values);
        System.out.println("sum1(fit) : "+result1);

        int result2=mycp.sum1(new int[] {1,2,3,4,14});
        System.out.println("sum1(over) : "+result2);

        int result3=mycp.sum2(values);
        System.out.println("sum2(fit) : "+result3);
        
        // ...을 사용해 배열을 사용하지 않고 숫자를 대입해도 된다
        int result4=mycp.sum2(1,2,3,4,14);
        System.out.println("sum2(over) : "+result4);
    }
}
