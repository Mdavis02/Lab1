#pragma once

namespace BitmapRetry2 {

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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(111, 348);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 67);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Button";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(64, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(333, 284);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(473, 447);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//Graphics ^g1, ^g2;
		int click = -1;
		Drawing::Brush^ yellowBrush;
		Drawing::Brush^ clearBrush;
		Drawing::Graphics^ g;
		Bitmap^ bmp = gcnew Bitmap(L"rosie.bmp");


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		/*g1 = this->CreateGraphics(); //for the form
		g2 = pictureBox1->CreateGraphics(); //for the pictureBox*/
		yellowBrush = gcnew Drawing::SolidBrush(Color::Yellow);
		clearBrush = gcnew Drawing::SolidBrush(Color::White);
		g = pictureBox1->CreateGraphics();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		click = click*-1;
		/*Brush ^mybrush, ^mybrush2;
		mybrush = gcnew SolidBrush(Color::Black);
		mybrush2 = gcnew SolidBrush(Color::Red);
		if (click >= 0)
			g2->FillEllipse(mybrush, Rectangle(30, 30, 30, 30));
		else
			g2->FillEllipse(mybrush2, Rectangle(30, 30, 30, 30));*/
		Drawing::Rectangle circleRect(38, 25, 150, 150);
		if (click >= 0)
			//g->FillEllipse(yellowBrush, circleRect);
			g->DrawImage(bmp, 0, 0);
		else
			g->FillRectangle(clearBrush, Rectangle(0, 0, 498, 299));

	}

	};
}
