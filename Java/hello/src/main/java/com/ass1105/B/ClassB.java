package com.ass1105.B;

public class ClassB implements InterfaceA{
    public int method(int a) {
        int tmp = 1;
        for (int i = 1; i <= a; i++) {
            tmp *= i;
        }
        return tmp;
    }
}
