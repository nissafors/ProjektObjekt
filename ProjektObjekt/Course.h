#pragma once
#include "stdafx.h"
#include "dbHandler.h"
#include <cliext\vector>
using namespace cliext;
using namespace System;

ref class Course
{
public:
	Course(String^ name, int courseId, int chiefId, int chiefExtra, DateTime startDate, DateTime endDate);
	String^ name();
	int courseId();
	String^ chiefId();
	String^ chiefExtra();
	String^ startDate();
	String^ endDate();
	String^ nmbrOfStud();
	static vector<Course^>^ getAllCourses(DbCommand^ cmd);
private:
	String^ _name;
	int _courseId, _chiefId, _chiefExtra, _nmbrOfStud;
	DateTime _startDate, _endDate;
};


