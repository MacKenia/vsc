package xyz.mac.services.impl;

import java.io.Serializable;
import java.util.List;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
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

    @Override
    @Cacheable(cacheNames = "CqnuPage", key = "'page: '+#page.current")
    public <E extends IPage<CqnuStu>> E page(E page, Wrapper<CqnuStu> queryWrapper) {
        return super.page(page, queryWrapper);
    }
}

