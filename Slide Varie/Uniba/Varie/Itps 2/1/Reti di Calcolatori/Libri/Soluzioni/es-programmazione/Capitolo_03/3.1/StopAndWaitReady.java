/**
* 	This is the class that simulates the Ready state in this protocol.
*	The class has four methods, one for each event. The signatures of
*	method is defined in the State intefrace and this state needs to show
* 	how they are implemented. The class is also responsible to set the next state
* 	in the mother class after handling the event. 
*/

import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class StopAndWaitReady implements StopAndWaitState
{
	StopAndWait sender;
	String []  actions;
	StopAndWaitStatus status;
	String curState, nextState;

	public StopAndWaitReady (StopAndWait sender)
	{
		this.sender = sender;
		actions = new String [3];
		curState = "Ready";
	} // Constructor
  
	public void requestToSend ()
	{ 
		actions[0] = "Packet with seqNo = " + sender.getS () + " was sent.";
		actions[1] = "Timer was started.";
		sender.setTimer (true);
		sender.setState (sender.getBlocking());
		nextState = "Blocking";
		actions[2] = "Window: S = " + sender.getS();
		status = new StopAndWaitStatus ("Stop and Wait Protocol: Sender Site");
		status.show (curState, nextState,  actions);
	} // End requestToSend
          
	public void timeout ()
	{
		actions[0] = "The event is not supported; we are in the ready state. ";
		actions[1] = null;
		sender.setState (sender.getReady());
		nextState = "Ready";
		actions[2] = "Window: S = " +sender.getS();
		status = new StopAndWaitStatus ("Stop and Wait Protocol: Sender Site");
		status.show (curState, nextState,  actions);
	} // End timeout

	public void errorFreeACK (int ackNo)
	{
		actions[0] = "The event is not supported; we are in the ready state. ";
		actions[1] = null;
		sender.setState (sender.getReady());
		nextState = "Ready";
		actions[2] = "Window: S = " +sender.getS();
		status = new StopAndWaitStatus ("Stop and Wait Protocol: Sender Site");
		status.show (curState, nextState,  actions);
	} // End errorFreeAck
             
	public void corruptedACK ()
	{
		actions[0] = "The event is not supported; we are in the ready state. ";
		actions[1] = null;
		sender.setState (sender.getReady());
		nextState = "Ready";
		actions[2] = "Window: S = " +sender.getS();
		status = new StopAndWaitStatus ("Stop and Wait Protocol: Sender Site");
		status.show (curState, nextState,  actions);
	} // End corruptedACK
        
} // End class    