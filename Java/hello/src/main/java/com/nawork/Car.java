package com.nawork;
import java.util.*;
public class Car {
    private int speed;
    private int volume;
    private int pos;
    Car(int a, int b, int c) {
        speed = a;
        volume = b;
	pos = c;
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
    
    public int VolumeUp(int a) {
	volume += a;
	return volume;
    }

    public int VolumeDecrease(int a) {
	    volume -= a;
	    return volume;
    }

    public int MoveForward(int a) {
	    pos += a;
	    return pos;
    }

    public int MoveBack(int a) {
	    pos -= a;
	    return pos;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Car car = new Car(0, 120, 0);
        car.setSpeed(30);
        System.out.println("Speed: " + car.getSpeed());
        System.out.println("SpeedUp 10:" + car.SpeedUp(10));
        System.out.println("SpeedDown 20:" + car.SpeedDown(20));
	System.out.println("VolumeDecrease 30:" + car.VolumeDecrease(30));
        String s = sc.nextLine();
        sc.close();
    }    
}
