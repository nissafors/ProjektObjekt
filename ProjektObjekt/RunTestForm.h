#pragma once
#include "Student.h"

namespace ProjektObjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RunTestForm
	/// </summary>
	public ref class RunTestForm : public System::Windows::Forms::Form
	{
	public:
		RunTestForm(int examinationCode, Student^ student)
			: _examinationCode(examinationCode), _student(student)
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
		~RunTestForm()
		{
			if (components)
			{
				delete components;
			}
		}

		// Our own members
	private:
		int _examinationCode;
		Student^ _student;

		// Winforms members
	private: System::Windows::Forms::Label^  pageNumberLabel;
	private: System::Windows::Forms::Button^  nextButton;
	protected:

	protected:

	private: System::Windows::Forms::Button^  previousButton;

	private: System::Windows::Forms::CheckedListBox^  answersCheckedListBox;

	private: System::Windows::Forms::Label^  textLabel;
	private: System::Windows::Forms::RichTextBox^  answerRichTextBox;


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
			this->pageNumberLabel = (gcnew System::Windows::Forms::Label());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->previousButton = (gcnew System::Windows::Forms::Button());
			this->answersCheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->textLabel = (gcnew System::Windows::Forms::Label());
			this->answerRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// pageNumberLabel
			// 
			this->pageNumberLabel->AutoSize = true;
			this->pageNumberLabel->Location = System::Drawing::Point(12, 9);
			this->pageNumberLabel->Name = L"pageNumberLabel";
			this->pageNumberLabel->Size = System::Drawing::Size(58, 13);
			this->pageNumberLabel->TabIndex = 0;
			this->pageNumberLabel->Text = L"Page 1 / 1";
			// 
			// nextButton
			// 
			this->nextButton->Location = System::Drawing::Point(551, 354);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(75, 23);
			this->nextButton->TabIndex = 1;
			this->nextButton->Text = L"Next";
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &RunTestForm::nextButton_Click);
			// 
			// previousButton
			// 
			this->previousButton->Enabled = false;
			this->previousButton->Location = System::Drawing::Point(13, 354);
			this->previousButton->Name = L"previousButton";
			this->previousButton->Size = System::Drawing::Size(75, 23);
			this->previousButton->TabIndex = 2;
			this->previousButton->Text = L"Previous";
			this->previousButton->UseVisualStyleBackColor = true;
			this->previousButton->Click += gcnew System::EventHandler(this, &RunTestForm::previousButton_Click);
			// 
			// answersCheckedListBox
			// 
			this->answersCheckedListBox->FormattingEnabled = true;
			this->answersCheckedListBox->Location = System::Drawing::Point(12, 109);
			this->answersCheckedListBox->Name = L"answersCheckedListBox";
			this->answersCheckedListBox->Size = System::Drawing::Size(614, 109);
			this->answersCheckedListBox->TabIndex = 3;
			this->answersCheckedListBox->Visible = false;
			// 
			// textLabel
			// 
			this->textLabel->AutoSize = true;
			this->textLabel->Location = System::Drawing::Point(12, 39);
			this->textLabel->Name = L"textLabel";
			this->textLabel->Size = System::Drawing::Size(49, 13);
			this->textLabel->TabIndex = 4;
			this->textLabel->Text = L"Question";
			// 
			// answerRichTextBox
			// 
			this->answerRichTextBox->Location = System::Drawing::Point(12, 225);
			this->answerRichTextBox->Name = L"answerRichTextBox";
			this->answerRichTextBox->Size = System::Drawing::Size(614, 123);
			this->answerRichTextBox->TabIndex = 5;
			this->answerRichTextBox->Text = L"";
			this->answerRichTextBox->Visible = false;
			// 
			// RunTestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(638, 389);
			this->Controls->Add(this->answerRichTextBox);
			this->Controls->Add(this->textLabel);
			this->Controls->Add(this->answersCheckedListBox);
			this->Controls->Add(this->previousButton);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->pageNumberLabel);
			this->Name = L"RunTestForm";
			this->Text = L"Test";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Event handlers
	private:
		System::Void previousButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Load previous page.
		}

		System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Load next page or submit test (if last page).
		}
	};
}
