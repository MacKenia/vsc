package xyz.mac.services;

import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;

@Service
public class AsyncService {

    @Async
    public void sendSMS() throws InterruptedException {
        System.out.println("beginning to send SMS");
        long start = System.currentTimeMillis();
        Thread.sleep(3000);
        long end = System.currentTimeMillis();
        System.out.println("end of SMS sending, time taken: " + (end - start));
    }
}