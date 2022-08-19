import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.io.Serializable;

public class MappaNavale implements Serializable{

  private Map<Cella,Set<Nave>> griglia;

  public MappaNavale(){
    griglia=new HashMap<Cella,Set<Nave>>();
  }

  public void assegnaNaveACella(Cella c,Nave n){
      if(griglia.containsKey(c)){
        griglia.get(c).add(n);
      }
      else{
        Set<Nave> navi=new HashSet<Nave>();
        navi.add(n);
        griglia.put(c,navi);
      }
  }

  public int contaNavi(Cella c){
    if(griglia.containsKey(c)){
      return griglia.get(c).size();
    }
    return 0;
  }

  public String toString(){
    return griglia.toString();
  }

  public static void main(String[] args){
      MappaNavale mappa=new MappaNavale();
      Cella c1=new Cella(0,0);
      Cella c2=new Cella(2,3);
      mappa.assegnaNaveACella(c1,new Nave("porco"));
      mappa.assegnaNaveACella(c1,new Nave("porco"));
      mappa.assegnaNaveACella(c2,new Nave("Madonna"));
      mappa.assegnaNaveACella(c2,new Nave("Puttana"));

      System.out.println(mappa);
      System.out.println(mappa.contaNavi(c2));
  }
}
