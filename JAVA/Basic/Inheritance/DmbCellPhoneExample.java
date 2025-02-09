package Basic.Inheritance;

public class DmbCellPhoneExample {
    public static void main(String[] args) {
        // 부모인 CellPhone이 아니라 자식인 DmbCellPhone을 객체로 생성한다
        DmbCellPhone obj = new DmbCellPhone("자바폰","검정",10);
        
        // 상속받은 model, color와 본 필드의 channel 모두 사용 가능하다
        System.out.println("모델 : "+obj.model);
        System.out.println("색상 : "+obj.color);
        System.out.println("채널 : "+obj.channel);

        // 부모 클래스의 메소드
        obj.powerOn();
        obj.bell();
        obj.sendVoice("A : 안녕하세요, 여보세요?");
        obj.receiveVoice("B : 안녕하세요! 저는 홍길동이에요");
        obj.sendVoice("A : 아 네 반갑습니다");
        obj.hangup();
        
        // 자식 클래스의 메소드
        obj.turnOnDmb();
        obj.changeChannelDmb(12);
        obj.turnOffDmb();
    }
}
