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
	
	// To be replaced with actual database call:
	String^ dbPassword = "pass";
	_user_t dbUserType = _user_t::student;

	// Compare passwords
	if (String::Compare(password, dbPassword) == 0)
	{
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
