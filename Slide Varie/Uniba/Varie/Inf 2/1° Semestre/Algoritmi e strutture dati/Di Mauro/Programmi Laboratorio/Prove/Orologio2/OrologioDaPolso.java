package Orologio2;

import java.util.Iterator;

public class OrologioDaPolso {

	Orologio<Ora> ore;
	Orologio<Minuto> minuti;

	public OrologioDaPolso() {

		ore = new Orologio<Ora>();
		minuti = new Orologio<Minuto>();

		for (int i = 23; i > -1; i--) {
			ore.add(new Ora(String.valueOf(i), null));
		}
		for (int i = 59; i > -1; i--) {
			if (i % 30 == 0 && i != 0)
				minuti.add(new Minuto(String.valueOf(i), new Event("bip")));
			else if (i == 0)
				minuti.add(new Minuto(String.valueOf(i), new Event("bip bip")));
			else
				minuti.add(new Minuto(String.valueOf(i), new Event(null)));
		}

	}

	public void start() {
		for (Ora ora : this.ore) {
			for (int i = 0; i < 60; i++) {
				if (i == 30 || i == 0) {
					System.out.println(this.ore.value().getName() + ":"
							+ this.minuti.value().getName() + " "
							+ this.minuti.value().getEvent().toString());
				}
				this.minuti.rotateF();
			}
			this.ore.rotateF();
		}

	}

	public boolean equals(OrologioDaPolso b) {
		boolean equal = false;

		if (this.ore.n == b.ore.n && this.minuti.n == b.minuti.n) {
			if (this.ore.value().getName().equals(b.ore.value().getName())
					&& this.minuti.value().getName()
							.equals(b.minuti.value().getName())) {
				Iterator<Ora> it = b.ore.iterator();
				Iterator<Minuto> it2 = b.minuti.iterator();
				for (Ora ora : this.ore) {
					if (!(ora.getName().equals(it.next().getName())))
						return false;
				}
				for (Minuto minuto : this.minuti) {
					if (minuto.getName().equals(it2.next().getName()))
						equal = true;
					else
						return false;
				}
			} else
				return false;

		}

		return equal;
	}

	

}
