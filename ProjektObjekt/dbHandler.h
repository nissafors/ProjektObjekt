#pragma once

//using namespace System;
//using namespace System::ComponentModel;
//using namespace System::Collections;
//using namespace System::Windows::Forms;
using namespace System::Data;
//using namespace System::Drawing;
using namespace System::Data::Common;
//using namespace System::Configuration;
using namespace System::Data::SqlClient;

ref class dbHandler
{
public:
	dbHandler();
	~dbHandler();
	DbCommand^ getCommand();
	void closeConnection();
private:
	DbProviderFactory^ _factory;
	DbConnection^ _connection;
	DbCommand^ _command;
};

