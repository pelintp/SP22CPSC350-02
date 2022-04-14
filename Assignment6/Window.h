#ifndef WINDOW_H
#define WINDOW_H

class Student; // Forward Class Declaration

class Window
{
public:
	Window(int id = 0);
	
	int getIdleTime();
	void setIdleTime();
	
	bool occupied();
	
	void greetStudent(Student* student);

	bool registerStudent();
	
	Student* endSession();

	void goodByeStudent();

private:
	bool isOccupied;
	
	int id;

	int idleTime;
	int studentTime;
	int workTime;
	
	Student* student;

};
#endif
