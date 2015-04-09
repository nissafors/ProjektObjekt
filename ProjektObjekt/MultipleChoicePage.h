#pragma once
#include "Page.h"
#include <cliext/vector>
using namespace cliext;

ref class MultipleChoicePage : public Page
{
public:
	MultipleChoicePage(String^ text, int pageNumber, int examinationCode);
	vector<String^>^ getOptions();
	int getAnswer();
	void setAnswer(int answer);
private:
	int _answer;
	vector<String^>^ _options = gcnew cliext::vector<String^>();
};

