/**
 * Example 39 - Member classes and Local Classes
 */
public class MemberClasses {

    static int sf;
    int nf;

    static class StaticMemberClass {
        static int ssf = sf + MemberClasses.sf;
        int snf = sf + MemberClasses.sf;
    }

    class NonStaticMemberClass {
        int nnf1 = sf + nf;
        int nnf2 = MemberClasses.sf + MemberClasses.this.nf;
    }

    void nonstaticmethod() {
        // Non Static method in Top Level Class
        // The local innser class in the method can use non-static
        // Top Level members
        class LocalClass {
            int m(int p) {
                return sf+nf+p;
            }
        }
    }

    public static void main(String[] args) {
        MemberClasses o = new MemberClasses();
        o.nonstaticmethod();
        StaticMemberClass s = new MemberClasses.StaticMemberClass();

        // TODO: Senthil Kumaran
        // How to access NonStaticMemberClass and LocalClass

    }
}
