import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Example 131 - A Method Returning an Iterable
 */
class MethodReturningIterable {

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

    public static void main(String[] args) {
        for (int i: fromTo(2, 20))
            System.out.println(i);
    }
}
