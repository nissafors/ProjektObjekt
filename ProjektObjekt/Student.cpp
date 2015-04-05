#include "stdafx.h"
#include "Student.h"

Student::Student(String^ username)
{
	_username = username;
	_userType = _user_t::student;
	_points = 0;
	readFromDB();
}

int Student::getPoints()
{
	return _points;
}

void Student::readFromDB()
{
	// Query database
	dbHandler dbh;
	DbCommand^ command = dbh.getCommand();
	command->CommandText = "SELECT namn FROM [dbo].[Student] WHERE username=@user";
	command->Parameters->Add(gcnew SqlParameter("@user", SqlDbType::Char));
	command->Parameters["@user"]->Value = _username;
	DbDataReader^ reader = command->ExecuteReader();
	reader->Read();
	_name = reader->GetString(0);
	reader->Close();
}
