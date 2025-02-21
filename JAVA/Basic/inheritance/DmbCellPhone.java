package Basic.inheritance;

// 자식 역할의 DmbCellPhone. CellPhone을 상속 받으며 변수와 메소드을 물러받아 사용할 수 있다
public class DmbCellPhone extends CellPhone {
    int channel;

    /*
        CellPhone을 상속받아 default 변수인 model, color를 사용할 수 있다.

    */
    DmbCellPhone(String model, String color, int channel) {
        this.model = model;
        this.color = color;
        this.channel = channel;
    };

    // 객체를 만들어 이 곳에서 사용할 수도 있다.
    CellPhone obj=new CellPhone();

    void turnOnDmb(){
        System.out.println("채널 "+channel+"번 DMB 방송 수신을 시작합니다.");
        // obj.hangup();
    }

    void changeChannelDmb(int channel){
        this.channel = channel;
        System.out.println("채널 "+channel +"번으로 바꿉니다");
    }

    void turnOffDmb(){
        System.out.println("DMB 방송 수신을 종료합니다.");
    };

}
