import java.io.File;
import java.io.IOException;

/**
 * Example 154 - Reading and Printing a Directory Hierarchy
 */
class ReadingPrintingDirHierarchy {

    static void showDir(int indent, File file) throws IOException {
        for (int i = 0; i < indent; i++) {
            System.out.print('-');
        }
        System.out.println(file.getName());
        if (file.isDirectory()) {
            File[] files = file.listFiles();
            for (int i = 0; i < files.length; i++) {
                showDir(indent+4, files[i]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        File f = new File("/Users/skumaran/github/uthcode/uthcode/languages/java");
        showDir(2, f);
    }

}
