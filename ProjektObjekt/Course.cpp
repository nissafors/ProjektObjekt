#include "stdafx.h"
#include "Course.h"

// Constructor
Course::Course(String^ name, int courseId, int chiefId, int chiefExtra, DateTime startDate, DateTime endDate)
	: _name(gcnew String(name)), _courseId(courseId), _chiefId(chiefId), _chiefExtra(chiefExtra), _startDate(startDate), _endDate(endDate)
{
}

// Getters
String^ Course::name()
{
	return _name;
}

int Course::courseId()
{
	return _courseId;
}

String^ Course::chiefId()
{
	return _chiefId.ToString();
}

String^ Course::chiefExtra()
{
	return _chiefExtra.ToString();
}

String^ Course::startDate() 
{ 
	return _startDate.Year.ToString() + " " + _startDate.Month.ToString() + " " + _startDate.Day.ToString(); 
}

String^ Course::endDate() 
{ 
	return _endDate.Year.ToString() + " " + _endDate.Month.ToString() + " " + _endDate.Day.ToString();
}

String^ Course::nmbrOfStud()
{
	return _nmbrOfStud.ToString();
}

// Return a vector of all Course objects that can be constructed from database
vector<Course^>^ Course::getAllCourses(DbCommand^ cmd)
{
	cmd->CommandText = "SELECT * FROM [dbo].[Kurs] ";
	DbDataReader^ reader = cmd->ExecuteReader();
	vector<Course^> ^clp = gcnew vector<Course^>();
	while (reader->Read())
		clp->push_back(gcnew Course(reader->GetString(0), reader->GetInt32(1), reader->GetInt32(2), reader->GetInt32(3),
		reader->GetDateTime(4), reader->GetDateTime(5)));

	reader->Close();
	return clp;
}
