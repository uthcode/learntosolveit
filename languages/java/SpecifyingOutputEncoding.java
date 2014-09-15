import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;

/**
 * Example 151 - Specifying a Particular Output Encoding
 *
 */

class SpecifyingOutputEncoding {

    public static void main(String[] args) throws UnsupportedEncodingException {
        String s = "áéíóú";
        String enc = "UTF-8";
        OutputStreamWriter osw = new OutputStreamWriter(System.out, enc);
        PrintWriter pw = new PrintWriter(osw);
        pw.println(s);
    }
}
