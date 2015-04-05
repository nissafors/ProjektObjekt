#pragma once

using namespace System;

enum _user_t { teacher, student };

public ref class User abstract
{
public:
	User();
	static User^ getUser(String^ username, String^ password);
	virtual ~User();
	String^ getUsername();
	String^ getName();
	_user_t getUserType();
protected:
	virtual void readFromDB() = 0;
	String^ _username;
	String^ _name;
	_user_t _userType;
};

