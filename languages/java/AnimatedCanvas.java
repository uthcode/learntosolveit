import javax.swing.*;
import java.awt.*;

/**
 * Example 95 - Graphic Animation Using the Runnable Interface
 */
class AnimatedCanvas extends Canvas implements Runnable{

    AnimatedCanvas() {
        Thread u = new Thread(this);
        u.start();
    }

    @Override
    public void run() {
        for(;;){
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {}
            repaint();
        }
    }

    public void paint(Graphics g) {
        g.drawString("Hello World", 200, 200);
    }

    public static void main(String[] args) {
        AnimatedCanvas animatedCanvas = new AnimatedCanvas();
        JFrame jp = new JFrame();
        jp.getContentPane().add(animatedCanvas, BorderLayout.CENTER);
        jp.setSize(new Dimension(500,500));
        jp.setVisible(true);
    }
}
