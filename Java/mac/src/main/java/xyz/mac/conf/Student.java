package xyz.mac.conf;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties(prefix = "student")
public class Student {
    private int number;
    private String name;
    private int age;
    private String gender;
    private String grade;

    public Student(int n, String na, int a) {
        this.number = n;
        this.name = na;
        this.age = a;
    }

    public Student(){}

    public void setNumber(int number){
        this.number = number;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setAge(int age){
        this.age = age;
    }

    public void setGender(String gender){
        this.gender = gender;
    }

    public void setGrade(String grade){
        this.grade = grade;
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

    public String getGender() {
        return gender;
    }

    public String getGrade() {
        return grade;
    }

    @Override
    public String toString(){
        return "Student{" +
                "number=" + number +
                ", name='" + name + '\'' +
                ", age='" + age + '\'' +
                ", gender='" + gender + '\'' +
                ", grade='" + grade + '\'' +
                '}';
    }

}
