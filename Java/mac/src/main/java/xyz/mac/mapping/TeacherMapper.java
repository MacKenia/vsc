package xyz.mac.mapping;

import java.util.List;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import xyz.mac.model.Teacher;
import xyz.mac.model.TeacherNA;

@Mapper
public interface TeacherMapper {
    @Select("select * from teacher")
    List<Teacher> getAll();

    @Select("select name,age from teacher")
    List<TeacherNA> getNameAge();

    @Select("select * from teacher where id=#{id}")
    Teacher getTeacherById(Integer id);

    @Insert("insert into teacher(id,name,age,gender) values (#{id}, #{name}, #{age}, #{gender})")
    int insert(Integer id, String name, Integer age, String gender);

    @Update("update teacher set age=#{age} where id = #{id}")
    int updateAge(Integer id, Integer age);

    @Update("update teacher set gender=#{gender} where id = #{id}")
    int updateGender(Integer id, String gender);

    @Delete("delete from student where id = #{id}")
    int delete(Integer id);
}
