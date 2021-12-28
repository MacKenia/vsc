package com.Finalwork;

import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import java.awt.event.ActionEvent;

public class Control implements ActionListener {
    private JButton[] but;
    private JTextField[] text;
    private JTextArea history;
    private int flag = 0;

    public Control(JButton[] b, JTextField[] f, JTextArea a) {
        but = b;
        text = f;
        history = a;
    }

    public void actionPerformed(ActionEvent e) {
        JButton active = (JButton) e.getSource();
        String command = active.getActionCommand();
        switch (command) {
            case "+":
                if (text[1].getText().equals("")) {
                    flag += 2;
                }
                text[1].setText("+");
                break;
            case "-":
                if (text[1].getText().equals("")) {
                    flag += 2;
                }
                text[1].setText("-");
                break;
            case "X":
                if (text[1].getText().equals("")) {
                    flag += 2;
                }
                text[1].setText("X");
                break;
            case "/":
                if (text[1].getText().equals("")) {
                    flag += 2;
                }
                text[1].setText("/");
                break;
            case "c":
                for (JTextField i : text) {
                    i.setText("");
                }
                flag = 0;
                break;
            case "√":
                text[(flag % 3)].setText(String.valueOf(Math.sqrt(Integer.valueOf(text[flag % 3].getText()))));
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
                text[3].setText("=" + result);
                history.append(
                        text[0].getText() + text[1].getText() + text[2].getText() + "=" + text[3].getText() + "\n");
                break;
            case "+/-":
                if (text[flag % 3].getText().substring(0, 1).equals("-")) {
                    text[flag % 3].setText(text[flag % 3].getText().substring(1));
                } else {
                    text[flag % 3].setText("-" + text[flag % 3].getText());
                }
                break;
            case "保存":

                break;
            case "查看":

                break;
            case "清除":
                history.setText("");
                break;
            default:
                if (text[3].getText().equals("")) {
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
