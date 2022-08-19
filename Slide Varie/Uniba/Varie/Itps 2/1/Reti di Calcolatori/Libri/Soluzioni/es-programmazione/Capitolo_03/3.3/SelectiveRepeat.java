/**
* 	This is the mother class in this program that uses five other classes and an 
*	interface to simulate the theoretical Selective-Repeat Protocol at the transport layer.
*	This class is responsible to get the event from the user and calls the class 
*	that handles that even. The main method in this class is the driver
*	for the whole program. The protocol uses two states: ready and blocking.
*	Each state is defined in its own class and the interface is responsible 
*	for the liaison between the states and the mother classes.  The code first
*	gets the event (using the Input class). The class then passes the
*	event to the appropriate state for handling. This class is also responsible for 
*	setting and getting the values of variables in the protocol. 
*/ 

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.math.*;

public class SelectiveRepeat
{
	private  SelectiveRepeatState  ready, blocking, current;
	private int m, sF, sN, wSize, ackNo, modulus;
	private boolean timer;        // true, running; false, otherwise.
	Set <Integer>  ackSet;
	SelectiveRepeatInput input;
	SelectiveRepeatModular modular;
      
	public SelectiveRepeat ()
	{        
		ackSet = new HashSet <Integer> ();
		ready = new SelectiveRepeatReady (this);
		blocking = new SelectiveRepeatBlocking (this);
		current = ready; 
		sF = 0;
		sN = 0;
		ackNo = 0;
		timer = false; 
		input = new SelectiveRepeatInput ();
		simulate ();         
	} // End constructor

	public void simulate ()
	{
		m = input.getIntInput ("Enter the number of bits, m, between 2 and 8.", 2, 8);
		modulus = (int) (Math.pow (2, m));
		wSize = (int) modulus / 2;
		modular = new SelectiveRepeatModular (modulus);
		getEvent ();
	} // End simulate  
       
	private void getEvent ()
	{
		int event = -1;
		String title = "Selective Repeat Protocol: Sender Side";
		String message = "Give ackNo between 0 and " + (modulus - 1) + ".";  
		String[] options = {"Request to Send", "Timeout", "Error Free ACK", "Corrupted ACK", "Quit"};     
		do 
		{
			event  = input.getOption ("Select the event", options);
			switch (event)    
			{
				case 0:	requestToSend ();
						break;
				case 1:	timeout ();
						break;
				case 2:	if (sF != sN)
						{
							ackNo = input.getIntInput ("Give ackNo, 0 to " + (modulus -1) , 0, modulus -1);
						}
						else 
						{
							ackNo = -1;
						}
						errorFreeACK (ackNo);
						break;
				case 3:	corruptedACK ();
						break;
				case 4:	break;
			}// End switch
		} while (event != 4);
	} // End  getEvent 

	public void requestToSend ()
	{
		current.requestToSend (); 
	} // End requestToSend

	public void timeout ()
	{
		current.timeout();
	}// End timeOut

	public void errorFreeACK (int an)
	{
		current.errorFreeACK ( an);
	} // End errorFreeACK

	public void corruptedACK()
	{
		current.corruptedACK();
	} // End corruptedACK 
      
	public void setState (SelectiveRepeatState state)
	{
		current = state;
	}// End setState

	public SelectiveRepeatState getReady()
	{
		return ready;
	} // End getReady

	public SelectiveRepeatState getBlocking()
	{
		return blocking;
	} // End getBlocking
      
	public void setSF (int sf)
	{
		sF= modular.residue (sf);
	} // End setSF

	public void setSN (int sn)
	{
		sN= modular.residue (sn);
	} // End setSN

	public void setTimer (boolean t)
	{
		timer = t;
	} // setTimer
   
	public int getModulus ()
	{
		return modulus;
	} // End getModulus

	public int getWSize ()
	{
		return wSize;
	} // End getWSize
      
	public int getSF ()
	{
		return sF;
	} // End getSF

	public int getSN ()
	{
		return sN;
	} // End gesSN

	public boolean getTimer ()
	{
		return timer;
	} // End getTimer

	public boolean validAck (int ackNo)
	{ 
		if (sF == sN)
		{
			return false;
		}
		else
		{
			int lower = modular.residue (sF);
			int upper = modular.residue (sN -1);
			return (modular.isInRange(ackNo, lower, upper));
		}
	} // End validAck

	public boolean isWindowSlided (int ackNo)
	{
		boolean slided = false;
		ackSet.add (ackNo);
		while (ackSet.contains (sF))
		{
			ackSet.remove (sF);
			sF = modular.add (sF , 1);
			slided = true;
		}
		return slided;
	} // End isWindowSlided

	public boolean duplicateAck (int ackNo)
	{
		return (ackSet.contains (ackNo));
	} // End duplicateAck

	public static void main (String[] args)
	{
		SelectiveRepeat sr = new SelectiveRepeat ();
	} // End main
      
} // End class  