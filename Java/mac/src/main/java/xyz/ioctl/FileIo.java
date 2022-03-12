package xyz.ioctl;

import java.io.File;
import java.util.Scanner;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;

public class FileIo {
    
    public static void main(String[] args) {
        String tmp;
        String fileName = "abc.txt";

        while(true){
            System.out.print("请选择操作:\n1.写入\n2.读取\n3.退出\n>");
            int choice = new Scanner(System.in).nextInt();
    
            switch (choice) {
                case 1:
                    System.out.print("请输入要写入的信息(输入空行结束):");
                    tmp = new Scanner(System.in).nextLine();
                    while(!tmp.equals("")) {
                        writeFile(fileName, tmp);
                        tmp = new Scanner(System.in).nextLine();
                    }
                    break;
                case 2:
                    readFile(fileName);
                    break;
                case 3:
                    System.exit(0);
                    break;
                default:
                    System.out.println("输入错误！");
                    break;
            }
        }
    }

    public static void readFile(String filePath) {
        try {
            File file = new File(filePath);
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line = null;
            while ((line = bufferedReader.readLine()) != null) {
                System.out.println(line);
            }
            bufferedReader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void writeFile(String filePath, String content) {
        try {
            File file = new File(filePath);
            FileWriter fileWriter = new FileWriter(file, true);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            bufferedWriter.write(content+"\n");
            bufferedWriter.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
