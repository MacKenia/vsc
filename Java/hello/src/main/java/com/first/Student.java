package com.first;
import java.util.*;

public class Student {
    private String name;
    private String number;

    Student(String names, String numbers) {
        name = names;
        number = numbers;
    }

    public void getInfo() {
        System.out.println("Student: " + name);
        System.out.println("Number: " + number);
    }
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Student student = new Student("王麻子", "110");
        student.getInfo();
        String st = s.nextLine();
        s.close();
    }
}
