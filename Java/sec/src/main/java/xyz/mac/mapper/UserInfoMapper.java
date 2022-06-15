package xyz.mac.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import xyz.mac.model.UserInfos;

@Mapper
public interface UserInfoMapper{
    @Select("select * from t_user where user = #{name}")
    UserInfos selectByName(String name);
}
