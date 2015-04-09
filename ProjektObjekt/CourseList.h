#include "stdafx.h"
#include "dbHandler.h"
#include <cliext\vector>
using namespace cliext;
using namespace System;
#pragma once


//ref class ShowTestsForm;
ref class CourseList
{
public:
	CourseList(String^ name, int courseId, int chiefId, int chiefExtra, DateTime startDate, DateTime endDate);//, int nmbrOfStud);
	String^ name();
	String^ courseId();
	String^ chiefId();
	String^ chiefExtra();
	String^ startDate();
	String^ endDate();
	String^ nmbrOfStud();
	static vector<CourseList^>^ getAllCourses(DbCommand^ cmd);

private:
	String^ _name;
	int _courseId, _chiefId, _chiefExtra, _nmbrOfStud;
	DateTime _startDate, _endDate;
	//ShowTestsForm^ _tf;


};


