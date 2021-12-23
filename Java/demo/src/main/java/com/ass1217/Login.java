package com.ass1217;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.*;

import javax.swing.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class Login extends JFrame{
    private Container ct = getContentPane();
    private FlowLayout layout = new FlowLayout();
    private BorderLayout gl = new BorderLayout();
    private JTextField in = new JTextField();
    private JPasswordField p = new JPasswordField();

    public static void main(String[] args) {
        Login lg = new Login();
        lg.setVisible(true);
    }

    public Login() {
        super();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("登陆");
        ct.setLayout(layout);
        gl.setHgap(3);
        gl.setVgap(6);
        setSize(480,240);

        JLabel name = new JLabel();
        JPanel paneln = new JPanel();
        name.setText("用户名:");
        paneln.setSize(470,10);
        in.setColumns(20);
        paneln.add(name);
        paneln.add(in);
        ct.add(paneln);

        JLabel pass = new JLabel();
        JPanel panelp = new JPanel();
        pass.setText("密码:");
        panelp.setSize(470,20);
        p.setColumns(20);
        panelp.add(pass);
        panelp.add(p);
        ct.add(panelp);

        JButton log = new JButton();
        JButton res = new JButton();
        JPanel panelb = new JPanel();
        panelb.setSize(470,20);
        FlowLayout fl = (FlowLayout)panelb.getLayout();
        fl.setHgap(50);
        log.setText("登陆");
        res.setText("重置");
        panelb.add(log);
        panelb.add(res);
        ct.add(panelb);

        class ActionLogin implements ActionListener{
            public void actionPerformed(ActionEvent e){
                String name = new String(in.getText());
                String pass = new String(p.getPassword());
                if(name.equals("ok") && pass.equals("yes")){
                    JOptionPane.showConfirmDialog(null, "登陆成功", "提示", JOptionPane.DEFAULT_OPTION);
                } else {
                    JOptionPane.showConfirmDialog(null, "登陆失败", "提示", JOptionPane.ERROR_MESSAGE);
                }
            }
        }

        class ActionRes implements ActionListener{
            public void actionPerformed(ActionEvent e){
                in.setText("");
                p.setText("");
                JOptionPane.showConfirmDialog(null, "重置成功", "提示", JOptionPane.PLAIN_MESSAGE);
            }
        }

        log.addActionListener(new ActionLogin());
        res.addActionListener(new ActionRes());
    }
}
