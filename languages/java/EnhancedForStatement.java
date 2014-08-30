/**
 * Example 69 - Enhanced for statement on an Array
 */
public class EnhancedForStatement {
    public static void main(String[] args) {
        int[] arr = { 2, 3, 4, 5, 7, 11};
        int sum = 0;
        for(int i: arr)
            sum += i;
        System.out.println(sum);
    }
}
