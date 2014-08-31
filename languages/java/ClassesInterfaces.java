/**
 * Example 86 - Classes Implementing Interfaces
 */

import javax.swing.*;
import java.applet.Applet;
import java.awt.*;

interface Colored { Color getColor();}
interface Drawable { void draw(Graphics g);}
interface ColoredDrawable extends Colored, Drawable {}

class ColoredPoint extends Point implements Colored {
    Color c;
    ColoredPoint(int x, int y, Color c) {
        super(x, y);
        this.c = c;
    }

    @Override
    public Color getColor() {
        return c;
    }
}

class ColoredDrawablePoint extends ColoredPoint implements ColoredDrawable {

    ColoredDrawablePoint(int x, int y, Color c) {
        super(x, y, c);
    }

    @Override
    public void draw(Graphics g) {
        g.fillRect(x, y, 1, 1);
    }
}

class ColoredRectangle implements ColoredDrawable {
    int x1, x2, y1, y2;
    Color c;

    ColoredRectangle(int x1, int y1, int x2, int y2, Color c) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
        this.c = c;
    }

    public Color getColor() {
        return c;
    }

    public void draw(Graphics g) {
        g.drawRect(x1, y1, x2-x1, y2-y1);
    }
}

class ClassesInterfaces extends Applet{

    public static void main(String[] args) {
        JFrame jp1 = new JFrame();
        ColoredRectangle rect = new ColoredRectangle(10, 10, 30, 30, Color.BLACK);
        // TODO: Senthil Kumaran - Use Graphics object g.
        ClassesInterfaces c  = new ClassesInterfaces();
        jp1.getContentPane().add(c, BorderLayout.CENTER);
        jp1.setVisible(true);

    }

}
