package com.ass1118;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Fish {

    public static Date transform(String str) throws Exception {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd");
        Date date = sdf.parse(str);
        return date;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Date dateOld = new Date();
        Date date = new Date();
        long d;
        
        // input the date for calculate
        System.out.print("输入开始的日期：");
        String st = sc.nextLine();
        System.out.print("输入要计算的日期: ");
        String str = sc.nextLine();
        try{
            dateOld = Fish.transform(st);
            date = Fish.transform(str);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        System.out.println(String.format("%tF", dateOld));
        System.out.println(String.format("%tF", date));

        // calculate the date
        d = date.getTime() - dateOld.getTime();
        d = (d/(24 * 60 * 60 * 1000)) % 5;

        if(d > 0 && d < 4) {
            System.out.println(str + "是打鱼日");
        } else {
            System.out.println(str + "是晒网日");
        }
        sc.close();
    }
}
