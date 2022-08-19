package pdk.presentation;

import java.util.ArrayList;

/**
 * Classe Servlet
 * 
 * @author ...
 * 
 */
public interface FrontController{

	/**
	 *  
	 * 
	 * @param request: Stringa che codifica il servizio da invocare 
	 * @param val: ArrayList<ArrayList<String>> impacchetta i dati della richiesta
	 * 	
	 */
	public Object processRequest(String request, ArrayList<ArrayList<String>> parametri);

}