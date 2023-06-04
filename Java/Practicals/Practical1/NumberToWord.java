package Practical1;
public class NumberToWord { // class starts here
    public static void main(String[] args) {
        int num = 340598;
        System.out.println(num);
        
        int reverseNumber = 0;
        while (num > 0) { // reversing number
            int rem = num % 10;
            reverseNumber = reverseNumber * 10 + rem;
            num /= 10;
        }
        num = reverseNumber ;

        while (num > 0) {
            int rem = num % 10; // storing digit

            if (rem == 0) { // if zero then not print in word
                num=num/10;
                continue;
            } else {
                switch (rem) { // switch case for 1 to 9 number
                    case 1:
                        System.out.print("One");
                        break;
                    case 2:
                        System.out.print("Two");
                        break;
                    case 3:
                        System.out.print("Three");
                        break;
                    case 4:
                        System.out.print("Four");
                        break;
                    case 5:
                        System.out.print("Five");
                        break;
                    case 6:
                        System.out.print("Six");
                        break;
                    case 7:
                        System.out.print("Seven");
                        break;
                    case 8:
                        System.out.print("Eight");
                        break;
                    case 9:
                        System.out.print("Nine");
                } // switch case ends here
            }
            System.out.print(" ");
            num /= 10;
        }// loop ends here
    }
}// class ends here
