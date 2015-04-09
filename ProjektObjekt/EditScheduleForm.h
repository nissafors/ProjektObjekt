#include "stdafx.h"
#include "CourseList.h"
#include "dbHandler.h"
#include <string>
using namespace std;
#pragma once
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
			dbHandler dbh;
			DbCommand^ cmd = dbh.getCommand();


			vector<CourseList^>^ courseListVector = CourseList::getAllCourses(cmd);
			lstCourseList->Items->Clear();

			vector<CourseList^>::iterator it = courseListVector->begin();

			int i = 0;
			for (; it != courseListVector->end(); it++);
			{
				ListViewItem^ Course = gcnew ListViewItem(courseListVector->at(i)->courseId());
				Course->SubItems->Add(courseListVector->at(i)->name());
				Course->SubItems->Add(courseListVector->at(i)->chiefId());
				Course->SubItems->Add(courseListVector->at(i)->startDate());
				Course->SubItems->Add(courseListVector->at(i)->endDate());
				Course->SubItems->Add(courseListVector->at(i)->endDate());
				//Course->SubItems->Add((**it).nmbrOfStud());
				lstCourseList->Items->Add(Course);
				i++;
			}
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
	private: System::Windows::Forms::ColumnHeader^  AntalStudenter;

	protected:


	protected:


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
			this->DoneButton = (gcnew System::Windows::Forms::Button());
			this->lstCourseList = (gcnew System::Windows::Forms::ListView());
			this->Kurskod = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kursnamn = (gcnew System::Windows::Forms::ColumnHeader());
			this->Kursansvarig = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartDatum = (gcnew System::Windows::Forms::ColumnHeader());
			this->Slutdatum = (gcnew System::Windows::Forms::ColumnHeader());
			this->AntalStudenter = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// DoneButton
			// 
			this->DoneButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->DoneButton->Location = System::Drawing::Point(1002, 551);
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
			this->lstCourseList->CheckBoxes = true;
			this->lstCourseList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->Kurskod, this->Kursnamn,
					this->Kursansvarig, this->StartDatum, this->Slutdatum, this->AntalStudenter
			});
			this->lstCourseList->FullRowSelect = true;
			this->lstCourseList->GridLines = true;
			this->lstCourseList->HideSelection = false;
			this->lstCourseList->LabelEdit = true;
			this->lstCourseList->Location = System::Drawing::Point(48, 32);
			this->lstCourseList->Name = L"lstCourseList";
			this->lstCourseList->Size = System::Drawing::Size(938, 466);
			this->lstCourseList->TabIndex = 1;
			this->lstCourseList->UseCompatibleStateImageBehavior = false;
			this->lstCourseList->View = System::Windows::Forms::View::Details;
			// 
			// Kurskod
			// 
			this->Kurskod->Text = L"Kurskod";
			this->Kurskod->Width = 97;
			// 
			// Kursnamn
			// 
			this->Kursnamn->Text = L"Kursnamn";
			this->Kursnamn->Width = 257;
			// 
			// Kursansvarig
			// 
			this->Kursansvarig->Text = L"Kursansvarig";
			this->Kursansvarig->Width = 162;
			// 
			// StartDatum
			// 
			this->StartDatum->Text = L"StartDatum";
			this->StartDatum->Width = 134;
			// 
			// Slutdatum
			// 
			this->Slutdatum->Text = L"Slutdatum";
			this->Slutdatum->Width = 127;
			// 
			// AntalStudenter
			// 
			this->AntalStudenter->Text = L"AntalStudenter";
			this->AntalStudenter->Width = 125;
			// 
			// EditScheduleForm
			// 
			this->AcceptButton = this->DoneButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1132, 605);
			this->Controls->Add(this->lstCourseList);
			this->Controls->Add(this->DoneButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"EditScheduleForm";
			this->Text = L"EditScheduleForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	};
}
