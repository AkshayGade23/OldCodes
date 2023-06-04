import java.io.*;

public class FileReadCharStream {
  public static void main(String[] args) throws IOException {

    BufferedReader br = new BufferedReader(new FileReader("./thought.txt"));

    String s;

    while ((s = br.readLine()) != null)
      System.out.println(s);

    br.close();
  }
}
