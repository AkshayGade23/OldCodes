package Program7;
class Base{
    void msg(){
        System.out.println("It's a Base Class");
    }
}
class Derived extends Base{
    @Override
    void msg(){
        System.out.println("It's a Derived Class");
    }
}
public class MethodOverriding {
    public static void main(String[] args) {
        Base baseObj = new Base();
        baseObj.msg();
        baseObj = new Derived();
        baseObj.msg();
    }
}
