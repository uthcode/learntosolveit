import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

/**
 * Example 82 - A try finally Statement.
 * Can't try on ideone.
 */
class TryFinally {

    static double[] readRecord(String filename) throws IOException {
        Reader freader = new FileReader(filename);
        BufferedReader breader = new BufferedReader(freader);
        double[] res = new double[3];

        try {
            res[0] = new Double(breader.readLine()).doubleValue();
            res[1] = new Double(breader.readLine()).doubleValue();
            res[2] = new Double(breader.readLine()).doubleValue();
        } finally {
            breader.close();
        }

        return res;
    }

    public static void main(String[] args) {
        try {
            double[] res = readRecord("tryFinally.txt");
            for(Double d: res)
                System.out.println(d);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
