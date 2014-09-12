/**
 * Example 118 - Wildcard Types
 */

class Vehicle {}

class Car extends Vehicle {}

class Sedan extends Car {}

class Shop<T> {
    private T thing;

    Shop(T thing) {
        this.thing = thing;
    }

    public T buyFrom() { return thing;}
    public void sellTo(T thing) { this.thing = thing;}

}

class WildcardTypes {

    public static void main(String[] args) {
        Shop<Sedan> sedanShop = new Shop<Sedan>(new Sedan());
        sedanShop.buyFrom();
    }

}
