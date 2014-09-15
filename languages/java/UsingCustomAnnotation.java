import java.lang.annotation.*;
import static java.lang.annotation.ElementType.*; // @Target arguments
import static java.lang.annotation.RetentionPolicy.*; // @Retention arguments
import java.lang.reflect.*;


/**
 * Example 164 - Declaring and Using a Custom Annotation Type
 */

enum Day {
    Mon, Tue, Wed, Thu, Fri, Sat, Sun;
    private final static Day[] day = values();
    public static Day toDay(int n) { return day[n];}
    public int toInt() { return ordinal(); }
}

enum Month {
    Jan(31), Feb(28), Mar(31), Apr(30), May(31), Jun(30),
    Jul(31), Aug(31), Sep(30), Oct(30), Nov(30), Dec(31);

    private final int days;
    private Month(int days) {
        this.days = days;
    }

    private final static Month[] month = values();

    public int days(int year) {
        // Simplistic - Does not take care of Leap year
        return days;
    }

    public static Month toMonth(int n) {
        return month[n-1];
    }

    public int toInt() {
        return ordinal()+1;
    }

    public Month succ() {
        return toMonth(toInt() + 1);
    }
}


@Target({TYPE, METHOD})
@Retention(RUNTIME)
@interface Author {
    public int oneHour = 60 * 60 * 1000;
    public String name();
    public Month month();
    public String[] diet() default {"iddiappam", "chappati"};
    public int weeklyWork() default 56 * oneHour;
}

@Retention(RUNTIME)
@interface Authors {
    public Author[] value();
}

class UsingCustomAnnotation {

    @Author(name="Senthil", month=Month.Jan, diet= {"iddiappam"})
    public void myMethod1() {}

    @Author(name="Shalini", month=Month.Mar, diet= {"chappati"})
    public void myMethod2() {}

    public static void main(String[] args) {
        Class ty = UsingCustomAnnotation.class;
        for (Method mif: ty.getMethods()) {
            System.out.println("\nGetting the annotations of " + mif.getName());

            // This finds only annotations with RUNTIME retention

            Annotation[] annos = mif.getDeclaredAnnotations();
            System.out.println("The annotations are: ");
            for(Annotation anno: annos)
                System.out.println(anno);
        }
    }



}
