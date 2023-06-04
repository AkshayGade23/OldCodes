import java.io.*;

interface in1 {
    void msg1();
}

interface in2 {
    void msg2();
}

class Derivedclass implements in1, in2 { // implementing in1 and in2 interface
    public void msg1() {
        System.out.println("Hii Everyone!");
    }

    public void msg2() {
        System.out.println("Good Morning!");
    }

    void greetMessage() {
        msg1();
        msg2();
    }
}

public class Multipleinheritance {
    public static void main(String[] args) {
        Derivedclass derivedObj = new Derivedclass();
        derivedObj.greetMessage();
    }
}
