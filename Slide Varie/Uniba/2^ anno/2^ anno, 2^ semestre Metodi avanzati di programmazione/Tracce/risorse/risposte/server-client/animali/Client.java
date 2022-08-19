import java.net.Socket;
import java.net.InetAddress;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Client {
public static void main (String[] args) throws IOException {
        InetAddress addr = InetAddress.getByName("127.0.0.1");
        Socket socket = new Socket (addr, 8080);

        try{
                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter out = new PrintWriter (new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())),true);
                out.println("pig");
                String str=in.readLine();
                System.out.println(str);
                out.println("cow");
                str=in.readLine();
                System.out.println(str);
                out.println("end");
        } finally {
                System.out.println("closing...");
                socket.close();
        }
}
}
