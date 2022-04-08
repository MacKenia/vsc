package xyz.mac.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor  //无参构造函数
@AllArgsConstructor  //全参构造函数
public class StudentNA {
    private String name;
    private int age;
}
