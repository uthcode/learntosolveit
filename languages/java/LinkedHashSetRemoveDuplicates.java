import java.util.LinkedHashSet;

/**
 * Example 123 - Using LinkedHashSet to Remove Duplicates While Maintaining Item Order
 */
class LinkedHashSetRemoveDuplicates {

    public static String[] unique(String[] filenames) {
        LinkedHashSet<String> uniqueFiles = new LinkedHashSet<String>();
        for(String filename: filenames)
            uniqueFiles.add(filename);
        return uniqueFiles.toArray(new String[0]);
    }

    public static void main(String[] args) {
        String[] dupNames = {"alice", "bob", "trudy", "bob", "alice"};
        for(String name: unique(dupNames))
            System.out.println(name);
    }
}
