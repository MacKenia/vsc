package xyz.mac.conf;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties(prefix = "teacher")
public class Teacher {
    private int number;
    private String name;
    private int age;
    private String position;
    private String wage;

    public Teacher(int n, String na, int a) {
        this.number = n;
        this.name = na;
        this.age = a;
    }

    public Teacher(){}

    public void setNumber(int number){
        this.number = number;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setAge(int age){
        this.age = age;
    }

    public void setPosition(String position){
        this.position = position;
    }

    public void setWage(String wage){
        this.wage = wage;
    }

    public int getNumber() {
        return number;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getPosition() {
        return position;
    }

    public String getWage() {
        return wage;
    }

    @Override
    public String toString() {
        return "Teacher{" +
                "number=" + number +
                ", name='" + name + '\'' +
                ", age='" + age + '\'' +
                ", position='" + position + '\'' +
                ", wage='" + wage + '\'' +
                '}';
    }

}
