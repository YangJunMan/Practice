package Basic.accessmodifier;

public class ClassA {
    //필드
    ClassA a1 = new ClassA(true);
    ClassA a2 = new ClassA(1);
    ClassA a3 = new ClassA("문자열");

    //생성자
    public ClassA(boolean B) {};    // public은 아무데나 접근 가능
    ClassA(int b){};    // default는 다른 패키지에선 호출 불가능
    private ClassA(String s){}; // private은 현재 ClassA 내에선 호출이 가능하지만 그 외엔 불가능

}
