package schedule.ui.core;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;

import javax.swing.WindowConstants;

import pdk.presentation.FrontController;


import schedule.frontController.Fc;
import schedule.utility.Index;
import schedule.utility.LimiteText;

/**Finestra per la modifica dei dati di un edificio
 * 
 * 
* This code was edited or generated using CloudGarden's Jigloo
* SWT/Swing GUI Builder, which is free for non-commercial
* use. If Jigloo is being used commercially (ie, by a corporation,
* company or business for any purpose whatever) then you
* should purchase a license for each developer using Jigloo.
* Please visit www.cloudgarden.com for details.
* Use of Jigloo implies acceptance of these licensing terms.
* A COMMERCIAL LICENSE HAS NOT BEEN PURCHASED FOR
* THIS MACHINE, SO JIGLOO OR THIS CODE CANNOT BE USED
* LEGALLY FOR ANY CORPORATE OR COMMERCIAL PURPOSE.
*/
public class F_ModificaEdificio extends javax.swing.JDialog {
	private static final long serialVersionUID = 1L;
	private JLabel lblCentrale;
	private JButton btnConferma;
	private JTextField txtNPiani;
	private JTextField txtIndirizzo;
	private JTextField txtNome;
	private JLabel lblNPiani;
	private JLabel lblIndirizzo;
	private JLabel lblNome;
	private String old_nome;

	private FrontController iFc = Fc.getInstance();
	/**
	 * 
	 * @param nomeAppl nome dell'applicazione
	 * @param dati dati dell'edificio da modificare
	 */
	
	public F_ModificaEdificio(String nomeAppl,String [] dati) {
		super();
		ImagePanel panel = new ImagePanel(new ImageIcon("icone/sfondo.jpg").getImage());
		try {
			this.old_nome=dati[0];
			setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
			pack();
			setModal(true);
			
			this.setSize(290, 200);
			setTitle(nomeAppl);	
			setResizable(false);
			getContentPane().add(panel);
			this.setLocation(new java.awt.Point(300, 200));
			panel.setLayout(null);
			{
				lblCentrale = new JLabel();
				panel.add(lblCentrale);
	/* TODO per le label si suggerisce l'uso di java.util.PropertyResourceBundle */
				lblCentrale.setText("Modifica Edificio");
				lblCentrale.setBounds(78, 12, 149, 16);
				lblCentrale.setFont(new java.awt.Font("Times New Roman",2,18));
			}
			{
				lblNome = new JLabel();
				panel.add(lblNome);
				lblNome.setText("Nome:");
				lblNome.setBounds(12, 50, 78, 16);
			}
			{
				lblIndirizzo = new JLabel();
				panel.add(lblIndirizzo);
				lblIndirizzo.setText("Indirizzo:");
				lblIndirizzo.setBounds(12, 78, 89, 16);
			}
			{
				lblNPiani = new JLabel();
				panel.add(lblNPiani);
				lblNPiani.setText("N° Piani:");
				lblNPiani.setBounds(12, 106, 78, 16);
			}
			{
				txtNome = new JTextField();
				
				panel.add(txtNome);
				txtNome.setBounds(113, 47, 165, 22);
			}
			{
				txtIndirizzo = new JTextField();
				
				panel.add(txtIndirizzo);
				txtIndirizzo.setBounds(113, 75, 165, 22);
			}
			{
				txtNPiani = new JTextField();
				
				panel.add(txtNPiani);
				txtNPiani.setBounds(113, 103, 165, 22);
			}
			{
				btnConferma = new JButton();
				panel.add(btnConferma);
				btnConferma.setText("Conferma");
				btnConferma.setBounds(159, 142, 119, 22);
				btnConferma.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent evt) {
						btnConfermaActionPerformed(evt);
					}
				});
			}
			txtNome.setDocument(new LimiteText(40));
			txtIndirizzo.setDocument(new LimiteText(100));
			txtNPiani.setDocument(new LimiteText(3));
			txtNome.setText(dati[Index.edi_Nome]);
			txtNPiani.setText(dati[Index.edi_Piani]);
			txtIndirizzo.setText(dati[Index.edi_Ind]);
			setVisible(true);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private void btnConfermaActionPerformed(ActionEvent evt) {

		ArrayList<ArrayList<String>> parametri = new ArrayList<ArrayList<String>>();
		ArrayList<String> par = new ArrayList<String>();

		//NOME
		par.add("String");
		par.add(txtNome.getText());
		parametri.add(par);
		
		//INDIRIZZO
		par = new ArrayList<String>();
		par.add("String");
		par.add(txtIndirizzo.getText());
		parametri.add(par);

		//NUMERO DEI PIANI
		par = new ArrayList<String>();
		par.add("String");
		par.add(txtNPiani.getText());
		parametri.add(par);
		
		//VECCHIO NOME
		par = new ArrayList<String>();		
		par.add("String");
		par.add(old_nome);
		parametri.add(par);
		
		
		Boolean esito = (Boolean) iFc.processRequest("confermaModificaEdificio", parametri);
		if (esito == true){
		dispose();
		}
	}
}