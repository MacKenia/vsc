package xyz.conf;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties(prefix = "teacher")
public class Teacher {
    private int number;
    private String name;
    private String age;
    private String position;
    private String wage;

    public void setNumber(int number){
        this.number = number;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setAge(String age){
        this.age = age;
    }

    public void setPosition(String position){
        this.position = position;
    }

    public void setWage(String wage){
        this.wage = wage;
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
