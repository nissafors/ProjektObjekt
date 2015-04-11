#pragma once
#include "dbHandler.h"
#include <cliext\vector>


namespace ProjektObjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BookingForm
	/// </summary>
	public ref class BookingForm : public System::Windows::Forms::Form
	{
	public:
		BookingForm(int coursIdSelected)
		{
			InitializeComponent();
			_coursIdSelected = coursIdSelected;
			updateTxtNmbrOfStud(_coursIdSelected);
			updateTxtCourseName(_coursIdSelected);
			updateLbxCourseMmt();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BookingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtCourseName;
	private: System::Windows::Forms::TextBox^  txtNmbrOfStud;
	private: System::Windows::Forms::Label^  lblCourses;
	private: System::Windows::Forms::Label^  lblNmbrOfStud;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int _nmbrOfStud;
		int _coursIdSelected;
		String^ _coursName;
		String^ _strDateSelected;
		String^ _couMmtSelected;
		DateTime^ _dteDateSelected;

		
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::Button^  btnBook;
	private: System::Windows::Forms::MonthCalendar^  cdrStartDate;
	private: System::Windows::Forms::Label^  lblValjDatum;
	private: System::Windows::Forms::Label^  lblValtDatum;
	private: System::Windows::Forms::Panel^  pnlDate;
	private: System::Windows::Forms::Label^  lblChoseCourseMmt;



	private: System::Windows::Forms::Panel^  pnlCourseMmt;

	private: System::Windows::Forms::Panel^  pnlCourse;
	private: System::Windows::Forms::Button^  btnOkPnlCourseMmt;
	private: System::Windows::Forms::Button^  btnOkPnlDate;
	private: System::Windows::Forms::ComboBox^  cbxSelCouMmt;
	private: System::Windows::Forms::Label^  lblEndTime;
	private: System::Windows::Forms::Label^  lblStartTime;
	private: System::Windows::Forms::TextBox^  txtEndTime;
	private: System::Windows::Forms::TextBox^  txtStartTime;



		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
			this->txtNmbrOfStud = (gcnew System::Windows::Forms::TextBox());
			this->lblCourses = (gcnew System::Windows::Forms::Label());
			this->lblNmbrOfStud = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->btnBook = (gcnew System::Windows::Forms::Button());
			this->cdrStartDate = (gcnew System::Windows::Forms::MonthCalendar());
			this->lblValjDatum = (gcnew System::Windows::Forms::Label());
			this->lblValtDatum = (gcnew System::Windows::Forms::Label());
			this->pnlDate = (gcnew System::Windows::Forms::Panel());
			this->txtEndTime = (gcnew System::Windows::Forms::TextBox());
			this->txtStartTime = (gcnew System::Windows::Forms::TextBox());
			this->lblEndTime = (gcnew System::Windows::Forms::Label());
			this->lblStartTime = (gcnew System::Windows::Forms::Label());
			this->btnOkPnlDate = (gcnew System::Windows::Forms::Button());
			this->lblChoseCourseMmt = (gcnew System::Windows::Forms::Label());
			this->pnlCourseMmt = (gcnew System::Windows::Forms::Panel());
			this->cbxSelCouMmt = (gcnew System::Windows::Forms::ComboBox());
			this->btnOkPnlCourseMmt = (gcnew System::Windows::Forms::Button());
			this->pnlCourse = (gcnew System::Windows::Forms::Panel());
			this->pnlDate->SuspendLayout();
			this->pnlCourseMmt->SuspendLayout();
			this->pnlCourse->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtCourseName
			// 
			this->txtCourseName->Enabled = false;
			this->txtCourseName->Location = System::Drawing::Point(7, 41);
			this->txtCourseName->Name = L"txtCourseName";
			this->txtCourseName->Size = System::Drawing::Size(253, 26);
			this->txtCourseName->TabIndex = 0;
			this->txtCourseName->TextChanged += gcnew System::EventHandler(this, &BookingForm::txtCourseName_TextChanged);
			// 
			// txtNmbrOfStud
			// 
			this->txtNmbrOfStud->Location = System::Drawing::Point(7, 122);
			this->txtNmbrOfStud->Name = L"txtNmbrOfStud";
			this->txtNmbrOfStud->Size = System::Drawing::Size(100, 26);
			this->txtNmbrOfStud->TabIndex = 1;
			// 
			// lblCourses
			// 
			this->lblCourses->AutoSize = true;
			this->lblCourses->Location = System::Drawing::Point(3, 9);
			this->lblCourses->Name = L"lblCourses";
			this->lblCourses->Size = System::Drawing::Size(41, 20);
			this->lblCourses->TabIndex = 2;
			this->lblCourses->Text = L"Kurs";
			// 
			// lblNmbrOfStud
			// 
			this->lblNmbrOfStud->AutoSize = true;
			this->lblNmbrOfStud->Location = System::Drawing::Point(3, 90);
			this->lblNmbrOfStud->Name = L"lblNmbrOfStud";
			this->lblNmbrOfStud->Size = System::Drawing::Size(118, 20);
			this->lblNmbrOfStud->TabIndex = 3;
			this->lblNmbrOfStud->Text = L"Antal studenter";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1289, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// btnBook
			// 
			this->btnBook->Location = System::Drawing::Point(1104, 585);
			this->btnBook->Name = L"btnBook";
			this->btnBook->Size = System::Drawing::Size(91, 38);
			this->btnBook->TabIndex = 6;
			this->btnBook->Text = L"Boka";
			this->btnBook->UseVisualStyleBackColor = true;
			// 
			// cdrStartDate
			// 
			this->cdrStartDate->Location = System::Drawing::Point(14, 14);
			this->cdrStartDate->Name = L"cdrStartDate";
			this->cdrStartDate->TabIndex = 7;
			this->cdrStartDate->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &BookingForm::cdrStartDate_DateChanged);
			// 
			// lblValjDatum
			// 
			this->lblValjDatum->AutoSize = true;
			this->lblValjDatum->Location = System::Drawing::Point(351, 14);
			this->lblValjDatum->Name = L"lblValjDatum";
			this->lblValjDatum->Size = System::Drawing::Size(84, 20);
			this->lblValjDatum->TabIndex = 8;
			this->lblValjDatum->Text = L"Välj datum";
			// 
			// lblValtDatum
			// 
			this->lblValtDatum->AutoSize = true;
			this->lblValtDatum->Location = System::Drawing::Point(351, 50);
			this->lblValtDatum->Name = L"lblValtDatum";
			this->lblValtDatum->Size = System::Drawing::Size(51, 20);
			this->lblValtDatum->TabIndex = 9;
			this->lblValtDatum->Text = L"label2";
			this->lblValtDatum->Visible = false;
			// 
			// pnlDate
			// 
			this->pnlDate->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlDate->Controls->Add(this->txtEndTime);
			this->pnlDate->Controls->Add(this->txtStartTime);
			this->pnlDate->Controls->Add(this->lblEndTime);
			this->pnlDate->Controls->Add(this->lblStartTime);
			this->pnlDate->Controls->Add(this->btnOkPnlDate);
			this->pnlDate->Controls->Add(this->cdrStartDate);
			this->pnlDate->Controls->Add(this->lblValtDatum);
			this->pnlDate->Controls->Add(this->lblValjDatum);
			this->pnlDate->Location = System::Drawing::Point(43, 293);
			this->pnlDate->Name = L"pnlDate";
			this->pnlDate->Size = System::Drawing::Size(557, 303);
			this->pnlDate->TabIndex = 10;
			// 
			// txtEndTime
			// 
			this->txtEndTime->Enabled = false;
			this->txtEndTime->Location = System::Drawing::Point(355, 198);
			this->txtEndTime->Name = L"txtEndTime";
			this->txtEndTime->Size = System::Drawing::Size(100, 26);
			this->txtEndTime->TabIndex = 20;
			// 
			// txtStartTime
			// 
			this->txtStartTime->Enabled = false;
			this->txtStartTime->Location = System::Drawing::Point(355, 123);
			this->txtStartTime->Name = L"txtStartTime";
			this->txtStartTime->Size = System::Drawing::Size(100, 26);
			this->txtStartTime->TabIndex = 19;
			// 
			// lblEndTime
			// 
			this->lblEndTime->AutoSize = true;
			this->lblEndTime->Location = System::Drawing::Point(351, 163);
			this->lblEndTime->Name = L"lblEndTime";
			this->lblEndTime->Size = System::Drawing::Size(84, 20);
			this->lblEndTime->TabIndex = 18;
			this->lblEndTime->Text = L"Välj Sluttid";
			// 
			// lblStartTime
			// 
			this->lblStartTime->AutoSize = true;
			this->lblStartTime->Location = System::Drawing::Point(351, 99);
			this->lblStartTime->Name = L"lblStartTime";
			this->lblStartTime->Size = System::Drawing::Size(91, 20);
			this->lblStartTime->TabIndex = 17;
			this->lblStartTime->Text = L"Välj Starttid";
			// 
			// btnOkPnlDate
			// 
			this->btnOkPnlDate->Enabled = false;
			this->btnOkPnlDate->Location = System::Drawing::Point(402, 251);
			this->btnOkPnlDate->Name = L"btnOkPnlDate";
			this->btnOkPnlDate->Size = System::Drawing::Size(90, 36);
			this->btnOkPnlDate->TabIndex = 16;
			this->btnOkPnlDate->Text = L"OK";
			this->btnOkPnlDate->UseVisualStyleBackColor = true;
			this->btnOkPnlDate->Click += gcnew System::EventHandler(this, &BookingForm::btnOkPnlDate_Click);
			// 
			// lblChoseCourseMmt
			// 
			this->lblChoseCourseMmt->AutoSize = true;
			this->lblChoseCourseMmt->Location = System::Drawing::Point(3, 18);
			this->lblChoseCourseMmt->Name = L"lblChoseCourseMmt";
			this->lblChoseCourseMmt->Size = System::Drawing::Size(116, 20);
			this->lblChoseCourseMmt->TabIndex = 11;
			this->lblChoseCourseMmt->Text = L"Välj Kursoment";
			// 
			// pnlCourseMmt
			// 
			this->pnlCourseMmt->Controls->Add(this->cbxSelCouMmt);
			this->pnlCourseMmt->Controls->Add(this->btnOkPnlCourseMmt);
			this->pnlCourseMmt->Controls->Add(this->lblChoseCourseMmt);
			this->pnlCourseMmt->Location = System::Drawing::Point(3, 175);
			this->pnlCourseMmt->Name = L"pnlCourseMmt";
			this->pnlCourseMmt->Size = System::Drawing::Size(537, 95);
			this->pnlCourseMmt->TabIndex = 15;
			// 
			// cbxSelCouMmt
			// 
			this->cbxSelCouMmt->FormattingEnabled = true;
			this->cbxSelCouMmt->Location = System::Drawing::Point(8, 53);
			this->cbxSelCouMmt->Name = L"cbxSelCouMmt";
			this->cbxSelCouMmt->Size = System::Drawing::Size(121, 28);
			this->cbxSelCouMmt->TabIndex = 16;
			// 
			// btnOkPnlCourseMmt
			// 
			this->btnOkPnlCourseMmt->Location = System::Drawing::Point(399, 48);
			this->btnOkPnlCourseMmt->Name = L"btnOkPnlCourseMmt";
			this->btnOkPnlCourseMmt->Size = System::Drawing::Size(90, 33);
			this->btnOkPnlCourseMmt->TabIndex = 15;
			this->btnOkPnlCourseMmt->Text = L"OK";
			this->btnOkPnlCourseMmt->UseVisualStyleBackColor = true;
			this->btnOkPnlCourseMmt->Click += gcnew System::EventHandler(this, &BookingForm::btnOkPnlCourseMmt_Click);
			// 
			// pnlCourse
			// 
			this->pnlCourse->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlCourse->Controls->Add(this->pnlCourseMmt);
			this->pnlCourse->Controls->Add(this->lblCourses);
			this->pnlCourse->Controls->Add(this->txtCourseName);
			this->pnlCourse->Controls->Add(this->txtNmbrOfStud);
			this->pnlCourse->Controls->Add(this->lblNmbrOfStud);
			this->pnlCourse->Location = System::Drawing::Point(43, 12);
			this->pnlCourse->Name = L"pnlCourse";
			this->pnlCourse->Size = System::Drawing::Size(557, 275);
			this->pnlCourse->TabIndex = 16;
			// 
			// BookingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1289, 635);
			this->Controls->Add(this->pnlCourse);
			this->Controls->Add(this->pnlDate);
			this->Controls->Add(this->btnBook);
			this->Controls->Add(this->menuStrip1);
			this->Location = System::Drawing::Point(1086, 585);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"BookingForm";
			this->Text = L"BookingForm";
			this->Click += gcnew System::EventHandler(this, &BookingForm::btnExit_Click);
			this->pnlDate->ResumeLayout(false);
			this->pnlDate->PerformLayout();
			this->pnlCourseMmt->ResumeLayout(false);
			this->pnlCourseMmt->PerformLayout();
			this->pnlCourse->ResumeLayout(false);
			this->pnlCourse->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txtCourseName_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
	}
			 System::Void updateTxtNmbrOfStud(int id)
			 {
				 dbHandler dbh;
				 DbCommand^ cmd = dbh.getCommand();
				 //DbDataReader^ reader = cmd->ExecuteReader();
				 cmd->CommandText = "Select COUNT(personNr) FROM StudentLäserKurs WHERE kursKod = @id";
				 cmd->Parameters->Add(gcnew SqlParameter("@id", SqlDbType::Int));
				 cmd->Parameters["@id"]->Value = id;
				 DbDataReader^ reader = cmd->ExecuteReader();
				 reader->Read();
				 _nmbrOfStud = reader->GetInt32(0);
				 txtNmbrOfStud->Text = _nmbrOfStud.ToString();
				 reader->Close();
			 }
			 System::Void updateTxtCourseName(int id)
			 {
				dbHandler dbh;
				DbCommand^ cmd = dbh.getCommand();
				cmd->CommandText = "Select Kurs.namn FROM Kurs WHERE Kurs.kursKod = @id";
				cmd->Parameters->Add(gcnew SqlParameter("@id", SqlDbType::Int));
				cmd->Parameters["@id"]->Value = id;
				DbDataReader^ reader = cmd->ExecuteReader();
				reader->Read();
				_coursName = reader->GetString(0);
				txtCourseName->Text = _coursName;
				reader->Close();
			 }
			 System::Void updateLbxCourseMmt()
			 {
				 cbxSelCouMmt->Items->Add("föreläsning");
				 cbxSelCouMmt->Items->Add("övning");
				 //cbxSelCouMmt->Items->Add("Dugga");
				 cbxSelCouMmt->Items->Add("laboration");

			 }
	private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
				this->Close();
	}
	private: System::Void cdrStartDate_DateChanged(System::Object^  sender, System::Windows::Forms::DateRangeEventArgs^  e) 
	{
				//visar ett datum
				cdrStartDate->MaxSelectionCount = 1;				
				_dteDateSelected = cdrStartDate->SelectionRange->Start;
				_strDateSelected = _dteDateSelected->ToShortDateString();		//tar inte med 	klockslag	
				lblValtDatum->Visible = true;
				lblValtDatum->Text = _strDateSelected;
				txtEndTime->Enabled = true;
				txtStartTime->Enabled = true;
	}
private: System::Void btnOkPnlCourseMmt_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 String^ str;
			 _couMmtSelected = cbxSelCouMmt->SelectedItem->ToString();
			 str = txtNmbrOfStud->Text;
			 _nmbrOfStud = Convert::ToInt32(str);
			 btnOkPnlDate->Enabled = true;
			 pnlDate->Enabled = true;
			 MessageBox::Show(_couMmtSelected + str  );
}
private: System::Void btnOkPnlDate_Click(System::Object^  sender, System::EventArgs^  e) {
}
};

}
