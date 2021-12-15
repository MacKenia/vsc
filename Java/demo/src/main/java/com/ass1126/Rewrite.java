package com.ass1126;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;

public class Rewrite {
    public static void main(String[] args) {
        File fl = new File(new Folder().path);
        File in = new File(fl, "source.txt");
        File out = new File(fl, "destination.txt");
        try {
            if(!out.exists()) {
                out.createNewFile();
            }
            FileReader fr = new FileReader(in);
            FileWriter fw = new FileWriter(out);
            FileInputStream fi = new FileInputStream(in);
            FileOutputStream fo = new FileOutputStream(out);
            byte[] bytes = new byte[100];
            char[] buff = new char[100];
            // int rs = fi.read(bytes);
            int rs = fr.read(buff);
            // fo.write(bytes, 0, rs);
            fw.write(buff,0,rs);
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}
