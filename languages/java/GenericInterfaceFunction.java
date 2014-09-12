/**
 * Example 113 - A Generic Interface Representing a Function
 *
 * TODO: Senthil Kumaran - implement methods
 */

interface MyList<T> extends Iterable<T> {
    int getCount();     // Number of elements
    T get(int i);       // Get the element at index i
    void set(int i, T item);    // Set element at index i
    void add(T item);   // Add element at index i
    void insert(int i, T item); // Insert element at index i
    void removeAt(int i);       // Remove item at index i
    <U> MyList<U> map(Mapper<T, U> f);  // Map f over all elements

}

interface Mapper<A, R> {
    R call(A x);
}


class GenericList {
}

public class GenericInterfaceFunction {
}
