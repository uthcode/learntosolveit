/**
 * Example 32 - Private Member Accessibility
 */
class PrivateMemberAccess {

    private static int x;

    static class SI {
        private static int y = x;
    }

    static void m() {
        int z = SI.y;
    }

    public static void main(String[] args) {
        m();
    }
}
