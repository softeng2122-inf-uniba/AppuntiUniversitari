public class Prodotto {
  private int codiceProdotto;
  private String nome;
  private double prezzo;

  public Prodotto(int codiceProdotto, String nome, double prezzo){
    this.codiceProdotto=codiceProdotto;
    this.nome=nome;
    this.prezzo=prezzo;
  }

  public String getNome(){
    return nome;
  }

  public double getPrezzo(){
    return prezzo;
  }

  public int getCodiceProdotto(){
    return codiceProdotto;
  }

  @Override
  public boolean equals(Object o){
    return ((Prodotto)o).codiceProdotto==codiceProdotto;
  }

  @Override
  public int hashCode(){
    return codiceProdotto;
  }

  @Override
  public String toString(){
    return codiceProdotto + " " + nome + " " + prezzo;
  }

}
