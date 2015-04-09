#pragma once
using namespace System;

enum page_t { info, write, multipleChoice };

ref class Page abstract
{
public:
	Page(String^ text, int pageNumber);
	virtual ~Page();
	virtual int getPageNumber();
	virtual String^ getText();
	virtual page_t getPageType();
protected:
	int _pageNumber;
	String^ _text;
	page_t _pageType;
};

