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
			this->SuspendLayout();
			// 
			// DoneButton
			// 
			this->DoneButton->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->DoneButton->Location = System::Drawing::Point(668, 358);
			this->DoneButton->Name = L"DoneButton";
			this->DoneButton->Size = System::Drawing::Size(75, 23);
			this->DoneButton->TabIndex = 0;
			this->DoneButton->Text = L"Done";
			this->DoneButton->UseVisualStyleBackColor = true;
			// 
			// EditScheduleForm
			// 
			this->AcceptButton = this->DoneButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(755, 393);
			this->Controls->Add(this->DoneButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"EditScheduleForm";
			this->Text = L"EditScheduleForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	};
}
