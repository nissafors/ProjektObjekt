#include "stdafx.h"
#include "CourseList.h"


CourseList::CourseList(String^ name, int courseId, int chiefId, int chiefExtra, DateTime startDate, DateTime endDate)/*, int nmbrOfStud)*/ :
_name(gcnew String(name)), _courseId(courseId), _chiefId(chiefId), _chiefExtra(chiefExtra), _startDate(startDate), _endDate(endDate)//, _nmbrOfStud(nmbrOfStud)
{
}
String^ CourseList::name() { return _name; }

String^ CourseList::courseId() { return _courseId.ToString(); }

String^ CourseList::chiefId() { return _chiefId.ToString(); }

String^ CourseList::chiefExtra() { return _chiefExtra.ToString(); }

String^ CourseList::startDate() 
{ 
	return _startDate.Year.ToString() + " : " + _startDate.Month.ToString() + " : " + _startDate.Day.ToString(); 
}

String^ CourseList::endDate() 
{ 
	return _endDate.Year.ToString() + " : " + _endDate.Month.ToString() + " : " + _endDate.Day.ToString();; 
}

String^ CourseList::nmbrOfStud() { return _nmbrOfStud.ToString(); }

vector<CourseList^>^ CourseList::getAllCourses(DbCommand^ cmd)
{
	cmd->CommandText = "SELECT * FROM [dbo].[Kurs] ";
	DbDataReader^ reader = cmd->ExecuteReader();
	vector<CourseList^> ^clp = gcnew vector<CourseList^>();
	while (reader->Read())
		clp->push_back(gcnew CourseList(reader->GetString(0), reader->GetInt32(1), reader->GetInt32(2), reader->GetInt32(3),
		reader->GetDateTime(4), reader->GetDateTime(5)));// , reader->GetInt32(6)));

	reader->Close();
	return clp;
}
