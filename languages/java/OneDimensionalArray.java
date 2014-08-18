/**
 * Example 18 - Creating and Using One-Dimensional Arrays
 */
public class OneDimensionalArray {
    public static void main(String[] args) {
        int[] freq = new int[6];
        for (int i = 0; i < 1000; i++) {
            int die = (int) ( 1 + 6 * Math.random()); // Die roll between 1 to 6
            freq[die-1] += 1;
        }

        for (int c = 1; c <= 6 ; c++) {
            System.out.println(c + " came up " + freq[c - 1] + " times");
        }

        // Initialize an Array of String objects

        String[] number = new String[20];   // Create array of null elements

        for (int i = 0; i < number.length; i++) {
            number[i] = "A" + i;
        }

        for (int i = 0; i < number.length; i++) {
            System.out.println(number[i]);

        }
    }
}
