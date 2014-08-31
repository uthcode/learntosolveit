import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Example 74 - Explicitly Going through an Iterable using while loop
 */
public class ExplicitIterableWhileLoop {
    public static void main(String[] args) {

        Iterable<Integer> ible = fromTo(13, 17);
        Iterator<Integer> iter = ible.iterator();

        while (iter.hasNext()) {
            int i = iter.next();
            System.out.println(i);
        }

    }

    public static Iterable<Integer> fromTo(final int m, final int n) {

        class FromToIterator implements Iterator<Integer> {

            private int i = m;

            @Override
            public boolean hasNext() {
                return  i <= n;
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
