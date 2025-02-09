package Basic.GetterSetter;

/* 
    단순하다. 객체를 set할 함수, get하는 함수!
    필드는 외부에서 접근하지 못하도록 private을 하고, 메소드를 통해서 필드의 값들을 수정하도록 유도한다
 */

public class Car {
    private int speed;
    private boolean stop;

    //getter
    public int getSpeed() {
      return speed;
    };
    public boolean isStop() {
        return stop;
    };

    //setter
    public void setSpeed(int speed) {
        if (speed<0){
            this.speed = 0;
        }else {
            this.speed = speed;
        }
    }
    public void setStop(boolean stop) {
        this.stop = stop;
        this.speed=0;
    }

    
}
