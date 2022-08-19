/**
* 	This is the class that simulates the Ready state in this protocol.
*	The class has four methods, one for each event. The signatures of
*	each method is defined in the State intefrace and this class needs to show
* 	how they are implemented. The class is also responsible to set the next state
* 	in the mother class after handling the event. 
*/

import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class GoBackNReady implements GoBackNState
{
	GoBackN sender;
	String []  actions;
	GoBackNStatus status;
	String curState, nextState;

	public GoBackNReady (GoBackN sender)
	{
		this.sender = sender;
		actions = new String [3];
		curState = "Ready";
	} // End constructor
  
	public void requestToSend ()
	{ 
		actions[0] = "Packet with seqNo = " + sender.getSN () + " was sent.";
		int temp = (sender.getSN() + 1) % sender.getModulus();
		sender.setSN (temp);
		if (sender.getTimer ())
		{
			actions[1] = "Timer is running.";
		}
		else 
		{
			actions[1] = "Timer was started.";
			sender.setTimer (true);
		}        
		if (sender.getCurWindowSize() == sender.getWSize())
		{
			sender.setState (sender.getBlocking());
			nextState = "Blocking";
		}
		else
		{
			sender.setState (sender.getReady());
			nextState = "Ready";
		}
		actions[2] = "Window: SF = " +sender.getSF() + "                  SN = " + sender.getSN();
		status = new GoBackNStatus ("Go Back N Protocol: Sender Site");
		status.show (curState, nextState,  actions);
	} // End requestToSend

	public void timeout ()
	{
		if (!sender.getTimer())
		{
			actions[0] = "The event is not supported; no timer is running.";
			actions[1] = null;             
		}
		else
		{
			actions[0] = "All outstanding packets were resent.";
			actions[1] = "Timer was restarted.";
			sender.setTimer (false);
			sender.setTimer (true);
		}
		sender.setState (sender.getReady());
		nextState = "Ready";
		actions[2] = "Window: SF = " +sender.getSF() + "                    SN = " + sender.getSN();
		status = new GoBackNStatus ("Go Back N Protocol: Sender Site");
		status.show (curState, nextState,  actions);  
	} // End timeout

	public void errorFreeACK (int ackNo)
	{
		if (ackNo == -1)
		{
			actions[0] = "There is not outstanding packet. The ACK was discarded.";
			actions[1] = null;
			sender.setState (sender.getReady ());
			nextState = "Ready";
		}
		else if (!sender.validAck (ackNo))
		{
			actions[0] = "The ACK was discarded; it was outside window";
			actions[1] = null;
			sender.setState (sender.getReady ());
			nextState = "Ready";
		}
             
		else
		{
			sender.setSF(ackNo);
			actions[0] = "The window slided";
			sender.setState (sender.getReady());
			nextState = "Ready";
			if (sender.getSF() == sender.getSN())
			{
				actions[1] = "Timer was cancelled.";
				sender.setTimer (false);
			}
			else
			{
				actions[1]= "Timer restarted";
				sender.setTimer (false);
				sender.setTimer (true);
			}
		}
                  
		actions[2] = "Window: SF = " +sender.getSF() + "                  SN = " + sender.getSN(); 
		status = new GoBackNStatus ("Go Back N Protocol: Sender Site");        
		status.show (curState, nextState,  actions);

	}// End errorFreeAck
             
	public void corruptedACK ()
	{
		actions[0] = "ACK was discarded; it was corrupted.";
		actions[1] = null;
		sender.setState (sender.getBlocking());
		nextState = "Blocking";
		actions[2] = "Window: SF = " +sender.getSF() + "                   SN = " + sender.getSN(); 
		status = new GoBackNStatus ("Selective Repeat Protocol: Sender Site");     
		status.show (curState, nextState,  actions);
	}// End corruptedACK
	
} // End class   