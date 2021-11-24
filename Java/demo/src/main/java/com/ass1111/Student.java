package com.ass1111;

public class Student {

    public void speak(int m) throws MyException {
        if(m > 1000) {
            throw new MyException("Number is bigger than 1000");
        }
    }
    public static void main(String[] args) {
        Student student = new Student();
        try {
            student.speak(1001);
        } catch (MyException e) {
            System.out.println(e.getMessage());
        }
    }
}