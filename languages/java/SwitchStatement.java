/**
 * Example 65 - A switch statement
 */
public class SwitchStatement {

    static String findCountry(int prefix) {
        switch(prefix) {
            case 1:     return "North America";
            case 44:    return "Great Britain";
            case 45:    return "Denmark";
            case 299:   return "Greenland";
            case 46:   return "Sweden";
            case 7:    return "Russia";
            case 972:     return "Israel";
            default:   return "Unknown";
        }
    }

    public static void main(String[] args) {

        System.out.println(findCountry(1));
        System.out.println(findCountry(46));
        System.out.println(findCountry(42));
    }
}
