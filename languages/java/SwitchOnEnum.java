/**
 * Example 66 - A Switch Statment on Enum Type
 */
class SwitchOnEnum {
    enum Month {
        Jan(31), Feb(28), Mar(31), Apr(30), May(31), Jun(30),
        Jul(31), Aug(31), Sep(30), Oct(31), Nov(30), Dec(31);

        private final int days;
        private Month(int days) { this.days = days;}
        private static String days(Month m) {
            switch(m) {
                case Apr:case Jun:case Sep:case Nov:
                    return "30";
                case Feb:
                    return "28 for non leap, 29 for leap year.";
                default:
                    return "31";
            }
        }
    }

    public static void main(String[] args) {
        Month month=Month.Jun;
        System.out.println(Month.days(month));
    }
}
