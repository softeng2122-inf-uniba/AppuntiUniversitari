import java.util.ArrayList;

public class Razionale{
  private int numeratore;
  private int denominatore;

  public Razionale(int numeratore, int denominatore){
    this.numeratore=numeratore;
    this.denominatore=denominatore;
  }

  public void setNumeratore(int numeratore){
    this.numeratore=numeratore;
  }

  public void setDenominatore(int denominatore){
    this.denominatore=denominatore;
  }

  public int getNumeratore(){
    return numeratore;
  }

  public int getDenominatore(){
    return denominatore;
  }

  @Override
  public String toString(){
    return numeratore+" "+denominatore;
  }

  public static void main (String[] args){
    ArrayList<Razionale> lista =new ArrayList<Razionale>();
    lista.add(new Razionale(3,4));
    lista.add(new Razionale(4,7));
    lista.add(new Razionale(2,4));
    lista.add(new Razionale(6,4));
    lista.add(new Razionale(8,1));
    lista.add(new Razionale(1,3));
    lista.add(new Razionale(5,4));
    lista.add(new Razionale(7,8));
    lista.add(new Razionale(9,4));
    lista.add(new Razionale(3,6));
    lista.add(new Razionale(1,5));

    lista.stream()
    .filter(p->p.getNumeratore()%2==0)
    .forEach(s->System.out.println(s));
  }

}
