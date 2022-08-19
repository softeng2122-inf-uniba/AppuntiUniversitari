package Datagramma;

import java.util.LinkedList;

public class TestMessaggio {

	private static void popolaMessaggio(Messaggio m,int size) {
		LinkedList<Integer> list = new LinkedList<Integer>();

		while (list.size() < size) {
			int i = (int) ((size) * Math.random());
			if (!list.contains(i)) {
				if (i == size-1) {
					Datagramma d = new Datagramma(null, null, i,
							String.valueOf((int)(Math.random()*1000)), true);
					m.addDatagramma(d);

					list.add(i);
				} else {
					Datagramma d = new Datagramma(null, null, i,
							String.valueOf((int)(Math.random()*1000)), false);
					m.addDatagramma(d);

					list.add(i);
				}
			}
		}

	}

	public static void main(String[] args) {
		Messaggio m = new Messaggio();
		Messaggio m2=new Messaggio();
		Messaggio m3= new Messaggio();
		
		popolaMessaggio(m,10);
		popolaMessaggio(m2,15);
		popolaMessaggio(m3,20);
		
		System.out.println(m);
		System.out.println(m2);
		System.out.println(m3);
		
		//confronto con se stesso
		System.out.println(m.confronta(m));
	
		System.out.println(m2.confronta(m3));
		

	}
}
