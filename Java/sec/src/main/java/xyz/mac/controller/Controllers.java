package xyz.mac.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

@Controller
public class Controllers {

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
}
