package processo;

import java.util.Random;

public class Processo {

	private int id ;
	private static int progressivo=1;
	private int durata;
	
	
	public Processo(){
		Random r= new Random();
		id=progressivo;
		progressivo++;
		durata=r.nextInt((800-50)+1) + 50;
	}
	
	public boolean execute(int time_slice){
		durata=durata-time_slice;
		
		if (durata<=0) return true;
		else return false;
	}
	
	public int getID(){
		return id;
	}
	
	public int getDurata(){
		return durata;
	}
	
	
}
