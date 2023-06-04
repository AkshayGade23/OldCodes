package Program6;

import java.util.HashMap;
public class HashmapPrgm {
    public static void main(String[] args) {
        HashMap<String,Integer> studMarks = new HashMap<>();

        // Adding Values in HashMap
        studMarks.put("Akshay", 10); // using put method
        studMarks.put("Tejas", 20);
        studMarks.put("Sumit", 30);
        studMarks.put("Sourabh", 40);
        
        System.out.println(studMarks);

        System.out.println("Size of HashMap studMarks = " + studMarks.size()); // using size method

        System.out.println("Marks of Akshay = " + studMarks.get("Akshay")); // using get method

        System.out.println("Checking whether given key (Sanjay) in it or not = " + studMarks.containsKey("Sanjay"));

    }
}
