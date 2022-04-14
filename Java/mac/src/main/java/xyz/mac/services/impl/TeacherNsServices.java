package xyz.mac.services.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import org.springframework.stereotype.Service;
import xyz.mac.mapping.TeacherNsMapper;
import xyz.mac.model.TeacherNs;
import xyz.mac.services.TeacherNsService;

@Service
public class TeacherNsServices extends ServiceImpl<TeacherNsMapper, TeacherNs> implements TeacherNsService {
    
}
