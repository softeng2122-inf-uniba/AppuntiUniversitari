public class Studente{
  String genere;
  int numeroEsami;
  double mediaVoti;


  public Studente(){}

  public Studente(String genere, int numeroEsami, double mediaVoti){
    this.genere=genere;
    this.numeroEsami=numeroEsami;
    this.mediaVoti=mediaVoti;
  }

  public String getGenere(){
    return genere;
  }

  public int getNumeroEsami(){
    return numeroEsami;
  }

  public double getMediaVoti(){
    return mediaVoti;
  }

  public void setGenere(String genere){
    this.genere=genere;
  }

  public void setNumeroEsami(int numeroEsami){
    this.numeroEsami=numeroEsami;
  }

  public void setMediaVoti(double mediaVoti){
    this.mediaVoti=mediaVoti;
  }

  @Override
  public String toString () {
    return new String(genere+" "+numeroEsami+" "+mediaVoti);
  }

}
