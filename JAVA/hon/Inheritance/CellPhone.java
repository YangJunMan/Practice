package hon.Inheritance;

// 부모 클래스 역할의 CellPhone.

public class CellPhone {
    String model;
    String color;
    void powerOn() {
        System.out.println("power on");};
    void powerOff() {};
    void bell(){};

    void sendVoice(String message){
        System.out.println("메세지를 보냅니다 : "+message);
    };
    void receiveVoice(String message){
        System.out.println("상대방 : "+message);
    };
    void hangup(){
        System.out.println("전화를 끊습니다");
    }
}
