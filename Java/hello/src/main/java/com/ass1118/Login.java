package com.ass1118;

import java.util.Scanner;

public class Login {
    public static class User {
        private String username;
        private String password;

        public User(String u, String p) {
            username = u;
            password = p;
        }

        public int login(String u, String p) {
            if (username.equals(u)) {
                if (password.equals(p)) {
                    return 1;
                } else {
                    return -2;
                }
            } else {
                return -1;
            }
        }
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Login.User[] group = new Login.User[80];
        int choice;
        int size = 0;
        while(true) {
            System.out.print("\n\n已注册用户["+ size +"/80]\n1. 创建用户\n2. 登陆\n3. 退出\n> ");
            choice = sc.nextInt();
            String username;
            String password;
            username = sc.nextLine();
            switch(choice) {
                case 1:
                    System.out.print("输入用户名：");
                    username = sc.nextLine();
                    System.out.print("请输入密码：");
                    password = sc.nextLine();
                    group[size++] = new Login.User(username, password);
                    break;

                case 2:
                    int result = 0;
                    System.out.print("输入用户名：");
                    username = sc.nextLine();
                    System.out.print("请输入密码：");
                    password = sc.nextLine();
                    for(int i = 0; i < size; i++) {
                        if(group[i].login(username, password) == 1){
                            result = 1;
                            break;
                        } else if(group[i].login(username, password) == -1) {
                            result = 2;
                            continue;
                        } else {
                            result = 3;
                            break;
                        }
                    }
                    if(result == 1) {
                        System.out.print("登录成功！");
                    } else if(result == 2) {
                        System.out.print("用户名不存在！");
                    } else {
                        System.out.print("密码错误！");
                    }
                    break;

                case 3:
                    sc.close();
                    return;
            }
        }
    }
}
