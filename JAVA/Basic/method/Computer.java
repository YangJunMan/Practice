package Basic.method;

public class Computer {
    int sum1(int [] values) {
        int sum = 0;
        for (int i = 0; i < values.length; i++) {
            sum += values[i];
        };
        return sum;
    }

    // ...을 통해 입력받는 변수의 개수에 따라 자동으로 배열이 생성된다. 즉, 매개변수의 개수를 몰라도 된다.
    int sum2(int ... values) {
        int sum = 0;
        for (int i = 0; i < values.length; i++) {
            sum += values[i];
        }
        return sum;
    };
}
