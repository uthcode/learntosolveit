/**
 * Example 73 - Binary Search of a Sorted Array using a While loop
 */
public class BinarySearchSortedArray {

    public static int binarySearch(double[] arr, double x) {
        int a = 0, b = arr.length - 1;

        while (a <= b) { // Loop invariant: arr[a-1] < x < arr[b+1]
            int i = (a + b) / 2;
            if (arr[i] < x)
                a = i + 1;
            else if (arr[i] > x)
                b = i - 1;
            else
                return i;   // because arr[i] == x
        }
        // Now a > b, in fact a = b+1 and b = a -1, and so arr[b] < x < arr[a]
        // TODO: Senthil Kumaran - Why ~a ?
        // return ~a;
        return -1;
    }

    public static void main(String[] args) {
        double[] arr = { 4, 5, 6, 7, 8, 10, 12, 14};
        System.out.println(binarySearch(arr, 6.0));
        System.out.println(binarySearch(arr, 9.0));
    }
}
