#include "stdafx.h"
#include "WritePage.h"

WritePage::WritePage(String^ text, int pageNumber) : Page(text, pageNumber)
{
	_pageType = page_t::write;
	_answer = "";
}

String^ WritePage::getAnswer()
{
	return _answer;
}

void WritePage::setAnswer(String^ answer)
{
	_answer = answer;
}
