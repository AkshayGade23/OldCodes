package Program6;

public class Wrapperclass {
    public static void main(String[] args) {
        int num1 = 10;

        // wrapping around the Integer Object
        Integer num1Wrap = new Integer(num1);
        System.out.println("\n\nInteger Wrapper \n");
        System.out.println("Value of num1Wrap as String= " + num1Wrap.toString());
        System.out.println("parseInt= " + Integer.parseInt("1234567"));
        System.out.println("compare(56, 43) = " + Integer.compare(56, 43));
        System.out.println("max(10,20) = " + Integer.max(10, 20));
        System.out.println("min(10,20) = " + Integer.min(10, 20));

        float num2 = 10;

        // wrapping around the Integer Object
        Float num2Wrap = new Float(num2);
        System.out.println("\n\nFloat Wrapper \n");
        System.out.println("Value of num2Wrap as String= " + num2Wrap.toString());
        System.out.println("parseInt= " + Float.parseFloat("1234.567"));
        System.out.println("compare(56.43f, 43.56f) = " + Float.compare(56.43f, 43.56f));
        System.out.println("max(10.20f, 20.10f) = " + Float.max(10.20f, 20.10f));
        System.out.println("min(10.20f, 20.10f) = " + Float.min(10.20f, 20.10f));

        double num3 = 10.5645;

        // wrapping around the Integer Object
        Double num3Wrap = new Double(num3);
        System.out.println("\n\nDouble Wrapper \n");
        System.out.println("Value of num3Wrap as String= " + num3Wrap.toString());
        System.out.println("parseDouble('1234.567')= " + Double.parseDouble("1234.567"));
        System.out.println("compare(56.43, 43.56) = " + Double.compare(56.43, 43.56));
        System.out.println("max(10.20, 20.10) = " + Double.max(10.20, 20.10));
        System.out.println("min(10.20, 20.10)= " + Double.min(10.20, 20.10));

        byte num4 = 11;
        byte num5 = 20;

        // wrapping around the Integer Object
        Byte num4Wrap = new Byte(num4);
        System.out.println("\n\nByte Wrapper \n");
        System.out.println("Value of num4Wrap as String= " + num4Wrap.toString());
        System.out.println("parseByte('64') " + Byte.parseByte("64"));

        int a = Byte.compare(num4, num5);
        System.out.print("compare(num4, num5) = ");
        if (a == 0) {
            System.out.println("equals");
        } else if (a < 0) {
            System.out.println("true");

        } else {
            System.out.println("false");

        }
        System.out.println("toUnsignedInt(num4) = " + Byte.toUnsignedInt(num4));



        char ch = 'A';

        // wrapping around the Integer Object
        Character chWrap = new Character(ch);
        System.out.println("\n\nCharacter Wrapper \n");
        System.out.println("Value of chWrap as String= " + chWrap.toString());
        System.out.println("toUpperCase('a')= " + Character.toUpperCase('a'));
        System.out.println("toLowerCase('B')= " + Character.toLowerCase('B'));
        System.out.println("compare('a', 'A') = " + Character.compare('a', 'A'));
        System.out.println("isWhitespace(' ') = " + Character.isWhitespace(' '));
        System.out.println("isDigit('2')= " + Character.isDigit('2'));

    }
}
