import java.io.File;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * Example 124 - Using a TreeSet to Show a Range of File Names in Alphabetic Order
 */

class TreeSetRange {

    public static void main(String[] args) {
        SortedSet<String> filenames = new TreeSet<String>();
        File cwd = new File(".");
        for(File f: cwd.listFiles())
            filenames.add(f.getName());
        for(String filename: filenames.subSet("P", "T"))
            System.out.println(filename);
    }

}
