package messaggio;
import java.net.InetAddress;


public class Datagramma {
	private InetAddress sorgente;
	private InetAddress destinazione;
	private int identificativo;
	private String dati;
	private boolean ultimo;
	
	public Datagramma (InetAddress s, InetAddress de, int i, String d, boolean u) {
		sorgente=s;
		destinazione=de;
		identificativo=i;
		dati=d;
		ultimo=u;
	}
	
	public InetAddress getSorgente(){
		return sorgente;
	}
	
	public InetAddress getDestinazione(){
		return destinazione;
	}
	
	
	public int getIdentificativo(){
		return identificativo;
	}
	
	public String getdati(){
		return dati;
	}
	
	public boolean getUltimo(){
		return ultimo;
	}
	
	public String toString(){
		String s= "sorgente: " + sorgente + " destinazione: " + destinazione + " identificativo: " + identificativo + " dati: " + dati; 
		return s;
	}
}
