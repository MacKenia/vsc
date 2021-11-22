package com.ass1118;

import java.util.Scanner;

public class Guess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int answer = (int)(Math.random() * 100) % 100;
        System.out.print("快猜: ");
        int guess = sc.nextInt();
        int times = 6;
        while (times-- > 0) {
            if(answer < guess) {
                System.out.println("太大了!");
                System.out.print("["+ (6-times) +"/6]重试: ");
                guess = sc.nextInt();
            } else if (answer > guess) {
                System.out.println("太小了!");
                System.out.print("["+ (6-times) +"/6]重试: ");
                guess = sc.nextInt();
            } else {
                System.out.println("恭喜你!");
                sc.close();
                return;
            }
        }
        System.out.println("次数用完了。");
        sc.close();
    }
}
