/**
* 	This class shows the state of the class (event, action, and next state) after
*	the corresponding event has been handled by one the two states. 
*/

import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class StopAndWaitStatus
{
	private String title;
	private JTextField [] field;
	private  JPanel panel;
	private JLabel [] label;
  
	public StopAndWaitStatus (String title)
	{
		this.title = title;
		panel = new JPanel ();
		field = new JTextField [2];
		label  = new JLabel [3];  
	} // End constructor
  
	public void show(String curState, String nextState, String[] action)
	{ 
		panel.setLayout (new GridLayout (5, 1)); 
		Font ft = new Font ("bold", 1, 18);
		for (int i = 0; i < 2; i++)
		{
			field[i] = new JTextField (14);
			field[i].setBackground (Color.black);
			field[i].setHorizontalAlignment (JTextField.CENTER);
			field[i].setFont (ft);
			field[i].setForeground (Color.white);
			field[i].setBorder (new BevelBorder (BevelBorder.RAISED)); 
		}
		field[0].setText ("Current State: " +curState); 
		field[1].setText ("Next State: " + nextState);
		panel.add (field[0]);   
		for (int i = 0; i < 3; i++)
		{
			label[i] = new JLabel (action [i]);
			panel.add (label[i]);
		}//End loop
		panel.add (field[1]);
		label[2].setForeground (Color.red);
		JOptionPane.showMessageDialog (null, panel, title, 1);
	}// End show
        
} // End class    