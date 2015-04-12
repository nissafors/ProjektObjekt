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
	static vector<Teacher^>^ getAllTeachers()
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

protected:
	void readFromDB() override;
private:
	int _salary;
	int _employeeNumber;
};
