import java.util.Comparator;

public class CompareCodiceProdotto implements Comparator<Prodotto>{

  public int compare(Prodotto p1, Prodotto p2){
    return ((Integer)p1.getCodiceProdotto()).compareTo(p2.getCodiceProdotto());
  }
}
