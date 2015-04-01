// Form.cpp : main project file.

#include "stdafx.h"
#include "Form.h"

using namespace ProjektObjekt;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form2());
	return 0;
}
