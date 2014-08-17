/**
 * Example 7 Scope of Fields, Parameters and Variables
 *
 * TODO: Senthil Kumaran - Make it a complete working example
 */
class Scope {

    void m1(int x) {
        System.out.printf("%d #1 in scope", x);
    }

    void m2(int v2) {
        System.out.printf("%d #5 in scope", v2);
    }

    void m3(int v3) {
        int x;
    }

    void m4(int v4) {
        {
            int x;
        }
        {
            int x;
        }
    }

    int x;

}
