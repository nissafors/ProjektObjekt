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
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(79, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Course to edit";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(83, 92);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(273, 28);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &EditScheduleForm::comboBox1_SelectedIndexChanged);
			// 
			// EditScheduleForm
			// 
			this->AcceptButton = this->DoneButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1132, 605);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->DoneButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"EditScheduleForm";
			this->Text = L"EditScheduleForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{

	}
	};
}
