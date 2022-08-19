import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;

public class MultiServer {
public static final int PORT = 8080;
public static void main (String [] args)throws IOException {
        ServerSocket s = new ServerSocket(PORT);
        try{
                while(true) {
                        Socket socket = s.accept();
                        try{
                                new Server(socket);

                        }catch(IOException e) {
                                socket.close();
                        }
                }
        }finally{
                s.close();
        }
}
}
