#pragma once
#include "MyQueue.h"
#include <string>
using namespace std;
namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: TQueue<int>* q; // Очередь
	private: int size = 1; // Размер очереди
	private: int start = 0; // Начальный размер очереди
	private: double veroyatnost = 0; // Вероятность добавления элементов
	private: int dobavleno = 0; // Количество добавленных элементов
	private: int ydaleno = 0; // Количество удалённых элементов
	
	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = CreateGraphics();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Graphics^ gr;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label_dob;
	private: System::Windows::Forms::Label^ label_yda;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
	private:
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_dob = (gcnew System::Windows::Forms::Label());
			this->label_yda = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(388, 13);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(96, 26);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"0.5";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(388, 77);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(96, 26);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"10";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(388, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(96, 26);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"100";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(157, 115);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(166, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Удалено из очереди\r\n";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(147, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(176, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Добавлено в очередь";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(157, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(206, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Вероятность добавления";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(149, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(215, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Начальная длина очереди";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(157, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Размер очереди";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 62);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 94);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 62);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label6
			// 
			this->label_dob->AutoSize = true;
			this->label_dob->Location = System::Drawing::Point(354, 145);
			this->label_dob->Name = L"label6";
			this->label_dob->Size = System::Drawing::Size(18, 20);
			this->label_dob->TabIndex = 8;
			this->label_dob->Text = L"0";
			// 
			// label7
			// 
			this->label_yda->AutoSize = true;
			this->label_yda->Location = System::Drawing::Point(364, 115);
			this->label_yda->Name = L"label7";
			this->label_yda->Size = System::Drawing::Size(18, 20);
			this->label_yda->TabIndex = 9;
			this->label_yda->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Turquoise;
			this->ClientSize = System::Drawing::Size(496, 641);
			this->Controls->Add(this->label_yda);
			this->Controls->Add(this->label_dob);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Name = L"MyForm";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		double randomdouble = (double)rand() / (RAND_MAX); // Случайный double от 0 до 1

		if (randomdouble <= veroyatnost && !q->IsFull()) { // Добавление нового элемента
			q->Push(0);
			dobavleno++;
		}
		else if (randomdouble > veroyatnost && !q->IsEmpty()) { // Удаление элемента
			q->Get();
			ydaleno++;
		}

		gr->Clear(Color::Turquoise);
		if (!q->IsEmpty()) {
			Pen^ bp = gcnew Pen(Color::Black);
			bp->Width = 10.0f;
			int deg1 = q->GetStart() * 360.0 / q->GetSize(); // Начальный угол
			int deg2 = (q->GetStart() + q->GetCount()) * 360.0 / q->GetSize(); // Конечный угол
			gr->DrawArc(bp, 30, 150, 250, 250, deg1, deg2 - deg1); 
		}

		label_dob->Text = gcnew String(to_string(dobavleno).c_str());
		label_yda->Text = gcnew String(to_string(ydaleno).c_str());
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		size = Int32::Parse(textBox1->Text);
		start = Int32::Parse(textBox2->Text);
		veroyatnost = Double::Parse(textBox3->Text);

		q = new TQueue<int>(size);

		for (int i = 0; i < start; i++) {
			q->Push(1);
		}
		dobavleno = start;
		timer1->Enabled = true;

	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
	}
};
}
