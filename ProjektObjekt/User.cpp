#include "stdafx.h"
#include "User.h"
#include "Student.h"
#include "Teacher.h"

User::User()
{
}

User^ User::getUser(String^ username, String^ password)
{
	// Get user from db where username is primary key.
	// dbUserType controls what kind of User derived object we will return.
	
	// Get password for username from db
	dbHandler dbh;
	String^ dbPassword;
	DbCommand^ command = dbh.getCommand();
	command->CommandText = "SELECT pass FROM [dbo].[Användare] WHERE username=@user";
	command->Parameters->Add(gcnew SqlParameter("@user", SqlDbType::Char));
	command->Parameters["@user"]->Value = username;
	DbDataReader^ reader = command->ExecuteReader();
	reader->Read();
	if (reader->HasRows)
	{
		// Found user, get password
		dbPassword = reader->GetString(0);
		reader->Close();
	}
	else
	{
		// No such user: abort
		reader->Close();
		command->Parameters->Clear();
		return nullptr;
	}

	// Compare passwords
	if (String::Compare(password, dbPassword) == 0)
	{
		// Password ok. Find out if user is teacher or student
		_user_t dbUserType;
		command->CommandText = "SELECT anstNr FROM [dbo].[Personal] WHERE username=@user";
		reader = command->ExecuteReader();
		reader->Read();
		if (reader->HasRows)
			dbUserType = _user_t::teacher;
		else
			dbUserType = _user_t::student;
		reader->Close();
		command->Parameters->Clear();

		// Return new subclass of User
		if (dbUserType == _user_t::student)
		{
			return gcnew Student(username);
		}
		else
		{
			return gcnew Teacher(username);
		}
	}
	else
	{
		// Password incorrect
		return nullptr;
	}
}

User::~User()
{
}

String^ User::getUsername()
{
	return _username;
}

String^ User::getName()
{
	return _name;
}

_user_t User::getUserType()
{
	return _userType;
}
