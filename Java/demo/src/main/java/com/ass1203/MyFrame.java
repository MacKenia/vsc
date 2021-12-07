package com.ass1203;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class MyFrame extends JFrame {
    public Container ct = getContentPane();
    public FlowLayout layout = new FlowLayout();
    public MyFrame() {
        super();
        setTitle("注册界面");
        setBounds(100, 100, 480, 260);
        layout.setHgap(10);
        layout.setVgap(10);
        layout.setAlignment(FlowLayout.CENTER);
        ct.setLayout(layout);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void username(Container ct) {
        final JLabel name = new JLabel();
        final JLabel tip = new JLabel();
        final JTextField in = new JTextField();
        final JPanel panel = new JPanel();
        ct.add(panel, BorderLayout.NORTH);
        name.setText("用户名:");
        in.setColumns(20);
        tip.setText("最长14个英文或7个汉字");
        panel.add(name);
        panel.add(in);
        panel.add(tip);

    }

    public void phone(Container ct) {
        final JLabel phone = new JLabel();
        final JTextField in = new JTextField();
        final JPanel panel = new JPanel();
        ct.add(panel, BorderLayout.NORTH);
        panel.setLayout(layout);
        phone.setText("电话:");
        in.setColumns(33);
        panel.add(phone);
        panel.add(in);
    }

    public void password(Container ct) {
        final JLabel password = new JLabel();
        final JPasswordField in = new JPasswordField();
        final JPanel panel = new JPanel();
        panel.setLayout(layout);
        ct.add(panel, BorderLayout.NORTH);
        password.setText("密码:");
        in.setEchoChar(' ');
        in.setColumns(33);
        panel.add(password);
        panel.add(in);
        
    }

    public void button(Container ct){
        final JLabel button = new JLabel();
        final JPanel panel = new JPanel();
        panel.setLayout(layout);
        ct.add(panel, BorderLayout.NORTH);
        button.setText("登陆");
        button.setBounds(100, 100, 100, 100);
        panel.add(button);
    }
    public static void main(String[] args) {
        MyFrame mf = new MyFrame();
        mf.setVisible(true);
        mf.username(mf.ct);
        mf.phone(mf.ct);
        mf.password(mf.ct);
        mf.button(mf.ct);
    }
}
