public class Palindrn {
    public static void main(String[] args) {
        String str = "abdcba";
        System.out.println(isPalindrom(str));

    }

    static boolean isPalindrom(String str) {
        if (str == null || str == "") {
            return true;
        }
        str = str.toLowerCase();

        for (int i = 0; i <= str.length()/2; i++) {
            char start = str.charAt(i);
            char end = str.charAt(str.length() - 1 - i);

            if (start != end) {
                return false;
            }
        }
        return true;
    }
}