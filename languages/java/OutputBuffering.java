import java.io.*;
import java.util.Timer;

/**
 * Example 150 - Output Buffering
 */
class OutputBuffering {

    public static void main(String[] args) throws IOException {
        OutputStream os1 = new FileOutputStream("tmp1.dat");
        writeints("Unbufferred: ", 1000000, os1);
        OutputStream os2 = new BufferedOutputStream(new FileOutputStream("tmp2.dat"));
        writeints("Bufferred: ", 100000, os2);
        Writer wr1 = new FileWriter("tmp1.dat");
        writeints("Unbuffered: ", 100000, wr1);
        Writer wr2 = new BufferedWriter(new FileWriter("tmp2.dat"));
        writeints("Buffered: ", 100000, wr2);
    }

    static void writeints(String msg, int count, OutputStream os) throws IOException {
        //Timer t = new Timer();
        for (int i = 0; i < count; i++) {
            os.write(i & 255);
        }
        os.close();
        // t.check() originally.
        System.out.println(msg);
    }

    static void writeints(String msg, int count, Writer os) throws IOException {
        //Timer t = new Timer();
        for (int i = 0; i < count; i++) {
            os.write(i & 255);
        }
        os.close();
        // t.check() originally
        System.out.println(msg);
    }
}
