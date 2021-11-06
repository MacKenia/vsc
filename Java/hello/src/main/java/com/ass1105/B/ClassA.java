package com.ass1105.B;

public class ClassA implements InterfaceA {
    public int method(int a) {
        int tmp = 0;
        for (int i = 1; i <= a; i++) {
            tmp += i;
        }
        return tmp;
    }
}
