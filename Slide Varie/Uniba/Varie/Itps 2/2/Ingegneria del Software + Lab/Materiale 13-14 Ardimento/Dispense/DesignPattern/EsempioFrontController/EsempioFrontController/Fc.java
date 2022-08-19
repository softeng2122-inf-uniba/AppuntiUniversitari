package schedule.frontController;
import java.util.ArrayList;
import pdk.presentation.FrontController;
import pdk.presentation.applicationController.ApplicationController;
import schedule.presentation.applicationController.ScheduleAC;


/**
 * Centralizza il punto di accesso per la gestione delle richieste
 * Delega all'Application Controller la gestione delle view e l'esecuzione dei servizi
 * @author ...
 * */
public class Fc implements FrontController
{
	private static Fc fc = null;

	/**
	 * uso del singleton perchè in esecuzione esista al massimo un'unica istanza del Front Controller
	 * @return l'istanza del Front Controller 
	 */
	public static Fc getInstance() {
		if (fc == null)
			Fc.fc = new Fc();
		return fc;				
	}
	/**
	* costruttore reso privato a causa dell'uso del singleton
	*/
	private Fc(){};

	public Object processRequest(String request, ArrayList<ArrayList<String>> parametri) {
		try {
			/*recupera lo specifico Application Controller di Schedule in base al contenuto dell’attributo 
			  map avvalorato secondo il contenuto del file XML ScheduleACFactory */
			ApplicationController ac = (ScheduleAC)(new AcFactory().getInstance(request));
			System.out.println("passo1");
			//restituisce il risultato dell'esecuzione del metodo richiesto
			return ac.handleRequest(request,parametri);
		} catch (Exception e) {
			System.err.println("PROCESSREQUEST: \nIMPOSSIBILE RESTITUIRE UN RISULTATO \n");
			e.printStackTrace();
			//dispatch(request, parametri);
		}
		return null;		
	}
}