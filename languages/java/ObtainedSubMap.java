import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;

/**
 * Example 128 - Obtaining a SubMap
 */

class Time implements Comparable<Time> {

    public final int hh, mm;

    Time(int hh, int mm) {
        this.hh = hh;
        this.mm = mm;
    }


    @Override
    public int compareTo(Time t) {
        return hh != t.hh ? hh - t.hh: mm - t.mm;
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || this.getClass() != o.getClass())
            return false;
        Time t = (Time) o;
        return hh == t.hh && mm == t.mm;
    }

    public int hashCode() {
        return 60 * hh + mm;
    }
}
class ObtainedSubMap {
    public static void main(String[] args) {
        SortedMap<Time, String> datebook = new TreeMap<Time, String>();
        datebook.put(new Time(12, 30), "Lunch");
        datebook.put(new Time(15, 30), "Afternoon coffee break");
        datebook.put(new Time(9, 0), "Lecture");
        datebook.put(new Time(13, 15), "Board Meeting");
        SortedMap<Time, String> pm = datebook.tailMap(new Time(12, 0));

        for (Map.Entry<Time, String> entry: pm.entrySet())
            System.out.println(entry.getKey() + " " + entry.getValue());
    }
}
