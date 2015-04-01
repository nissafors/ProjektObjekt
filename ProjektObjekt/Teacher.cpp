#include "stdafx.h"
#include "Teacher.h"

Teacher::Teacher(String^ username)
{
}

int Teacher::getSalary()
{
	return _salary;
}

void Teacher::readFromDB()
{
	_username = "user";
	_name = "Projekt Objekt";
	_userType = _user_t::teacher;
	_salary = 30000;
}
