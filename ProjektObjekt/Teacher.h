#pragma once
#include "User.h"

public ref class Teacher : public User
{
public:
	Teacher(String^ username);
	int getSalary();
	void readFromDB() override;
private:
	int _salary;
};

