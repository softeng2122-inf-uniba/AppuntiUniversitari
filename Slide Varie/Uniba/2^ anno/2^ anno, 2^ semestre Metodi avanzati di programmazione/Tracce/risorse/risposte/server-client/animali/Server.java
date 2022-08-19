import java.net.Socket;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Server extends Thread {
private Socket socket;
private BufferedReader in;
private PrintWriter out;

public Server(Socket s)throws IOException {
        socket=s;
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
        start();
}

@Override
public void run(){
        try{
                boolean running=true;
                while(running) {
                        String str=in.readLine();
                        switch(str) {
                        case "pig":
                                out.println("oink");
                                break;
                        case "cow":
                                out.println("moo");
                                break;
                        case "end":
                                running=false;
                                break;
                        default:
                                out.println("A SCATTAE");
                        }
                }
                System.out.println("closing...");
        }catch(IOException e) {
                System.err.println("IO Exception");
        }finally{
                try{
                        socket.close();
                }catch(IOException i) {
                        System.err.println("Socket not closed");
                }
        }
}
}
