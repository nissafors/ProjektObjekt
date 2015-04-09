#include "stdafx.h"
#include "MultipleChoicePage.h"

MultipleChoicePage::MultipleChoicePage(String^ text, int pageNumber, int examinationCode)
	: Page(text, pageNumber)
{
	_pageType = page_t::multipleChoice;
	
	// Load _options from db
	dbHandler dbh;
	DbCommand^ cmd = dbh.getCommand();
	cmd->CommandText = "SELECT alternativText FROM Alternativ WHERE exKod = @exCode AND sidNr = @page ORDER BY alternativNr";
	cmd->Parameters->Add(gcnew SqlParameter("@exCode", SqlDbType::Int));
	cmd->Parameters["@exCode"]->Value = examinationCode;
	cmd->Parameters->Add(gcnew SqlParameter("@page", SqlDbType::Int));
	cmd->Parameters["@page"]->Value = _pageNumber;
	DbDataReader^ reader = cmd->ExecuteReader();
	while (reader->Read())
	{
		_options->push_back(reader->GetString(0));
	}
}

vector<String^>^ MultipleChoicePage::getOptions()
{
	return _options;
}

int MultipleChoicePage::getAnswer()
{
	return _answer;
}

void MultipleChoicePage::setAnswer(int answer)
{
	_answer = answer;
}
