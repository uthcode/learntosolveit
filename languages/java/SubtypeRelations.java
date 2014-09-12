/**
 * Example 114 - Subtype Relations between Generic Classes and Interfaces
 */

interface Movable {
    void move(int dx, int dy);
}

class LabelPoint<L> implements Movable {
    protected int x, y;
    private L lab;

    public LabelPoint(int x, int y, L lab) {
        this.x = x;
        this.y = y;
        this.lab = lab;
    }

    @Override
    public void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
}

class ColorLabelPoint<L, C> extends LabelPoint<L> {
    private C c;
    public ColorLabelPoint(int x, int y, L lab, C c) {
        super(x, y, lab);
        this.c = c;
    }
}
class SubtypeRelations {

    public static void main(String[] args) {
        ColorLabelPoint<String, Integer> colorLabelPoint = new ColorLabelPoint<String, Integer>(10, 10, "Uthcode",42);
        colorLabelPoint.move(10, 10);
        System.out.println(colorLabelPoint.x + " " + colorLabelPoint.y);

    }

}
