

public class CommandLArgu { // class Starts here
    public static void main(String[] args) {
        int sum = 0;

        // Suming  Command line arguments
        for (int i = 0; i < args.length; i++) {
            sum += Integer.parseInt(args[i]); // adding arguments in variable sum
        }
        
        System.out.println("Sum of Command Line Arguments = " + sum);

    }
} // class ends here
