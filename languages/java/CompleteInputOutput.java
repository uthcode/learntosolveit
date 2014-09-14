import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Example 140 - A Complete Input-Output Example
 */
class CompleteInputOutput {

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int count = 0;
        String s = r.readLine();
        while (s != null & !s.equals("")) {
            count++;
            s = r.readLine();
        }
        System.out.println("You entered " + count + " non empty lines");
    }

}
