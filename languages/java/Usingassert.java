import java.util.LinkedList;

/**
 * Example 84 - Using assert to Specify and Check Invariants
 * TODO: Senthil Kumaran - Substitute with a complete working example.
 */
class Usingassert {
    static class WordList {
        private LinkedList<String> strings = new LinkedList<String>();
        private int length = -1;    // Invariant: equal word lengths plus inter-word spaces
        private int length() { return length; }

        public void addLast(String s) {
            strings.addLast(s);
            length += 1 + s.length();
            assert length == computeLength() + strings.size() - 1;
        }

        public String removeFirst() {
            String res = strings.removeFirst();
            length -= 1 + res.length();
            assert length == computeLength() + strings.size() - 1;
            return res;
        }

        private int computeLength() {
            return 0;
        }
    }
}
