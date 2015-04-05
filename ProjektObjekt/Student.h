#pragma once
#include "User.h"

public ref class Student : public User
{
public:
	Student(String^ username);
	int getPoints();
protected:
	void readFromDB() override;
private:
	int _points;
};

