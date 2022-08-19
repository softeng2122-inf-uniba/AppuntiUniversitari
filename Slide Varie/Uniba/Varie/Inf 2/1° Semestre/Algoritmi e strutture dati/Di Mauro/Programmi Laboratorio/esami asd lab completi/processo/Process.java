package processo;

public class Process {
	private static int count=1;
	
	private int ID;
	private String path;
	private State stato;
	private int priority;

	public Process (String pa, int pr){
		this.stato=State.UNRUNNABLE;
		this.ID=count;
		count ++;
		this.priority=pr; 
		this.path=pa;
	}
	
	public int getPriority() {
		return this.priority;
	}
	
	public String toString() {
		String s= "ID: " + getID() + " path: " + getPath() + " stato: " + getState() + " priorità: " + getPriority();
		return s;
	}
	
	public State getState(){
		return this.stato;
	}
	
	public int getID(){
		return this.ID;
	}
	
	public String getPath() {
		return this.path;
	}
	
	public void setState(State s){
		if ((this.stato==State.UNRUNNABLE && s==State.STOP) || (this.stato==State.STOP && s==State.UNRUNNABLE)) {
			throw new EccezioneStatoNonValido("cambio di stato non valido");
		}
		
		this.stato=s;
	}
}
