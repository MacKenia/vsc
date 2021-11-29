package com.ass1126;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class Count {
    public static void main(String[] args) {
        File fold = new File(new Folder().path);
        File file = new File(fold, "demo.txt");
        long old = System.currentTimeMillis();
        long now = 0;
        int[] group = new int[52];
        int result = 0;
        try {
            FileInputStream fi = new FileInputStream(file);
            byte[] buf = new byte[1];
            int rs = 0;
            while ((rs=fi.read(buf))>0) {
                String tmp = new String(buf, 0, rs);
                if(tmp.compareTo("a") >= 0 && tmp.compareTo("z") <= 0) {
                    group[tmp.compareTo("a")]++;
                } else if(tmp.compareTo("A") >= 0 && tmp.compareTo("Z") <= 0) {
                    group[26 + tmp.compareTo("A")]++;
                }
            }
            System.out.println();
            for(int i = 0; i < group.length; i++) {
                if(group[result] < group[i]) result = i;
            }
            now = System.currentTimeMillis();
            if(result > 25) {
                System.out.println("The numerous letter is " + (char)(result -26 +'A'));
            } else {
                System.out.println("The numerous letter is " + (char)(result+'a'));
            }
            System.out.println("It appears " + group[result] + " times.");
            System.out.println("It takes " + (now-old) + "ms.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
