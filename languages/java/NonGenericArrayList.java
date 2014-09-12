import java.util.ArrayList;

/**
 * Example 104 - Using Non Generic ArrayList: Run-Time Type Checks and Wrapping of Values
 */

class Person {
    String name;
    Person(String name) {
        this.name = name;
    }
}
class NonGenericArrayList {

    public static void main(String[] args) {
        ArrayList cool = new ArrayList();
        cool.add(new Person("Gopal"));
        cool.add(new Person("chotu"));

        // Wrong, but no compiletime check

        cool.add(new Exception("bholu"));
        cool.add(new Person("bheem"));

        // Compiles OK, but fails at runtime

        Person p = (Person) (cool.get(2));

    }
}
