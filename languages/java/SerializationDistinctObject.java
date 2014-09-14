import java.io.*;

/**
 * Example 149 - Serialization to Distinct ObjectOutputStreams Does Not Preserve Sharing
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

class SerializationDistinctObject {

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

        InputStream is = new FileInputStream(f);

        ObjectOutputStream oos1 =  new ObjectOutputStream(os);
        oos1.writeObject(o1);
        oos1.flush();

        ObjectOutputStream oos2 = new ObjectOutputStream(os);
        oos2.writeObject(o2);
        oos2.close();

        // Read the objects from file, non-shared c.
        ObjectInputStream ois1 = new ObjectInputStream(is);
        SO o1i = (SO) (ois1.readObject());
        ObjectInputStream ois2 = new ObjectInputStream(is);
        SO o2i = (SO) (ois2.readObject());
        o1i.cprint(); // Prints i1c4, i2c4
        o2i.cprint();
        o1i.c.ci = 5; // Update two different cs
        o2i.c.ci = 6;
        o1i.cprint();
        o2i.cprint();

    }
}
