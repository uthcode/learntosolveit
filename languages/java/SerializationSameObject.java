import java.io.*;

/**
 * Example 148 - Serialization to the Same ObjectOutputStream Preserves Sharing
 */

class SC implements Serializable {
    int ci;
}

class SO implements Serializable {
    int i; SC c;
    SO(int i, SC c) {
        this.i = i;
        this.c = c;
    }

    void cprint() {
        System.out.print("i" + i + "c" + c.ci + " ");
    }

}


class SerializationSameObject {

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        File f = new File("objects.dat");
        // Create the objects and write them to file
        SC c = new SC();
        SO o1 = new SO(1, c);
        SO o2 = new SO(2, c);
        o1.c.ci = 3;
        o2.c.ci = 4;
        o1.cprint();
        o2.cprint();

        OutputStream os = new FileOutputStream(f);
        ObjectOutputStream oos = new ObjectOutputStream(os);
        oos.writeObject(o1);
        oos.writeObject(o2);
        oos.close();

        // Read the objects from file.
        InputStream is = new FileInputStream(f);
        ObjectInputStream ois = new ObjectInputStream(is);
        SO o1i = (SO)(ois.readObject());
        SO o2i = (SO) (ois.readObject());

        o1i.cprint();
        o2i.cprint();
        o1i.c.ci = 5;
        o2i.c.ci = 6;
        o1i.cprint();
        o2i.cprint();

    }
}
