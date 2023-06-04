package Program5;
public class StringandStringBuff {
    public static void main(String[] args) {
        String  strng = "   Java Programming"; // String initialization
        StringBuffer strngBuffr = new StringBuffer("Java Advanced");
        
        // 10 String Methods
        System.out.println("String Methods \n");
        System.out.println("toLowerCase() = " +strng.toLowerCase());
        System.out.println("toUpperCase() = "+strng.toUpperCase());
        System.out.println("length() = "+strng.length());
        System.out.println("trim() = "+strng.trim());
        System.out.println("charAt(5) = "+strng.charAt(5));
        System.out.println("contains('Program') = "+strng.contains("Program"));
        System.out.println("endsWith('ingg') = "+strng.endsWith("ingg"));
        System.out.println("concat(' - 1') = "+strng.concat(" - 1"));
        System.out.println("equals('   Java Programming') = "+strng.equals("   Java Programming"));
        System.out.println("isEmpty() = "+strng.isEmpty());
        
        
        // 10 StringBuffer Methods
        System.out.println("\nStringBuffer Methods =\n");

        System.out.println("capacity() = "+strngBuffr.capacity());
        System.out.println("length() = "+strngBuffr.length());
        System.out.println("charAt(6) = "+strngBuffr.charAt(6));
        System.out.println("substring(6) = "+strngBuffr.substring(6));
        System.out.println("substring(6,10) = "+strngBuffr.substring(6,10));
        System.out.println("reverse() = "+strngBuffr.reverse());
        System.out.println("append() = "+strngBuffr.append(" GPP"));
        System.out.println("replace(0,3,'DEC') = "+strngBuffr.replace(0,3,"DEC"));
        System.out.println("delete(0,3) = "+strngBuffr.delete(0,3));
        System.out.println("deleteCharAt(3) = "+strngBuffr.deleteCharAt(3));

    }
}