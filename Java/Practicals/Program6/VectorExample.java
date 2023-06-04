package Program6;

import java.util.Vector;

public class VectorExample{
  public static void main(String[] args) {
      Vector vectr = new Vector(10,4); // Declaring and Initializing Vector
       
      //Adding to 2 int in vector
      vectr.add(23);
      vectr.add(10);
      System.out.println(vectr);
      
      //Adding to 2 float in vector
      vectr.add(23.23);
      vectr.add(27.27);
      System.out.println(vectr);
      
      //Adding to 3 double in vector
      vectr.add(23.23333333333333333);
      vectr.add(2323.232323232323);
      vectr.add(2727.272727272727);
      System.out.println(vectr);
      
      // Checking Whether 10 is in it or not
      System.out.println("Checking Whether 10 is in it or not : "+vectr.contains(10));


  }
}