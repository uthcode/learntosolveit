import java.io.*;

/**
 * Example 146 - Reading Numbers from a Text File, Line by Line
 */
class ReadingNumbersLineByLine {

    static void sumlines(String filename) throws IOException {
        LineNumberReader lnr = new LineNumberReader(new FileReader(filename));
        lnr.setLineNumber(1);
        StreamTokenizer stok = new StreamTokenizer(lnr);
        stok.parseNumbers();
        stok.eolIsSignificant(true);
        stok.nextToken();
        while (stok.ttype != StreamTokenizer.TT_EOF) {
            int lineno = lnr.getLineNumber();
            double sum = 0;
            while (stok.ttype != StreamTokenizer.TT_EOL) {
                if (stok.ttype == StreamTokenizer.TT_NUMBER)
                    sum += stok.nval;
                stok.nextToken();
            }
            System.out.println("Sum of line " + lineno + " is " + sum);
            stok.nextToken();
        }
    }

    public static void main(String[] args) throws IOException {
        sumlines("ReadingNumbersLineByLine.java");
    }
}
