/**
 * Example 27 - Abstract Classes, Subclasses, and Overriding
 */
class AbstractClass {

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
}
