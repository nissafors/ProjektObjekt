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
{public:
//	Jobb(int id,int tids�tg�ng,int kontoId, int anst�lldId)
	Jobb(int id, String ^ beskrivning,int tids�tg�ng,int kontoId, int anst�lldId)
		:_id(id),_beskrivning(gcnew String(beskrivning)), _tids�tg�ng(tids�tg�ng),_kontoId(kontoId),_anst�lldId(anst�lldId)
	{ _beskrivning= gcnew String(beskrivning);
	}
	String ^ beskrivning()
	{
		return _beskrivning;
	}
	int  tids�tg�ng()
	{
		return _tids�tg�ng;
	}
	int  anst�lldId()
	{
		return _anst�lldId;
	}
/*
	Jobb(const Jobb % other)
	{
		_id=other._id;
//5		_beskrivning=gcnew String(other._beskrivning);
		_tids�tg�ng=other._tids�tg�ng;
		_kontoId=other._kontoId;
		_anst�lldId=other._anst�lldId;
	}
*/

	static void spara(DbCommand^ cmd, String ^ beskrivning, int tids�tg�ng, int anst�lldId,int kontoId)
	{
			cmd->CommandText = "INSERT INTO [dbo].[Jobb] ([beskrivning], [tids�tg�ng], [anst�lldId], [kontoId]) VALUES (@beskrivning,@totaltid, @anstalld,@konto)";
			cmd->Parameters->Add(gcnew SqlParameter("@beskrivning", SqlDbType::VarChar));
			cmd->Parameters["@beskrivning"]->Value=beskrivning->ToString();
			cmd->Parameters->Add(gcnew SqlParameter("@totaltid", SqlDbType::Int));
			cmd->Parameters["@totaltid"]->Value=tids�tg�ng;
			cmd->Parameters->Add(gcnew SqlParameter("@anstalld", SqlDbType::Int));
			cmd->Parameters["@anstalld"]->Value=anst�lldId;
			cmd->Parameters->Add(gcnew SqlParameter("@konto", SqlDbType::Int));
			cmd->Parameters["@konto"]->Value=kontoId;
			int i = cmd->ExecuteNonQuery();
			cmd->Parameters->Clear();
	}
	static vector<Jobb^>^ h�mtaAlla(DbCommand^ cmd)
	{
		cmd->CommandText="SELECT * FROM [dbo].[Jobb] ";
		DbDataReader^ reader = cmd->ExecuteReader();
		vector<Jobb^> ^jv=gcnew vector<Jobb^>();
		while (reader->Read())
			jv->push_back(gcnew Jobb(reader->GetInt16(0),reader->GetString(1),reader->GetInt32(2),reader->GetInt32(3),reader->GetInt32(4)));
		reader->Close();
		return jv;
   }
	static void deleteAll(DbCommand^ cmd)
	{
		cmd->CommandText="DELETE FROM [dbo].[Jobb] ";
			int i = cmd->ExecuteNonQuery();
		
	}
private:
	int _id;
	String ^ _beskrivning;
	int _tids�tg�ng;
	int _kontoId;
	int _anst�lldId;
};