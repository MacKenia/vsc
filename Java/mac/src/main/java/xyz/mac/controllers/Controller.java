package xyz.mac.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import xyz.mac.conf.Student;

@RestController 
public class Controller {

    @Autowired
    Student student = new Student();

    @GetMapping("test")
    public String index() {
        return student.toString();
    }
}
