/**
 * Example 26 - Top-Level, Member and Local classes
 */
public class TopLevelClass {

    static class StaticMemberClass {

    }

    class NonStaticMemberInnerClass {

    }

    void nonstaticmethod() {
        Object o2 = new NonStaticMemberInnerClass();
        // Local (inner) class in method
        // Can be used only within this method
        class NonStaticLocalClass {

        }
        Object o3 = new NonStaticLocalClass();
    }

    static void staticmethod() {
        // Local class in method
        class StaticLocalClass {

        }
    }

    public void testnonstatic() {
        Object o4 = new TopLevelClass();
        Object o5 = new NonStaticMemberInnerClass();

        nonstaticmethod();
        // TODO: Senthil Kumaran - Why is this not accessible?
        //o4.nonstaticmethod();
    }


    public static void teststatic() {

        Object o1 = new StaticMemberClass();
        TopLevelClass.staticmethod();

    }

}
