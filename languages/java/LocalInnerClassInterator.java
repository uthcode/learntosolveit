import java.util.Iterator;

/**
 * Example 40 - An Iterator as a Local class
 */
public class LocalInnerClassInterator {

    static Iterator<String> suffixes(final String s) {
        class SuffixIterator implements Iterator<String> {
            int startindex = 0;

            @Override
            public boolean hasNext() {
                return startindex < s.length();
            }

            @Override
            public String next() {
                return s.substring(startindex++);
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException();

            }
        }

        return new SuffixIterator();
    }

    public static void main(String[] args) {
        Iterator<String> seq = suffixes(args[0]);
        while (seq.hasNext()) {
            System.out.println(seq.next());
        }
    }

}
