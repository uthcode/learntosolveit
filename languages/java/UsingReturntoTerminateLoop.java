/**
 * Example 76 - Using return to Terminate a Loop Early
 */
public class UsingReturntoTerminateLoop {

    static final String[] wdays =
            {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    static int wdayno3(String wday) {
        for (int i = 0; i < wdays.length; i++)
            if (wday.equals(wdays[i]))
                return i+1;
        return -1;
    }


    public static void main(String[] args) {
        System.out.println(wdayno3("Monday"));
        System.out.println(wdayno3("Sommar"));

    }
}
