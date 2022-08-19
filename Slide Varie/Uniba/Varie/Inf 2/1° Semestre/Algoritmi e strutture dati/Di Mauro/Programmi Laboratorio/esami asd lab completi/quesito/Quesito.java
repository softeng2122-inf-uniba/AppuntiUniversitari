package quesito;

public class Quesito<T> implements AddOnlyQueue<T>{

	public String quesito;
	private T [] S;
	private int n;

	//costruttore della classe quesito 
	public Quesito(String q) {
		quesito=q;
		S= (T[]) new Object[1]; // utilizzo un array con tecnica del raddoppiamento/dimezzamento per gestire la coda
		n=0; // numero di elementi effettivametne presenti nella coda
	}

	
	public void add(T dato) {
		if (n==S.length){
			T[] tmp= (T[]) new Object[S.length*2]; 
			for (int i=0; i<n; i++){
				tmp[i]=S[i];
			}
			S=tmp;
		}
		S[n]=dato;
		n++;
	}

	
	public T getElem(int i) {
		if (n==0) throw new EccezioneQuesitoVuoto("il quesito non ha voti scrutinati");
		if (i<=0 || i>n ) throw new EccezioneIndiceNonValido("indece non valido");
		return S[i-1];
	}

	public int numberElements() {
		return n;
	}

}
