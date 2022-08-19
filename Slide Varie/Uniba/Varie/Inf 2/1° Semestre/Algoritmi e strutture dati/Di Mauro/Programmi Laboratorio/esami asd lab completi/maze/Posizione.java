package maze;

public class Posizione {


	private int x;
	private int y;
	
	public Posizione(int X, int Y){
		x=X;
		y=Y;
	}
	
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
	public boolean equals(Posizione p){
		return (x==p.getX() && y==p.getY());
	}
	
	public String toString(){
		String s= "("+x+","+y+")";
		return s;
	}
		
}
