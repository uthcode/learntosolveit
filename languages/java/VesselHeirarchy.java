/**
 * Example 28 - Using the Vessel Hierarchy from Abstract class example
 */
class VesselHeirarchy {

    abstract class Vessel {
        double contents;
        abstract double capacity();
        void fill(double amount) {
            contents = Math.min(contents + amount, capacity());
        }
    }

    class Tank extends Vessel {

        double length, width, height;

        Tank(double length, double width, double height) {
            this.length = length;
            this.width = width;
            this.height = height;
        }

        double capacity() {
            return length * width * height;
        }

        public String toString() {
            return "tank (" + length + ", " + width + ", " + height + ")";
        }
    }

    class Cube extends Tank {

        Cube(double side) {
            super(side, side, side);
        }

        public String toString() {
            return "cube (" + length + ")";
        }
    }

    class Barrel extends Vessel {
        double radius, height;

        Barrel(double radius, double height) {
            this.radius = radius;
            this.height = height;
        }

        double capacity() {
            return height * Math.PI * radius * radius;
        }

        public String toString() {
            return "barrel (" + radius + ", " + height + ")";
        }
    }

    public void test() {
        Vessel v1 = new Barrel(3, 10);
        Vessel v2 = new Tank(10, 20, 12);
        Vessel v3 = new Cube(4);

        Vessel[] vs = {v1, v2, v3};

        v1.fill(90);
        v1.fill(10);
        v2.fill(100);
        v2.fill(80);

        double sum = 0;

        for (int i = 0; i < vs.length; i++) {
            sum += vs[i].capacity();
        }

        System.out.println("Total capacity is " + sum);

        for (int i = 0; i < vs.length; i++) {
            System.out.println("vessel number " + i + ": " + vs[i]);
        }
    }

    public static void main(String[] args) {
        VesselHeirarchy o = new VesselHeirarchy();
        o.test();
    }
}
