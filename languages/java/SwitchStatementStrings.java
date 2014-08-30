import java.util.HashMap;

/**
 * Example 67 - The switch Statement and Strings
 */

class SwitchStatementStrings {

    private static  final HashMap<String, Integer> wdayNumber = new HashMap<String, Integer>();

    static {
        int wdayno = 0;
        String[] wdays =
                {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        for(String wday: wdays)
            wdayNumber.put(wday, wdayno++);
    }

    public static int wdayno5(String wday) {
        Integer res = wdayNumber.get(wday);
        return res == null ? -1: res;
    }

    public static void main(String[] args) {
        Integer index = wdayNumber.get(args[0]);
        Integer hours = 8;
        switch( index != null ? index: -1) {
            case 0:
                System.out.format("Monday: pay is %.2f%n", 10+7.42*hours);
                break;
            case 1:case 2:case 3:case 4:
                System.out.format("Workday: pay is %.2f%n", 7.42*hours);
                break;
            case 5:case 6:
                System.out.format("Weekend: pay is %.2f%n", 20+1.25*7.42*hours);
                break;
            default:
                System.out.format("Unknown weekday: %s%n", args[0]);
        }

    }
}
