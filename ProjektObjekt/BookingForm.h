#pragma once
#include "dbHandler.h"
#include <cliext\vector>
#include "Room.h"
#include "Teacher.h"



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
		String^ _courseMomentSelected;
		String^ _startTime;
		String^ _endTime;
		DateTime^ _dteDateSelected;
		vector<Room^> ^_roomsVector;
		vector<Room^> ^_roomsVectorToLbxAvailableRooms;
		vector<Teacher^> ^_allTeacherVector;
		

		
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
	private: System::Windows::Forms::Button^  btnShowRoomsPnlDate;

	private: System::Windows::Forms::ComboBox^  cbxSelCouMmt;
	private: System::Windows::Forms::Label^  lblEndTime;
	private: System::Windows::Forms::Label^  lblStartTime;
	private: System::Windows::Forms::TextBox^  txtEndTimeHour;

	private: System::Windows::Forms::TextBox^  txtStartTimeHour;
	private: System::Windows::Forms::TextBox^  txtEndTimeMinutes;
	private: System::Windows::Forms::TextBox^  txtStartTimeMinutes;
	private: System::Windows::Forms::Label^  lbl1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::ListBox^  lbxAvailableRooms;

	private: System::Windows::Forms::Button^  btnAvbryt;
	private: System::Windows::Forms::Label^  lblAvailableRooms;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::ComboBox^  cbxSelectTeacher;
	private: System::Windows::Forms::Label^  lblSelectTeacher;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->txtEndTimeMinutes = (gcnew System::Windows::Forms::TextBox());
			this->txtStartTimeMinutes = (gcnew System::Windows::Forms::TextBox());
			this->txtEndTimeHour = (gcnew System::Windows::Forms::TextBox());
			this->txtStartTimeHour = (gcnew System::Windows::Forms::TextBox());
			this->lblEndTime = (gcnew System::Windows::Forms::Label());
			this->lblStartTime = (gcnew System::Windows::Forms::Label());
			this->btnShowRoomsPnlDate = (gcnew System::Windows::Forms::Button());
			this->lblChoseCourseMmt = (gcnew System::Windows::Forms::Label());
			this->pnlCourseMmt = (gcnew System::Windows::Forms::Panel());
			this->cbxSelCouMmt = (gcnew System::Windows::Forms::ComboBox());
			this->btnOkPnlCourseMmt = (gcnew System::Windows::Forms::Button());
			this->pnlCourse = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->cbxSelectTeacher = (gcnew System::Windows::Forms::ComboBox());
			this->lblSelectTeacher = (gcnew System::Windows::Forms::Label());
			this->lblAvailableRooms = (gcnew System::Windows::Forms::Label());
			this->lbxAvailableRooms = (gcnew System::Windows::Forms::ListBox());
			this->btnAvbryt = (gcnew System::Windows::Forms::Button());
			this->pnlDate->SuspendLayout();
			this->pnlCourseMmt->SuspendLayout();
			this->pnlCourse->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtCourseName
			// 
			this->txtCourseName->Enabled = false;
			this->txtCourseName->Location = System::Drawing::Point(7, 41);
			this->txtCourseName->Name = L"txtCourseName";
			this->txtCourseName->Size = System::Drawing::Size(253, 26);
			this->txtCourseName->TabIndex = 0;
			
			// 
			// txtNmbrOfStud
			// 
			this->txtNmbrOfStud->Location = System::Drawing::Point(342, 41);
			this->txtNmbrOfStud->Name = L"txtNmbrOfStud";
			this->txtNmbrOfStud->Size = System::Drawing::Size(169, 26);
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
			this->lblNmbrOfStud->Location = System::Drawing::Point(338, 9);
			this->lblNmbrOfStud->Name = L"lblNmbrOfStud";
			this->lblNmbrOfStud->Size = System::Drawing::Size(118, 20);
			this->lblNmbrOfStud->TabIndex = 3;
			this->lblNmbrOfStud->Text = L"Antal studenter";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1041, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// btnBook
			// 
			this->btnBook->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnBook->Enabled = false;
			this->btnBook->Location = System::Drawing::Point(809, 588);
			this->btnBook->Name = L"btnBook";
			this->btnBook->Size = System::Drawing::Size(155, 36);
			this->btnBook->TabIndex = 6;
			this->btnBook->Text = L"Boka";
			this->btnBook->UseVisualStyleBackColor = true;
			this->btnBook->Click += gcnew System::EventHandler(this, &BookingForm::btnBook_Click);
			// 
			// cdrStartDate
			// 
			this->cdrStartDate->Enabled = false;
			this->cdrStartDate->Location = System::Drawing::Point(11, 23);
			this->cdrStartDate->Name = L"cdrStartDate";
			this->cdrStartDate->TabIndex = 7;
			this->cdrStartDate->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &BookingForm::cdrStartDate_DateChanged);
			// 
			// lblValjDatum
			// 
			this->lblValjDatum->AutoSize = true;
			this->lblValjDatum->Location = System::Drawing::Point(351, 23);
			this->lblValjDatum->Name = L"lblValjDatum";
			this->lblValjDatum->Size = System::Drawing::Size(84, 20);
			this->lblValjDatum->TabIndex = 8;
			this->lblValjDatum->Text = L"Välj datum";
			// 
			// lblValtDatum
			// 
			this->lblValtDatum->AutoSize = true;
			this->lblValtDatum->Location = System::Drawing::Point(351, 56);
			this->lblValtDatum->Name = L"lblValtDatum";
			this->lblValtDatum->Size = System::Drawing::Size(51, 20);
			this->lblValtDatum->TabIndex = 9;
			this->lblValtDatum->Text = L"label2";
			this->lblValtDatum->Visible = false;
			// 
			// pnlDate
			// 
			this->pnlDate->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlDate->Controls->Add(this->label1);
			this->pnlDate->Controls->Add(this->lbl1);
			this->pnlDate->Controls->Add(this->txtEndTimeMinutes);
			this->pnlDate->Controls->Add(this->txtStartTimeMinutes);
			this->pnlDate->Controls->Add(this->txtEndTimeHour);
			this->pnlDate->Controls->Add(this->txtStartTimeHour);
			this->pnlDate->Controls->Add(this->lblEndTime);
			this->pnlDate->Controls->Add(this->lblStartTime);
			this->pnlDate->Controls->Add(this->btnShowRoomsPnlDate);
			this->pnlDate->Controls->Add(this->cdrStartDate);
			this->pnlDate->Controls->Add(this->lblValtDatum);
			this->pnlDate->Controls->Add(this->lblValjDatum);
			this->pnlDate->Location = System::Drawing::Point(34, 228);
			this->pnlDate->Name = L"pnlDate";
			this->pnlDate->Size = System::Drawing::Size(557, 343);
			this->pnlDate->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(413, 250);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 20);
			this->label1->TabIndex = 24;
			this->label1->Text = L":";
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->Location = System::Drawing::Point(413, 158);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(13, 20);
			this->lbl1->TabIndex = 23;
			this->lbl1->Text = L":";
			
			// 
			// txtEndTimeMinutes
			// 
			this->txtEndTimeMinutes->Enabled = false;
			this->txtEndTimeMinutes->Location = System::Drawing::Point(436, 247);
			this->txtEndTimeMinutes->Name = L"txtEndTimeMinutes";
			this->txtEndTimeMinutes->Size = System::Drawing::Size(28, 26);
			this->txtEndTimeMinutes->TabIndex = 22;
			// 
			// txtStartTimeMinutes
			// 
			this->txtStartTimeMinutes->Enabled = false;
			this->txtStartTimeMinutes->Location = System::Drawing::Point(436, 155);
			this->txtStartTimeMinutes->Name = L"txtStartTimeMinutes";
			this->txtStartTimeMinutes->Size = System::Drawing::Size(28, 26);
			this->txtStartTimeMinutes->TabIndex = 20;
			// 
			// txtEndTimeHour
			// 
			this->txtEndTimeHour->Enabled = false;
			this->txtEndTimeHour->Location = System::Drawing::Point(374, 247);
			this->txtEndTimeHour->Name = L"txtEndTimeHour";
			this->txtEndTimeHour->Size = System::Drawing::Size(28, 26);
			this->txtEndTimeHour->TabIndex = 21;
			// 
			// txtStartTimeHour
			// 
			this->txtStartTimeHour->Enabled = false;
			this->txtStartTimeHour->Location = System::Drawing::Point(374, 155);
			this->txtStartTimeHour->Name = L"txtStartTimeHour";
			this->txtStartTimeHour->Size = System::Drawing::Size(28, 26);
			this->txtStartTimeHour->TabIndex = 19;
			// 
			// lblEndTime
			// 
			this->lblEndTime->AutoSize = true;
			this->lblEndTime->Location = System::Drawing::Point(351, 210);
			this->lblEndTime->Name = L"lblEndTime";
			this->lblEndTime->Size = System::Drawing::Size(160, 20);
			this->lblEndTime->TabIndex = 18;
			this->lblEndTime->Text = L"Välj Sluttid (Tim : Min)";
			// 
			// lblStartTime
			// 
			this->lblStartTime->AutoSize = true;
			this->lblStartTime->Location = System::Drawing::Point(351, 123);
			this->lblStartTime->Name = L"lblStartTime";
			this->lblStartTime->Size = System::Drawing::Size(167, 20);
			this->lblStartTime->TabIndex = 17;
			this->lblStartTime->Text = L"Välj Starttid (Tim : Min)";
			// 
			// btnShowRoomsPnlDate
			// 
			this->btnShowRoomsPnlDate->Enabled = false;
			this->btnShowRoomsPnlDate->Location = System::Drawing::Point(342, 292);
			this->btnShowRoomsPnlDate->Name = L"btnShowRoomsPnlDate";
			this->btnShowRoomsPnlDate->Size = System::Drawing::Size(169, 36);
			this->btnShowRoomsPnlDate->TabIndex = 16;
			this->btnShowRoomsPnlDate->Text = L"Visa lediga salar";
			this->btnShowRoomsPnlDate->UseVisualStyleBackColor = true;
			this->btnShowRoomsPnlDate->Click += gcnew System::EventHandler(this, &BookingForm::btnShowRoomsPnlDate_Click);
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
			this->pnlCourseMmt->Location = System::Drawing::Point(3, 87);
			this->pnlCourseMmt->Name = L"pnlCourseMmt";
			this->pnlCourseMmt->Size = System::Drawing::Size(535, 111);
			this->pnlCourseMmt->TabIndex = 15;
			// 
			// cbxSelCouMmt
			// 
			this->cbxSelCouMmt->FormattingEnabled = true;
			this->cbxSelCouMmt->Location = System::Drawing::Point(8, 53);
			this->cbxSelCouMmt->Name = L"cbxSelCouMmt";
			this->cbxSelCouMmt->Size = System::Drawing::Size(249, 28);
			this->cbxSelCouMmt->TabIndex = 16;
			this->cbxSelCouMmt->SelectedIndexChanged += gcnew System::EventHandler(this, &BookingForm::cbxSelCouMmt_SelectedIndexChanged);
			// 
			// btnOkPnlCourseMmt
			// 
			this->btnOkPnlCourseMmt->Enabled = false;
			this->btnOkPnlCourseMmt->Location = System::Drawing::Point(339, 53);
			this->btnOkPnlCourseMmt->Name = L"btnOkPnlCourseMmt";
			this->btnOkPnlCourseMmt->Size = System::Drawing::Size(169, 33);
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
			this->pnlCourse->Location = System::Drawing::Point(34, 23);
			this->pnlCourse->Name = L"pnlCourse";
			this->pnlCourse->Size = System::Drawing::Size(557, 190);
			this->pnlCourse->TabIndex = 16;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->btnAvbryt);
			this->panel1->Controls->Add(this->pnlCourse);
			this->panel1->Controls->Add(this->btnBook);
			this->panel1->Controls->Add(this->pnlDate);
			this->panel1->Location = System::Drawing::Point(21, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(993, 640);
			this->panel1->TabIndex = 17;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->cbxSelectTeacher);
			this->panel2->Controls->Add(this->lblSelectTeacher);
			this->panel2->Controls->Add(this->lblAvailableRooms);
			this->panel2->Controls->Add(this->lbxAvailableRooms);
			this->panel2->Location = System::Drawing::Point(618, 23);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(346, 548);
			this->panel2->TabIndex = 18;
			// 
			// cbxSelectTeacher
			// 
			this->cbxSelectTeacher->Enabled = false;
			this->cbxSelectTeacher->FormattingEnabled = true;
			this->cbxSelectTeacher->Location = System::Drawing::Point(24, 452);
			this->cbxSelectTeacher->Name = L"cbxSelectTeacher";
			this->cbxSelectTeacher->Size = System::Drawing::Size(249, 28);
			this->cbxSelectTeacher->TabIndex = 20;
			this->cbxSelectTeacher->SelectedIndexChanged += gcnew System::EventHandler(this, &BookingForm::cbxSelectTeacher_SelectedIndexChanged);
			// 
			// lblSelectTeacher
			// 
			this->lblSelectTeacher->AutoSize = true;
			this->lblSelectTeacher->Location = System::Drawing::Point(20, 415);
			this->lblSelectTeacher->Name = L"lblSelectTeacher";
			this->lblSelectTeacher->Size = System::Drawing::Size(79, 20);
			this->lblSelectTeacher->TabIndex = 19;
			this->lblSelectTeacher->Text = L"Välj lärare";
			// 
			// lblAvailableRooms
			// 
			this->lblAvailableRooms->AutoSize = true;
			this->lblAvailableRooms->Location = System::Drawing::Point(20, 10);
			this->lblAvailableRooms->Name = L"lblAvailableRooms";
			this->lblAvailableRooms->Size = System::Drawing::Size(107, 20);
			this->lblAvailableRooms->TabIndex = 18;
			this->lblAvailableRooms->Text = L"Lediga lokaler";
			// 
			// lbxAvailableRooms
			// 
			this->lbxAvailableRooms->FormattingEnabled = true;
			this->lbxAvailableRooms->ItemHeight = 20;
			this->lbxAvailableRooms->Location = System::Drawing::Point(24, 42);
			this->lbxAvailableRooms->Name = L"lbxAvailableRooms";
			this->lbxAvailableRooms->Size = System::Drawing::Size(291, 344);
			this->lbxAvailableRooms->TabIndex = 7;
			this->lbxAvailableRooms->SelectedIndexChanged += gcnew System::EventHandler(this, &BookingForm::lbxAvailableRooms_SelectedIndexChanged);
			// 
			// btnAvbryt
			// 
			this->btnAvbryt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnAvbryt->Location = System::Drawing::Point(34, 588);
			this->btnAvbryt->Name = L"btnAvbryt";
			this->btnAvbryt->Size = System::Drawing::Size(155, 36);
			this->btnAvbryt->TabIndex = 17;
			this->btnAvbryt->Text = L"Avbryt";
			this->btnAvbryt->UseVisualStyleBackColor = true;
			this->btnAvbryt->Click += gcnew System::EventHandler(this, &BookingForm::btnAvbryt_Click);
			// 
			// BookingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 690);
			this->Controls->Add(this->panel1);
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
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
			 Void updateTxtNmbrOfStud(int id)
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
			 void updateTxtCourseName(int id)
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
			 Void updateLbxCourseMmt()
			 {
				 cbxSelCouMmt->Items->Add("föreläsning");
				 cbxSelCouMmt->Items->Add("övning");
				  cbxSelCouMmt->Items->Add("laboration");
			 }
			 bool controllTimes()
			 {
				 int sh, eh, sm, em; //start- och sluttimma, start- och slutminut
				 try
				 {
					 sh = Convert::ToInt32(txtStartTimeHour->Text);
					 sm = Convert::ToInt32(txtStartTimeMinutes->Text);
					 eh = Convert::ToInt32(txtEndTimeHour->Text);
					 em = Convert::ToInt32(txtEndTimeMinutes->Text);
				 }
				 catch (Exception^ e)
				 {
					 MessageBox::Show("Felaktig inmatning, måste ange heltal.");
					 return false;
				 }
				 if ((sh >= 0 && sh < 25) && (sm >= 0 && sm < 61) && (eh >= 0 && eh < 25) && (em >= 0 && em < 61))
				 {					 
					 return true;
				 }
				 else
				 { 
					 MessageBox::Show("Felaktig inmatning\nTimmar: 0 - 24 \nMinuter: 0 - 60");
					 return false; 
				 }
			 }
			 bool controllSeats()
			 {
				 int tempSeats = 0;
				 try{ tempSeats = Convert::ToInt32(txtNmbrOfStud->Text); }
				 catch (Exception^ e)
				 {
					 MessageBox::Show("Felaktig inmatning, måste ange heltal.");
					 return false;
				 }
				 if (tempSeats >= 0){ return true; }
				 else
				 {
					 MessageBox::Show("Felaktig inmatning, måste ange heltal >= 0");
					 return false;
				 }
			 }
			 vector<Room^>^ getAvailableRoom()
			 {
				 // Lista med alla salar
				 _roomsVector = Room::getAllRooms();
				 // Lista med LokalId
				 
				 
				 dbHandler dbh;
				 DbCommand^ cmd = dbh.getCommand();
				 cmd->CommandText = "SELECT UndervisningsMoment.salsNr FROM UndervisningsMoment WHERE UndervisningsMoment.datum = @date AND @startTime <= UndervisningsMoment.slutTid AND @endTime >= UndervisningsMoment.startTid";
				
				 // Hämtar startTiden och lägger in den som ett timevärde
				 cmd->Parameters->Add(gcnew SqlParameter("@startTime", SqlDbType::Time));
				 cmd->Parameters["@startTime"]->Value = _startTime;
				 
				 // Hämtar slutTiden och lägger in den som ett timevärde
				 cmd->Parameters->Add(gcnew SqlParameter("@endTime", SqlDbType::Time));
				 cmd->Parameters["@endTime"]->Value = _endTime;
				 
				 // Hämtar datum och lägger in den som ett datevärde
				 cmd->Parameters->Add(gcnew SqlParameter("@date", SqlDbType::Date));
				 cmd->Parameters["@date"]->Value = _strDateSelected;
				 DbDataReader^ reader = cmd->ExecuteReader();
				 
				 //Lista med lokalId
				 vector<int>^ _roomIdVector = gcnew vector<int>();
				 while (reader->Read())
					 _roomIdVector->push_back(reader->GetInt32(0));
				 reader->Close();
				 cmd->Parameters->Clear();
				 vector<Room^> ^_availablerooms = gcnew vector<Room^>();
				 // Loopa igenom LokalListan och lägg till de rum som är lediga
				 for (int i = 0; i < _roomsVector->size(); i++)
				 {
					 Room^ _tmpRooms = _roomsVector->at(i);
					 // kolla om matchning finns
					 bool match = false;
					 for (int i = 0; i < _roomIdVector->size(); i++)
					 {
						 if (_tmpRooms->getRoomNr() == _roomIdVector->at(i))
						 {
							 match = true;
							 break;
						 }
					 }
					 if (!match && _tmpRooms->getSeats() >= _nmbrOfStud)
						 _availablerooms->push_back(_tmpRooms);
				 }
				 return _availablerooms;
			 }
			 void bookEducationMoment()
			 {
				 dbHandler dbh;
				 DbCommand^ cmd = dbh.getCommand();
				 
				 cmd->CommandText = "INSERT INTO UndervisningsMoment (kursKod, anstNr, typ, startTid, slutTid, datum, salsNr) SELECT @CourseId, @employeId, @type, @startTime, @endTime, @date, @roomNr";

				 // Lägger in kursKoden
				 cmd->Parameters->Add(gcnew SqlParameter("@CourseId", SqlDbType::Int));
				 cmd->Parameters["@CourseId"]->Value = _coursIdSelected;

				 // Lägger in anstNr
				 cmd->Parameters->Add(gcnew SqlParameter("@employeId", SqlDbType::Int));
				 cmd->Parameters["@employeId"]->Value = _allTeacherVector->at(cbxSelectTeacher->SelectedIndex)->getEmployeeNumber();

				 // Lägger in typ
				 cmd->Parameters->Add(gcnew SqlParameter("@type", SqlDbType::VarChar));
				 cmd->Parameters["@type"]->Value = _courseMomentSelected;

				 // Lägger in starttid
				 cmd->Parameters->Add(gcnew SqlParameter("@startTime", SqlDbType::Time));
				 cmd->Parameters["@startTime"]->Value = _startTime;

				 // Lägger in sluttid
				 cmd->Parameters->Add(gcnew SqlParameter("@endTime", SqlDbType::Time));
				 cmd->Parameters["@endTime"]->Value = _endTime;

				 // Lägger in datum
				 cmd->Parameters->Add(gcnew SqlParameter("@date", SqlDbType::Date));
				 cmd->Parameters["@date"]->Value = _strDateSelected;

				 // Lägger in rumsnr
				 cmd->Parameters->Add(gcnew SqlParameter("@roomNr", SqlDbType::Int));
				 cmd->Parameters["@roomNr"]->Value = _roomsVectorToLbxAvailableRooms->at(lbxAvailableRooms->SelectedIndex)->getRoomNr();
				 
				 cmd->ExecuteNonQuery();
				 cmd->Parameters->Clear();
				 MessageBox::Show("Bokning klar: \nUndervisningstyp: \t" + _courseMomentSelected + "\nDatum:\t\t" + _strDateSelected);
			 }

			 void updateCbxAllTeachers()
			 {
				 _allTeacherVector = Teacher::getAllTeachers();
				 vector<Teacher^>::iterator it = _allTeacherVector->begin();
				 for (it; it != _allTeacherVector->end(); it++)
				 {					
					 cbxSelectTeacher->Items->Add( (**it).getName());					 
				 }
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
				txtEndTimeMinutes->Enabled = true;
				txtEndTimeHour->Enabled = true;
				txtStartTimeHour->Enabled = true;
				txtStartTimeMinutes->Enabled = true;
	}
private: System::Void btnOkPnlCourseMmt_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 String^ str;
			 cdrStartDate->Enabled = true;
			 if (controllSeats()) //kontroller inmatning i antal studenter
			 {
				 _courseMomentSelected = cbxSelCouMmt->SelectedItem->ToString();
				 str = txtNmbrOfStud->Text;
				 _nmbrOfStud = Convert::ToInt32(str);
				 btnShowRoomsPnlDate->Enabled = true;
				 pnlDate->Enabled = true;
				 //MessageBox::Show(_couMmtSelected + str  );
			 }
}
private: System::Void btnShowRoomsPnlDate_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (controllTimes())
			 {
				 _startTime = ((txtStartTimeHour->Text) + ":" + (txtStartTimeMinutes->Text));
				 _endTime = (txtEndTimeHour->Text) + ":" + (txtEndTimeMinutes->Text);
				 //MessageBox::Show(_startTime + "\n" + _endTime);
				 // Hämtar alla salar
				 _roomsVectorToLbxAvailableRooms = getAvailableRoom();
				 lbxAvailableRooms->Items->Clear(); // rensar salfönstret
				 // Lägger in alla lediga salar
				 for (int i = 0; i < _roomsVectorToLbxAvailableRooms->size(); i++)
				 {
					 Room^ _Room = _roomsVectorToLbxAvailableRooms->at(i);
					 lbxAvailableRooms->Items->Add("Salsnummer: " + _Room->getRoomNr() + "   Platser: " + _Room->getSeats());
				 }
			 }
}		 
private: System::Void cbxSelCouMmt_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
{
			 btnOkPnlCourseMmt->Enabled = true;
}
private: System::Void btnAvbryt_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void lbxAvailableRooms_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 cbxSelectTeacher->Enabled = true;			 
			 updateCbxAllTeachers();			
}
private: System::Void btnBook_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 bookEducationMoment();
			 lbxAvailableRooms->Items->Clear();			 
			 cbxSelectTeacher->Items->Clear();
			 cbxSelectTeacher->Enabled = false;
			 btnBook->Enabled = false;
}
private: System::Void cbxSelectTeacher_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 btnBook->Enabled = true;
}
};

}
