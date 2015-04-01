#include "stdafx.h"
#include "Student.h"

Student::Student(String^ username)
{
	readFromDB();
}

int Student::getPoints()
{
	return _points;
}

void Student::readFromDB()
{
	_username = "user";
	_name = "Projekt Objekt";
	_userType = _user_t::student;
	_points = 30;
}
