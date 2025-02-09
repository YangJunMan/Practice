package Basic.Inheritance;

public class NewCellPhoneOverload extends CellPhone {

    NewCellPhoneOverload(String model, String color) {
        this.model = model;
        this.color = color;
    }

    @Override
    void powerOn(){
        System.out.println("New Power on");
    };

    @Override
    void hangup(){
        System.out.println("새 전화를 끊습니다");
    }
}
