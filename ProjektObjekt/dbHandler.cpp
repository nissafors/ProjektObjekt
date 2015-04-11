#include "stdafx.h"
#include "dbHandler.h"

dbHandler::dbHandler()
{
	_factory = DbProviderFactories::GetFactory("System.Data.SqlClient");
}

dbHandler::~dbHandler() {
	closeConnection();
}

DbCommand^ dbHandler::getCommand()
{
	// Get connection
	_connection = _factory->CreateConnection();
	_connection->ConnectionString = "Data Source=MACBOOK-PRO;Initial Catalog=DBanan14hj;Integrated Security=False;User ID=anan14hj;Password=Jwcg998;Connect Timeout=15;Encrypt=False;TrustServerCertificate=False";
	//_connection->ConnectionString = "Data Source=NILSSONS_PC;Initial Catalog=DBnida1300;Integrated Security=False;User ID=nida1300;Password=Ecod558;Connect Timeout=15;Encrypt=False;TrustServerCertificate=False";
	//_connection->ConnectionString = "Data Source=FISKEN;Initial Catalog=DBguju1393;Integrated Security=False;User ID=guju1393;Password=guju1393;Connect Timeout=15;Encrypt=False;TrustServerCertificate=False";
	_connection->Open();
	
	// Create DB command
	_command = _factory->CreateCommand();
	_command->Connection = _connection;

	return _command;
}

void dbHandler::closeConnection()
{
	if (_connection != nullptr)
	{
		_connection->Close();
	}
}