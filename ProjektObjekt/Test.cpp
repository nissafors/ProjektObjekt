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

void Test::saveAnswers(Int64 socSecNo)
{
	// Get db command
	dbHandler dbh;
	DbCommand^ cmd = dbh.getCommand();


	// Loop through pages in test and
	String^ answer;
	Page^ pageToSave;
	for (int i = 0; i < _numberOfPages; i++)
	{
		pageToSave = _pages->at(i);

		// Get page's answer into a string (if any)
		if (pageToSave->getPageType() == page_t::multipleChoice)
		{
			MultipleChoicePage^ mcPageToSave = dynamic_cast<MultipleChoicePage^>(pageToSave);
			vector<int>^ mcAnswers = mcPageToSave->getAnswer();
			answer = String::Join(", ", mcAnswers);
		}
		else if (pageToSave->getPageType() == page_t::write)
		{
			WritePage^ wPageToSave = dynamic_cast<WritePage^>(pageToSave);
			answer = wPageToSave->getAnswer();
		}
		else
		{
			answer = "";
		}

		// Write string to db
		if (pageToSave->getPageType() == page_t::multipleChoice || pageToSave->getPageType() == page_t::write)
		{
			cmd->CommandText = "INSERT INTO TentaSvar (personNr, exKod, sidNr, svarsText) SELECT @socSecNo, @exCode, @pageNo, @answer";
			cmd->Parameters->Add(gcnew SqlParameter("@socSecNo", SqlDbType::BigInt));
			cmd->Parameters["@socSecNo"]->Value = socSecNo;
			cmd->Parameters->Add(gcnew SqlParameter("@exCode", SqlDbType::Int));
			cmd->Parameters["@exCode"]->Value = _examinationCode;
			cmd->Parameters->Add(gcnew SqlParameter("@pageNo", SqlDbType::Int));
			cmd->Parameters["@pageNo"]->Value = pageToSave->getPageNumber();
			cmd->Parameters->Add(gcnew SqlParameter("@answer", SqlDbType::Text));
			cmd->Parameters["@answer"]->Value = answer;
			cmd->ExecuteNonQuery();

			// Clear cmd for reuse
			cmd->Parameters->Clear();
		}
	}

	// TODO: Unlink student from this test
}

int Test::getNumberOfPages()
{
	return _numberOfPages;
}

int Test::getExaminationCode()
{
	return _examinationCode;
}
