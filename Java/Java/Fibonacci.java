public class Fibonacci { // class starts here
    public static void main(String[] args) {
       
        int a = 0;
        int b = 1;

        System.out.println("Fibonacci Series upto 50");

        System.out.println(a); // printing first two 
        System.out.println(b); // values that is 0 and 1

        for(int count = 0;b <= 50;count++) {  // for loop to print fibonacci numbers upto 50 
            int temp = a;
            a = b;
            b = b + temp;
            System.out.printf(" %d,",b);
        }
       
    }
} // class ends here