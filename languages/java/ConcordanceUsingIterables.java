import java.io.*;
import java.util.*;

/**
 * Example 130 - Printing a Concordance Using Iterables
 */
class ConcordanceUsingIterables {

    static SortedMap<String, SortedSet<Integer>> buildIndex(String filename) throws IOException {

        Reader r = new BufferedReader(new FileReader(filename));
        StreamTokenizer stok = new StreamTokenizer(r);
        stok.quoteChar('"');
        stok.ordinaryChars('!', '/');
        stok.nextToken();

        SortedMap<String, SortedSet<Integer>> index = new TreeMap<String, SortedSet<Integer>>();

        while (stok.ttype != StreamTokenizer.TT_EOF) {
            if (stok.ttype == StreamTokenizer.TT_WORD) {
                SortedSet<Integer> ts;
                if (index.containsKey(stok.sval))
                    ts = index.get(stok.sval);
                else {
                    ts = new TreeSet<Integer>();
                    index.put(stok.sval, ts);
                }
                ts.add(stok.lineno());
            }
            stok.nextToken();
        }
        return index;
    }

    static void printIndex(SortedMap<String, SortedSet<Integer>> index) {
        for (Map.Entry<String, SortedSet<Integer>> entry: index.entrySet()) {
            System.out.print(entry.getKey() + ": ");
            SortedSet<Integer> lineNoSet = entry.getValue();
            for (int lineno: lineNoSet)
                System.out.print(lineno + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        SortedMap<String, SortedSet<Integer>> concord = buildIndex("WeekdayNametoNumberHashMap.java");
        printIndex(concord);
    }
}
