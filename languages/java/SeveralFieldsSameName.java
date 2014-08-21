/**
 * Example 30 - Several Fields with Same Name
 */

class B{

    int vf;
    static int sf;
    B(int i) {
        vf = i;
        sf = i+1;
    }
}
class C extends  B {
    int vf;
    static int sf;

    C(int i) {
        super(i+20);
        vf = i;
        sf = i + 2;
    }
}

class D extends C {
    int vf;

    D(int i) {
        super(i+40);
        vf = i;
        sf = i+ 4;
    }
}
