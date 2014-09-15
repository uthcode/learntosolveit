import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Example 156 - Socket Communication Between Processes
 *
 * For Server
 * java SocketCommunication
 *
 * For Client
 * java SocketCommunication localhost
 */
class SocketCommunication {
    final static int PORT = 2357;

    public static void main(String[] args) throws IOException {
        boolean server = args.length == 1 && args[0].equals("server");
        boolean client = args.length == 2 && args[0].equals("client");

        if (server) {
            ServerSocket serversock = new ServerSocket(PORT);
            for (;;) {
                Socket sock = serversock.accept();
                DataInputStream dis = new DataInputStream(sock.getInputStream());
                DataOutputStream dos = new DataOutputStream(sock.getOutputStream());
                int query = dis.readInt();
                dos.writeBoolean(isprime(query));
                dis.close();
                dos.close();
            }
        } else if (client) {
            for (int i = 1; i < 1000; i++) {
                Socket sock = new Socket(args[1], PORT);
                DataOutputStream dos = new DataOutputStream(sock.getOutputStream());
                DataInputStream dis = new DataInputStream(sock.getInputStream());
                dos.writeInt(i);
                if (dis.readBoolean())
                    System.out.print(i + " ");
                dos.close();
                dis.close();
            }
        } else {
            System.out.println("Neither server nor client.");
        }
    }

    static boolean isprime(int p) {
        for (int i = 2; i <= Math.sqrt(p); i++)
            if ((p % i) == 0)
                return false;
        return true;
    }
}
