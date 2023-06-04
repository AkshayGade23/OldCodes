package Practical1;
public class Constructor { // class starts here

    Constructor() { // Default constructor
        System.out.println("Good Morning");
    }

    Constructor(String name) { // parameterized Constructor
        System.out.println("Hey " + name + ", Good Morning");
    }

    Constructor(String name, String surname) { // Overloaded Constructor
        System.out.println("Hey " + name + " "+surname+ ", Good Morning");
    }

    public static void main(String[] args) {
           Constructor obj1 = new Constructor(); // default constructor will call
           Constructor obj2 = new Constructor("Akshay");// parameterized Constructor will call
           Constructor obj3 = new Constructor("Akshay","Gade"); // Overloaded Constructor will call
    }
}// class ends here
