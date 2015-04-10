#pragma once
#include "Page.h"

ref class WritePage : public Page
{
public:
	WritePage(String^ text, int pageNumber);
	String^ getAnswer();
	void setAnswer(String^ answer);
private:
	String^ _answer;
};