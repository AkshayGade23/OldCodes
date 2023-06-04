

interface AIDSC{
    void m1();
    void m2();
};

abstract class Aids implements AIDSC{
    @Override
    public void m2(){
        System.out.println("Babasaheb");
    }
    public void m3(){
        System.out.println("Gade");
    }
};

class NestedDemo{
    interface I1{
        void t1();
    }
    interface I2{
        void t2();
    }

};

class NestedDemo2 implements NestedDemo.I1,NestedDemo.I2 {
    @Override
    public void t1(){}
    public void t2(){}
};

public class AbstractDemo extends Aids{

    @Override
    public void m1(){
        System.out.println("Akshay");
    }
    public static void main(String[] args) {
        AbstractDemo a1 = new AbstractDemo();
    }
}