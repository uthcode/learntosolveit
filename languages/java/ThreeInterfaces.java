/**
 * Example 85 - Three Interface Declarations
 */

import java.awt.*;

interface Colored {
    Color getColor();
}

interface Drawable {
    void draw(Graphics g);
}

interface ColoredDrawable extends Colored, Drawable {}

class ThreeInterfaces {
    public static void main(String[] args) {
        System.out.println("Example for Interfaces");
    }
}
