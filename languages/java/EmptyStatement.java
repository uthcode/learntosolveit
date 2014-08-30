/**
 * Example 62 - Empty Statement and Infinite Loop Because of misplaced semicolon
 */
public class EmptyStatement {

    public static void main(String[] args) {

        int i = 0;
        // misplaced semicolon; runs forver and ever.
        while(i < 10);
            i++;
    }
}
