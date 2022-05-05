package xyz.mac.services.impl;

import java.util.List;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;

import org.springframework.cache.annotation.Cacheable;
import org.springframework.stereotype.Service;

import xyz.mac.mapping.CqnuStuMapper;
import xyz.mac.model.CqnuStu;
import xyz.mac.services.CqnuStuService;

@Service
public class CqnuStuServices extends ServiceImpl<CqnuStuMapper, CqnuStu> implements CqnuStuService {
    @Override
    @Cacheable(cacheNames = "cqnuStu")
    public List<CqnuStu> list() {
        return super.list();
    }

    
}
