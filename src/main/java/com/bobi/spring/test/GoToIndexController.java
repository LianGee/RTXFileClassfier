package com.bobi.spring.test;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class GoToIndexController {
    @RequestMapping(value="index.do")  
    public void index_jsp(Model model){  
        model.addAttribute("bobi", "welcom to index");  
        System.out.println("index.jsp");  
    }  
}
