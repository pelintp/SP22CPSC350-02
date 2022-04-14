#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Simulation.h"

#include "Student.h"
#include "Window.h"

using namespace std;

Simulation::Simulation() : regWindow(nullptr), numWindows(0) {}

Simulation::~Simulation()
{
	while (!doneQueue.isEmpty())
	{
		delete doneQueue.front();

		doneQueue.pop();
	}

	delete[] regWindow;
}


//filename printing

void Simulation::run(const std::string& filename)
{
	ifstream fin(filename);

	fin >> numWindows;
	regWindow = new Window[numWindows]{};

	int clock = 0, tick = 0, numStudents = 0, registrants = 0;
	bool work = true;

	while (work)
	{
		if (clock > 1)
			incrementIdleTimes();

		clock++;

		incrementWorkTime();

		if (clock > tick)
		{
			if (!fin.eof())
				fin >> tick >> ws;
		}

		if (clock == tick)
		{
			if (!fin.eof())
				fin >> numStudents >> ws;

			for (int i = 0; i < numStudents; i++)
			{
				if (!fin.eof())
				{
					int studentTime = 0;

					fin >> studentTime >> ws;

					waitQueue.push(new Student(++registrants, studentTime));
				}
			}
		}

		while (!waitQueue.isEmpty())
		{
			int winNumber = checkForOpenWindow();

			if (winNumber != -1)
			{
				regWindow[winNumber].greetStudent(waitQueue.front());

				waitQueue.pop();
			}
			else
			{
				incrementStudentWaitTimes();

				break;
			}

		}

		if (waitQueue.isEmpty() && allWindowsOpen())
		{
			work = false;
			continue;
		}

	}

	printMetrics();
}


// dusing the private functions here

bool Simulation::allWindowsOpen()
{
	int count = 0;
	for (int i = 0 ; i < numWindows; i++)
	{
		if (!regWindow[i].occupied())
			count++;
	}

	return count == numWindows;
}

bool Simulation::allWindowsOccupied()
{
	int count = 0;
	for (int i = 0; i < numWindows; i++)
	{
		if (regWindow[i].occupied())
			count++;
	}

	return count == numWindows;
}

int Simulation::checkForOpenWindow()
{
	for (int i = 0; i < numWindows; i++)
	{
		if (!regWindow[i].occupied())
			return i;
	}

	return -1;
}

void Simulation::incrementIdleTimes()
{
	// Set unoccupied windows idle time
	for (int i = 0; i < numWindows; i++)
	{
		if (!regWindow[i].occupied())
			regWindow[i].setIdleTime();
	}

}

void Simulation::incrementStudentWaitTimes()
{
	// Set students' wait time if they
	// are waiting in wait queue
	if (waitQueue.size() == 1)
	{
		waitQueue.front()->setWaitTime();
	}
	else
	{
		for (int i = 0; i < waitQueue.size(); i++)
		{
			Student* s = waitQueue.front();

			s->setWaitTime();

			waitQueue.pop();

			waitQueue.push(s);
		}
	}

}

void Simulation::incrementWorkTime()
{
	for (int i = 0; i < numWindows; i++)
	{
		if (regWindow[i].occupied())
		{
			bool isDone = regWindow[i].registerStudent();

			if (isDone)
			{
				doneQueue.push(regWindow[i].endSession());

				regWindow[i].goodByeStudent();
			}
		}
	}

}

void Simulation::printMetrics()
{
	int max = 0, sum = 0, studentID = 0, tenMinutesWait = 0;

	int numStudents = doneQueue.size();

	int* waitTimes = new int[numStudents] {};

	for (int i = 0; i < doneQueue.size(); i++)
	{
		Student* s = doneQueue.front();

		waitTimes[i] = s->getWaitTime();

		if (s->getWaitTime() > max)
		{
			max = s->getWaitTime();

			studentID = s->getStudentID();
		}

		if (s->getWaitTime() > 10)
			tenMinutesWait++;

		sum += s->getWaitTime();

		doneQueue.pop();

		doneQueue.push(s);
	}

	double mean = static_cast<double>(sum / static_cast<double>(doneQueue.size()));

	sort(waitTimes, waitTimes + numStudents);

	int median = 0;
	if (numStudents % 2 == 0)
		median = waitTimes[numStudents / 2];
	else
		median = waitTimes[(numStudents+1) / 2];

	cout << fixed << setprecision(2) << "mean student wait time in queue: " << mean << endl;
	cout << fixed << setprecision(2) << "median student wait time in queue: " << median << endl;
	cout << fixed << setprecision(2) << "longest student wait time in queue: " << max << endl;
	cout << fixed << setprecision(2) << "no. of students waiting > 10 ticks: " << tenMinutesWait << endl;

	delete[] waitTimes;

	max = sum = 0;

	int	windowID = 0, fiveMinutesWait = 0;
	for (int i = 0; i < numWindows; i++)
	{
		if (regWindow[i].getIdleTime() > max)
		{
			max = regWindow[i].getIdleTime();

			windowID = i + 1;
		}

		if (regWindow[i].getIdleTime() > 5)
			fiveMinutesWait++;


		if (regWindow[i].getIdleTime() > 0)
			sum += regWindow[i].getIdleTime();
	}

	mean = static_cast<double>(sum / static_cast<double>(numWindows));
	cout << fixed << setprecision(2) << "mean window idle time: " << mean << endl;
	cout << fixed << setprecision(2) << "longest window idle time: " << max << endl;
	cout << fixed << setprecision(2) << "no. of windows idle > 5 ticks: " << fiveMinutesWait << endl;


}
