class Base {
    void greetingMsg(){
        System.out.println("Good Morning!");
    }
}
class Derived extends Base {
  void greetingMsgWithName(String name){
      System.out.print("Hi " + name + ", ");
      greetingMsg();
  }
}

public class SingleInheritance {
    public static void main(String[] args) {
        Derived derivedObj = new Derived(); 
        derivedObj.greetingMsg(); // calling SuperClass Method
        derivedObj.greetingMsgWithName("Akshay"); 
    }
}
