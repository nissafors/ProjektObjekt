#include "stdafx.h"
#include <cliext\vector>
using namespace System;
using namespace cliext;



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::Common;
	using namespace System::Configuration;
	using namespace System::Data::SqlClient;





ref class Anst�lld
{

public:
	Anst�lld (int id, String ^ f�rnamn, String ^ efternamn,String ^ personnummer):
		_id(id),_f�rnamn(gcnew String(f�rnamn)), _efternamn(gcnew String(efternamn)),_personnummer(gcnew String(personnummer)) 
	{}
	String ^ f�rnamn()
	{
		return _f�rnamn;
	}
	String ^ efternamn()
	{
		return _efternamn;
	}
	int id()
	{
		return _id;
	}


	static String ^ h�mtaF�rnamn(DbCommand^ cmd, int sid)
	{
		cmd->CommandText="SELECT * FROM [dbo].[Anst�lld] WHERE id=@sid";
		cmd->Parameters->Add(gcnew SqlParameter("@sid", SqlDbType::Int));
		cmd->Parameters["@sid"]->Value=sid;
		DbDataReader^ reader = cmd->ExecuteReader();
		reader->Read();
		String ^returner = reader->GetString(1);
		reader->Close();
		cmd->Parameters->Clear();
		return returner;
   }
		static vector<Anst�lld^>^ h�mtaAlla(DbCommand^ cmd)
	{
		cmd->CommandText="SELECT * FROM [dbo].[Anst�lld] ";
		DbDataReader^ reader = cmd->ExecuteReader();
		vector<Anst�lld^> ^jv=gcnew vector<Anst�lld^>();
		while (reader->Read())
			jv->push_back(gcnew Anst�lld(reader->GetInt16(0),reader->GetString(1),reader->GetString(2),reader->GetString(3)));
		reader->Close();
		return jv;
   }


private:
	int _id;
	String ^ _f�rnamn;
	String ^ _efternamn;
	String ^ _personnummer;

};