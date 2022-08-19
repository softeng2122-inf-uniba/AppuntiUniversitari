import java.net.*;
import java.io.*;

public class SommaProdottoClient {
private Socket s;
private ObjectInputStream in;
private ObjectOutputStream out;
public SommaProdottoClient(InetAddress i, int PORT) throws IOException {
        s= new Socket(i, PORT);
}
public SommaProdottoClient(String i, int PORT) throws IOException {
        s= new Socket(InetAddress.getByName(i), PORT);
}
public void run(){

        try{
                in= new ObjectInputStream(s.getInputStream());
                out= new ObjectOutputStream(s.getOutputStream());

                System.out.println("Scegliere 1 per la somma");
                System.out.println("Scegliere 2 per il prodotto");

                BufferedReader keyIn = new BufferedReader(new InputStreamReader(System.in));

                out.writeObject(keyIn.readLine());

                if (in.readObject().equals("OK")) {
                        System.out.println("Scegliere due interi");
                        out.writeObject(Integer.parseInt(keyIn.readLine()));
                        out.writeObject(Integer.parseInt(keyIn.readLine()));
                        System.out.println(in.readObject());
                }else{
                        System.out.println("A SORT");
                }

                keyIn.close();

        }catch(IOException e) {
                System.err.println("can't get streams");
        }catch(ClassNotFoundException e) {
                System.err.println("class not found");
        }finally{
                try{
                        s.close();
                }catch(IOException e) {
                        System.err.println("socket not closed");
                }
        }

}

public static void main (String [] args){
        try{
                SommaProdottoClient s = new SommaProdottoClient("127.0.0.1", 8080);
                s.run();
        }catch(IOException e) {
                System.err.println("something is going wrong");
        }
}

}
