import java.util.Comparator;

public class CompareNome implements Comparator<Prodotto>{

  public int compare(Prodotto p1, Prodotto p2){
    return p1.getNome().compareTo(p2.getNome());
  }
}
