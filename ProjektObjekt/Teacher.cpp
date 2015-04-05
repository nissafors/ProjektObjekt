#include "stdafx.h"
#include "Teacher.h"

Teacher::Teacher(String^ username)
{
	_username = username;
	_userType = _user_t::teacher;
	_salary = 0;
	readFromDB();
}

int Teacher::getSalary()
{
	return _salary;
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
