package xyz.mac.controllers;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

import xyz.mac.model.CqnuStu;
import xyz.mac.model.Result;
import xyz.mac.model.Student;
import xyz.mac.model.Teacher;
import xyz.mac.model.TeacherNs;
import xyz.mac.services.CqnuStuService;
import xyz.mac.services.impl.StudentServices;
import xyz.mac.services.impl.TeacherNsServices;
import xyz.mac.services.impl.TeacherServices;


@Controller
// @Api(tags = "所有信息接口")
public class FrontController {
    @Autowired
    StudentServices studentServices;
 
    @Autowired
    TeacherNsServices teacherNsServices;

    @Autowired
    TeacherServices teacherServices;

    @Autowired
    CqnuStuService cqnuStuServices;

    @Value("${photo.file.dir}")
    public String realPath;

    @GetMapping("/")
    public String index() {
        return "index";
    }

    @GetMapping("/Student")
    public String stu(Model model,@RequestParam("stuName") String name, int age){
        List<Student> stuList = studentServices.getAllStudents();
        System.out.println(stuList);
        model.addAttribute("stuList",stuList);
        model.addAttribute("info",name+" "+age);
        return "Student";
    }
    
    @GetMapping("/Teacher")
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

    @PostMapping("info")
    public String infoS(HttpServletRequest request) {
        request.getParameter("name");
        request.getRemoteAddr();
        Cookie[] cookies = request.getCookies();
        return "info";
    }

    @GetMapping("info/{name}/{age}")
    @CrossOrigin
    public String infoT(@PathVariable String name, @PathVariable int age) {
        return "info";
    }

    @PostMapping("/getData")
    @ResponseBody
    public List<CqnuStu> postMethodName(Integer pages) {
        QueryWrapper<CqnuStu> queryWrapper = new QueryWrapper<>();
        Page<CqnuStu> page = new Page<>(pages, 10);
        System.out.println("------------------"+pages+"------------------");
        queryWrapper.like("grade", "202");
        cqnuStuServices.page(page, queryWrapper);
        System.out.println(page.getRecords());
        return page.getRecords();
    }

    @PostMapping("/getPages")
    @ResponseBody
    public long getPages() {
        QueryWrapper<CqnuStu> queryWrapper = new QueryWrapper<>();
        Page<CqnuStu> page = new Page<>(1, 10);
        queryWrapper.like("grade", "202");
        cqnuStuServices.page(page, queryWrapper);
        return page.getPages();
    }
    
    @GetMapping("teacher")
    @ResponseBody
    public Result<List<TeacherNs>> teachers() {
        return new Result<>(200, "success", teacherNsServices.list());
    }

    @GetMapping("teacher/{id}")
    @ResponseBody
    public Result<TeacherNs> teacherId(@PathVariable int id) {
        QueryWrapper<TeacherNs> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("id", id);
        queryWrapper.getSqlSelect();
        System.out.println("查询的id为: " + id);
        return new Result<TeacherNs>(200, "select", teacherNsServices.getOne(queryWrapper));
    }

    @PostMapping("teacher/{id}")
    @ResponseBody
    public Result<Boolean> teacherAdd(@PathVariable int id, @RequestBody TeacherNs teacherNs) {
        QueryWrapper<TeacherNs> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("id", id);
        teacherNsServices.remove(queryWrapper);
        System.out.println("添加的id为: " + id);
        return new Result<>(200, "add", teacherNsServices.save(teacherNs));
    }

    @PutMapping("teacher/{id}")
    @ResponseBody
    public Result<Boolean> teacherUpdate(@PathVariable int id, @RequestBody TeacherNs teacherNs) {
        QueryWrapper<TeacherNs> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("id", id);
        System.out.println("更新的id为: " + id);
        return new Result<>(200, "update", teacherNsServices.update(teacherNs, queryWrapper));
    }

    @DeleteMapping("teacher/{id}")
    @ResponseBody
    public Result<Boolean> teacherDelete(@PathVariable int id) {
        QueryWrapper<TeacherNs> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("id", id);
        System.out.println("删除的id为: " + id);
        return new Result<>(200, "delete", teacherNsServices.remove(queryWrapper));
    }

    @PostMapping("CqnuStu/{id}")
    @ResponseBody
    public Result<Boolean> studentAdd(@PathVariable long id, @RequestBody CqnuStu student) {
        System.out.println("添加的id为: " + id);
        System.out.println("添加的学生为: " + student);
        QueryWrapper<CqnuStu> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("id", id);
        cqnuStuServices.remove(queryWrapper);
        return new Result<>(200, "add", cqnuStuServices.save(student));
    }

    @PutMapping("CqnuStu/{id}")
    @ResponseBody
    public Result<Boolean> studentUpdate(@PathVariable long id, @RequestBody CqnuStu student) {
        System.out.println("添加的id为: " + id);
        System.out.println("添加的学生为: " + student);
        QueryWrapper<CqnuStu> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("id", id);
        return new Result<>(200, "update", cqnuStuServices.update(student, queryWrapper));
    }

    @DeleteMapping("CqnuStu/{id}")
    @ResponseBody
    public Result<Boolean> studentDelete(@PathVariable long id){
        System.out.println("删除的学生id为: " + id);
        QueryWrapper<CqnuStu> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("id", id);
        return new Result<>(200, "delete", cqnuStuServices.remove(queryWrapper));
    }

    private String upLoadFileString(MultipartFile img, String origin) throws IOException{
        String fileName = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss SSSS").format(new Date());
        String ext = origin.substring(origin.lastIndexOf("."));
        String newFile = fileName + ext;
        img.transferTo(new File(realPath, newFile));
        return newFile;
    }

    @PostMapping("/upload")
    @ResponseBody
    public Result<String> upload(@RequestParam("file") MultipartFile file) throws IOException {
        String newFile = upLoadFileString(file, file.getOriginalFilename());
        return new Result<>(200, "success", newFile);
    }

    @GetMapping("/log_in")
    public String login() {
        return "login";
    }
}
