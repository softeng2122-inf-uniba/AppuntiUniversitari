package PriorityQueue;

import PriorityQueue.Enum.State;

public class Process {

	private String path;
	private int priority;
	private int id;
	private State state;

	public Process(String path, int priority) {
		this.path = path;
		this.priority = priority;
		this.id = path.hashCode();
		this.state = State.UNRUNNABLE;
	}

	public int getId() {
		return id;
	}

	public void setState() {
		if (this.state.equals(State.UNRUNNABLE))
			this.state = State.RUNNABLE;
		else if (this.state.equals(State.RUNNABLE))
			this.state = State.STOP;
		else if (this.state.equals(State.STOP))
			this.state = State.UNRUNNABLE;
	}

	public String getPath() {
		return path;
	}

	public State getState() {
		return state;
	}

	public int getPriority() {
		return priority;
	}

	public String toString() {

		return "Path: " + this.getPath() + " Priority: " + this.getPriority()
				+ " ID: " + this.getId() + " State: " + this.getState();

	}

}
