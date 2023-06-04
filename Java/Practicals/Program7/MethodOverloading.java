package Program7;

public class MethodOverloading {
    public void sayMyName(String name) {
        System.out.println("Your name is " + name);
    }

    public void sayMyName(String name, String surname) {
        System.out.println("Your name is " + name + " " + surname);
    }

    public void sayMyName(String name, String middleName, String surname) {
        System.out.println("Your name is " + name + " " + middleName + " " + surname);
    }

    public static void main(String[] args) {
        MethodOverloading object = new MethodOverloading();
        object.sayMyName("Akshay");
        object.sayMyName("Akshay", "Gade");
        object.sayMyName("Akshay", "Babasaheb", "Gade");
    }
}
