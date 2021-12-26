package com.ass1223;

import java.awt.event.ActionListener;
import java.awt.Container;
import java.awt.Component;

import javax.swing.JButton;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import java.awt.event.ActionEvent;

public class Controller implements ActionListener{

    private Container ct;
    private TriangeModel tm = new TriangeModel();

    public Controller(Container c){
        this.ct = c;
    }

    public void actionPerformed(ActionEvent e){
        JButton but = (JButton)e.getSource();
        String ac = new String(but.getActionCommand());
        if(ac.equals("计算面积")){
            TriangeModel tm = new TriangeModel();
            Component[] cpm = ct.getComponents();
            JTextField a = (JTextField)cpm[1];
            JTextField b = (JTextField)cpm[3];
            JTextField c = (JTextField)cpm[5];
            JTextArea d = (JTextArea)cpm[7];
            int ia = Integer.valueOf(a.getText());
            int ib = Integer.valueOf(b.getText());
            int ic = Integer.valueOf(c.getText());
            tm.setA(ia);
            tm.setB(ib);
            tm.setC(ic);
            d.setText("三角形的面积为："+String.valueOf(tm.cal()));
            tm.cal();
        }
    }
}
