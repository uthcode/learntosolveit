/**
 * Example 117 - A Generic Method in a Generic Class
 *
 * TODO: Senthil Kumaran - Implement a complete Linked List
 * http://www2.hawaii.edu/~esb/2008fall.ics211/LinkedList.java.html
 * http://www.csie.ntu.edu.tw/~cyy/courses/oop/13summer/chap15java5th.pdf
 *
 */

import java.util.Iterator;

interface MyList<T> extends Iterable<T> {
    int getCount(); // Number of elements
    T get(int i);   // Get element at index i
    void set(int i, T item);    // Set element at index i
    void add(T item);   // Add element at end
    void insert(int i, T item); // Insert element at index i
    void removeAt(int i);   // Remove element at index i
    <U> MyList<U> map(Mapper<T, U> f); // Map f over all elements
}

interface Mapper<A, R> {
    R call(A x);
}

class MyLinkedList<T> implements MyList<T> {

    protected int size; // Number of elements in the
    protected Node<T> first, last;

    protected static class Node<U> {
        public Node<U> prev, next;
        public U item;

        Node(U item) {
            this.item = item;
        }

    }

    public MyLinkedList() {
        first = last = null;
        size = 0;
    }

    public MyLinkedList(T... arr) { }

    @Override
    public int getCount() {
        return 0;
    }

    @Override
    public T get(int i) {
        return null;
    }

    @Override
    public void set(int i, T item) {

    }

    public void add(T item) {
        insert(size, item);
    }

    public void insert(int i, T item) {



    }

    @Override
    public void removeAt(int i) {

    }

    /** Map f over all elements */
    @Override
    public <U> MyList<U> map(Mapper<T, U> f) {
        MyLinkedList<U> res = new MyLinkedList<U>();
        for(T x: this)
            res.add(f.call(x));
        return res;
    }

    public boolean equals(Object that) {
        return equals((MyList<T>)that);
    }

    public boolean equals(MyList<T> that) {
        return this == that;
    }

    @Override
    public Iterator<T> iterator() {
        return null;
    }
}

class GenericMethodGenericClass {
    public static void main(String[] args) {
        MyLinkedList.Node<String> item = new MyLinkedList.Node<String>("Senthil");
        MyLinkedList<MyLinkedList.Node> linkedList = new MyLinkedList<MyLinkedList.Node>();

    }
}
