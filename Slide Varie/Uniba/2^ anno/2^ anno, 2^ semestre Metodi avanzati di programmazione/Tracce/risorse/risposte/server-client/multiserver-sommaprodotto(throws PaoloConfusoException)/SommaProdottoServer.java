import java.net.*;
import java.io.*;

public class SommaProdottoServer {
private static final int PORT = 8080;
private ServerSocket s;

public SommaProdottoServer() throws IOException {
        s=new ServerSocket(PORT);
}

public void run(){
        try{
                while(true) {
                        Socket socket = s.accept();
                        try{
                                new SommaProdottoServerOne(socket);
                        }catch(IOException e) {
                                socket.close();
                                e.printStackTrace();
                        }
                }
        }catch(IOException e) {
                e.printStackTrace();
        }finally{
                try{
                        s.close();
                }catch(IOException e) {
                        e.printStackTrace();
                }
        }
}

public static void main(String [] args){
        try{
                SommaProdottoServer server = new SommaProdottoServer();
                server.run();
        }catch(IOException e) {
                System.err.println("server is loff");
        }

}

}
