public class SumofDigits { // class start here
    public static void main(String[] args) {
        int num = 555;
        int sum = 0;
        do { // do-while loop
            int rem = num % 10;
            sum = sum + rem;
            num = num / 10;
        } while (num > 0); // loop condition

        System.out.printf("Sum of Digit's in number is %d ", sum);
    }
} // ends here