package com.ass1126;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Me {
    public static void main(String[] args) {
        File file = new File(new Folder().path);
        File f = new File(file, "me.txt");
        try {
            FileOutputStream out = new FileOutputStream(f);
            FileInputStream in = new FileInputStream(f);
            byte[] bytes = new byte[512];
            byte buffer[] = new String("2020051615308\n杨鸿强\n").getBytes();
            byte buffer2[] = new String("114514").getBytes();
            int rs = 0;
            if(!file.exists()) {
                file.createNewFile();
            }
            out.write(buffer);
            out.write(buffer2);
            out.close();
            while ((rs = in.read(bytes, 0, 512)) > 0) {
                String s = new String(bytes, 0, rs);
                System.out.println(s);
            }
            in.close();
            
        } catch (IOException e) {
            e.printStackTrace();
        }

    }    
}
