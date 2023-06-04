package com.akshay;

public class ExceptionHandling {
    public static void main(String[] args) {
        int dividend = 10;
        int divisor= 0;
        int quotient;

        System.out.println("Before try");
        try{
            System.out.println("Entered in Try");
            quotient = dividend/divisor;
            System.out.println("Outgoing from Try");
        }
        catch (ArithmeticException e){
            System.out.println("Exception is : " + e.getMessage());
        }
        System.out.println("After try...");
    }
}
