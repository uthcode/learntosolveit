/**
 * Example 100 - Efficiently Concatenating All Command Line Arguments
 */
class ConcatCliArgs {
    public static void main(String[] args) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < args.length; i++)
            res.append(args[i]);
        System.out.println(res.toString());
    }
}
