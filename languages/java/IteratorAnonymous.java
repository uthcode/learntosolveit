import java.util.Iterator;

/**
 * Example 41 - An Iterator as an Anonymous Local Class
 */
public class IteratorAnonymous {

    static Iterator<String> suffixes(final String s) {
        return new Iterator<String>() {
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
        };

    }

    public static void main(String[] args) {
        Iterator<String> seq = suffixes(args[0]);

        while (seq.hasNext())
            System.out.println(seq.next());
    }
}
