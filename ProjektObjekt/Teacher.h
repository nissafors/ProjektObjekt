#pragma once
#include "User.h"
#include <cliext/vector>
using namespace cliext;

public ref class Teacher : public User
{
public:
	Teacher();
	Teacher(String^ username);
	int getSalary();
	int getEmployeeNumber();
	static vector<Teacher^>^ getAllTeachers();
protected:
	void readFromDB() override;
private:
	int _employeeNumber;
	int _salary;
};

