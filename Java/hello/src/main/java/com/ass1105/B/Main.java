package com.ass1105.B;

public class Main {
    public static void main(String[] args) {
        InterfaceA ca = new ClassA(); //接口的回调
        InterfaceA cb = new ClassB();
        System.out.println(ca.method(3)); //接口的回调
        System.out.println(cb.method(3));
    }
}
