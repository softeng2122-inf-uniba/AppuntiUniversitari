import java.util.ArrayList;

public class Collezione{
  ArrayList <Studente> Studenti;

  public Collezione(ArrayList<Studente>Studenti){
    this.Studenti=Studenti;
  }

  public Collezione(){
    Studenti=new ArrayList<Studente>();
  }

  public void addStudente(Studente s){
    Studenti.add(s);
  }

  public Studente getStudente(int i){
    return Studenti.get(i);
  }

  public Studente maxNumeroEsamiFemale(){
    return Studenti.stream()
    .filter(s->s.getGenere().equals("female"))
    .reduce(new Studente("nullStudent", 0, 0), (a,b)-> a.getNumeroEsami()>b.getNumeroEsami() ? a : b);

  }

  public static void main(String [] args){
    Collezione c=new Collezione();
    c.addStudente(new Studente("female", 10, 18));
    c.addStudente(new Studente("male", 0, 0));
    c.addStudente(new Studente("female", 22, 30));
    c.addStudente(new Studente("female", 4, 18));
    c.addStudente(new Studente("male", 35, 18));
    c.addStudente(new Studente("female", 19, 18));
    c.addStudente(new Studente("female", 21, 18));
    System.out.println(c.maxNumeroEsamiFemale());
  }
}
