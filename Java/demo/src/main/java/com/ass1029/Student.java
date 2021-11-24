package com.ass1029;
import java.util.*;

public class Student {
        String name;
        int age;
        public Student(String n, int a) {
                name = n;
                age = a;
        }

        public void show() {
                System.out.println("Student's name:" + name);
                System.out.println("age: " + age);
        }

        public class UnderGraduate extends Student {
                String major;
                UnderGraduate(String n, String m, int a)
                {
                        super(n, a);
                        major = m;
                }

                public void show() {
                        System.out.println("Student's name:" + name);
                        System.out.println("age: " + age);
                        System.out.println("major: " + major);
                }
        }

        public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);
                Student st = new Student("Jack", 19);
                UnderGraduate un = st.new UnderGraduate("Mike", "Computer Science", 19);
                st.show();
                un.show();
                String s = sc.nextLine();
                sc.close();
        }
}
