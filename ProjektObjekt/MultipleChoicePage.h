#pragma once
#include "Page.h"
#include <cliext/vector>

ref class MultipleChoicePage : public Page
{
public:
	MultipleChoicePage(String^ text, int pageNumber, int examinationCode);
	cliext::vector<String^>^ getOptions();
	int getAnswer();
	void setAnswer(int answer);
private:
	int _answer;
	cliext::vector<String^>^ _options;
};

