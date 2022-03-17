package xyz.mac.conf;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties(prefix = "student")
public class Student {
    private int number;
    private String name;
    private String age;
    private String gender;
    private String grade;

    public void setNumber(int number){
        this.number = number;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setAge(String age){
        this.age = age;
    }

    public void setGender(String gender){
        this.gender = gender;
    }

    public void setGrade(String grade){
        this.grade = grade;
    }

    @Override
    public String toString(){
        return "Teacher{" +
                "number=" + number +
                ", name='" + name + '\'' +
                ", age='" + age + '\'' +
                ", gender='" + gender + '\'' +
                ", grade='" + grade + '\'' +
                '}';
    }

}
