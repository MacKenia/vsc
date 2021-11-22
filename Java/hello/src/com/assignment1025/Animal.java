package com.assignment1025;
import java.util.*;

public class Animal {
    private String name;
    private int leg;
    private int count;
    public void setLeg(int a){
        leg = a;
    }

    public int getLeg() {
        return leg;
    }

    public void setKind(String kind){
        name = kind;
    }

    public String getKind() {
        return name;
    }

    public void setCount(int a) {
        count = a;
    }

    public int getCount() {
        return count;
    }

    public class Fish extends Animal {
        public int getCount(){
            return super.count;
        }
    }

    public class Tiger extends Animal {

    }
    
    public class SouthEastTiger extends Animal {

    }

    public static void main(String[] args) {
        
        Fish f = new Animal().new Fish();
        f.setCount(100);
        System.out.println(f.getCount());
    }
}
