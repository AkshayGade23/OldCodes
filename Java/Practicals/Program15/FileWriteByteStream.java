// package Program15;

import java.io.*;

public class FileWriteByteStream {
    public static void main(String[] args) throws IOException {
        int i;
        FileOutputStream fout;
        fout = new FileOutputStream("./name.txt", true);
        String s = "I am Akshay";

        char[] ch = s.toCharArray();
        for (i = 0; i < ch.length; i++)
            fout.write(ch[i]);
            
        fout.close();
        System.out.println("Succesfully written");
    }
}
