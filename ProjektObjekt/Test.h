#pragma once
#include <cliext/vector>
#include "Page.h"

ref class Test
{
public:
	Test(int examinationCode);
	//Page^ getPage(int pageNumber);
private:
	int _examinationCode;
	//cliext::vector<Page^>^ _pages;
};