package com.ass1118;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
public class Fish {

    public static Date transform(String str) throws Exception {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy/mm/dd");
        Date date = sdf.parse(str);
        return date;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Date dateOld = new Date(0);
        Date date = new Date();
        long d;

        String str = sc.nextLine();
        try{
            date = Fish.transform(str);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        d = dateOld.getTime() - date.getTime();
        d = (d/(365 * 24 * 60 * 60 * 1000)) % 5;

        if(d < 3) {
            System.out.println("");
        } else {
            System.out.println("");
        }
        System.out.println();
        System.out.print(dateOld);
        sc.close();
    }
}
