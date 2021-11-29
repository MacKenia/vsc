package com.ass1126;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class Example {
    public static void main(String[] args) {
        File f = new File(new Folder().path);
        File fi = new File(f, "example.txt");
        try {
            byte[] buffer = new byte[512];
            FileInputStream fis = new FileInputStream(fi);
            int rs = 0;
            System.out.println("The contents of the Example.txt is: ");
            while ((rs = fis.read(buffer, 0, 512)) > 0) {
                String s = new String(buffer, 0, rs);
                System.out.println(s);
            }
            fis.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}