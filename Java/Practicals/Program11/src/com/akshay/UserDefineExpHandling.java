package com.akshay;

public class UserDefineExpHandling {
    public static void main(String[] args) {
        int accountBalance = 5000;
        int withDrawingAmount = 6000;
        try {
            if (accountBalance < withDrawingAmount)
                throw new MyException("Insufficient Amount");

            accountBalance = accountBalance - withDrawingAmount;
            System.out.println("Successful Withdrawl");
            System.out.println("Your account balance = " + accountBalance);
        } catch (MyException e) {
            System.out.println(e.getMessage());
            System.out.println("Account Balance = " + accountBalance);
            System.out.println("WithDrawing Amount = " + withDrawingAmount);
        }
    }
}
class  MyException extends Exception{
    public MyException(String s){
        super(s);
    }
}