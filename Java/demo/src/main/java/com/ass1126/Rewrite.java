package com.ass1126;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class Rewrite {
    public static void main(String[] args) {
        File fl = new File(new Folder().path);
        File in = new File(fl, "source.txt");
        File out = new File(fl, "destination.txt");
        try {
            if(!out.exists()) {
                out.createNewFile();
            }
            FileInputStream fi = new FileInputStream(in);
            FileOutputStream fo = new FileOutputStream(out);
            byte[] bytes = new byte[100];
            int rs = fi.read(bytes);
            fo.write(bytes, 0, rs);
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}
