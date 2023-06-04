
import java.io.*;


public class FileWriteCharStream {
    public static void main(String[] args) throws IOException {

        BufferedWriter bw = new BufferedWriter(new FileWriter("./thoughts.txt", true));
        bw.write("Do Good and Good will come to you");

        bw.close();

        System.out.println("Succesfully written");
    }
}
