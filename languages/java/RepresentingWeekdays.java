/**
 * Example 88 - Representing Weekdays and Months using Enum Types
 * TODO: Senthil Kumaran - Provide a Working Example
 */
public class RepresentingWeekdays {
    enum Day {
        Mon, Tue, Wed, Thu, Fri, Sat, Sun;
        private final static Day[] day = values();
        public static Day toDay(int n) { return day[n];}
        public int toInt() { return ordinal(); }
    }

    enum Month {
        Jan(31), Feb(28), Mar(31), Apr(30), May(31), Jun(30),
        Jul(31), Aug(31), Sep(30), Oct(30), Nov(30), Dec(31);

        private final int days;
        private Month(int days) {
            this.days = days;
        }

        private final static Month[] month = values();

        public int days(int year) {
            // Simplistic - Does not take care of Leap year
            return days;
        }

        public static Month toMonth(int n) {
            return month[n-1];
        }

        public int toInt() {
            return ordinal()+1;
        }

        public Month succ() {
            return toMonth(toInt() + 1);
        }
    }

    class MyDate {
        final int yy;
        final Month mm;
        final int dd;

        public MyDate(int yy, Month mm, int dd) throws Exception {
            this.yy = yy;
            this.mm = mm;
            this.dd = dd;
        }

        public String toString() {
            return String.format("%4d-%02d-%02d", yy, mm.toInt(), dd);
        }

    }
}
