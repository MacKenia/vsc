package xyz.mac;

import java.util.List;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import xyz.mac.mapping.StudentMapper;
import xyz.mac.mapping.TeacherMapper;
import xyz.mac.model.Student;
import xyz.mac.model.Teacher;

@SpringBootTest
class MacApplicationTests {

	@Autowired
	private StudentMapper studentMapper;

	@Autowired
	private TeacherMapper teacherMapper;

	@Test
	void student() {
		List<Student> students = studentMapper.getAll();
		System.out.println(students);
	}

	@Test
	void teacher() {
		List<Teacher> teachers = teacherMapper.getAll();
		System.out.println(teachers);
	}

	@Test
	void getStudent() {
		Student stu = studentMapper.getStudentById(1);
		System.out.println(stu);
	}

	@Test
	void update() {
		int stu1 = studentMapper.updateAge(1, 99);
		int stu2 = studentMapper.delete(5);
		System.out.println(stu1+","+stu2);
	}

}
