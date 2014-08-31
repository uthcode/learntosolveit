import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Example 71 - Explicitly Going through an Iterable Using for
 */

public class ExplicitIterable {
    public static void main(String[] args) {
        Iterable<Integer> ible = fromTo(13, 17);
        for(Iterator<Integer> iter = ible.iterator(); iter.hasNext(); /* none */) {
            int i = iter.next();
            System.out.println(i);
        }

    }

    public static Iterable<Integer> fromTo(final int m, final int n) {

        class FromToIterator implements Iterator<Integer> {
            private int i = m;

            @Override
            public boolean hasNext() {
                return i <= n;
            }

            @Override
            public Integer next() {
                if (i <= n)
                    return i++;
                else
                    throw new NoSuchElementException();
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }
        }

        class FromToIterable implements Iterable<Integer> {

            @Override
            public Iterator<Integer> iterator() {
                return new FromToIterator();
            }
        }

        return new FromToIterable();

    }
}
