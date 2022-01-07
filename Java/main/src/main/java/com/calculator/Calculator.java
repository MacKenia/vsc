package com.calculator;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.Dimension;
import java.awt.Insets;

import javax.swing.JScrollPane;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.border.Border;
import javax.swing.plaf.DimensionUIResource;

public class Calculator extends JFrame {
    public Container ct = getContentPane();
    // 布局管理器
    final FlowLayout fl = new FlowLayout();
    public JSplitPane sp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, true);
    private BorderLayout bl = new BorderLayout();
    private GridLayout gl = new GridLayout(4,5);
    // 输入框
    private JTextField in1 = new JTextField();
    private JTextField in2 = new JTextField();
    private JTextField op = new JTextField();
    private JTextField out = new JTextField();
    private JTextArea history = new JTextArea();
    // 按钮集合 利于调用
    private JTextField[] text = {in1, op, in2, out};
    private JButton[] but = new JButton[23];
    private JPanel[] pan = new JPanel[5];
    private int pans = 0;
    private int buts = 0;
    // 个性化设置
    private Insets is = new Insets(2,2,2,2);
    private Font ft = new Font("Arial",Font.BOLD,17);
    // 监听
    private Control listener = new Control(but, text, history);
    // 构造函数
    Calculator() {
        super();
        setTitle("计算器");
        setSize(634, 324);
        ct.setLayout(fl);
        setContentPane(sp);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        // 装入左右面板
        leftPanel();
        rightPanel();
        // 对按钮进行修改
        for(JButton i : but){
            i.setPreferredSize(new Dimension(52,32));
        }
        // 设置split属性
        sp.setContinuousLayout(true);
        sp.setDividerLocation(JSplitPane.CENTER_ALIGNMENT);
        sp.setDividerSize(0);
        // 更换字体
        for(JTextField i : text){
            i.setHorizontalAlignment(JTextField.CENTER);
            i.setMargin(is);
            i.setFont(ft);
            i.setEditable(false);
        }
        // 更换主题
        try{
            for(UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                }
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
        // 重新设置可见
        setVisible(true);
    }
    // 左面板
    void leftPanel() {
        JPanel leftPanel = new JPanel(fl);
        leftPanel.add(inputField());
        leftPanel.add(buttons());
        sp.setLeftComponent(leftPanel);
    }
    // 右面板
    void rightPanel() {
        JPanel rigJPanel = new JPanel(fl);
        rigJPanel.add(outputField());
        rigJPanel.add(historyArea());
        rigJPanel.add(extraFunction());
        sp.setRightComponent(rigJPanel);
    }
    // 添加按钮
    JPanel buttons () {
        int BPan = pans++;
        pan[BPan] = new JPanel(gl);

        gl.setHgap(17);
        gl.setVgap(26);

        String[][] bs = {{"1", "2", "3", "/", "c"},{"4", "5", "6", "X", "<-"},{"7", "8", "9", "-", "√"},{"0", "+/-", ".", "+", "="}};
        for(String[] i : bs){
            for(String j : i){
                but[buts] = new JButton(j);
                but[buts].addActionListener(listener);
                // but[buts].setSize(new DimensionUIResource(100,100));
                pan[BPan].add(but[buts++]);
            }
        }
        return pan[BPan];
    }
    // 添加输入框
    JPanel inputField(){
        int FPan = pans++;
        pan[FPan] = new JPanel(fl);
        fl.setVgap(10);
        in1.setColumns(9);
        op.setColumns(3);
        in2.setColumns(9);
        in1.setText("0");
        pan[FPan].add(in1);
        pan[FPan].add(op);
        pan[FPan].add(in2);
        return pan[FPan];
    }
    // 添加输出框
    JPanel outputField(){
        int FPan = pans++;
        pan[FPan] = new JPanel(fl);
        out.setColumns(14);
        pan[FPan].add(out);
        return pan[FPan];
    }
    // 添加历史记录框
    JPanel historyArea(){
        int APan = pans++;
        JScrollPane scp = new JScrollPane();
        scp.setViewportView(history);
        scp.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        // history.setLineWrap(true);
        pan[APan] = new JPanel(new FlowLayout());
        history.setColumns(17);
        history.setRows(8);
        history.setMargin(new Insets(5,5,5,5));
        history.setEditable(false);
        pan[APan].add(scp);
        return pan[APan];
    }
    // 添加额外功能键
    JPanel extraFunction(){
        int EPan = pans++;
        int first = buts;
        FlowLayout efl = new FlowLayout();
        efl.setVgap(0);
        efl.setHgap(10);
        pan[EPan] = new JPanel(efl);
        String[] ext ={"保存","查看","清除"};
        for(String i : ext){
            but[buts] = new JButton(i);
            but[buts].addActionListener(listener);
            but[buts].setMargin(new Insets(0,0,0,0));
            pan[EPan].add(but[buts++]);
        }
        // 监听
        class cate implements ActionListener{
            public void actionPerformed(ActionEvent e){
                if((((JButton)e.getSource()).getActionCommand()).equals("保存")){
                }else{
                }
            }
        }

        but[first].addActionListener(new cate());
        but[first+1].addActionListener(new cate());
        
        return pan[EPan];
    }
}
