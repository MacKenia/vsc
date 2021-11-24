package com.ass1111;

public class Number {
    public int count(int a, int b) {
        return a*b;
    }

    public static void main(String[] args) {
        Number number = new Number();
        try {
            number.count(1,3);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
