import java.util.Set;
import java.util.HashSet;

public class Cella{
  private int riga;
  private int colonna;

  public Cella(int riga,int colonna){
    this.riga=riga;
    this.colonna=colonna;
  }

  public boolean equals(Object c){
    return riga==((Cella)c).riga&&colonna==((Cella)c).colonna;
  }

  public int hashCode(){
    return new Integer(riga).hashCode()/(new Integer(colonna).hashCode()+1);
  }

  public String toString(){
    return "Riga: "+riga+" Colonna: "+colonna;
  }
}
