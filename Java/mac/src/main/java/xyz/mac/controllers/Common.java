package xyz.mac.controllers;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class Common {
    @GetMapping("/commonToIndex")
    public String index(Model model) {
        return "index";
    }

    @GetMapping("/layoutToMain")
    public String main(Model model) {
        return "main";
    }
}
