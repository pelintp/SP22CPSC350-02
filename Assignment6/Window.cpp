#include "Window.h"

#include "Student.h"

Window::Window(int id) : isOccupied(false), id(id), student(nullptr)
{
	idleTime = studentTime = workTime = 0;
}

int Window::getIdleTime() { return idleTime; }

void Window::setIdleTime() { idleTime++; }

bool Window::occupied() { return isOccupied; }

void Window::greetStudent(Student* student)
{
	isOccupied = true;

	this->student = student;

	studentTime = student->getSessionTime();
}

bool Window::registerStudent()
{
	++workTime;

	return workTime == studentTime;
}

Student* Window::endSession()
{
	isOccupied = false;

	workTime = 0;

	return student;
}

void Window::goodByeStudent() { student = nullptr; }






