import java.util.Comparator;

/**
 * Example 116 - A Generic Quicksort Method for Comparable Values
 */
public class GenericQuicksortComparable {

    public static <T extends Comparable<T>> void qsort(T[] arr, int a, int b) {
        if (a < b) {
            int i = a, j = b;
            T x = arr[(i + j) / 2];

            do {
                while (arr[i].compareTo(x) < 0) i++;
                while (x.compareTo(arr[j]) < 0) j--;

                if ( i <= j) {
                    T tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    i++;
                    j--;
                }

            } while (i <= j);

            qsort(arr, a, j);
            qsort(arr, i, b);
        }
    }

    public static void main(String[] args) {
        Integer[] ia = {30, 20, 10, 5, 6, 99};
        GenericQuicksortComparable.<Integer>qsort(ia, 0, ia.length-1);
        for(Integer i: ia) {
            System.out.println(i);
        }

    }
}
