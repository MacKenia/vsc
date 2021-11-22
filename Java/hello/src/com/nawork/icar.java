package com.nawork;

import java.util.*;

public class icar {
    public static void main(String[] args) {
        Car c = new Car(0, 100, 0);
        Scanner sc = new Scanner(System.in);
        boolean flag = true;
        while (flag) {
            System.out.print("请选择操作：\n1.加速\n2.减速\n3.向前移动\n4.向后移动\n5.显示状态\n6.退出\n>");
            int choice = sc.nextInt();
            int tmp;
            switch (choice) {
                case 1:
                    System.out.print("请输入速度：");
                    tmp = sc.nextInt();
                    System.out.println("更改后的速度为：" + c.SpeedUp(tmp));
                    break;
                case 2:
                    System.out.print("请输入速度：");
                    tmp = sc.nextInt();
                    System.out.println("减速后的速度为：" + c.SpeedDown(tmp));
                    break;
                case 3:
                    System.out.print("请输入移动距离：");
                    tmp = sc.nextInt();
                    System.out.println("移动后的位置：" + c.MoveForward(tmp));
                    break;
                case 4:
                    System.out.print("请输入移动距离：");
                    tmp = sc.nextInt();
                    System.out.println("移动后的位置：" + c.MoveBack(tmp));
                    break;
                case 5:
                    System.out.println("速度：" + c.getSpeed() + "\n体积为：" + c.VolumeUp(0) + "\n位置为：" + c.MoveBack(0));
                    break;
                case 6:
                    flag = false;
            }
        }
        sc.close();

    }
}
