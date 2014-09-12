import java.util.ArrayList;

/**
 * Example 120 - Java Generics Limitation: Cannot Create Array with Generic Element Type
 */

class G<T> {

}

class GenericsLimitation<T> {

    public void M() {
        T[] tarr;   // Legal Declaration
        G<T>[] ctarr;   // Legal Declaration
        G<Integer>[] ciarr; // Legal Declaration

        // tarr = new T[5];         // Illegal generic array creation
        // ctarr = new G<T>[5];     // Illegal generic array creation
        // ciarr = new G<Integer>[5];   // Illegal generic array creation

        ArrayList<T> tlist;
        ArrayList<G<T>> ctlist;
        ArrayList<G<Integer>> cilist;

        tlist = new ArrayList<T>();
        ctlist = new ArrayList<G<T>>();
        cilist = new ArrayList<G<Integer>>();
    }

    public static void main(String[] args) {

    }
}
