import java.util.ArrayList;
import java.util.Date;

/**
 * Example 107 - A Generic Class for Logging
 */

class Log<T> {
    private final int size;
    private static int instanceCount = 0;
    private int count = 0;
    private T[] log;

    public Log(T[] log) {
        this.log = log;
        this.size = log.length;
        instanceCount++;
    }

    public void add(T msg) {
        log[count++ % size] = msg;
    }

    public T getLast() {
        return count == 0 ? null: log[(count - 1) % size];
    }

    public ArrayList<T> getAll() {
        ArrayList<T> r = new ArrayList<T>();
        for (int i = 0; i < log.length; i++) {
            r.add(log[i]);
        }
        return r;
    }

}
class GenericClassLogging {
    public static void main(String[] args) {
        Log<Date> log2 = new Log<Date>(new Date[5]);
        log2.add(new Date());
        log2.add(new Date(1000));
        log2.add(new Date(1111111111));
        log2.add(new Date(1234567890));
        log2.add(new Date(1410303686));
        for (Date d: log2.getAll())
            System.out.println(d);
    }
}
