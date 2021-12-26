package com.ass1223;

import java.awt.FlowLayout;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class MVCWindow extends JFrame{

    private FlowLayout fl = new FlowLayout();
    private Container ct = getContentPane();
    private Controller ctrl = new Controller(ct);

    public JLabel a = new JLabel("边长A");
    public JLabel b = new JLabel("边长B");
    public JLabel c = new JLabel("边长C");
    public JTextField ta = new JTextField();
    public JTextField tb = new JTextField();
    public JTextField tc = new JTextField();
    public JButton bt = new JButton("计算面积");
    public JTextArea re = new JTextArea(5,40);
    public MVCWindow(){
        super();
        setTitle("三角形");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 200);
        fl.setHgap(10);
        fl.setVgap(10);
        ta.setColumns(5);
        tb.setColumns(5);
        tc.setColumns(5);
        ct.setLayout(fl);
        bt.setSize(10,10);
        ct.add(a);
        ct.add(ta);
        ct.add(b);
        ct.add(tb);
        ct.add(c);
        ct.add(tc);
        ct.add(bt);
        ct.add(re);
        bt.addActionListener(ctrl);
    }
}
