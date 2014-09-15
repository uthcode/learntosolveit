/**
 * Example 165 - Example of Features in Java 5
 */

import static java.lang.System.*;
import static java.lang.Math.*;
import java.util.*;

class JavaFiveFeatures {

    public static void main(String[] args) {
        double giga = exp(30.0 * log(2.0)); // 2^30
        out.println("2^30 = " + giga);
        out.format("2^30 = %12.2f\n", giga);

        String res = concat("Cop", "en", "hagen");
        out.format("result = %s\n", res);

        Direction dir = Direction.North;
        dir = dir.turnLeft();
        out.println(dir);

        List<Double> list = new ArrayList<Double>();
        list.add(7.2);
        list.add(22.4);
        list.add(-9.2);

        for (double d: list)
            out.format("%+7.1f\n", d);

    }

    static String concat(String... ss) { // Variable-arity method
        StringBuilder sb = new StringBuilder();
        for(String s: ss)
            sb.append(s);
        return sb.toString();
    }

    enum Direction {
        East, North, West, South;   //Enum Values

        public Direction turnLeft() {
            switch (this) {
                case East: return Direction.North;
                case North: return Direction.West;
                case West: return Direction.South;
                case South: return Direction.East;
                default: throw new RuntimeException("Impossible");
            }
        }

    }

}
