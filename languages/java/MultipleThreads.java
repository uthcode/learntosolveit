import java.io.IOException;

/**
 * Example 91 - Multiple Threads
 */

class Incrementer extends Thread {
    public int i;
    public void run() {
        for(;;) {
            i++;
            yield();
        }
    }
}
class MultipleThreads {
    public static void main(String[] args) throws IOException {
        Incrementer u = new Incrementer();
        u.start();
        System.out.println("Repeatedly press a key to get the current value of i");
        for(;;) {
            System.in.read();
            System.out.println(u.i);
        }
    }
}
