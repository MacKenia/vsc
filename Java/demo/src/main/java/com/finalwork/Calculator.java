package com.Finalwork;

import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JSplitPane;

public class Calculator extends JFrame {
    public Container ct = getContentPane();
    final FlowLayout layout = new FlowLayout();
    public JSplitPane sp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, true);

    public static void main(String[] args){
        Calculator cal = new Calculator();
    }

    Calculator() {
        super();
        setTitle("计算器");
        setSize(480, 260);
        setVisible(true);
        ct.setLayout(layout);
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
