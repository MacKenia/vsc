package xyz.mac.mapping;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;

import org.apache.ibatis.annotations.Mapper;

import xyz.mac.model.Student;

@Mapper
public interface StudentNsMapper extends BaseMapper<Student>{
    
}
