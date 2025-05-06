#pragma once

namespace LABA72 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(94, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(169, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(94, 77);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(169, 22);
			this->textBox2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(74, 151);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Check Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(74, 207);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Generate password";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(49, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"login:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Password:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(522, 288);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ login = textBox1->Text;

	try {
		if (!System::Text::RegularExpressions::Regex::IsMatch(login,
			"^(?=.*[A-Z])(?=.*\\d)(?=.*[^\\w\\s])(?=.{8,})[A-Za-z\\d\\W]+$")) {
			throw gcnew System::Exception("Логін повинен містити мінімум 1 велику літеру, 1 цифру, 1 спецсимвол, бути довжиною не менше 8 символів і складатися лише з англійських літер.");
		}
		MessageBox::Show("Логін коректний.");
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ password = GeneratePassword();
	textBox2->Text = password;

	try {
		if (!IsStrongPassword(password)) {
			throw gcnew System::Exception("Пароль не відповідає політиці Microsoft.");
		}
		MessageBox::Show("Пароль згенеровано і відповідає політиці безпеки.");
	}
	catch (System::Exception^ ex) {
		MessageBox::Show(ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

		 bool IsStrongPassword(String^ password) {
			 return System::Text::RegularExpressions::Regex::IsMatch(password,
				 "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^\\w\\s])(?=.{8,})");
		 }

		 String^ GeneratePassword() {
			 System::String^ chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
			 System::Random^ rand = gcnew System::Random();
			 System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();

			 for (int i = 0; i < 12; i++) {
				 sb->Append(chars[rand->Next(chars->Length)]);
			 }
			 return sb->ToString();
}
};
}
