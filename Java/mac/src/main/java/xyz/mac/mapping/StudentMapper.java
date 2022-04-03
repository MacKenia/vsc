package xyz.mac.mapping;

import java.util.List;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import xyz.mac.model.Student;
import xyz.mac.model.StudentNA;

@Mapper
public interface StudentMapper {
    @Select("select * from student")
    List<Student> getAll();

    @Select("select name,age from student")
    List<StudentNA> getNameAge();

    @Select("select * from student where id = #{id}")
    Student getStudentById(Integer id);

    @Insert("insert into student(id,name,age,gender) values (#{id},#{name},#{age},#{gender})")
    int insert(Integer id, String name, Integer age, String gender);

    @Update("update student set age=#{age} where id=#{id}")
    int updateAge(Integer id, Integer age);

    @Update("update student set gender=#{gender} where id=#{id}")
    int updateGender(Integer id, String gender);

    @Delete("delete from student where id = #{id}")
    int delete(Integer id);
}
 