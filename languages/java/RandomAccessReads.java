import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

/**
 * Example 153 - Random Access Reads from a String Array File
 * TODO: Senthil Kumaran - The file reads the contents written by StringArrayFile
 */
class RandomAccessReads {

    static String readOneString(String filename, int i) throws IOException {
        final int INTSIZE = 4, LONGSIZE = 8;
        RandomAccessFile raf = new RandomAccessFile(filename, "r");
        raf.seek(raf.length() - INTSIZE);
        int N = raf.readInt();
        raf.seek(raf.length() - INTSIZE - LONGSIZE * N + LONGSIZE * i);
        long si = raf.read();
        raf.seek(si);
        String s = raf.readUTF();
        raf.close();
        return s;
    }

    public static void main(String[] args) throws IOException {
        System.out.println(readOneString("sample.txt", 1));
    }
}
