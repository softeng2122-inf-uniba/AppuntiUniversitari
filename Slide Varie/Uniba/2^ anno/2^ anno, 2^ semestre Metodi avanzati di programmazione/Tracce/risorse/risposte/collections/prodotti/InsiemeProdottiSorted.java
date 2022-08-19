import java.util.TreeSet;
import java.util.Comparator;

public class InsiemeProdottiSorted{
    TreeSet<Prodotto> insieme;
    public InsiemeProdottiSorted(Comparator<Prodotto> c){
      insieme=new TreeSet<Prodotto>(c);
    }

    public void addProdotto(Prodotto p){
      insieme.add(p);
    }

    @Override
    public String toString(){
      return insieme.toString();
    }

    public static void main (String [] args){
      InsiemeProdottiSorted i = new InsiemeProdottiSorted(new CompareNome());
      i.addProdotto(new Prodotto(0, "grisulli", 10));
      i.addProdotto(new Prodotto(0, "grisulli", 11));
      i.addProdotto(new Prodotto(1, "colavito", 20));
      i.addProdotto(new Prodotto(1, "loconte", 21));
      System.out.println(i);

      // InsiemeProdottiSorted ii = new InsiemeProdottiSorted(new CompareCodiceProdotto());
      // ii.addProdotto(new Prodotto(0, "grisulli", 10));
      // ii.addProdotto(new Prodotto(0, "leone", 11));
      // ii.addProdotto(new Prodotto(1, "colavito", 20));
      // ii.addProdotto(new Prodotto(0, "loconte", 21));
      // System.out.println(ii);
    }

}
