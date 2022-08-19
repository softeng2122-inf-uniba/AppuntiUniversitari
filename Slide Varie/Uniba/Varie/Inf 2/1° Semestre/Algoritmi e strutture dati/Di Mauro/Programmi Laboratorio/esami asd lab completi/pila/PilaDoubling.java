package pila;

public class PilaDoubling<T> implements Pila<T>{

	private T[] S= (T[])new Object[1];
	private int n=0;
	
	public static void main(String[] args) {
		Pila<Integer> p= new PilaDoubling<Integer>();
		for (int i=0; i<10; i++) {
			p.push(i);
		}
		for (int i=0; i<10; i++){
			System.out.println(p.top());
			p.pop();
		}
	}

	@Override
	public boolean isEmpty() {
		return n==0;
	}

	@Override
	public void push(T e) {
		if (n==S.length){
			T[] tmp= (T[])new Object[S.length*2];
			for (int i=0; i<n; i++){
				tmp[i]=S[i];
			}
			S=tmp;
		}
		S[n]=e;
		n++;
	}

	@Override
	public T top() {
		if (n==0) throw new EccezionePilaVuota();
		return S[n-1];
	}

	@Override
	public void pop() {
		if (n==0) throw new EccezionePilaVuota();
		n--;
		if (n>1 && n<S.length/4){
			T[] tmp= (T[])new Object [S.length/2];
			for (int i=0; i<n; i++) {
				tmp[i]=S[i];
			}
			S=tmp;
		}
		
	}

}
