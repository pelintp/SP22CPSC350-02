#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>

#include "Queue.h"

// Forward Class Declarations
class Student; 
class Window;

class Simulation
{
public:
	Simulation();
	~Simulation();
	
	void run(const std::string& filename); //runs to simulation

private:
	bool allWindowsOpen();
	bool allWindowsOccupied();
	
	int checkForOpenWindow();
	
	void incrementIdleTimes();
	void incrementStudentWaitTimes();
	void incrementWorkTime();
	
	void printMetrics();
		
	Queue<Student*> waitQueue;
	Queue<Student*> doneQueue;

	Window* regWindow;
	int numWindows;
};
#endif
