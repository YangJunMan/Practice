package hello.hellospring.controller;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {

    @GetMapping("hello")
    public String hello(Model model) {
        model.addAttribute("data", "Hello World");
        return "hello";
    }   //ResponseBody가 없으면 자동으로 viewResolver에 던진다.

    @GetMapping("hello-mvc")
    public String helloMvc(@RequestParam(value="name",required=true) String name, Model model) {
        model.addAttribute("name", name);
        return "hello-template";
    }

    @GetMapping("hello-string")
    @ResponseBody
    public String hellostring(@RequestParam("name") String name){
        return "hello"+name; //spring이라는걸 넣으면 hello spring이 되겠지?
    }

    @GetMapping("hello-api")
    @ResponseBody   /*ResponseBody가 있네? json으로 거쳐서 던진다. (Hello객체를 보고, json방식으로 http에 응답을 넘겨준다)*/
    public Hello helloApi(@RequestParam("name") String name){
        Hello hello = new Hello();
        hello.setName(name);
        return hello;
    }

    static class Hello{
        private String name;

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }
    }

}