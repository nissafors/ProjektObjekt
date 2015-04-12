#pragma once
#include "stdafx.h"
#using <System.Data.Entity.dll>
#include "Course.h"
#include "dbHandler.h"
#include <string>
#include "BookingForm.h"

using namespace std;

namespace ProjektObjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form to select course for which to edit schedule
	/// </summary>
	public ref class SelectCourseForm : public System::Windows::Forms::Form
	{
	public:
		SelectCourseForm(void)
		{
			InitializeComponent();
			updateCourseList();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SelectCourseForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// Our own members
		vector<Course^>^ _courseVector;

		// Winforms members
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::ListView^  lstCourseList;
	private: System::Windows::Forms::ColumnHeader^  Kurskod;
	private: System::Windows::Forms::ColumnHeader^  Kursnamn;
	private: System::Windows::Forms::ColumnHeader^  Kursansvarig;
	private: System::Windows::Forms::ColumnHeader^  StartDatum;
	private: System::Windows::Forms::ColumnHeader^  Slutdatum;
	private: System::Windows::Forms::Button^  btnBook;
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
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->lstCourseList = (gcnew System::Windows::Forms::ListView());
			this->Kurskod = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kursnamn = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kursansvarig = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartDatum = (gcnew System::Windows::Forms::ColumnHeader());
			this->Slutdatum = (gcnew System::Windows::Forms::ColumnHeader());
			this->btnBook = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Location = System::Drawing::Point(552, 320);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 0;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			// 
			// lstCourseList
			// 
			this->lstCourseList->AllowColumnReorder = true;
			this->lstCourseList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->Kurskod, this->Kursnamn,
					this->Kursansvarig, this->StartDatum, this->Slutdatum
			});
			this->lstCourseList->FullRowSelect = true;
			this->lstCourseList->GridLines = true;
			this->lstCourseList->HideSelection = false;
			this->lstCourseList->LabelEdit = true;
			this->lstCourseList->Location = System::Drawing::Point(11, 11);
			this->lstCourseList->Margin = System::Windows::Forms::Padding(2);
			this->lstCourseList->Name = L"lstCourseList";
			this->lstCourseList->Size = System::Drawing::Size(697, 304);
			this->lstCourseList->TabIndex = 1;
			this->lstCourseList->UseCompatibleStateImageBehavior = false;
			this->lstCourseList->View = System::Windows::Forms::View::Details;
			// 
			// Kurskod
			// 
			this->Kurskod->Text = L"Code";
			this->Kurskod->Width = 70;
			// 
			// Kursnamn
			// 
			this->Kursnamn->Text = L"Name";
			this->Kursnamn->Width = 197;
			// 
			// Kursansvarig
			// 
			this->Kursansvarig->Text = L"Teacher";
			this->Kursansvarig->Width = 162;
			// 
			// StartDatum
			// 
			this->StartDatum->Text = L"Start date";
			this->StartDatum->Width = 94;
			// 
			// Slutdatum
			// 
			this->Slutdatum->Text = L"End date";
			this->Slutdatum->Width = 86;
			// 
			// btnBook
			// 
			this->btnBook->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnBook->Location = System::Drawing::Point(633, 320);
			this->btnBook->Name = L"btnBook";
			this->btnBook->Size = System::Drawing::Size(75, 23);
			this->btnBook->TabIndex = 2;
			this->btnBook->Text = L"Book";
			this->btnBook->UseVisualStyleBackColor = true;
			this->btnBook->Click += gcnew System::EventHandler(this, &SelectCourseForm::btnBook_Click);
			// 
			// SelectCourseForm
			// 
			this->AcceptButton = this->btnBook;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(718, 351);
			this->Controls->Add(this->btnBook);
			this->Controls->Add(this->lstCourseList);
			this->Controls->Add(this->cancelButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"SelectCourseForm";
			this->Text = L"Select course";
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::Void btnBook_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (lstCourseList->SelectedIndices->Count > 0)
			{
				int courseIdSelected = _courseVector[lstCourseList->SelectedIndices[0]]->courseId();
				
				//setCourseIdSelected(courseIdSelected);
				BookingForm^ bf = gcnew BookingForm(courseIdSelected);
				bf->ShowDialog(this);
				
			}
			else
			{
				Close();
			}

		}
		
		System::Void updateCourseList()
		{
			dbHandler dbh;
			DbCommand^ cmd = dbh.getCommand();
		 			 
			_courseVector = Course::getAllCourses(cmd);
			lstCourseList->Items->Clear();

			// Prepare command to get teachers name
			cmd->CommandText = "SELECT namn FROM Personal WHERE anstNr = @teacher";
			cmd->Parameters->Clear();
			cmd->Parameters->Add(gcnew SqlParameter("@teacher", SqlDbType::Int));
			DbDataReader^ reader;

			// Iterera igenom hela schemat och skriv ut den
			vector<Course^>::iterator it = _courseVector->begin();
			for (it; it != _courseVector->end(); it++)
			{
				// Get teachers name
				String^ a = (**it).chiefId();
				int b = int::Parse((**it).chiefId());
				cmd->Parameters["@teacher"]->Value = int::Parse((**it).chiefId());
				reader = cmd->ExecuteReader();
				reader->Read();
				String^ teacher = reader->GetString(0);
				reader->Close();
				
				// Add course data to ListView
				ListViewItem^ _course = gcnew ListViewItem((**it).courseId().ToString());
				_course->SubItems->Add((**it).name());
				_course->SubItems->Add(teacher);
				_course->SubItems->Add((**it).startDate());
				_course->SubItems->Add((**it).endDate());
				lstCourseList->Items->Add(_course);
			}
		}
	};
}
