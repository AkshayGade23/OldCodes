public class BackSpaceStringComapre {
    public static void main(String[] args) {
        String s = "xywrrmp";
        String t = "xywrrmu#p";
        System.out.println("compare " + backspaceCompare(s, t));
    }

    static boolean backspaceCompare(String s, String t) {
        return backpsaceString(s).equals(backpsaceString(t));
    }

    static String backpsaceString(String str) {

        // StringBuilder temp = new StringBuilder();

        // for (int i = 0; i < str.length(); i++) {

        // if (str.charAt(i) == '#') {
        // if (temp.length() != 0) {
        // temp.deleteCharAt(temp.length() - 1);

        // }
        // } else
        // temp.append(str.charAt(i));

        // System.out.println("temp " + temp);
        // }
        // System.out.println("--------");
        // return temp.toString();

        int i = 0;
        int size = str.length();
        while (i < size) {
            
            if (str.charAt(i) == '#') {

                if (i == 0) {
                    str = str.substring(1);
                    size--;
                }

                else if (i == 1) {
                    str = str.substring(2);
                    i--;
                    size -= 2;
                } else {
                    str = str.substring(0, i - 1) + str.substring(i + 1);
                    i--;
                    size -= 2;
                }
            } else
                i++;
        }

        return str;
        
    }

    
}
