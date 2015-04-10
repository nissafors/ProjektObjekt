#pragma once
#include <cliext/vector>
#include "InfoPage.h"
#include "WritePage.h"
#include "MultipleChoicePage.h"
using namespace cliext;

ref class Test
{
public:
	Test(int examinationCode);
	Page^ getFirstPage();
	Page^ getNextPage(int &pageIndex);
	Page^ getPreviousPage(int &pageIndex);
	void saveAnswers(Int64 socSecNo);
	int getNumberOfPages();
	int getExaminationCode();
private:
	int _examinationCode = 0;
	int _currentPageIndex = 0;
	int _numberOfPages = 0;
	vector<Page^>^ _pages = gcnew vector<Page^>;
};