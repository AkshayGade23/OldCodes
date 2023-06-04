package Practical1;
public class Prime { // class  starts here
    public static void main(String[] args) {
        int num = 230;
        int c = 2;
        boolean isPrime = true;

        while (c * c < num) {  // checking prime or not
            if (num % c == 0) {
                isPrime = false;
                break;
            }
            c++;
        }

        if (isPrime) { // printing output -> is prime or not 
            System.out.println("Given number is prime");
        } else {
            System.out.println("Given number is not  prime");

        }
        
    }
}//class ends here 
