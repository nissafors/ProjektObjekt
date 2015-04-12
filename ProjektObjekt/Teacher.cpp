#include "stdafx.h"
#include "Teacher.h"

Teacher::Teacher()
{
	_username = "";
	_userType = _user_t::teacher;
	_salary = 0;
	_employeeNumber = 0;
}

Teacher::Teacher(String^ username)
{
	_username = username;
	_userType = _user_t::teacher;
	_salary = 0;
	_employeeNumber = 0;
	readFromDB();
}

int Teacher::getSalary()
{
	return _salary;
}

int Teacher::getEmployeeNumber()
{
	return _employeeNumber;
}

void Teacher::readFromDB()
{
	// Query database
	dbHandler dbh;
	DbCommand^ command = dbh.getCommand();
	command->CommandText = "SELECT namn, lön FROM [dbo].[Personal] WHERE username=@user";
	command->Parameters->Add(gcnew SqlParameter("@user", SqlDbType::Char));
	command->Parameters["@user"]->Value = _username;
	DbDataReader^ reader = command->ExecuteReader();
	reader->Read();
	_name = reader->GetString(0);
	if (!reader->IsDBNull(1))
		_salary = reader->GetInt16(1);
	reader->Close();
}

vector<Teacher^>^ Teacher::getAllTeachers()
{
	dbHandler dbh;
	DbCommand^ command = dbh.getCommand();
	command->CommandText = "SELECT namn, lön, anstNr FROM Personal";
	DbDataReader^ reader = command->ExecuteReader();
	vector<Teacher^>^ allTeachers = gcnew vector<Teacher^>();
	Teacher^ teacher;
	while (reader->Read())
	{
		teacher = gcnew Teacher();
		teacher->_name = reader->GetString(0);
		teacher->_salary = reader->GetInt32(1);
		teacher->_employeeNumber = reader->GetInt32(2);
		allTeachers->push_back(teacher);
		delete teacher;
	}

	return allTeachers;
}
