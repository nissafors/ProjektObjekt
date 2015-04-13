#pragma once
#include "Student.h"
#include "dbHandler.h"
#include "RunTestForm.h"
#include <cliext/vector>

namespace ProjektObjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cliext;

	/// <summary>
	/// Summary for ShowTestsForm
	/// </summary>
	public ref class ShowTestsForm : public System::Windows::Forms::Form
	{
	public:
		ShowTestsForm(Student^ student) : _student(student)
		{
			InitializeComponent();

			// Get db command
			dbHandler dbh;
			DbCommand^ cmd = dbh.getCommand();
			cmd->CommandText = "SELECT ExaminationsMoment.exKod, Kurs.namn FROM ExaminationsMoment, StudentLäserKurs, Kurs WHERE StudentLäserKurs.personNr = @personNr AND StudentLäserKurs.kursKod = ExaminationsMoment.kursKod AND ExaminationsMoment.typ = 'tenta' AND Kurs.kursKod = StudentLäserKurs.kursKod";
			cmd->Parameters->Add(gcnew SqlParameter("@personNr", SqlDbType::BigInt));
			cmd->Parameters["@personNr"]->Value = _student->getSocSecNr();
			DbDataReader^ reader = cmd->ExecuteReader();
			for (int i = 0; reader->Read(); i++)
			{
				_exCode->push_back(reader->GetInt32(0));
				String^ item = "Examination " + _exCode->at(i) + " in " + reader->GetString(1);
				selectTestComboBox->Items->Add(item);
			}
			if (selectTestComboBox->Items->Count > 0)
			{
				selectTestComboBox->SelectedIndex = 0;
				runTestButton->Enabled = true;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShowTestsForm()
		{
			if (components)
			{
				delete components;
			}
		}

		// Our members
	private:
		vector<int>^ _exCode = gcnew vector<int>();
		Student^ _student;

		// Winforms members
	private: System::Windows::Forms::Button^  runTestButton;
	private: System::Windows::Forms::Button^  closeButton;
	private: System::Windows::Forms::ComboBox^  selectTestComboBox;
	private: System::Windows::Forms::Label^  selectTestLabel;
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
			this->runTestButton = (gcnew System::Windows::Forms::Button());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->selectTestComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->selectTestLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// runTestButton
			// 
			this->runTestButton->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->runTestButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->runTestButton->Enabled = false;
			this->runTestButton->Location = System::Drawing::Point(212, 65);
			this->runTestButton->Name = L"runTestButton";
			this->runTestButton->Size = System::Drawing::Size(75, 23);
			this->runTestButton->TabIndex = 0;
			this->runTestButton->Text = L"Run test";
			this->runTestButton->UseVisualStyleBackColor = true;
			this->runTestButton->Click += gcnew System::EventHandler(this, &ShowTestsForm::runTestButton_Click);
			// 
			// closeButton
			// 
			this->closeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->closeButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->closeButton->Location = System::Drawing::Point(131, 65);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(75, 23);
			this->closeButton->TabIndex = 1;
			this->closeButton->Text = L"Close";
			this->closeButton->UseVisualStyleBackColor = true;
			// 
			// selectTestComboBox
			// 
			this->selectTestComboBox->FormattingEnabled = true;
			this->selectTestComboBox->Location = System::Drawing::Point(16, 29);
			this->selectTestComboBox->Name = L"selectTestComboBox";
			this->selectTestComboBox->Size = System::Drawing::Size(271, 21);
			this->selectTestComboBox->TabIndex = 2;
			// 
			// selectTestLabel
			// 
			this->selectTestLabel->AutoSize = true;
			this->selectTestLabel->Location = System::Drawing::Point(13, 13);
			this->selectTestLabel->Name = L"selectTestLabel";
			this->selectTestLabel->Size = System::Drawing::Size(57, 13);
			this->selectTestLabel->TabIndex = 3;
			this->selectTestLabel->Text = L"Select test";
			// 
			// ShowTestsForm
			// 
			this->AcceptButton = this->runTestButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->closeButton;
			this->ClientSize = System::Drawing::Size(299, 100);
			this->Controls->Add(this->selectTestLabel);
			this->Controls->Add(this->selectTestComboBox);
			this->Controls->Add(this->closeButton);
			this->Controls->Add(this->runTestButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"ShowTestsForm";
			this->Text = L"Tests";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void runTestButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Has this test already been taken by this _student?
			dbHandler dbh;
			DbCommand^ cmd = dbh.getCommand();
			cmd->CommandText = "SELECT COUNT(*) FROM TentaSvar WHERE exKod = @exCode AND personNr = @student";
			cmd->Parameters->Add(gcnew SqlParameter("@exCode", SqlDbType::Int));
			cmd->Parameters["@exCode"]->Value = _exCode->at(selectTestComboBox->SelectedIndex);
			cmd->Parameters->Add(gcnew SqlParameter("@student", SqlDbType::BigInt));
			cmd->Parameters["@student"]->Value = _student->getSocSecNr();
			DbDataReader^ reader = cmd->ExecuteReader();
			reader->Read();

			if (reader->GetInt32(0) > 0)
			{
				// Yes. Show warning and don't run the test.
				MessageBox::Show("This test has already been taken by you. Please contact your teacher for further instructions.", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else
			{
				// Nope. Run the test.
				RunTestForm^ rtf = gcnew RunTestForm(_exCode->at(selectTestComboBox->SelectedIndex), _student);
				rtf->ShowDialog(this);
				delete rtf;
			}
		}
	};
}
