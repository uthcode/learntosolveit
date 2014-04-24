public class Describe {
    static void describe(Class<?> clazz, String pad, String leadin) {
    if (clazz == null) return;
    String type =
        clazz.isInterface() ? "interface" :
        clazz.isArray() ? "array" :
        clazz.isPrimitive() ? "primitive" :
        clazz.isEnum() ? "enum" :
        "class";
    System.out.printf("%s%s%s %s ( %s )%n",
        pad, leadin, type, clazz.getSimpleName(), clazz.getName());
    for (Class<?> interfaze : clazz.getInterfaces()) {
        describe(interfaze, pad + "   ", "implements ");
    }
    describe(clazz.getComponentType(), pad + "   ", "elements are ");
    describe(clazz.getSuperclass(), pad + "   ", "extends ");
}
static void describe(Class<?> clazz) {
    describe(clazz, "", "");
    System.out.println();
}
public static void main(String[] args) {
    describe(boolean[][].class);
    describe(java.math.RoundingMode.class);
    describe(java.util.ArrayList.class);
    describe(void.class);
}
}
