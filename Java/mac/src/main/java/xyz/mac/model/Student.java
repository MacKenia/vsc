package xyz.mac.model;

import org.springframework.stereotype.Component;

@Component
public class Student {
    private int id;
    private String name;
    private int age;
    private String gender;

    public Student(int n, String na, int a) {
        this.id = n;
        this.name = na;
        this.age = a;
    }

    public Student(){}

    public void setId(int id){
        this.id = id;
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

    public int getId() {
        return id;
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

    @Override
    public String toString(){
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age='" + age + '\'' +
                ", gender='" + gender + '\'' +
                '}';
    }

}
