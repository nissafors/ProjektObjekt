/*
 * This is the main form. Here's a map of the code structure:
 *	 #includes
 *	 namespace Forms
 *   {
 *       using namespace System;
 *       [...]
 *	     class Form2 : public Form
 *       {
 *           // Constructor and destructor
 *           Form2(void)
 *           ~Form2()
 *           // Properties for database handling
 *           DbProviderFactory^ fac;
 *           DbConnection^ conn;
 *           DbCommand^ cmd;
 *           // Forms component declarations. Don't touch! Use the designer window.
 *           private: System::Windows::Forms::Button^  button1;
 *           [...]
 *   #pragma region Windows Form Designer generated code
 *           // This is where GUI components are created. Don't touch!  Use the designer window.
 *           [...]
 *   #pragma endregion
 *           // Event handlers. These functions are called when the form is used, for example
 *           // when a button is clicked.
 *           [...]
 *       }; // End of class definition
 *   } // End of Forms namespace
 */

#pragma once

#include "LoginForm.h"

//#using <System.Data.Entity.dll>
//#include <cliext\vector>

namespace ProjektObjekt{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::Common;
	using namespace System::Configuration;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// This is the main form. From here a user may log in to the system. If the user is an
	/// administrator (s)he may edit the schedule. Student users can access their tests.
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		// Default constructor
		Form2(void)
		{
			InitializeComponent();
			_loggedIn = false;
		}

	protected:
		// Destructor
		~Form2()
		{
			if (components)
			{
				delete components;
			}

			if (conn != nullptr) conn->Close();
		}

	private:
		// For database connection and manipulation
		DbProviderFactory^ fac;
		DbConnection^ conn;
		DbCommand^ cmd;

		// Our own class members
		bool _loggedIn;

		// Windows forms components declarations

	private: System::Windows::Forms::Label^  currentUserLabel;
	private: System::Windows::Forms::Button^  logInOutButton;
	private: System::Windows::Forms::Button^  doStuffButton;
	private: System::Windows::Forms::Button^  exitButton;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->currentUserLabel = (gcnew System::Windows::Forms::Label());
			this->logInOutButton = (gcnew System::Windows::Forms::Button());
			this->doStuffButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// currentUserLabel
			// 
			this->currentUserLabel->AutoSize = true;
			this->currentUserLabel->Location = System::Drawing::Point(13, 13);
			this->currentUserLabel->Name = L"currentUserLabel";
			this->currentUserLabel->Size = System::Drawing::Size(94, 13);
			this->currentUserLabel->TabIndex = 0;
			this->currentUserLabel->Text = L"Current user: none";
			// 
			// logInOutButton
			// 
			this->logInOutButton->Location = System::Drawing::Point(12, 41);
			this->logInOutButton->Name = L"logInOutButton";
			this->logInOutButton->Size = System::Drawing::Size(276, 23);
			this->logInOutButton->TabIndex = 1;
			this->logInOutButton->Text = L"Log in";
			this->logInOutButton->UseVisualStyleBackColor = true;
			this->logInOutButton->Click += gcnew System::EventHandler(this, &Form2::logInOutButton_Click);
			// 
			// doStuffButton
			// 
			this->doStuffButton->Enabled = false;
			this->doStuffButton->Location = System::Drawing::Point(12, 71);
			this->doStuffButton->Name = L"doStuffButton";
			this->doStuffButton->Size = System::Drawing::Size(276, 23);
			this->doStuffButton->TabIndex = 2;
			this->doStuffButton->Text = L"Unavailable";
			this->doStuffButton->UseVisualStyleBackColor = true;
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(12, 101);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(276, 23);
			this->exitButton->TabIndex = 3;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &Form2::exitButton_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 141);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->doStuffButton);
			this->Controls->Add(this->logInOutButton);
			this->Controls->Add(this->currentUserLabel);
			this->Name = L"Form2";
			this->Text = L"Fake University";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*
		 * Windows forms event handlers
		 */

	private:
		System::Void logInOutButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (_loggedIn == false) {
				Form^ loginForm = gcnew LoginForm;
				if (loginForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					// To be replaced:
					doStuffButton->Enabled = true;
					doStuffButton->Text = "Current user: Admin";
					logInOutButton->Text = "Log out";
					_loggedIn = true;
				}
			}
			else
			{
				doStuffButton->Enabled = false;
				doStuffButton->Text = "Unavailable";
				logInOutButton->Text = "Log in";
				_loggedIn = false;
			}
		}

	private:
		System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Application::Exit();
		}

	}; // End of class Form2
} // namespace endbracket
