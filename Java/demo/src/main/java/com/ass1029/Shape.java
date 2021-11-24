package com.ass1029;
import java.util.*;

public abstract class Shape {
        int x, y;
        public abstract void center();
        public abstract double diameter();
        public abstract double getArea();

        public static class Circle extends Shape {
                Scanner sc = new Scanner(System.in);
                int r;
                public Circle() {
                        System.out.print("Please input the circle center:");
                        x = sc.nextInt();
                        y = sc.nextInt();
                        System.out.print("Please input the circle radius:");
                        r = sc.nextInt();
                }

                public void center() {
                        System.out.println("The circle center is (" + x + "," + y + ")");
                }

                public double diameter() {
                        System.out.println("The circle diameter is " + 2*3.14*r);
                        return 2*3.14*r;
                }

                public double getArea() {
                        System.out.println("The circle area is " + 3.14*r*r);
                        return 3.14*r*r;
                }
        }

        public static class Square extends Shape {
                Scanner sc = new Scanner(System.in);
                public Square() {
                        System.out.print("Please input the square center:");
                        x = sc.nextInt();
                        y = sc.nextInt();
                }

                public void center() {
                        System.out.println("The Square center is (" + x + "," + y + ")");
                }

                public double diameter() {
                        System.out.println("The Square diameter is " + 2*(x + y));
                        return 2*(x + y);
                }
                

                public double getArea() {
                        System.out.println("The Square area is " + x*y);
                        return x*y;
                }

        }

        public static void main(String[] args) {
                Square sq = new Shape.Square();
                Circle ci = new Shape.Circle();
                sq.center();
                sq.diameter();
                sq.getArea();
                ci.center();
                ci.diameter();
                ci.getArea();
        }
}

