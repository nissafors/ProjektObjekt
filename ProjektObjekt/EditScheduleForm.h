#pragma once
#include "stdafx.h"
#using <System.Data.Entity.dll>
#include "CourseList.h"
#include "dbHandler.h"
#include <string>

using namespace std;

namespace ProjektObjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EditScheduleForm
	/// </summary>
	public ref class EditScheduleForm : public System::Windows::Forms::Form
	{
	public:
		EditScheduleForm(void)
		{
			InitializeComponent();
			// Get db command
			
			
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditScheduleForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  DoneButton;
	private: System::Windows::Forms::ListView^  lstCourseList;
	private: System::Windows::Forms::ColumnHeader^  Kurskod;
	private: System::Windows::Forms::ColumnHeader^  Kursnamn;
	private: System::Windows::Forms::ColumnHeader^  Kursansvarig;
	private: System::Windows::Forms::ColumnHeader^  StartDatum;
	private: System::Windows::Forms::ColumnHeader^  Slutdatum;
	private: System::Windows::Forms::Button^  btnBook;
	private: System::Windows::Forms::TextBox^  txtCourseId;
	private: System::Windows::Forms::TextBox^  textBox2;


	protected:


	protected:


	private:
		vector<CourseList^>^ _courseListVector;
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
			this->DoneButton = (gcnew System::Windows::Forms::Button());
			this->lstCourseList = (gcnew System::Windows::Forms::ListView());
			this->Kurskod = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kursnamn = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kursansvarig = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartDatum = (gcnew System::Windows::Forms::ColumnHeader());
			this->Slutdatum = (gcnew System::Windows::Forms::ColumnHeader());
			this->btnBook = (gcnew System::Windows::Forms::Button());
			this->txtCourseId = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// DoneButton
			// 
			this->DoneButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->DoneButton->Location = System::Drawing::Point(1150, 469);
			this->DoneButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->DoneButton->Name = L"DoneButton";
			this->DoneButton->Size = System::Drawing::Size(112, 35);
			this->DoneButton->TabIndex = 0;
			this->DoneButton->Text = L"Done";
			this->DoneButton->UseVisualStyleBackColor = true;
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
			this->lstCourseList->Location = System::Drawing::Point(35, 158);
			this->lstCourseList->Name = L"lstCourseList";
			this->lstCourseList->Size = System::Drawing::Size(1044, 466);
			this->lstCourseList->TabIndex = 1;
			this->lstCourseList->UseCompatibleStateImageBehavior = false;
			this->lstCourseList->View = System::Windows::Forms::View::Details;
			// 
			// Kurskod
			// 
			this->Kurskod->Text = L"Kurskod";
			this->Kurskod->Width = 70;
			// 
			// Kursnamn
			// 
			this->Kursnamn->Text = L"Kursnamn";
			this->Kursnamn->Width = 197;
			// 
			// Kursansvarig
			// 
			this->Kursansvarig->Text = L"Kursansvarig";
			this->Kursansvarig->Width = 162;
			// 
			// StartDatum
			// 
			this->StartDatum->Text = L"StartDatum";
			this->StartDatum->Width = 94;
			// 
			// Slutdatum
			// 
			this->Slutdatum->Text = L"Slutdatum";
			this->Slutdatum->Width = 86;
			// 
			// btnBook
			// 
			this->btnBook->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnBook->Location = System::Drawing::Point(1150, 320);
			this->btnBook->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnBook->Name = L"btnBook";
			this->btnBook->Size = System::Drawing::Size(112, 35);
			this->btnBook->TabIndex = 2;
			this->btnBook->Text = L"Book";
			this->btnBook->UseVisualStyleBackColor = true;
			this->btnBook->Click += gcnew System::EventHandler(this, &EditScheduleForm::btnBook_Click);
			// 
			// txtCourseId
			// 
			this->txtCourseId->Location = System::Drawing::Point(35, 63);
			this->txtCourseId->Name = L"txtCourseId";
			this->txtCourseId->Size = System::Drawing::Size(100, 26);
			this->txtCourseId->TabIndex = 3;
			this->txtCourseId->TextChanged += gcnew System::EventHandler(this, &EditScheduleForm::txtCourseId_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(179, 62);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 4;
			// 
			// EditScheduleForm
			// 
			this->AcceptButton = this->DoneButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1478, 605);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->txtCourseId);
			this->Controls->Add(this->btnBook);
			this->Controls->Add(this->lstCourseList);
			this->Controls->Add(this->DoneButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"EditScheduleForm";
			this->Text = L"EditScheduleForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnBook_Click(System::Object^  sender, System::EventArgs^  e) 
	{
			if (lstCourseList->SelectedIndices->Count > 0)
			{
				int courseid = _courseListVector[lstCourseList->SelectedIndices[0]]->courseId();
				//ListViewItem^ courseSelected = gcnew ListViewItem();
				//courseSelected = lstCourseList->;
				//courseSelected->SubItems->Add(lstCourseList->SelectedItems->ToString());
				//int i;
				//courseSelected->GetSubItemAt([0]);
				
				
				//String^ _courseid;
				//_courseid = lstCourseList->SelectedItems->ToString();
				//courseSelected = lstCourseList->SelectedItems->ToString();
				//ListView::SelectedListViewItemCollection^ breakfast = this->lstCourseList->SelectedItems;
				
				
				//i = Int32Converter::Parse(this->lstCourseList->Items[selec]->SubItems[1]->Text);
				//i = int::Parse(lstCourseList->SelectedItems->CopyTo ToString());
				//int i = Convert::ToInt32(lstCourseList->SelectedItems[0]->ToString());
				
				//i = stoi(_courseid);
				//	MessageBox::Show(courseSelected);
			//ListViewItem^ courseSelected =  gcnew ListViewItem();
			}
			else
			{
				Close();
			}

	}
private: System::Void txtCourseId_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
			int _courseId;
			_courseId = Convert::ToInt32(txtCourseId->Text);
			dbHandler dbh;
			DbCommand^ cmd = dbh.getCommand();

			vector<CourseList^>^ _selectedCourse;
			//_selectedCourse = CourseList::getSelectedCourses(cmd);

	}
		 System::Void updateCourseList()
		 {
			 dbHandler dbh;
			 DbCommand^ cmd = dbh.getCommand();

			 
			 _courseListVector = CourseList::getAllCourses(cmd);

			 lstCourseList->Items->Clear();

			 // Iterera igenom hela schemat och skriv ut den
			 vector<CourseList^>::iterator it = _courseListVector->begin();
			 for (it; it != _courseListVector->end(); it++)
			 {
				 ListViewItem^ _course = gcnew ListViewItem((**it).courseId().ToString());
				 _course->SubItems->Add((**it).name());
				 _course->SubItems->Add((**it).chiefId());
				 _course->SubItems->Add((**it).startDate());
				 _course->SubItems->Add((**it).endDate());
				 //course->SubItems->Add((**it).endDate());

				 lstCourseList->Items->Add(_course);
			 }
		 }
};
}
