import java.util.Random;

/**
 * Example 92 - Mutual Exclusion
 */

class Util {
    public static void pause(int low, int high) {
        Random r = new Random();
        int R = r.nextInt(high-low) +low;
        try {
            Thread.sleep(R);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static int random(int low, int high) {
        Random r = new Random();
        int R = r.nextInt(high-low) + low;
        return R;
    }

}
class Printer extends Thread {
    static Object mutex = new Object();
    public void run() {
        for(;;) {
            synchronized (mutex) {
                System.out.print("-");
                Util.pause(100, 300);
                System.out.print("/");
            }
            Util.pause(0, 200);
        }
    }
}
class MutualExclusion {
    public static void main(String[] args) {
        new Printer().start();
        new Printer().start();
    }
}
