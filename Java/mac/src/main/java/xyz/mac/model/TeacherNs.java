package xyz.mac.model;

import org.springframework.boot.autoconfigure.web.WebProperties.Resources.Chain.Strategy;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class TeacherNs {
    private int id;
    private String name;
    private int age;
    private String rank;
}
