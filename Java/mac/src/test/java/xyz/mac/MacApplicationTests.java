package xyz.mac;

import java.util.List;

import static org.mockito.ArgumentMatchers.doubleThat;

import java.util.HashMap;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import xyz.mac.mapping.StudentMapper;
import xyz.mac.mapping.StudentNsMapper;
import xyz.mac.mapping.TeacherMapper;
import xyz.mac.model.Student;
import xyz.mac.model.Teacher;

@SpringBootTest
class MacApplicationTests {

	@Autowired
	private StudentMapper studentMapper;

	@Autowired
	private TeacherMapper teacherMapper;

	@Autowired
	private StudentNsMapper studentNsMapper;

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

	@Test
	void MP_selectList() {
		QueryWrapper<Student> queryWrapper = new QueryWrapper<>();
		queryWrapper.ge("id", 2);
		List<Student> students = studentNsMapper.selectList(queryWrapper);
		System.out.println(students);
	}

	@Test
	void MP_update() {
		Student student = new Student();
		student.setId(1);
		student.setName("张三");
		student.setAge(99);
		HashMap<String, Object> map = new HashMap<>();
		int stu1 = studentNsMapper.updateById(student);
		System.out.println(stu1);
	}

	@Test
	void Inversion() {
		// 求矩阵的逆矩阵
		double[][] matrix = { { 3, 2, 1 }, { 1, 1, 1 }, { 1, 0, 1 } };
		double[][] matrixOne = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
		double[][] matrixExtend = new double[matrix.length][matrix.length * 2];

		// 初始化矩阵
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix.length; j++) {
				matrixExtend[i][j] = matrix[i][j];
				matrixExtend[i][j + matrix.length] = matrixOne[i][j];
			}
		}

		// 输出矩阵
		for (int i = 0; i < matrixExtend.length; i++) {
			for (int j = 0; j < matrixExtend[i].length; j++) {
				System.out.print(matrixExtend[i][j] + "\t");
			}
			System.out.println();
		}

		// 上三角
		for (int i = 0; i < matrixExtend.length-1; i++) {
			for (int j = i+1; j < matrixExtend.length; j++) {
				double tmp = matrixExtend[j][i] / matrixExtend[i][i];
				// System.out.println(tmp);
				for (int k = 0; k < matrixExtend[j].length; k++) {
					matrixExtend[j][k] = matrixExtend[j][k] - tmp * matrixExtend[i][k];
				}
			}
		}

		
		// 下三角
		for (int i = matrixExtend.length - 1; i > 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				double tmp = matrixExtend[j][i] / matrixExtend[i][i];
				// System.out.println(tmp);
				for (int k = 0; k < matrixExtend[j].length; k++) {
					matrixExtend[j][k] = matrixExtend[j][k] - tmp * matrixExtend[i][k];
				}
			}	
		}

		// 化简
		for (int i = 0; i < matrixExtend.length; i++) {
			double tmp = matrixExtend[i][i];
			for (int j = 0; j < matrixExtend[i].length; j++) {
				matrixExtend[i][j] /= tmp;
			}
		}

		System.out.println();

		for (int i = 0; i < matrixExtend.length; i++) {
			for (int j = 0; j < matrixExtend[i].length; j++) {
				System.out.print(matrixExtend[i][j] + "\t");
			}
			System.out.println();
		}
	}
}
