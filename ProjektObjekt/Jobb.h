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

ref class Jobb
{
public:
	// Constructor
	Jobb(int id, String ^ beskrivning,int tidsåtgång,int kontoId, int anställdId)
		: _id(id), _beskrivning(gcnew String(beskrivning)), _tidsåtgång(tidsåtgång), _kontoId(kontoId), _anställdId(anställdId)
	{
		_beskrivning= gcnew String(beskrivning);
	}

	// Getters
	String ^ beskrivning()
	{
		return _beskrivning;
	}

	int  tidsåtgång()
	{
		return _tidsåtgång;
	}

	int  anställdId()
	{
		return _anställdId;
	}

	//// Write new Jobb to DB
	//static void spara(DbCommand^ cmd, String ^ beskrivning, int tidsåtgång, int anställdId, int kontoId)
	//{
	//	cmd->CommandText = "INSERT INTO [dbo].[Jobb] ([beskrivning], [tidsåtgång], [anställdId], [kontoId]) VALUES (@beskrivning,@totaltid, @anstalld,@konto)";
	//	cmd->Parameters->Add(gcnew SqlParameter("@beskrivning", SqlDbType::VarChar));
	//	cmd->Parameters["@beskrivning"]->Value = beskrivning->ToString();
	//	cmd->Parameters->Add(gcnew SqlParameter("@totaltid", SqlDbType::Int));
	//	cmd->Parameters["@totaltid"]->Value = tidsåtgång;
	//	cmd->Parameters->Add(gcnew SqlParameter("@anstalld", SqlDbType::Int));
	//	cmd->Parameters["@anstalld"]->Value = anställdId;
	//	cmd->Parameters->Add(gcnew SqlParameter("@konto", SqlDbType::Int));
	//	cmd->Parameters["@konto"]->Value = kontoId;
	//	int i = cmd->ExecuteNonQuery();
	//	cmd->Parameters->Clear();
	//}

	//// Read all Jobb's from DB
	//static vector<Jobb^>^ hämtaAlla(DbCommand^ cmd)
	//{
	//	cmd->CommandText="SELECT * FROM [dbo].[Jobb] ";
	//	DbDataReader^ reader = cmd->ExecuteReader();
	//	vector<Jobb^> ^jv = gcnew vector<Jobb^>();
	//	while (reader->Read())
	//		jv->push_back(gcnew Jobb(reader->GetInt16(0), reader->GetString(1), reader->GetInt32(2), reader->GetInt32(3), reader->GetInt32(4)));
	//	reader->Close();
	//	return jv;
	//}

	//// Delete all Jobb's from DB
	//static void deleteAll(DbCommand^ cmd)
	//{
	//	cmd->CommandText = "DELETE FROM [dbo].[Jobb] ";
	//	int i = cmd->ExecuteNonQuery();
	//}

private:
	int _id;
	String ^ _beskrivning;
	int _tidsåtgång;
	int _kontoId;
	int _anställdId;
};