package xyz.mac;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import xyz.conf.Student;

@SpringBootTest
class MacApplicationTests {

	@Autowired
	Student student = new Student();

	@Test
	void contextLoads() {
		System.out.println(student.toString());
	}

}
