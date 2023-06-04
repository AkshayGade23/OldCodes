// Write a program to implictly and explictly  type casting

package Practical1;
public class TypeCastingDemo {  // start of Class TypeCasting 
    public static void main(String[] args) {
        
      // implicit type Casting
      byte bytte  = 127;
      short shorrt = bytte; // byte to short
      int innt = shorrt; // short to int
      long lonng = innt; // int to long
      float floaat = lonng; // long to float
      double doublle = floaat; // float to double
      
      System.out.println("Implicit type casting");
      System.out.println(" bytte = " + bytte);
      System.out.println(" shorrt = " + shorrt);
      System.out.println(" innt = " + innt);
      System.out.println(" lonng = " + lonng);
      System.out.println(" floaat = " + floaat);
      System.out.println(" doublle = " + doublle);
      
      // explicit type Casting
      double ddouble = 125.4567855;
      float ffloat = (float) ddouble; // double to float 
      long llong = (long) ffloat; // float to long
      int iint = (int) llong; // long to int
      short sshort = (short) iint; // int to short
      byte bbyte  = (byte) sshort; // short to byte
      
      
      System.out.println("Explicit type casting");
      System.out.println(" ddouble = " + ddouble);
      System.out.println(" ffloat = " + ffloat);
      System.out.println(" llong = " + llong);
      System.out.println(" iint = " + iint);
      System.out.println(" sshort = " + sshort);
      System.out.println(" bbyte = " + bbyte);

    }
} // end of class TypeCastingDemo
