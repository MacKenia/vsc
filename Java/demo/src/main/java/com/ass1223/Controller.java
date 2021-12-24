package com.ass1223;

import java.awt.event.ActionListener;
import java.awt.Container;
import java.awt.Component;

import javax.swing.JButton;
import javax.swing.JFrame;

import java.awt.event.ActionEvent;

public class Controller implements ActionListener{

    private JFrame frame;
    private Container ct;

    public Controller(JFrame c){
        this.frame = c;
    }

    public void actionPerformed(ActionEvent e){
        JButton but = (JButton)e.getSource();
        String ac = new String(but.getActionCommand());
        if(ac.equals("计算面积")){
            frame.
            TriangeModel tm = new TriangeModel();
            Component[] cpm = ct.getComponents();
            System.out.print(cpm[0].getInputContext());
            tm.cal();
        }
    }
}
