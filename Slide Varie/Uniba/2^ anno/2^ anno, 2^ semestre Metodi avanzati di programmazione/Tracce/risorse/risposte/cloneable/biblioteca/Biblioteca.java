import java.util.HashMap;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Serializable;
import java.util.Map;

class Biblioteca implements Serializable, Cloneable {
private transient String password;
private HashMap<Integer,Libro> a = new HashMap< >();
Biblioteca(String psw){
        password=psw;
}
void registra(Libro l){
        a.put(l.getCodice(),l);
}

public void salva(String fname)throws FileNotFoundException, IOException {
        FileOutputStream outFile = new FileOutputStream(fname);
        ObjectOutputStream outStream = new ObjectOutputStream(outFile);
        outStream.writeObject(this);
}

public Biblioteca carica (String fname)throws FileNotFoundException, IOException, ClassNotFoundException {
        FileInputStream inFile = new FileInputStream (fname);
        ObjectInputStream inStream = new ObjectInputStream (inFile);
        return (Biblioteca)inStream.readObject();
}

public static void main (String[] args)throws FileNotFoundException, IOException, ClassNotFoundException {
        Biblioteca finia = new Biblioteca ("pollofritto");
        //finia.carica("pollo.dat");
        finia.registra(new Libro("La commedia di Pina"));
        finia.registra(new Libro("Il nome della cosa"));
        finia.registra(new Libro("Cappuccetto Grosso"));
        finia.registra(new Libro("Il Codice della PostePay"));
        Biblioteca bibliotecadiSEMERARO = (Biblioteca)finia.clone();
        System.out.println(finia);
        System.out.println(bibliotecadiSEMERARO);
}

@Override
public String toString(){
        return a.toString() + password;
}

public Object clone(){
        Object o=null;

        try{
                o=super.clone();
                ((Biblioteca)o).a=(HashMap<Integer,Libro>)a.clone();
                for (Map.Entry<Integer,Libro> m : a.entrySet()) {
                        ((Biblioteca)o).a.put(m.getKey().intValue(), (Libro)(m.getValue().clone()));
                }
                ((Biblioteca)o).password= new String(password);

        }catch(CloneNotSupportedException e) {
                System.err.println("clone not supported");
        }

        return o;
}

}
