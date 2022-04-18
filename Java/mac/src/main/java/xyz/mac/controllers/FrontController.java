package xyz.mac.controllers;

import java.util.List;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import xyz.mac.model.CqnuStu;
import xyz.mac.model.Student;
import xyz.mac.model.Teacher;
import xyz.mac.services.impl.CqnuStuServices;
import xyz.mac.services.impl.StudentServices;
import xyz.mac.services.impl.TeacherServices;


@Controller
public class FrontController {
    @Autowired
    StudentServices studentServices;

    @Autowired
    TeacherServices teacherServices;

    @Autowired
    CqnuStuServices cqnuStuServices;

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

    @PostMapping("/getData")
    @ResponseBody
    public List<CqnuStu> postMethodName(Integer pages) {
        QueryWrapper<CqnuStu> queryWrapper = new QueryWrapper<>();
        Page<CqnuStu> page = new Page<>(pages, 10);
        queryWrapper.like("grade", "202");
        cqnuStuServices.page(page, queryWrapper);
        return page.getRecords();
    }

    @PostMapping("/getPages")
    @ResponseBody
    public long getPages() {
        QueryWrapper<CqnuStu> queryWrapper = new QueryWrapper<>();
        Page<CqnuStu> page = new Page<>(1, 10);
        queryWrapper.like("grade", "202");
        cqnuStuServices.page(page, queryWrapper);
        return page.getTotal();
    }
    
}
