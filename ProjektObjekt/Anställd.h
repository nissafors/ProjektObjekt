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

ref class Anställd
{
public:
	// Constructor
	Anställd (int id, String ^ förnamn, String ^ efternamn, String ^ personnummer)
		: _id(id), _förnamn(gcnew String(förnamn)), _efternamn(gcnew String(efternamn)), _personnummer(gcnew String(personnummer))
	{
	}

	// Getters
	String ^ förnamn()
	{
		return _förnamn;
	}

	String ^ efternamn()
	{
		return _efternamn;
	}

	int id()
	{
		return _id;
	}

	// Read förnamn from database
	//static String ^ hämtaFörnamn(DbCommand^ cmd, int sid)
	//{
	//	cmd->CommandText = "SELECT * FROM [dbo].[Anställd] WHERE id=@sid";
	//	cmd->Parameters->Add(gcnew SqlParameter("@sid", SqlDbType::Int));
	//	cmd->Parameters["@sid"]->Value = sid;
	//	DbDataReader^ reader = cmd->ExecuteReader();
	//	reader->Read();
	//	String ^returner = reader->GetString(1);
	//	reader->Close();
	//	cmd->Parameters->Clear();
	//	return returner;
	//}
	
	// Read everything Anställd related from DB
	//static vector<Anställd^>^ hämtaAlla(DbCommand^ cmd)
	//{
	//	cmd->CommandText="SELECT * FROM [dbo].[Anställd] ";
	//	DbDataReader^ reader = cmd->ExecuteReader();
	//	vector<Anställd^> ^jv = gcnew vector<Anställd^>();
	//	while (reader->Read())
	//		jv->push_back(gcnew Anställd(reader->GetInt16(0), reader->GetString(1), reader->GetString(2), reader->GetString(3)));
	//	reader->Close();
	//	return jv;
	//}

private:
	int _id;
	String ^ _förnamn;
	String ^ _efternamn;
	String ^ _personnummer;

};