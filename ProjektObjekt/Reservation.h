#pragma once
#pragma once
#include "stdafx.h"
#include <cliext\vector>
#include "dbHandler.h"
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
ref class Reservation
{
public:
	Reservation(int id, int courseKod, int employeId, String^ date, String^ startTime, String^ endTime, String^ type, int roomNr) : _id(id), _courseKod(courseKod),
		_employeId(employeId), _date(date), _startTime(startTime), _endTime(endTime), _type(type), _roomNr(roomNr) {	}

	// Hämtar alla bokningar på ett visst datum
	static vector<Reservation^> ^  getReservation(String ^date)
	{
		vector<Reservation^> ^ _reservationsVector = gcnew vector<Reservation^>();
		dbHandler dbh;
		DbCommand^ cmd = dbh.getCommand();
		cmd->CommandText = "SELECT UndervisningsMoment.* FROM UndervisningsMoment WHERE UndervisningsMoment.datum = @date ORDER BY UndervisningsMoment.startTid, UndervisningsMoment.salsNr";
		
		// Hämtar datum och lägger in den som ett datevärde
		cmd->Parameters->Add(gcnew SqlParameter("@date", SqlDbType::Date));
		cmd->Parameters["@dat"]->Value = date;
		DbDataReader^ reader = cmd->ExecuteReader();
		while (reader->Read())
		{
			String^ readDate = reader->GetDateTime(6).Year.ToString() + "-";
			String ^month = reader->GetDateTime(6).Month.ToString();
			if (month->Length != 2) 
				readDate += "0";
			readDate+= month + "-";
			month = reader->GetDateTime(6).Day.ToString(); // lägg till en 0:a på dag ifall dag < 10
			if (month->Length != 2)
				readDate += "0";
			readDate += month;
			
			// Konverterar tid till en sträng på formen hh:ss från hh:ss::mm
			TimeSpan^ ts = (TimeSpan^)(reader->GetValue(4));
			String^ startTimeString = ts->ToString()->Substring(0, 5);
			ts = (TimeSpan^)(reader->GetValue(5));
			String^ endTimeString = ts->ToString()->Substring(0, 5);
			//
			_reservationsVector->push_back(gcnew Reservation(reader->GetInt32(0), reader->GetInt32(1), reader->GetInt32(2), readDate, startTimeString, endTimeString, reader->GetString(3), reader->GetInt32(7)));
		}
		reader->Close();
		cmd->Parameters->Clear();
		return _reservationsVector;
	}
	
	String^ getCourseName()
	{
		dbHandler dbh;
		DbCommand^ cmd = dbh.getCommand();
		cmd->CommandText = "SELECT DISTINCT Kurs.namn FROM Kurs, UndervisningsMoment WHERE UndervisningsMoment.kursKod = @nr AND Kurs.kursKod = UndervisningsMoment.kursKod";
		cmd->Parameters->Add(gcnew SqlParameter("@nr", SqlDbType::Int));
		cmd->Parameters["@nr"]->Value = _courseKod;
		DbDataReader^ reader = cmd->ExecuteReader();
		reader->Read();
		String^ name = reader->GetString(0);
		reader->Close();
		cmd->Parameters->Clear();
		return name;
	}
	String^ getDate()
	{
		return _date;
	}

	String^ getStartTime()
	{
		return _startTime;
	}

	String^ getEndTime()
	{
		return _endTime;
	}

	int getRoom()
	{
		return _roomNr;
	}

	String^ getType()
	{
		return _type;
	}

private:
	int _id;
	int _courseKod;
	int _employeId;
	int _roomNr;
	String^ _date;
	String^ _startTime;
	String^ _endTime;
	String^ _type;
	

};


