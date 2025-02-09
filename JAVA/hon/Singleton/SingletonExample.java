package hon.Singleton;

// 싱글톤은 말 그대로 단 하나의 인스턴스만 생성한다. 때문에 여러 클래스들에서 하나의 동일한 인스턴스로 접근하기 좋다

public class SingletonExample {
    public static void main(String[] args) {
        /*
            싱글톤 사용 시 여러 객체 참조를 만들어 내는 것은 불가능
            Singleton obj1=new Singleton();
            Singleton obj2=new Singleton();

         */

        // 싱글톤은 여러 객체로 만들지 않았고, 또한 static으로 선언되었기 때문에 하나의 instance만 return받을 수 있다
        Singleton obj1 = Singleton.getInstance();
        Singleton obj2 = Singleton.getInstance();

        if (obj1==obj2){
            System.out.println("obj1 and obj2 are the same");
        }
        else{
            System.out.println("obj1 and obj2 are not the same");
        }

    }
}
