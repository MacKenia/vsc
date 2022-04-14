package xyz.mac.services.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import org.springframework.stereotype.Service;

import xyz.mac.mapping.StudentNsMapper;
import xyz.mac.model.StudentNs;
import xyz.mac.services.StudentNsService;

@Service
public class StudentNsServices extends ServiceImpl<StudentNsMapper, StudentNs> implements StudentNsService {

}
