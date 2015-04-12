#pragma once

namespace ProjektObjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		// Getters
		String^ getUsername() {
			return usernameTextBox->Text;
		}
		String^ getPassword() {
			return passwordTextBox->Text;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  usernameLabel;
	private: System::Windows::Forms::TextBox^  usernameTextBox;
	private: System::Windows::Forms::Label^  passwordLabel;
	private: System::Windows::Forms::TextBox^  passwordTextBox;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::Button^  logInButton;
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
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->logInButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Location = System::Drawing::Point(12, 9);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(55, 13);
			this->usernameLabel->TabIndex = 0;
			this->usernameLabel->Text = L"Username";
			// 
			// usernameTextBox
			// 
			this->usernameTextBox->Location = System::Drawing::Point(12, 25);
			this->usernameTextBox->Name = L"usernameTextBox";
			this->usernameTextBox->Size = System::Drawing::Size(210, 20);
			this->usernameTextBox->TabIndex = 1;
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Location = System::Drawing::Point(12, 48);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(53, 13);
			this->passwordLabel->TabIndex = 2;
			this->passwordLabel->Text = L"Password";
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Location = System::Drawing::Point(12, 64);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(210, 20);
			this->passwordTextBox->TabIndex = 3;
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(12, 90);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 4;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// logInButton
			// 
			this->logInButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->logInButton->Location = System::Drawing::Point(147, 90);
			this->logInButton->Name = L"logInButton";
			this->logInButton->Size = System::Drawing::Size(75, 23);
			this->logInButton->TabIndex = 5;
			this->logInButton->Text = L"Log in";
			this->logInButton->UseVisualStyleBackColor = true;
			// 
			// LoginForm
			// 
			this->AcceptButton = this->logInButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(234, 127);
			this->Controls->Add(this->logInButton);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameTextBox);
			this->Controls->Add(this->usernameLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"LoginForm";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};
}
