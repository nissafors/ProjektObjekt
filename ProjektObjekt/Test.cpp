#include "stdafx.h"
#include "Test.h"

Test::Test(int examinationCode) : _examinationCode(examinationCode)
{
	// Read pages from db
	dbHandler dbh;
	DbCommand^ cmd = dbh.getCommand();
	cmd->CommandText = "SELECT sidNr, sidText, typ FROM Sida WHERE exKod = @exCode ORDER BY sidNr";
	cmd->Parameters->Add(gcnew SqlParameter("@exCode", SqlDbType::Int));
	cmd->Parameters["@exCode"]->Value = examinationCode;
	DbDataReader^ reader = cmd->ExecuteReader();
	
	// Push pages into a Page vector using dynamic binding
	while (reader->Read())
	{
		_numberOfPages++;
		int page = reader->GetInt32(0);
		String^ text = reader->GetString(1);
		String^ type = reader->GetString(2);
		if (type->StartsWith("info"))
		{
			_pages->push_back(gcnew InfoPage(text, page));
		}
		else if (type->StartsWith("flerval"))
		{
			_pages->push_back(gcnew MultipleChoicePage(text, page, _examinationCode));
		}
		else
		{
			_pages->push_back(gcnew WritePage(text, page));
		}
	}
}

Page^ Test::getFirstPage()
{
	if (_pages->size() > 0)
	{
		return _pages->at(0);
	}
	else
		return nullptr;
}

// pageIndex will be set to _currentPageIndex in case the Page's own pageNumber is off.
Page^ Test::getNextPage(int &pageIndex)
{
	if (_pages->size() > 0)
	{
		if (_currentPageIndex + 1 >= _pages->size())
		{
			pageIndex = _currentPageIndex;
			return _pages->at(_currentPageIndex);
		}
		else
		{
			pageIndex = ++_currentPageIndex;
			return _pages->at(_currentPageIndex);
		}
	}
	else
		return nullptr;
}

// pageIndex will be set to _currentPageIndex in case the Page's own pageNumber is off.
Page^ Test::getPreviousPage(int &pageIndex)
{
	if (_pages->size() > 0)
	{
		if (_currentPageIndex - 1 < 0)
		{
			pageIndex = _currentPageIndex;
			return _pages->at(_currentPageIndex);
		}
		else
		{
			pageIndex = --_currentPageIndex;
			return _pages->at(_currentPageIndex);
		}
	}
	else
		return nullptr;
}

int Test::getNumberOfPages()
{
	return _numberOfPages;
}