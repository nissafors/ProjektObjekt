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
#include "User.h"

namespace ProjektObjekt {
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
			_currentUser = nullptr;

			// Connect to database engine
			//fac = DbProviderFactories::GetFactory("System.Data.SqlClient");
			//conn = fac->CreateConnection();
			//conn->ConnectionString = "Data Source=MACBOOK-PRO;Initial Catalog=DBanan14hj;Integrated Security=False;User ID=anan14hj;Password=Jwcg998;Connect Timeout=15;Encrypt=False;TrustServerCertificate=False";
			//conn->Open();
			
			// Prepare DB command
			//cmd = fac->CreateCommand();
			//cmd->Connection = conn;
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
		User^ _currentUser;

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
			this->doStuffButton->Click += gcnew System::EventHandler(this, &Form2::doStuffButton_Click);
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
			if (_currentUser == nullptr) {
				// Show login dialog
				LoginForm^ loginForm = gcnew LoginForm;
				if (loginForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
				{
					// Get a User based on dialog user input from login dialog
					String^ username = loginForm->getUsername();
					String^ password = loginForm->getPassword();
					delete loginForm;

					_currentUser = User::getUser(username, password);
					if (_currentUser != nullptr)
					{
						String^ lblTxt = "Current user: " + username;
						currentUserLabel->Text = lblTxt;
						doStuffButton->Enabled = true;
						logInOutButton->Text = "Log out";

						if (_currentUser->getUserType() == _user_t::student)
							doStuffButton->Text = "Show tests";
						else
							doStuffButton->Text = "Edit schedule";
					}
					else
					{
						// Login failed. Make sure we are logged out.
						logout();
					}
				}
			}
			else
			{
				// Logout requested
				logout();
			}
		}

	private:
		System::Void exitButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Application::Exit();
		}

		System::Void doStuffButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			if (_currentUser != nullptr && _currentUser->getUserType() == _user_t::student)
			{
				// User is a student: Call show tests form
			}
			else if (_currentUser != nullptr && _currentUser->getUserType() == _user_t::teacher)
			{
				// User is a teacher: Call edit schedule form
			}
		}

		void logout()
		{
			_currentUser = nullptr;
			currentUserLabel->Text = "Current user: none";
			doStuffButton->Enabled = false;
			doStuffButton->Text = "Unavailable";
			logInOutButton->Text = "Log in";
		}
	}; // End of class Form2
} // namespace endbracket
