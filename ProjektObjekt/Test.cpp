#include "stdafx.h"
#include "Test.h"
//#include "InfoPage.h"
//#include "WritePage.h"
//#include "MultipleChoicePage.h"

Test::Test(int examinationCode) : _examinationCode(examinationCode)
{
	//_pages = gcnew cliext::vector<Page^>();
	// TODO: Read pages from db
	dbHandler dbh;
	DbCommand^ cmd = dbh.getCommand();
	cmd->CommandText = "SELECT sidNr, sidText, typ FROM Sida WHERE exKod = @exCode ORDER BY sidNr";
	cmd->Parameters->Add(gcnew SqlParameter("@exCode", SqlDbType::Int));
	cmd->Parameters["@exCode"]->Value = examinationCode;
	DbDataReader^ reader = cmd->ExecuteReader();
	while (reader->Read())
	{
		//int page = reader->GetInt32(0);
		//String^ text = reader->GetString(1);
		//String^ type = reader->GetString(2);
		//if (String::Compare(type, "info") == 0)
		//{
		//	_pages->push_back(gcnew InfoPage(text, page));
		//}
		//else if (String::Compare(type, "flerval") == 0)
		//{
		//	_pages->push_back(gcnew MultipleChoicePage(text, page, _examinationCode));
		//}
		//else
		//{
		//	_pages->push_back(gcnew WritePage(text, page));
		//}
	}
}
