package com.ass1223;

public class TriangeModel {
    private double a, b, c;
    public TriangeModel(double a, double b, double c){
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public TriangeModel(){
        this(0, 0, 0);
    }
    public double setA(double a){
        return this.a = a;
    }
    public double setB(double b){
        return this.b = b;
    }
    public double setC(double c){
        return this.c = c;
    }
    public double cal(){
        double p = (a+b+c)/2;
        return Math.sqrt(p*(p-a)*(p-b)*(p-c));
    }
}
