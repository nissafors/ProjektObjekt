#include "stdafx.h"
#include "Page.h"

Page::Page(String^ text, int pageNumber) : _text(text), _pageNumber(pageNumber)
{
}

Page::~Page()
{
}

int Page::getPageNumber()
{
	return _pageNumber;
}

String^ Page::getText()
{
	return _text;
}

page_t Page::getPageType()
{
	return _pageType;
}
