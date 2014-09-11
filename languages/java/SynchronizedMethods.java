import java.util.Random;

/**
 * Example 93 - Synchronized Methods in an Object
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

class Bank {
    private int account1 = 10, account2 = 20;

    synchronized public void transfer(int amount) {
        int new1 = account1 - amount;
        Util.pause(0,10);
        account1 = new1;
        account2 = account2 + amount;
        System.out.println("Sum is " + (account1 + account2));
    }
}

class Clerk extends Thread {
    private Bank bank;

    public Clerk(Bank bank) {
        this.bank = bank;
    }

    public void run() {
        for(;;) {
            bank.transfer(Util.random(-10, 10));
            Util.pause(200, 300);
        }
    }
}
public class SynchronizedMethods {
    public static void main(String[] args) {
        Bank bank = new Bank();
        new Clerk(bank).start();
        new Clerk(bank).start();
    }
}
