import java.io.*;
import java.util.*;

/**
 * Example 135 - A Comparator for the String Class
 */

class StringComparator {

    static SortedMap<String, SortedSet<Integer>> buildIndex(String filename) throws IOException {

        Reader r = new BufferedReader(new FileReader(filename));
        StreamTokenizer stok = new StreamTokenizer(r);
        stok.quoteChar('"');
        stok.ordinaryChars('!', '/');
        stok.nextToken();

        SortedMap<String, SortedSet<Integer>> index = new TreeMap<String, SortedSet<Integer>>(new IgnoreCaseComparator());

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

    static class IgnoreCaseComparator implements Comparator<String> {
        @Override
        public int compare(String s1, String s2) {
            int res = s1.compareToIgnoreCase(s2);
            return res != 0 ? res : s1.compareTo(s2);
        }
    }

    public static void main(String[] args) {
        try {
            SortedMap<String, SortedSet<Integer>> concord = buildIndex("WeekdayNametoNumberHashMap.java");

            for(String word: concord.keySet())
                System.out.println(word + concord.get(word).toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
