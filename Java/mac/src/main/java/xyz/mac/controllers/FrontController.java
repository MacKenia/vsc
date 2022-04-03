package xyz.mac.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import xyz.mac.model.Student;
import xyz.mac.model.Teacher;
import xyz.mac.services.impl.StudentServices;
import xyz.mac.services.impl.TeacherServices;

@Controller
public class FrontController {
    @Autowired
    StudentServices studentServices;

    @Autowired
    TeacherServices teacherServices;

    @GetMapping("/Student")
    public String stu(Model model){
        List<Student> stuList = studentServices.getAllStudents();
        System.out.println(stuList);
        model.addAttribute("stuList",stuList);
        return "Student";
    }
    
    @GetMapping("/Teacher")
    public String tea(Model model) {
        List<Teacher> teaList = teacherServices.getAllTeachers();
        System.out.println(teaList);
        model.addAttribute("teaList",teaList);
        return "Teacher";
    }

    @GetMapping("/commonToIndex")
    public String index(Model model) {
        return "index";
    }

    @GetMapping("/layoutToMain")
    public String main(Model model) {
        return "main";
    }
}
