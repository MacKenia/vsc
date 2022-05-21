package xyz.mac.services.impl;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import org.springframework.cache.annotation.Cacheable;
import org.springframework.stereotype.Service;

import xyz.mac.mapping.TeacherNsMapper;
import xyz.mac.model.TeacherNs;
import xyz.mac.services.TeacherNsService;

@Service
public class TeacherNsServices extends ServiceImpl<TeacherNsMapper, TeacherNs> implements TeacherNsService {
    @Override
    @Cacheable(cacheNames = "teacherNs")
    public TeacherNs getOne(Wrapper<TeacherNs> queryWrapper) {
        return super.getOne(queryWrapper);
    }
}
