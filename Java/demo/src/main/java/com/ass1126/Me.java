package com.ass1126;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;

public class Me {
    public static void main(String[] args) {
        File file = new File(new Folder().path);
        File f = new File(file, "me.txt");
        try {
            FileOutputStream out = new FileOutputStream(f);
            byte buffer[] = new String("2020051615308").getBytes();
            byte buffer2[] = new String("麦肯齐123").getBytes();
            if(!file.exists()) {
                file.createNewFile();
            }
            out.write(buffer);
            out.write(buffer2);
            out.close();
            
        } catch (IOException e) {
            e.printStackTrace();
        }

    }    
}
