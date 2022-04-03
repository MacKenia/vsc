package xyz.mac.services.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import xyz.mac.mapping.TeacherMapper;
import xyz.mac.model.Teacher;
import xyz.mac.services.TeacherService;

@Service
public class TeacherServices implements TeacherService {
    @Autowired
    private TeacherMapper TeacherMapper;

    @Override
    public List<Teacher> getAllTeachers() {
        List<Teacher> teachers = TeacherMapper.getAll();
        return teachers;
    }
}
