import java.util.ArrayList;

public class Coordinata{
  private double latitudine;
  private double longitudine;

  public Coordinata(double latitudine, double longitudine){
    this.latitudine=latitudine;
    this.longitudine=longitudine;
  }

  public void setLatitudine(double latitudine){
    this.latitudine=latitudine;
  }

  public void setLongitudine(double longitudine){
    this.longitudine=longitudine;
  }

  public double getLatitudine(){
    return latitudine;
  }

  public double getLongitudine(){
    return longitudine;
  }

  @Override
  public String toString(){
    return latitudine+" "+longitudine;
  }

  public static void main (String[] args){
    ArrayList<Coordinata> lista =new ArrayList<Coordinata>();
    lista.add(new Coordinata(3,4));
    lista.add(new Coordinata(4,7));
    lista.add(new Coordinata(2,4));
    lista.add(new Coordinata(6,4));
    lista.add(new Coordinata(8,1));
    lista.add(new Coordinata(1,3));
    lista.add(new Coordinata(5,4));
    lista.add(new Coordinata(7,8));
    lista.add(new Coordinata(9,4));
    lista.add(new Coordinata(3,6));
    lista.add(new Coordinata(1,5));

    lista.stream()
    .filter(p->p.getLatitudine()<5 && p.getLongitudine()<7)
    .forEach(s->System.out.println(s));
  }

}
