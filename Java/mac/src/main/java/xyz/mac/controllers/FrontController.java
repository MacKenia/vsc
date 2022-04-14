package xyz.mac.controllers;

import java.util.List;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

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

    @PostMapping("/Student")
    public String stu(Model model,@RequestParam("stuName") String name, int age){
        List<Student> stuList = studentServices.getAllStudents();
        System.out.println(stuList);
        model.addAttribute("stuList",stuList);
        model.addAttribute("info",name+" "+age);
        return "Student";
    }
    
    @PostMapping("/Teacher")
    public String tea(Model model, Teacher tea) {
        List<Teacher> teaList = teacherServices.getAllTeachers();
        System.out.println(teaList);
        model.addAttribute("teaList",teaList);
        return "Teacher";
    }

    @GetMapping("/commonToIndex")
    public String index(Model model, String name, int age) {
        return "index";
    }

    @GetMapping("/layoutToMain")
    public String main(Model model) {
        return "main";
    }

    @GetMapping("index")
    public String infoO(Model model) {
        return "index";
    }

    @PostMapping("info")
    public String infoS(HttpServletRequest request) {
        request.getParameter("name");
        request.getRemoteAddr();
        Cookie[] cookies = request.getCookies();
        return "info";
    }

    @GetMapping("info/{name}/{age}")
    public String infoT(@PathVariable String name, @PathVariable int age) {
        return "info";
    }
}
