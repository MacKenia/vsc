package xyz.mac.sec;

import java.io.File;
import java.util.Date;

import javax.mail.MessagingException;
import javax.mail.internet.MimeMessage;

import org.junit.jupiter.api.Test;
import org.springframework.amqp.core.AmqpAdmin;
import org.springframework.amqp.core.Binding;
import org.springframework.amqp.core.DirectExchange;
import org.springframework.amqp.core.FanoutExchange;
import org.springframework.amqp.core.Queue;
import org.springframework.amqp.core.TopicExchange;
import org.springframework.amqp.rabbit.core.RabbitTemplate;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.mail.javamail.MimeMessageHelper;

import xyz.mac.model.User;

@SpringBootTest
class SecApplicationTests {
	@Autowired
	RabbitTemplate rabbitTemplate;

	@Autowired
	AmqpAdmin amqpAdmin;

	@Autowired
	private JavaMailSender javaMailSender;

	@Value("${spring.mail.username}")
	private String from;

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
		amqpAdmin.declareExchange(new FanoutExchange("exchange_what"));
		amqpAdmin.declareQueue(new Queue("fanout_queue_email"));
		amqpAdmin.declareQueue(new Queue("fanout_queue_sms"));
		amqpAdmin.declareBinding(new Binding("fanout_queue_email",
				Binding.DestinationType.QUEUE, "exchange_what", "", null));
		amqpAdmin.declareBinding(new Binding("fanout_queue_sms",
				Binding.DestinationType.QUEUE, "exchange_what", "", null));
	}

	@Test
	public void psubPublisher() {
		User user = new User();
		user.setId(1);
		user.setUsername("科比");
		rabbitTemplate.convertAndSend("exchange_what", "", user);

		user.setId(2);
		user.setUsername("谷爱凌");
		rabbitTemplate.convertAndSend("exchange_what", "", user);

		user.setId(3);
		user.setUsername("丁真");
		rabbitTemplate.convertAndSend("exchange_what", "", user);
	}

	@Test
	public void routingCreate() {
		amqpAdmin.declareExchange(new DirectExchange("exchange_why"));
		amqpAdmin.declareQueue(new Queue("routing_queue_error"));
		amqpAdmin.declareBinding(new Binding("routing_queue_error", Binding.DestinationType.QUEUE, "exchange_why",
				"error_routing_key", null));
	}

	@Test
	public void routingPublisher() {
		rabbitTemplate.convertAndSend("exchange_why",
				"error_routing_key",
				"routing send  error message");
	}

	@Test
	public void topicCreate() {
		amqpAdmin.declareExchange(new TopicExchange("exchange_when"));
		amqpAdmin.declareQueue(new Queue("topic_queue_email"));
		amqpAdmin.declareQueue(new Queue("topic_queue_sms"));
		amqpAdmin.declareBinding(new Binding("topic_queue_email", Binding.DestinationType.QUEUE, "exchange_when",
				"topic.email.#", null));
		amqpAdmin.declareBinding(new Binding("topic_queue_sms", Binding.DestinationType.QUEUE, "exchange_when",
				"topic.sms.#", null));
	}

	@Test
	public void topicPublisher() {
		rabbitTemplate.convertAndSend("exchange_when", "info.email",
				"topics send  email message");
		rabbitTemplate.convertAndSend("exchange_when", "info.sms",
				"topics send  sms message");
		rabbitTemplate.convertAndSend("exchange_when",
				"info.email.sms",
				"topics send  email and sms message");
	}

    /**
     * 发送邮件并携带附件.
     * 请注意 from 、 to 邮件服务器是否限制邮件大小
     *
     * @param to       目标email 地址
     * @param subject  邮件主题
     * @param text     纯文本内容
     * @param filePath 附件的路径 当然你可以改写传入文件
     * @throws javax.mail.MessagingException
     * @throws javax.mail.MessagingException
     */
	@Test
	public void sendMail() throws MessagingException {
		sendMailWithAttachment("maikenqi@outlook.com", "Test", "这是一封垃圾邮件", "C:\\Users\\MacKenia\\Pictures\\2022-06-19-142928.jpg");
	}


    public void sendMailWithAttachment(String to, String subject, String text, String filePath) throws MessagingException {

        File attachment = new File(filePath);
        MimeMessage mimeMessage = javaMailSender.createMimeMessage();
        MimeMessageHelper helper=new MimeMessageHelper(mimeMessage,true);
        helper.setFrom(from);
        helper.setTo(to);
        helper.setSubject(subject);
        helper.setText(text);
        helper.addAttachment(attachment.getName(),attachment);
        javaMailSender.send(mimeMessage);

    }

}
