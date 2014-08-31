/**
 * Example 72 Linear Array Search Using a While loop
 */
public class WhileLoop {

    static final String[] wdays =
            {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    static int wdayno2(String wday) {
        int i = 0;

        while (i < wdays.length && ! wday.equals(wdays[i]))
            i++;

        // Now i >= wdays.length or wday equals wdays[i]

        if (i < wdays.length)
            return i+1;
        else
            return -1;  // Here used to mean 'not found'

    }

    public static void main(String[] args) {
        System.out.println(wdayno2("Monday"));
        System.out.println(wdayno2("Sunday"));
        System.out.println(wdayno2("Sommar"));
    }
}
