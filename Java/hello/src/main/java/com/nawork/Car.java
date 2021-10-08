package com.first;
import java.util.*;
public class Car {
    private int speed;
    private int volume;
    Car(int a, int b) {
        speed = a;
        volume = b;
    }

    public int getSpeed() {
        return speed;
    }

    public int setSpeed(int sp) {
        speed = sp;
        return speed;
    }

    public int SpeedUp(int a) {
        speed += a;
        return speed;
    }

    public int SpeedDown(int a) {
        speed -= a;
        return speed;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Car car = new Car(0, 120);
        car.setSpeed(30);
        System.out.println("Speed: " + car.getSpeed());
        System.out.println("SpeedUp 10:" + car.SpeedUp(10));
        System.out.println("SpeedDown 20:" + car.SpeedDown(20));
        String s = sc.nextLine();
        sc.close();
    }    
}
