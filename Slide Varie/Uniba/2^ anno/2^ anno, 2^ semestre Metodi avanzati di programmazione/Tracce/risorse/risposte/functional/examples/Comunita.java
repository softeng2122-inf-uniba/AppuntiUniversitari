import java.util.LinkedList;
import java.util.List;
import java.util.function.Predicate;
import java.util.function.Consumer;
import java.util.function.Function;

class Comunita {
  private List <Persona> lista=new LinkedList<>();

  //DEPRECATED
  public void printPersoneConPiuDi(int eta) {
    for (Persona p : lista) {
      if (p.getEta() >= eta) {
        p.printPersona();
      }
    }
  }

  //DEPRECATED
  public void printPersoneConEtaCompresaFra(int inf, int sup) {
    for (Persona p : lista) {
      if (inf <= p.getEta() && p.getEta() < sup) {
        p.printPersona();
      }
    }
  }

  private void add(Persona p){lista.add(p);}

  public List<Persona> getList() {
    return lista;
  }

  public void printPersoneConPredicate(Predicate<Persona>pred) {
    for (Persona p : lista) {
      if (pred.test(p)) {
        p.printPersona();
      }
    }
  }

  public void elaboraPersone(Predicate<Persona>pred, Consumer<Persona> cons) {
    for (Persona p : lista) {
      if (pred.test(p)) {
        cons.accept(p);
      }
    }
  }

  public void elaboraPersoneConFunction(Predicate<Persona>pred, Consumer<Persona> cons, Function<Persona,String> mapp) {
    for (Persona p : lista) {
      if (pred.test(p)) {
        String data = mapp.apply(p);
        cons.accept(p);
      }
    }
  }

  public static void main (String args[]) {
    Comunita c=new Comunita();
    c.add(new Persona("AA", 22, "a@b"));
    c.add(new Persona("AB", 12, "a@a"));
    c.add(new Persona("CA", 21, "c@b"));
    c.add(new Persona("AA", 29, "cc@b"));

    c.printPersoneConPredicate(p->p.getEta()>=18 && p.getEta()<=25);

    System.out.println("----");

    c.elaboraPersone(p->p.getEta()>=18 && p.getEta()<=25, p->p.printPersona());

    System.out.println("----");

    c.elaboraPersoneConFunction(p->p.getEta()>=18 && p.getEta()<=25, p->p.printPersona(), p->p.getNome());

    System.out.println("----");

    System.out.println("Now starting with aggregates");

    System.out.println("----");

    c.getList()
    .stream() //gets the stream
    .filter(p->p.getEta()>=18 && p.getEta()<=25) //filters the stream
    .map(p->p.getNome())//maps to the name of the Persona
    .forEach(n->System.out.println(n));//does something for each item of the stream

    System.out.println("----");
    System.out.println("Now calculating the avg... should be 21");

    double avg = c.getList()
    .stream()
    .mapToInt(p->p.getEta())
    .average()
    .getAsDouble();
    System.out.println(avg);

    System.out.println("----");
    System.out.println("Now the sum with reduce");

    int sum=c.getList()
    .stream()
    .map(p->p.getEta())
    .reduce(0, (a,b)->a+b);
    System.out.println(sum);

    System.out.println("----");
    System.out.println("Now the sum with filter and reduce");

    sum=c.getList()
    .stream()
    .filter(p->p.getNome().toUpperCase().charAt(0)=='A')
    .map(p->p.getEta())
    .reduce(0, (a,b)->a+b);
    System.out.println(sum);

    System.out.println("----");
    System.out.println("Now the avg with collect");

    Media media=c.getList()
    .stream()
    .map(p->p.getEta())
    .collect(Media::new, Media::accept, Media::combine);
    System.out.println(media.average());

  }



}
