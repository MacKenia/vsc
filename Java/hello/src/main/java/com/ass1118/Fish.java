package com.ass1118;

import java.util.Date;
import java.util.Scanner;

public class Fish {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Date dateOld = new Date(0);
        int[] date = new int[3];
        boolean flag = false;
        for (int i = 0; i < 3; i++) {
            date[i] = sc.nextInt();
        }
        System.out.print(date);
        int year = Integer.parseInt(String.format("%tY", dateOld)) - Integer.parseInt(String.format("%tY", date[0]));
        int month = Integer.parseInt(String.format("%tm", dateOld)) - Integer.parseInt(String.format("%tm", date[1]));
        int day = Integer.parseInt(String.format("%td", dateOld)) - Integer.parseInt(String.format("%td", date[2]));

        System.out.println();
        System.out.print(dateOld);
        sc.close();
    }
}
