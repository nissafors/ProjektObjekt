#pragma once
#include "User.h"

public ref class Student : public User
{
public:
	Student(String^ username);
	Int64 getSocSecNr();
protected:
	void readFromDB() override;
private:
	Int64 _socSecNr;
};

