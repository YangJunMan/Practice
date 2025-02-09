package Basic.Static;

// static을 이용하면 메모리에 선입력되기 때문에 이와 관련된 오류를 조심해야한다

public class ClassName {
    int filed1;
    void method1(){
        System.out.println("이것은 인스턴스필드의 함수입니다");
    }

    static int filed2;
    static void method2(){
        System.out.println("이것은 static필드의 함수입니다");
    }

    static void method3(){
        /*
        사용 불가. static 필드 안에 인스턴스 필드 변순느 사용불가
        this.filed1=10;
        this.method1();
         */
        
        filed2=10; // static으로 선언된 변수와 함수는 사용가능.
        method2();
        
    }

    // static 메소드에서 인스턴스 객체를 사용하기 위해선 객체 참조를 선언해 메모리에 등록해야 사용 가능하다
    static void method4(){
        ClassName obj=new ClassName();
        obj.filed1=20;
        obj.method1();
    }


}
