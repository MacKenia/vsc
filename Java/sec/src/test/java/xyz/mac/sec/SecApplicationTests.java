package xyz.mac.sec;

import java.util.Date;
import xyz.mac.model.User;

import org.junit.jupiter.api.Test;
import org.springframework.amqp.core.AmqpAdmin;
import org.springframework.amqp.core.Binding;
import org.springframework.amqp.core.FanoutExchange;
import org.springframework.amqp.core.Queue;
import org.springframework.amqp.rabbit.core.RabbitTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class SecApplicationTests {
	@Autowired
	RabbitTemplate rabbitTemplate;

	@Autowired
	AmqpAdmin amqpAdmin;

	@Test
	void contextLoads() {
	}

	@Test
	public void Producer() {
		String message = new Date() + "Beijing";
		System.out.println("生产者生产消息=====" + message);
		rabbitTemplate.convertAndSend("rabbitmq_queue", message);
	}

	@Test
	public void amqpAdmin() {
		amqpAdmin.declareExchange(new FanoutExchange("fanout_exchange_one"));
		amqpAdmin.declareQueue(new Queue("fanout_queue_email"));
		amqpAdmin.declareQueue(new Queue("fanout_queue_sms"));
		amqpAdmin.declareBinding(new Binding("fanout_queue_email",
				Binding.DestinationType.QUEUE, "fanout_exchange", "", null));
		amqpAdmin.declareBinding(new Binding("fanout_queue_sms",
				Binding.DestinationType.QUEUE, "fanout_exchange", "", null));
	}

	@Test
	public void psubPublisher() {
		User user = new User();
		user.setId(1);
		user.setUsername("科比");
		rabbitTemplate.convertAndSend("fanout_exchange_one", "", user);

		user.setId(2);
		user.setUsername("谷爱凌");
		rabbitTemplate.convertAndSend("fanout_exchange_one", "", user);

		user.setId(3);
		user.setUsername("丁真");
		rabbitTemplate.convertAndSend("fanout_exchange_one", "", user);
	}

}
