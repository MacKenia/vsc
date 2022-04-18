
package xyz.mac;

import java.util.List;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import xyz.mac.mapping.StudentMapper;
import xyz.mac.mapping.StudentNsMapper;
import xyz.mac.mapping.TeacherMapper;
import xyz.mac.model.CqnuStu;
import xyz.mac.model.Student;
import xyz.mac.model.StudentNs;
import xyz.mac.model.Teacher;
import xyz.mac.model.TeacherNs;
import xyz.mac.services.impl.CqnuStuServices;
import xyz.mac.services.impl.StudentNsServices;
import xyz.mac.services.impl.TeacherNsServices;

@SpringBootTest
class MacApplicationTests {

	@Autowired
	private StudentMapper studentMapper;

	@Autowired
	private TeacherMapper teacherMapper;

	@Autowired
	private StudentNsMapper studentNsMapper;

	@Autowired
	private StudentNsServices studentNsServices;

	@Autowired
	private TeacherNsServices teacherNsServices;

	@Autowired
	private CqnuStuServices cqnuStuServices;

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
		QueryWrapper<StudentNs> queryWrapper = new QueryWrapper<>();
		queryWrapper.le("id", 5);
		List<StudentNs> students = studentNsMapper.selectList(queryWrapper);
		for (StudentNs student : students) {
			System.out.println(student);
		}
	}

	@Test
	void MP_update() {
		StudentNs student = new StudentNs();
		student.setId(99);
		student.setName("张三");
		int stu1 = studentNsMapper.updateById(student);
		System.out.println(stu1);
	}

	@Test
	void MP_qu() {
		QueryWrapper<StudentNs> qw = new QueryWrapper<>();
		qw.lt("id", 4);
		List<StudentNs> students =studentNsMapper.selectList(qw);
		for (StudentNs student : students) {
			System.out.println(student);
		}
	}

	@Test
	void MP_StuService() {
		QueryWrapper<StudentNs> qw = new QueryWrapper<>();
		qw.lt("age", 20);
		List<StudentNs> students = studentNsServices.list(qw);
		for (StudentNs student : students) {
			System.out.println(student);
		}
	}


	@Test
	void testInsert() {
		StudentNs student = new StudentNs();
		student.setId(101);
		student.setName("张三");
		student.setAge(99);
		if (studentNsServices.save(student)) {
			System.out.println("插入成功");
		} else {
			System.out.println("插入失败");
		}
	}

	@Test
	void testTeaInsert() {
		TeacherNs teacherNs = new TeacherNs();
		teacherNs.setId(101);
		teacherNs.setName("张三");
		teacherNs.setAge(99);
		teacherNs.setRanks("班主任");
		if (teacherNsServices.save(teacherNs)) {
			System.out.println("插入成功");
		} else {
			System.out.println("插入失败");
		}
	}

	@Test
	void testPage() {
		Page<StudentNs> page = new Page<>(2, 10);
		QueryWrapper<StudentNs> qw = new QueryWrapper<>();
		qw.lt("age", 20);
		studentNsServices.page(page,qw);
        System.out.println(page.getCurrent());
        System.out.println(page.getTotal());
        System.out.println(page.getSize());
        System.out.println(page.getRecords());
        System.out.println(page.hasNext());
        System.out.println(page.hasPrevious());
	}

	@Test
	void testCPage(){
		Page<CqnuStu> page = new Page<>(1,5);
		QueryWrapper<CqnuStu> qw = new QueryWrapper<>();
		qw.eq("major", "计算机科学与技术");
		cqnuStuServices.page(page,qw);
		System.out.println(page.getCurrent());
		System.out.println(page.getTotal());
		System.out.println(page.getSize());
		System.out.println(page.getRecords());
		System.out.println(page.hasNext());
		System.out.println(page.hasPrevious());
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
