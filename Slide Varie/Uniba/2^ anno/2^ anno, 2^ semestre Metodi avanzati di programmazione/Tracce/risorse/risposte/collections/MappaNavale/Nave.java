public class Nave{

public String nome;
  public Nave(String nome){
    this.nome=nome;
  }

public boolean equals(Object n){
  return nome.equals(((Nave)n).nome);
}

    public int hashCode(){
      return nome.hashCode();
    }

    public String toString(){
      return nome;
    }

}
