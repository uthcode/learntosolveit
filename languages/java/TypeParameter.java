import java.io.PrintWriter;

/**
 * Example 109 - Type Parameter Constraints
 * TODO: Senthil Kumaran - Implement Methods
 */

interface Printable { void print(PrintWriter fs);}

class PrintableMyLinkedList<T extends Printable> extends MyLinkedList<T> implements Printable {

    public void print(PrintWriter fs) {
        for (T x: this)
            x.print(fs);
    }

}
public class TypeParameter {

    class MyPrinter implements Printable {
        @Override
        public void print(PrintWriter fs) {
        }
    }
    public static void main(String[] args) {
        PrintableMyLinkedList<MyPrinter> myLinkedList = new PrintableMyLinkedList<MyPrinter>();
    }
}
