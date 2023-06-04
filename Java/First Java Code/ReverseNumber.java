import java.util.Scanner;

public class ReverseNumber {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int num = in.nextInt();
        int reverseNumber = 0;

        while (num > 0) {
            int rem = num % 10;
            reverseNumber = reverseNumber * 10 + rem;
            num /= 10;
        }
        System.out.println(reverseNumber);
        in.close();
    }
}
