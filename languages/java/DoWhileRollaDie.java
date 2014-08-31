/**
 * Example 75 - Using do-while to Roll a Die and Compute Sum Until 5 or 6 Comes up
 */
public class DoWhileRollaDie {

    public static void main(String[] args) {
        int sum = 0, eyes;

        do {
            eyes = (int) (1 + 6 * Math.random());
            sum += eyes;
        } while (eyes < 5);

        sum -= eyes; // remove the 5 added.

        System.out.println(sum);
    }
}
