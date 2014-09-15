import java.io.*;

/**
 * Example 155 - Internal Pipes Between Threads
 */
class InternalPipes {

    public static void main(String[] args) throws IOException {
        PipedOutputStream outpipe = new PipedOutputStream();
        PipedInputStream inpipe = new PipedInputStream(outpipe);
        final DataOutputStream outds = new DataOutputStream(outpipe);
        DataInputStream inds = new DataInputStream(inpipe);

        // This thread ouputs primes to outds -> outpipe -> inpipe -> inds;

        class Producer extends Thread {
            public void run() {
                try {
                    outds.writeInt(2);
                    for (int p = 3; true; p+=2) {
                        int q = 3;
                        while (q*q <=p && p%q != 0)
                            q+= 2;
                        if (q*q > p) {
                            outds.writeInt(p);
                            System.out.print(".");
                        }
                    }
                } catch (IOException e) {
                    System.out.println("<terminated>: " + e);
                }
            }
        }

        new Producer().start();

        for(;;) {
            for (int n = 0; n < 10; n++)
                System.out.print(inds.readInt() + " ");
            System.in.read();
        }
    }
}
