import java.io.*;

/**
 * Example 145 - Reading Numbers from a Text File
 */
class ReadingNumbers {

    static void sumfile(String filename) throws IOException {
        Reader r = new BufferedReader(new FileReader(filename));
        StreamTokenizer stok = new StreamTokenizer(r);
        stok.parseNumbers();
        double sum = 0;
        stok.nextToken();

        while (stok.ttype != StreamTokenizer.TT_EOF) {
            if (stok.ttype == StreamTokenizer.TT_NUMBER)
                sum += stok.nval;
            else
                System.out.println("Nonnumber: " + stok.sval);
            stok.nextToken();
        }

        System.out.println("The file sum is " + sum);

    }

    public static void main(String[] args) throws IOException {
        sumfile("ReadingNumbers.java");
    }
}
