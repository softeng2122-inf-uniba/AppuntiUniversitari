import java.io.Serializable;

class Libro implements Serializable, Cloneable {
private static int id=0;
private int codice=id++;
private String titolo;
Libro (String titolo){
        this.titolo=titolo;

}
int getCodice(){
        return codice;
}

public Object clone(){
        Object o=null;

        try{
                o=super.clone();
                ((Libro)o).titolo= new String(titolo);

        }catch(CloneNotSupportedException e) {
                System.err.println("Clone not supported");
        }

        return o;

}

// @Override
// public String toString(){
//         return "(" + titolo + " " + codice+ ")";
// }
}
