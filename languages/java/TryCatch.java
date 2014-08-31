/**
 * Example 81 - A try-catch Statement
 */



class TryCatch {
    static final String[] wdays =
            {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    static class WeekdayException extends Exception{
        public WeekdayException(String wday) {
            super("Illegal weekday: " + wday);
        }
    }


    static int wdayno4(String wday) throws WeekdayException {
        for (int i = 0; i < wdays.length; i++)
            if (wday.equals(wdays[i]))
                return i+1;
        throw new WeekdayException(wday);
    }

    public static void main(String[] args) {
        try {
            System.out.println(args[0] + " is weekday number " + wdayno4(args[0]));
        } catch (WeekdayException x) {
            System.out.println("Weekday problem: " + x);
        } catch (Exception x) {
            System.out.println("Other problem: " + x);
        }
    }
}
