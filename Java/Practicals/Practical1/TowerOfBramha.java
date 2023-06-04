
package Practical1;
public class TowerOfBramha {

    public static void main(String[] args) {
        int n=3;
        tob( n,'A', 'B', 'C');

    }

    static void tob(int n, char src, char dest, char wtho) {
        if (n == 1) {
            System.out.println("<" + src + ", " + dest + ">");
            return;
        }

        tob(n-1,src,wtho,dest);
        tob(1,src,dest,wtho);
        tob(n-1, wtho, dest, src);
    }

}
