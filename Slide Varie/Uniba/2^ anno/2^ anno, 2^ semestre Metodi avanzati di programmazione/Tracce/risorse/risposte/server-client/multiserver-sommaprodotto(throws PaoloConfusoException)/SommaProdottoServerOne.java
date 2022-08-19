import java.net.*;
import java.io.*;

class SommaProdottoServerOne implements Runnable {
private Thread th;
private ObjectInputStream in;
private ObjectOutputStream out;
private Socket s;

SommaProdottoServerOne(Socket s)throws IOException {
        this.s=s;
        out=new ObjectOutputStream(s.getOutputStream());
        in=new ObjectInputStream(s.getInputStream());
        th=new Thread(this);
        th.start();
}

public void run(){
        try{
                String op = (String)in.readObject();

                switch(op) {
                case "1":
                        out.writeObject("OK");
                        int i = (Integer)in.readObject();
                        int j = (Integer)in.readObject();
                        out.writeObject(i+j);
                        break;
                case "2":
                        out.writeObject("OK");
                        int x = (Integer)in.readObject();
                        int y = (Integer)in.readObject();
                        out.writeObject(x*y);
                        break;
                default:
                        out.writeObject("ERROR");
                }

        }catch(IOException e) {
                e.printStackTrace();
        }catch(ClassNotFoundException e) {
                e.printStackTrace();
        }finally{
                try{
                        s.close();
                }catch(IOException e) {
                        System.err.println("socket not closed");
                }
        }
}


}
