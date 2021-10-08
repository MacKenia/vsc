package com.first;
import java.util.*;

public class User {
    private String username;
    private String password;
    User(){
        username = null;
        password = null;
    }

    User(String u, String p) {
        username = u;
        password = p;
    }

    public String getUsername() { return username; }

    public String getPassword() { return password; }

    public String setPassword(String p) { 
        password = p;
        return password; 
    }

    public String setUsername(String u) {
        username = u;
        return username;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        User user1 = new User();
        User user2 = new User("admin", "password");
        user1.setUsername("root");
        user1.setPassword("noPasswd");
        System.out.println("user1's name: " + user1.getUsername());
        System.out.println("user1's passwd:" + user1.getPassword());
        System.out.println("user2's name: " + user2.getUsername());
        System.out.println("user2's passwd:" + user2.getPassword());
        String st = sc.nextLine();
        sc.close();
    }    
}
