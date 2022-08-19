import java.util.function.IntConsumer;

public class Media implements IntConsumer{
  private int totale;
  private int contatore;

  public double average(){
    return contatore==0 ? 0 : ((double)totale)/contatore;
  }

  public void accept(int i){
    totale+=i;
    contatore++;
  }

  public void combine(Media altro){
    totale+=altro.totale;
    contatore+=altro.contatore;
  }

}
