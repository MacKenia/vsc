package xyz.mac.services.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import xyz.mac.mapping.StudentMapper;
import xyz.mac.model.Student;
import xyz.mac.services.StudentService;

@Service
public class StudentServices implements StudentService{
    @Autowired
    private StudentMapper studentMapper;

    @Override
    public List<Student> getAllStudents() {
        return studentMapper.getAll();
    }
}
