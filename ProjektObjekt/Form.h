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
	#using <System.Data.Entity.dll>
	#include"Jobb.h"
	#include"Anställd.h"	
	#include <cliext\vector>

namespace Forms{

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
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		// Default constructor
		Form2(void)
		{
			InitializeComponent();
			
			// Connect to database engine
			//fac = DbProviderFactories::GetFactory("System.Data.SqlClient");
			//conn = fac->CreateConnection();
			//conn->ConnectionString = "Data Source=jth-stud.hj.se;Initial Catalog=DBmoab1313;Integrated Security=False;User ID=moab1313;Password=XXXXXX;Connect Timeout=15;Encrypt=False;TrustServerCertificate=False";
			//conn->Open();

			// Prepare DB command
			//cmd = fac->CreateCommand();
			//cmd->Connection = conn;

			// Fill vector with Anställd objects using static method hämtaAlla() in class Anställd
		    //vector<Anställd^>^ anställdvektor = Anställd::hämtaAlla(cmd);
			
			// Iterate through vector and add .förnamn and .efternamn to listBox1
			//vector<Anställd^>::iterator it = anställdvektor->begin();
			//listBox1->Items->Clear();
			//for(it; it!=anställdvektor->end(); it++)
			//{
			//	comboBox1->Items->Add((**it).förnamn() + "  " + (**it).efternamn());
			//}
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

		// Windows forms components declarations
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(172, 149);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 22);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Spara";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(125, 123);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(88, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(122, 97);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Beskrivning";
			this->label1->Click += gcnew System::EventHandler(this, &Form2::label1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(125, 178);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(185, 95);
			this->listBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(231, 123);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(79, 20);
			this->textBox2->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(228, 97);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Tidsåtgång";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(182, 279);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Radera allt";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(172, 31);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(451, 371);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/*
		 * Windows forms event handlers
		 */

	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e)
		{
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//try
			//{
			//	// Get Anställd objects into vector using hämtaAlla().
			//	// cmd was prepared in the constructor
			//	vector<Anställd^>^ anställdvektor = Anställd::hämtaAlla(cmd);
			//	
			//	// Call Jobb::spara to save whats in textBox1
			//	Jobb::spara(cmd, gcnew String(textBox1->Text), Convert::ToInt32(textBox2->Text), anställdvektor[comboBox1->SelectedIndex]->id(), 3);
			//	
			//	// Get Jobb objects into vector using Jobb::hämtaAlla
			//	vector<Jobb^>^ jobbvvektor=Jobb::hämtaAlla(cmd);
			//	
			//	// Iterate through vector and add Jobb object contents to listBox1
			//	vector<Jobb^>::iterator it=jobbvvektor->begin();
			//	listBox1->Items->Clear();
			//	for(it;it!=jobbvvektor->end(); it++)
			//	{
			//		listBox1->Items->Add((**it).beskrivning() + "          " + Convert::ToString((**it).tidsåtgång()) + "      " + Anställd::hämtaFörnamn(cmd, (**it).anställdId()));
			//	}
			//}
			//catch(Exception^ e)
		    //{
			//	// Print exception message in listBox1 if there was an error
			//	listBox1->Items->Add(e->Message);
			//}
		}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
		{
		}
	
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
		{
		}
	
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//// Call Jobb::deleteAll() and clear contents in listBox1
			//Jobb::deleteAll(cmd);
			//listBox1->Items->Clear();
		}

	}; // End of class Form2
} // End of namespace Forms
