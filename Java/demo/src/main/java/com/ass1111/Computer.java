package com.ass1111;

public class Computer {
    public int func(int a, int b) throws MyException {
        if(a < 0 || b < 0) {
            throw new MyException("number must be positive");
        }
        if(a < b) {
            int tmp = a;
            a = b;
            a = tmp;
        }
        if(a%b == 0) return b;
        return func(b, a%b);
    }

    public static void main(String[] args) {
        Computer com = new Computer();
        try {
            com.func(-1, 2);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
