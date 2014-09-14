import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Example 142 - Printing Numbers to a Text file
 */
class PrintingNumbers {

    public static void main(String[] args) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter("dice.txt"));
        for (int i = 1; i <= 1000; i++) {
            int die = (int) (1 + 6 * Math.random());
            pw.print(die);
            pw.print(' ');

            if (i % 20 == 0)
                pw.println();
        }

        pw.println();
        pw.close();
    }

}
