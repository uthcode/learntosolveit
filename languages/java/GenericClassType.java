import java.util.Date;

/**
 * Example 106 - A Generic Class Type for Pairs
 */

class Pair<T, U> {
    public final T fst;
    public final U snd;
    public Pair(T fst, U snd) {
        this.fst = fst;
        this.snd = snd;
    }

    public String toString() {
        return "(" + this.fst.toString() + ", " + this.snd.toString() + ")";
    }
}
class GenericClassType {
    public static void main(String[] args) {
        Pair<String, Integer> p1 = new Pair<String, Integer>("Neils", 1947);
        Pair<Double, Integer> p2 = new Pair<Double, Integer>(2.718, 1);
        Pair<Date, String> p3 = new Pair<Date, String>(new Date(), "now");

        System.out.println(p1);
        System.out.println(p2);
        System.out.println(p3);
    }


}
