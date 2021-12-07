package com.smdx;

import javax.swing.JFrame;

public class swing extends JFrame{
    public static void main(String[] args) {
        swing sg = new swing();
        sg.setVisible(true);
    }

    public swing() {
        super();
        setTitle("swing中的jFrame框架");
        setBounds(100,100,500,375);
        getContentPane().setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    
}