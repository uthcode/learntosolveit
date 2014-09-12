import java.util.ArrayList;

/**
 * Example 105 - Using Generic ArrayList: Compile-Time Type Checks
 */

class Person {
    String name;
    Person(String name) {
        this.name = name;
    }
}

public class GenericArrayLists {

    public static void main(String[] args) {
        ArrayList<Person> cool = new ArrayList<Person>();
        cool.add(new Person("Gopal"));
        cool.add(new Person("Chotu"));
        cool.add(new Exception("Bholu")); // Wrong detected at Compile-time
        cool.add(new Person("Bheem"));
        Person p = cool.get(2);
    }
}
