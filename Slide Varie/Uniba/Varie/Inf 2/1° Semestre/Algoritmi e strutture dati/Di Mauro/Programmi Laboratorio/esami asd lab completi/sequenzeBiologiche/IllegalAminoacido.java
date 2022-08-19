package sequenzeBiologiche;

public class IllegalAminoacido extends RuntimeException{
	
	IllegalAminoacido(){
		
	}
	
	IllegalAminoacido(String messaggio){
		super (messaggio);
	}

}
