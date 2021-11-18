package com.ass1118;

import java.util.Scanner;

public class Guess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int answer = (int)(Math.random() * 100) % 100;
        int guess = sc.nextInt();
        System.out.println("快猜: ");
        while (true) {
            if(answer < guess) {
                System.out.println("太大了!");
                System.out.print("重试: ");
                guess = sc.nextInt();
            } else if (answer > guess) {
                System.out.println("太小了!");
                System.out.print("重试: ");
                guess = sc.nextInt();
            } else {
                System.out.println("恭喜你!");
                break;
            }
        }
        sc.close();
    }
}
