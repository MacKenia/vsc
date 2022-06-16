package xyz.mac.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.ResponseBody;

import xyz.mac.services.AsyncService;

@Controller
public class Controllers {

    @Autowired
    public AsyncService asyncService;
    @GetMapping("/")
    public String index() {
        return "index";
    }

    @GetMapping("/login")
    public String loginPage() {
        return "login";
    }

    @GetMapping("/detail/{type}/{path}")
    public String toDetail(@PathVariable("type")String type, @PathVariable("path")String path) {
        return "detail/"+type+"/"+path;
    }

    @GetMapping("async")
    @ResponseBody
    public String async() throws InterruptedException {
        long start = System.currentTimeMillis();
        System.out.println("before async");
        asyncService.sendSMS();
        System.out.println("after async");
        long end = System.currentTimeMillis();
        System.out.println("time taken: " + (end - start));
        return "test over";
    }
}
