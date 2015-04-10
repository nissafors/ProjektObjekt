#pragma once
#include "Page.h"
#include <cliext/vector>
using namespace cliext;

ref class MultipleChoicePage : public Page
{
public:
	MultipleChoicePage(String^ text, int pageNumber, int examinationCode);
	vector<String^>^ getOptions();
	vector<int>^ getAnswer();
	void setAnswer(vector<int>^ answer);
private:
	vector<int>^ _answer = gcnew cliext::vector<int>();
	vector<String^>^ _options = gcnew cliext::vector<String^>();
};

