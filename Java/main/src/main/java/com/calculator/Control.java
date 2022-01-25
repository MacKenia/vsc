package com.calculator;

import java.awt.FileDialog;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.sound.sampled.FloatControl;
import javax.swing.*;

import org.w3c.dom.Text;
public class Control implements ActionListener {
    private JButton[] but;
    private JTextField[] text;
    private JTextArea history;
    private int flag = 0;
    private List<String> recordings = new ArrayList<String>();
    private JFrame dialog = new JFrame("Open a File");
    private FileDialog fload = new FileDialog(dialog, "Open file", FileDialog.LOAD);
    private FileDialog fSave = new FileDialog(dialog, "Save File", FileDialog.SAVE);
    private File hisFile;
    private DecimalFormat df = new DecimalFormat("0.000");
    private SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd-hh_mm");
    // 构造函数
    public Control(JButton[] b, JTextField[] f, JTextArea a) {
        but = b;
        text = f;
        history = a;
    }
    // 重写
    public void actionPerformed(ActionEvent e) {
        JButton active = (JButton) e.getSource();
        String command = active.getActionCommand();
        switch (command) {
            case "+":
                if(text[0].getText().equals("")) break;
                if (text[1].getText().equals("")) {
                    flag += 2;
                }
                text[1].setText("+");
                break;
            case "-":
                if(text[0].getText().equals("")) break;
                if (text[1].getText().equals("")) {
                    flag += 2;
                }
                text[1].setText("-");
                break;
            case "X":
                if(text[0].getText().equals("")) break;
                if (text[1].getText().equals("")) {
                    flag += 2;
                }
                text[1].setText("X");
                break;
            case "/":
                if(text[0].getText().equals("")) break;
                if (text[1].getText().equals("")) {
                    flag += 2;
                }
                text[1].setText("/");
                break;
            case "c":
                for (JTextField i : text) {
                    i.setText("");
                }
                text[0].setText("0");
                flag = 0;
                break;
            case "√":
                if(text[flag%3].getText().equals("")) break;
                text[(flag % 3)].setText(df.format(Math.sqrt(Double.valueOf(text[flag % 3].getText()))));
                break;
            case "<-":
                text[3].setText("");
                int tmp = flag;
                if (text[tmp].getText().equals("")) {
                    tmp = --flag;
                }
                if (flag < 0) {
                    flag = 0;
                    tmp = 0;
                    break;
                }
                System.out.println(tmp);
                text[tmp].setText(text[tmp].getText().substring(0, text[tmp].getText().length() - 1));
                break;
            case "=":
                if(text[1].getText().equals("") || text[2].getText().equals("")){
                    text[3].setText("Lack input!");
                    break;
                } else if (text[0].getText().equals("0") || text[2].getText().equals("0")){
                    text[3].setText("Error input!");
                    for (int i = 0; i < 3; i++){
                        text[i].setText("");
                    }
                    break;
                }
                Double in1 = Double.valueOf(text[0].getText());
                Double in2 = Double.valueOf(text[2].getText());
                Double result = 0d;
                switch (text[1].getText()) {
                    case "+":
                        result = in1 + in2;
                        break;
                    case "-":
                        result = in1 - in2;
                        break;
                    case "X":
                        result = in1 * in2;
                        break;
                    case "/":
                        result = in1 / in2;
                        break;
                }
                text[3].setText("=" + df.format(result));
                if(recordings.size() != 0 && recordings.get(recordings.size()-1).equals(text[0].getText() + text[1].getText() + text[2].getText() + text[3].getText())){
                    break;
                }
                history.append(
                        text[0].getText() + text[1].getText() + text[2].getText() + text[3].getText() + "\n");
                recordings.add(new Date().toString());
                recordings.add(text[0].getText() + text[1].getText() + text[2].getText() + text[3].getText());
                for(String i : recordings){
                    System.out.println(i);
                }
                break;
            case "+/-":
                if(text[flag % 3].getText().equals("")){
                    text[flag % 3].setText("-" + text[flag % 3].getText());
                    break;
                }
                if (text[flag % 3].getText().charAt(0)=='-') {
                    text[flag % 3].setText(text[flag % 3].getText().substring(1));
                } else {
                    text[flag % 3].setText("-" + text[flag % 3].getText());
                }
                break;
            case "保存":
                try {
                    hisFile = new File(sdf.format(new Date())+".txt");
                    System.out.println(hisFile.getAbsoluteFile());
                    FileWriter fw = new FileWriter(hisFile);
                    for(String i : recordings) {
                        fw.write(i + "\n");
                        System.out.println(i);
                    }
                    fw.close();
                } catch (Exception ei) {
                    ei.getStackTrace();
                }
                JOptionPane.showMessageDialog(null, "保存成功", "保存成功",JOptionPane.INFORMATION_MESSAGE);
                break;
                case "查看":
                fload.setVisible(true);
                fload.setMultipleMode(false);
                System.out.println(fload.getFile());
                try{
                    hisFile = new File(fload.getDirectory(), fload.getFile());
                    BufferedReader fr = new BufferedReader(new FileReader(hisFile));
                    String buffer;
                    while((buffer = fr.readLine()) != null)
                    {
                        System.out.println(buffer);
                        history.append(buffer + '\n');
                    }
                    fr.close();
                }catch(Exception ei){
                    ei.getStackTrace();
                }
                break;
            case "清除":
                history.setText("");
                break;
            case ".":
                if(text[flag % 3].getText().contains(".")) break;
                if(text[flag % 3].getText().equals("") || text[flag % 3].getText().equals("0")){
                    text[flag % 3].setText("0.");
                } else {
                    text[flag % 3].setText(text[flag % 3].getText() + ".");
                }
                break;
            default:
                if (text[3].getText().equals("")) {
                    if(flag == 0 && text[0].getText().equals("0")) text[0].setText("");
                    text[flag % 3].setText(text[flag % 3].getText() + command);
                } else {
                    for (JTextField i : text) {
                        i.setText("");
                    }
                    flag = 0;
                    text[flag % 3].setText(text[flag % 3].getText() + command);
                }
                break;
        }
    }

}
