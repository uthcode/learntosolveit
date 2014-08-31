import javax.swing.*;
import java.applet.Applet;
import java.awt.*;

/**
 * Example 87 - Using Interfaces as Types
 * TODO: Senthil Kumaran - Correct the Graphics Part.
 */
class UsingInterfacesAsTypes extends Applet  {

    static void printcolors(Colored[] cs) {
        for (int i = 0; i < cs.length; i++) {
            System.out.println(cs[i].getColor().toString());
        }
    }

    static void draw(Graphics g, ColoredDrawable[] cs) {
        for (int i = 0; i < cs.length; i++) {
            g.setColor(cs[i].getColor());
            cs[i].draw(g);
        }
    }

    public static void main(String[] args) {
        JFrame jp1 = new JFrame();
        // TODO: Senthil Kumaran - Use Graphics object g.
        UsingInterfacesAsTypes t = new UsingInterfacesAsTypes();
        jp1.getContentPane().add(t, BorderLayout.CENTER);
        jp1.setVisible(true);
    }
}
