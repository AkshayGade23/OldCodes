import java.awt.*;
import java.applet.*;
import java.awt.event.*;
import java.beans.beancontext.BeanContext;

/*
<applet code="Calculator.class" width="600" height= "600"></applet>
*/

public class Calculator extends Applet implements ActionListener {
    TextField tfArea;
    Button btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn0, btnadd, btnsub, btnmul, btndiv, btnequal,
            btnclear;
    String exp = "\0";
    String prev = "+";
    int result = 0;

    public void init() {
        tfArea = new TextField(10);
        add(tfArea);

        btn0 = new Button("0");
        btn1 = new Button("1");
        btn2 = new Button("2");
        btn3 = new Button("3");
        btn4 = new Button("4");
        btn5 = new Button("5");
        btn6 = new Button("6");
        btn7 = new Button("7");
        btn8 = new Button("8");
        btn9 = new Button("9");

        add(btn0);
        add(btn1);
        add(btn2);
        add(btn3);
        add(btn4);
        add(btn5);
        add(btn6);
        add(btn7);
        add(btn8);
        add(btn9);

        btnadd = new Button("+");
        btnsub = new Button("-");
        btnmul = new Button("*");
        btndiv = new Button("/");
        add(btnadd);
        add(btnsub);
        add(btnmul);
        add(btndiv);

        btnequal = new Button("=");
        add(btnequal);

        btnclear = new Button("Clear");
        add(btnclear);

        btn0.addActionListener(this);
        btn1.addActionListener(this);
        btn2.addActionListener(this);
        btn3.addActionListener(this);
        btn4.addActionListener(this);
        btn5.addActionListener(this);
        btn6.addActionListener(this);
        btn7.addActionListener(this);
        btn8.addActionListener(this);
        btn9.addActionListener(this);
        btnsub.addActionListener(this);
        btnadd.addActionListener(this);
        btnmul.addActionListener(this);
        btndiv.addActionListener(this);
        btnequal.addActionListener(this);
        btnclear.addActionListener(this);

    }

    void calcute(String exp, String prev) {
        int expn = Integer.parseInt(exp);
        switch (prev) {
            case "+":
                result += expn;
                break;
            case "-":
                result -= expn;

                break;
            case "*":
                result *= expn;
                break;
            case "/":
                result /= expn;
                break;
        }
        System.out.println(result);

    }

    @Override
    public void actionPerformed(java.awt.event.ActionEvent e) {

        String btn = e.getActionCommand();
        switch (btn) {
            case "0":
                exp = exp + btn;
                tfArea.setText(exp);
                break;

            case "1":
                exp = exp + btn;
                tfArea.setText(exp);
                break;
            case "2":
                exp = exp + btn;
                tfArea.setText(exp);
                break;
            case "3":
                exp = exp + btn;
                tfArea.setText(exp);
                break;
            case "4":
                exp = exp + btn;
                tfArea.setText(exp);
                break;
            case "5":
                exp = exp + btn;
                tfArea.setText(exp);
                break;
            case "6":
                exp = exp + btn;
                tfArea.setText(exp);
                break;
            case "7":
                exp = exp + btn;
                tfArea.setText(exp);
                break;
            case "9":
                exp = exp + btn;
                tfArea.setText(exp);
                break;
            case "+":

                calcute(tfArea.getText(), prev);
                tfArea.setText("+");
                exp = "\0";
                prev = "+";
                break;
            case "-":

            calcute(tfArea.getText(), prev);
                tfArea.setText("-");
                prev = "-";
                exp = "\0";
                break;
            case "*":

            calcute(tfArea.getText(), prev);
                tfArea.setText("*");
                prev = "*";
                exp = "\0";
                break;
            case "/":

            calcute(tfArea.getText(), prev);
                tfArea.setText("/");
                prev = "/";
                exp = "\0";
                break;
            case "=":

                tfArea.setText("" + result);
                break;
            case "Clear":

                tfArea.setText("\0");
                break;

        }
    }

}
