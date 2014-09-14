import java.util.Comparator;

/**
 * Example 132 - A Comparator for the Integer Class
 */

class IntComparator implements Comparator<Integer> {

    @Override
    public int compare(Integer v1, Integer v2) {
        return v1 < v2 ? -1 : v1 > v2 ? +1 : 0;
    }
}

class IntegerComparator {

    public static <T> void qsort(T[] arr, Comparator<T> cmp, int a, int b) {
        if (a < b) {
            int i = a, j = b;
            T x = arr[(i + j) / 2];

            do {
                while (cmp.compare(arr[i], x) < 0) i++;
                while (cmp.compare(x, arr[j]) < 0) j--;

                if ( i <= j) {
                    T tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    i++;
                    j--;
                }

            } while (i <= j);

            qsort(arr, cmp, a, j);
            qsort(arr, cmp, i, b);
        }
    }

    public static void main(String[] args) {
        Integer[] ia = {30, 20, 10, 5, 6, 99};
        GenericQuickSort.<Integer>qsort(ia, new IntComparator(), 0, ia.length-1);
        for(Integer i: ia) {
            System.out.println(i);
        }

    }


}
