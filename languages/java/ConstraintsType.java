import java.util.Date;

/**
 * Example 110 - Constraints Involving Type Parameters
 */

class ComparablePair<T extends Comparable<T>, U extends Comparable<U>>
        implements Comparable<ComparablePair<T, U>>
        {

            public final T fst;
            public final U snd;

            public ComparablePair(T fst, U snd) {
                this.fst = fst;
                this.snd = snd;
            }

            @Override
            public int compareTo(ComparablePair<T, U> that) {
                int firstCmp = this.fst.compareTo(that.fst);
                return firstCmp != 0 ? firstCmp : this.snd.compareTo(that.snd);
            }
        }
class ConstraintsType {

    public static void main(String[] args) {
        Date d = new Date(10);
        String s = "Senthil";
        ComparablePair<String, Date> p1 = new ComparablePair<String, Date>(s, d);
        ComparablePair<String, Date> p2 = new ComparablePair<String, Date>("Kumaran", new Date(11));
        ComparablePair<String, Date> p3 = new ComparablePair<String, Date>(s, d);
        System.out.println(p1.compareTo(p2));
        System.out.println(p1.compareTo(p3));
    }
}
