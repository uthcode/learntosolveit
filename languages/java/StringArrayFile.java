import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.NoSuchElementException;

/**
 * Example 152 - Organizing a String Array File For Random Access
 * TODO: Senthil Kumaran - verify the content written.
 *
 */


class StringArrayFile {

    static Iterable<String> fromTo() {

        class FromToIterator implements Iterator<String> {
            private int n = 10;
            private int m = 100;
            private int i = m;
            @Override
            public boolean hasNext() {
                return i <= n;
            }

            @Override
            public String next() {
                if (i <= n) {
                    i += 1;
                    return String.valueOf(i);
                } else
                    throw new NoSuchElementException();
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }
        }

        class FromToIterable implements Iterable<String> {
            @Override
            public Iterator<String> iterator() {
                return new FromToIterator();
            }
        }

        return new FromToIterable();
    }


    static void writeStrings(String filename, Iterable<String> strGenerator) throws IOException {
        RandomAccessFile raf = new RandomAccessFile(filename, "rw");
        raf.setLength(0);
        ArrayList<Long> offsetttable = new ArrayList<Long>();
        for(String s: strGenerator) {
            offsetttable.add(raf.getFilePointer());
            raf.writeUTF(s);
        }

        for(long offset: offsetttable)
            raf.writeLong(offset);

        raf.writeInt(offsetttable.size());
        raf.close();
    }

    public static void main(String[] args) throws IOException {
        writeStrings("sample.txt", fromTo());
    }

}
