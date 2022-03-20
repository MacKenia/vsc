package xyz.mac.controllers;

import java.util.ArrayList;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import xyz.mac.conf.Student;
import xyz.mac.conf.Teacher;

@Controller
public class FrontController {
    @GetMapping("/Student")
    public String stu(Model model){
        ArrayList<Student> stuList = new ArrayList<Student>();
        stuList.add(new Student(1, "SJohn", 20));
        stuList.add(new Student(2, "SJane", 21));
        stuList.add(new Student(3, "SJack", 22));
        model.addAttribute("stuList",stuList);
        return "Student";
    }
    
    @GetMapping("/Teacher")
    public String tea(Model model) {
        ArrayList<Teacher> teaList = new ArrayList<Teacher>();
        teaList.add(new Teacher(1, "TJohn", 20));
        teaList.add(new Teacher(2, "TJane", 21));
        teaList.add(new Teacher(3, "TJack", 22));
        model.addAttribute("teaList",teaList);
        return "Teacher";
    }
}
