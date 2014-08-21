/**
 * Example 44 - Inner Object
 */
class InnerObjects {
    static int sf;
    int nf;

    static class SMC {
        static int ssf = sf + InnerObjects.sf;
        int snf = sf + InnerObjects.sf;
    }

    class NMC {
        int nnf1 = sf + nf;
        int nnf2 = InnerObjects.sf + InnerObjects.this.nf;
    }

    void nm() {
        class NLC {
            int m(int p) {
                return sf + nf + p;
            }
        }
    }

    public static void main(String[] args) {
        InnerObjects oo = new InnerObjects();
        InnerObjects.NMC io1 = oo.new NMC();
        InnerObjects.NMC io2 = oo.new NMC();
        InnerObjects.SMC sio = new InnerObjects.SMC();
    }
}
