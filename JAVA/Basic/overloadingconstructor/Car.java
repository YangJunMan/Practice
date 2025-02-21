package Basic.overloadingconstructor;

public class Car {

        String company="현대자동차";
        String model;
        String color;
        int maxSpeed;

        /*

        생성자. 이후에 Car() or Car('model') or Car('model','color').. 뭘 하든 실행 가능

        Car(){
        }
        Car(String model){
                this.model=model;
        }
        Car(String model,String color){
                this.model=model;
                this.color=color;
        }
        Car(String model,String color,int maxSpeed){
                this.model=model;
                this.color=color;
                this.maxSpeed=maxSpeed;
        }
        */

        Car(){
        }
        Car(String model){ // 최하단의 Car 호출
                // this로 이 Car 호출.
                this(model,"은색",250);
        }
        Car(String model,String color){ // 최하단의 Car 호출
                //this로 이 Car 호출.
                this(model,color,250);
        }
        
        // 여기 있는 Car 하나를 이용해 위의 다양한 생성자들을 간결하게 만들 수 있다
        Car(String model,String color,int maxSpeed){
                this.model=model;
                this.color=color;
                this.maxSpeed=maxSpeed;
        }

}