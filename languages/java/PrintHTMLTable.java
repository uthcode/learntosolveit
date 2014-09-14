import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Example 143 - Printing an HTML Table
 */
class PrintHTMLTable {

    public static void main(String[] args) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter("temperature.html"));
        pw.println("<TABLE BORDER><TR><TH>Fahrenheit<TH>Celsius</TR>");
        for (int f = 10; f <= 200 ; f += 10) {
            double c = 5 * (f - 32.0) / 9;
            pw.format("<TR ALIGN=RIGHT><TD>%d<TD>%.1f%n", f, c);
        }
        pw.println("</TABLE>");
        pw.close();
    }
}
