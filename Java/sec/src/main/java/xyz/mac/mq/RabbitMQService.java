package xyz.mac.mq;

import org.springframework.amqp.core.Message;
import org.springframework.amqp.rabbit.annotation.Exchange;
import org.springframework.amqp.rabbit.annotation.Queue;
import org.springframework.amqp.rabbit.annotation.QueueBinding;
import org.springframework.amqp.rabbit.annotation.RabbitListener;

// @Service
public class RabbitMQService {
    @RabbitListener(queues = "fanout_queue_email")
    public void psubConsumerEmail(Message message) {
        byte[] body = message.getBody();
        String s = new String(body);
        System.out.println("邮件业务接收到消息： " + s);
    }

    @RabbitListener(queues = "fanout_queue_sms")
    public void psubConsumerSms(Message message) {
        byte[] body = message.getBody();
        String s = new String(body);
        System.out.println("短信业务接收到消息： " + s);
    }

    @RabbitListener(bindings = @QueueBinding(value = @Queue("routing_queue_error"), exchange = @Exchange(value = "exchange_why", type = "direct"), key = "error_routing_key"))
    public void routingConsumerError(String message) {
        System.out.println("接收到error级别日志消息: " + message);
    }

    @RabbitListener(bindings = @QueueBinding(value = @Queue("routing_queue_all"), exchange = @Exchange(value = "exchange_why", type = "direct"), key = {
            "error_routing_key", "info_routing_key", "warning_routing_key" }))
    public void routingConsumerAll(String message) {
        System.out.println("接收到info、error、warning等级别日志消息: " + message);
    }

    @RabbitListener(bindings = @QueueBinding(value = @Queue("topic_queue_email"), exchange = @Exchange(value = "exchange_when", type = "topic"), key = "info.#.email.#"))
    public void topicConsumerEmail(String message) {
        System.out.println("接收到邮件订阅需求处理消息： " + message);
    }

    @RabbitListener(bindings = @QueueBinding(value = @Queue("topic_queue_sms"), exchange = @Exchange(value = "exchange_when", type = "topic"), key = "info.#.sms.#"))
    public void topicConsumerSms(String message) {
        System.out.println("接收到短信订阅需求处理消息： " + message);
    }

}
