public class Persona{
  private int eta;
  private String nome;
  private String indEmail;

  public Persona(String n, int e, String i){
    eta = e;
    nome = n;
    indEmail = i;
  }

  public int getEta(){return eta;}
  public String getNome(){return nome;}
  public String getIndEmail(){return indEmail;}

  @Override
  public String toString(){
    return nome + " " + eta + " " + indEmail;
  }

  public void printPersona() {System.out.println(toString());}

  public static void main(String[] args){
    Persona p=new Persona("Antonio", 20, "antoniogrisulli23@gmail.com");
    p.printPersona();
  }
}
