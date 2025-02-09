package Basic.Static;

/*
 static에 대한 이해.

 static을 선언할 경우 메모리에 바로 저장된다
 그렇기 때문에 별도로 추가 객체 참조 변수로 [Caculator cal=new Caculator();] 접근 할 필요가 없다
 객체 참조 변수로 접근하는 것도 가능하긴 하다
 Caculator의 plus를 사용하려면 ..=Caculator.plus(a,b); 로 선언하면 된다

 또한 static으로 선언된 메소드에선 내부에 '인스턴스' 필드에 선언된 변수, 함수를 사용할 수 없다
 왜냐하면 static이 사용되지 않은 '인스턴스'는 아직 메모리에 저장(실행)된 상태가 아니기 때문이다
 */

public class CaculatorExample {
    public static void main(String[] args) {
        double result1=10*10*Caculator.pi;
        int result2=Caculator.plus(3,4);
        int result3=Caculator.minus(3,4);

        System.out.println("plus2 : "+result2+"\nplus3 : "+result2);

    }
}
