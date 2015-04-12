#pragma once
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

ref class Room
{
public:
	Room(int roomNr, int seats) :_roomNr(roomNr), _seats(seats){}
	
	static vector<Room^>^ getAllRooms()
	{
		dbHandler dbh;
		DbCommand^ cmd = dbh.getCommand();
		vector<Room^> ^_roomVector = gcnew vector<Room^>();
		cmd->CommandText = "SELECT Lokal.* FROM Lokal";
		DbDataReader^ reader = cmd->ExecuteReader();
		while (reader->Read())
			_roomVector->push_back(gcnew Room(reader->GetInt32(0), reader->GetInt32(1)));
		reader->Close();
		return _roomVector;
	}

	int getRoomNr() 
	{ 
		return _roomNr; 
	}
	int getSeats() 
	{ 
		return _seats; 
	}
private:
	int _roomNr;
	int _seats;
};

