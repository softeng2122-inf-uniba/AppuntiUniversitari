package Pila;

public class PilaArray<T> implements Pila<T> {

	private Object[] S = new Object[1];
	private int n = 0;

	@Override
	public void push(T elem) {

		S[n] = elem;
		n++;

		if (n == S.length) {
			Object[] temp = new Object[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}

	}

	@Override
	public void pop() {
		if (isEmpty())
			throw new EccezionePilaVuota("La pila è vuota!");
		else {
			n--;
			if (n < S.length / 4) {
				Object[] temp = new Object[S.length / 2];
				for (int i = 0; i < n; i++)
					temp[i] = S[i];
				S = temp;
			}

		}
	}

	@Override
	public boolean isEmpty() {
		return n == 0;
	}

	@Override
	public Object top() {
		if (isEmpty())
			throw new EccezionePilaVuota("La pila è vuota!");
		else
			return S[n - 1];
	}

	public static void main(String[] args) {

		PilaArray<String> pila = new PilaArray<String>();
		pila.push("ciao");
		System.out.println(pila.top());

		pila.push("aueee");
		System.out.println(pila.top());
		pila.pop();
		
		System.out.println(pila.top());


	}

}
