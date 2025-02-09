package hon.GetterSetter;

public class CarExample {
    public static void main(String[] args) {
        Car myCar = new Car();

        myCar.setSpeed(-50);

        System.out.println("myCar speed.(set -50) : "+myCar.getSpeed());

        myCar.setSpeed(50);

        System.out.println("myCar speed.(set 50) : "+myCar.getSpeed());

        if (!myCar.isStop()){
            myCar.setStop(true);
        }
        System.out.println("myCar stop.(set true) : "+myCar.isStop());
    }
}
