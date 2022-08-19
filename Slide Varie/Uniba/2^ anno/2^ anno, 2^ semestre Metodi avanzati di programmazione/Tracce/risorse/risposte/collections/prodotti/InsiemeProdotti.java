import java.util.HashSet;

public class InsiemeProdotti{
  HashSet<Prodotto> insieme;

  public InsiemeProdotti(){
    insieme=new HashSet<Prodotto>();
  }

  public void addProdotto(Prodotto p){
    insieme.add(p);
  }

  @Override
  public String toString(){
    return insieme.toString();
  }

  public static void main (String [] args){
    InsiemeProdotti i = new InsiemeProdotti();
    i.addProdotto(new Prodotto(0, "grisulli", 10));
    i.addProdotto(new Prodotto(0, "leone", 11));
    i.addProdotto(new Prodotto(1, "colavito", 20));
    i.addProdotto(new Prodotto(1, "loconte", 21));
    System.out.println(i);
  }

}
