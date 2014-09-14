import java.util.Random;

/**
 * Example 14 - Aligning Numbers in Columns using out.format
 */
class AlignNumbers {
    public static void main(String[] args) {
        Random rnd = new Random();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j <5; j++)
                System.out.format("%4d", rnd.nextInt(1000));
        System.out.format("%n");
    }
}
