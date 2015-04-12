/*
 * This is the main window.
 */

#pragma once

#include "LoginForm.h"
#include "EditScheduleForm.h"
#include "ShowTestsForm.h"
#include "User.h"

using namespace System::Windows::Forms;

namespace ProjektObjekt {

	/// <summary>
	/// This is the main form. From here a user may log in to the system. If the user is an
	/// administrator (s)he may edit the schedule. Student users can access their tests.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		// Default constructor
		MainForm(void)
		{
			InitializeComponent();
			_currentUser = nullptr;
		}

	protected:
		// Destructor
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
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
			this->logInOutButton->Click += gcnew System::EventHandler(this, &MainForm::logInOutButton_Click);
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
			this->doStuffButton->Click += gcnew System::EventHandler(this, &MainForm::doStuffButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->Location = System::Drawing::Point(12, 101);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(276, 23);
			this->exitButton->TabIndex = 3;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &MainForm::exitButton_Click);
			// 
			// Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 141);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->doStuffButton);
			this->Controls->Add(this->logInOutButton);
			this->Controls->Add(this->currentUserLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainForm";
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
						String^ lblTxt = "Current user: " + _currentUser->getName() + " [" + username + "]";
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
				ShowTestsForm^ stf = gcnew ShowTestsForm(dynamic_cast<Student^>(_currentUser));
				stf->ShowDialog(this);
			}
			else if (_currentUser != nullptr && _currentUser->getUserType() == _user_t::teacher)
			{
				// User is a teacher: Call edit schedule form
				EditScheduleForm^ esf = gcnew EditScheduleForm;
				esf->ShowDialog(this);
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
	}; // End of class MainForm
} // namespace endbracket
