/**
 * Example 133 - A Time Class Implementing Comparable<Time>
 */
class TimeComparable {

    static class Time implements Comparable<Time> {

        public final int hh, mm;

        public Time(int hh, int mm) {
            this.hh = hh;
            this.mm = mm;
        }

        @Override
        public int compareTo(Time t) {
            return hh != t.hh ? hh - t.hh : mm - t.mm;
        }

        public boolean equals(Object o) {
            if (this == o)
                return true;

            if (o == null || this.getClass() != o.getClass())
                return false;

            Time t = (Time)o;
            return hh == t.hh && mm == t.mm;
        }
    }

    public static void main(String[] args) {
        Time t1 = new Time(10, 10);
        Time t2 = new Time(10, 5*2);
        System.out.println(t1.compareTo(t2));
        System.out.println(t1.equals(t2));

    }
}
