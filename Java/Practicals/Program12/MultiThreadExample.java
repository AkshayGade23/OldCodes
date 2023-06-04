package Program12;

class MultiThreadClass extends Thread {
    String id;

    MultiThreadClass(String id) {
        this.id = id;
    }

    public void run() {
        for(int i = 1;i<5;i++){
        System.out.println("Thread " + id + " is Running -> " + i);
        }
    }
}

public class MultiThreadExample {
    public static void main(String args[]) {
        Thread Object1 = new Thread(new MultiThreadClass("Thrd 1"));
        Thread Object2 = new Thread(new MultiThreadClass("Thrd 2"));
        Thread Object3 = new Thread(new MultiThreadClass("Thrd 3"));
        Object1.start();
        Object2.start();
        Object3.start();
    }
}
