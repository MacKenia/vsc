package com.Finalwork;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.BorderLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class Calculator extends JFrame {
    public Container ct = getContentPane();
    final FlowLayout fl = new FlowLayout();
    public JSplitPane sp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, true);
    private BorderLayout bl = new BorderLayout();
    private JTextField in1 = new JTextField();
    private JTextField in2 = new JTextField();
    private JTextField op = new JTextField();
    private JTextField out = new JTextField();
    private JTextArea history = new JTextArea();


    public static void main(String[] args){
        Calculator cal = new Calculator();
    }

    Calculator() {
        super();
        setTitle("计算器");
        setSize(480, 260);
        setVisible(true);
        ct.setLayout(fl);
        setContentPane(sp);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    void leftpanel() {
        
        // split.setLeftComponent();
    }

    void rightpanel() {

    }

    void buttons () {
        String[][] bs = {{"1", "2", "3", "/", "c"},{"4", "5", "6", "*", "<-"},{"7", "8", "9", "-", "1/x"},{"0", "+/-", ".", "+", "="}};

    }
}
