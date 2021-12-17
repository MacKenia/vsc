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

    public static void main(String[] args) {
        Login lg = new Login();
    }

    public Login() {
        super();
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("登陆");
        ct.setLayout(gl);
        gl.setHgap(3);
        gl.setVgap(6);
        setSize(480,240);

        JLabel name = new JLabel();
        JPanel paneln = new JPanel();
        JTextField in = new JTextField();
        name.setText("用户名:");
        paneln.setSize(470,10);
        in.setColumns(20);
        paneln.add(name);
        paneln.add(in);
        ct.add(paneln);

        JLabel pass = new JLabel();
        JPanel panelp = new JPanel();
        JPasswordField p = new JPasswordField();
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

        class actionlog implements ActionListener{
            public void actionPerformed(ActionEvent e){
                JButton active = (JButton)e.getSource();
                String btn = e.getActionCommand();
                if(btn.equals("登陆")){
                    JOptionPane 
                } else {

                }
            }
        }
    }
}
