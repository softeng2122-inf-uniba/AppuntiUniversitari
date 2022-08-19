package process;

public class Process {

	private String path;
	private int id;
	private static int n=1;
	
	public Process(String p) {
		this.path=p;
		this.id=n;
		n++;
	}

	
	public int getID(){
		return this.id;
	}
	
	public String getPath() {
		return this.path;
	}
	
	public String toString(){
		String s="processo= [path: " + this.path + " id: " + this.id+"]"; 
		return s;	
	}
	
}
