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
			updateTxtBoxes(coursIdSelected);
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
			this->txtCourseName = (gcnew System::Windows::Forms::TextBox());
			this->txtNmbrOfStud = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// txtCourseName
			// 
			this->txtCourseName->Location = System::Drawing::Point(116, 90);
			this->txtCourseName->Name = L"txtCourseName";
			this->txtCourseName->Size = System::Drawing::Size(100, 26);
			this->txtCourseName->TabIndex = 0;
			this->txtCourseName->TextChanged += gcnew System::EventHandler(this, &BookingForm::txtCourseName_TextChanged);
			// 
			// txtNmbrOfStud
			// 
			this->txtNmbrOfStud->Location = System::Drawing::Point(351, 90);
			this->txtNmbrOfStud->Name = L"txtNmbrOfStud";
			this->txtNmbrOfStud->Size = System::Drawing::Size(100, 26);
			this->txtNmbrOfStud->TabIndex = 1;
			// 
			// BookingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 434);
			this->Controls->Add(this->txtNmbrOfStud);
			this->Controls->Add(this->txtCourseName);
			this->Name = L"BookingForm";
			this->Text = L"BookingForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txtCourseName_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
	}
			 System::Void updateTxtBoxes(int id)
			 {
				 dbHandler dbh;
				 DbCommand^ cmd = dbh.getCommand();
				 //DbDataReader^ reader = cmd->ExecuteReader();
				 cmd->CommandText = "Select COUNT(personNr) FROM StudentLäserKurs WHERE kursKod = @id";
				 cmd->Parameters->Add(gcnew SqlParameter("@id", SqlDbType::Int));
				 cmd->Parameters["@id"]->Value = id;
				 DbDataReader^ reader = cmd->ExecuteReader();
				 reader->Read();
				  int result = reader->GetInt32(0);
				  txtNmbrOfStud->Text = result.ToString();
			 }
	};

}
