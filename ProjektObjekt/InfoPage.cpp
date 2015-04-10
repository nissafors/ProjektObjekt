#include "stdafx.h"
#include "InfoPage.h"

InfoPage::InfoPage(String^ text, int pageNumber) : Page(text, pageNumber)
{
	_pageType = page_t::info;
}
