/**
 * Example 64 - Sequence of if-else Statements
 */
public class SequenceIfElse {
    static int wdaynol(String wday) {
        if (wday.equals("Monday")) return 1;
        else if (wday.equals("Tuesday")) return 2;
        else if (wday.equals("Wednesday")) return 3;
        else if (wday.equals("Thursday")) return 4;
        else if (wday.equals("Friday")) return 5;
        else if (wday.equals("Saturday")) return 6;
        else if (wday.equals("Sunday")) return 7;
        else return -1;
    }

    public static void main(String[] args) {
        System.out.println(wdaynol("Tuesday"));
        System.out.println(wdaynol("Sunday"));
    }
}
