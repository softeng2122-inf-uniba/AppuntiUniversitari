package processo;
import circList.*;

public class Scheduler {

	private static final int TIME_SLICE=100; 

	
	public static void main(String[] args) {
		CircList<Processo> circProcessi=new ListaCircDL<Processo>();
		int i;
		for (i=1; i<=6; i++){
			
			System.out.println("iterata " + i + ":");
			Processo p= new Processo();
			circProcessi.addCircList(p);
			for (Processo pr: circProcessi){
				System.out.print ("(" + pr.getID() + "," + pr.getDurata() + ") " );
			}
			System.out.println("");
			p=circProcessi.value();
			if (p.execute(TIME_SLICE)) {
				circProcessi.delCircList();			
				System.out.println("Processo " + p.getID() + " terminato");
			}
			
			circProcessi.setDir(Direzione.forward);
			circProcessi.ruota();
		}
		
		while (!circProcessi.isEmpty()){
		
			System.out.println("iterata " + i + ":");
			for (Processo pr: circProcessi){
				System.out.print("(" + pr.getID() + "," + pr.getDurata() + ") " );
			}
			System.out.println("");
			Processo p=circProcessi.value();
			if (p.execute(TIME_SLICE)) {
				circProcessi.delCircList();			
				System.out.println("Processo " + p.getID() + " terminato");
			}
			
			circProcessi.setDir(Direzione.forward);
			circProcessi.ruota();
			i++;
		}
	}

}
