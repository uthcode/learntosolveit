/**
 * Example 83 - Using assert to Specify and Check the Result of an Algorithm
 */
public class UsingassertsCheckAlgorithm {

    static int sqrt(int x) {
        if ( x < 0)
            throw new IllegalArgumentException("sqrt: negative argument");
        int temp, y = 0, b = 0x8000, bshft = 15, v = x;
        do {
            if (v >= (temp = (y << 1) + b << bshft--)) {
                y += b;
                v -= temp;
            }
        } while ((b >>= 1) > 0);

        assert (long) y * y <= x && (long)(y + 1) * (y + 1) > x;
        return y;
    }

    public static void main(String[] args) {
        System.out.println(sqrt(16));

    }
}
