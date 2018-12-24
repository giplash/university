#pragma once
#include <stdio.h>      
#include <math.h> 
#include <iostream>

namespace LibVis3a {
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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(37, 31);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(968, 706);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1044, 752);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Variant 1";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		int l, b, h, w;
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		h = pictureBox1->Height;
		w = pictureBox1->Width;
								
		e->Graphics->DrawLine(Pens::Black, 0, h / 2, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w / 2, 0, w / 2, h);
		
		e->Graphics->DrawLine(Pens::Black, w - 25, h / 2 + 8, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w - 25, h / 2 - 8, w, h / 2);
		e->Graphics->DrawLine(Pens::Black, w / 2 - 8, 25, w / 2, 0);
		e->Graphics->DrawLine(Pens::Black, w / 2 + 8, 25, w / 2, 0);
		
		e->Graphics->DrawString("X", this->Font, Brushes::SteelBlue, w - 15, h / 2 - 25);
		e->Graphics->DrawString("Y", this->Font, Brushes::SteelBlue, w / 2 - 25, 5);
		double x1, x2, y1, y2, x, y, mx, my, x0, y0, dx, dt;

		x1 = -3.14; // from
		x2 = 3.14; // to
		dx = 0.001; // step
		y1 = tan(x1);
		y2 = tan(x2);
		x = x1;
		
		while (x <= x2)
		{
			y = pow(x, 2);
			if (y < y1) y1 = y;
			if (y > y2) y2 = y;
			x += dx;
		}
		

		my = 0.5*h / (y2 - y1); // mashtab po osi y
		mx = w / (x2 - x1); // mashtab po osi x
		x = x1;
		y1 = tan(x1);
		x += dx;
		// График
		while (x <= x2)
		{
			y = tan(x);
			e->Graphics->DrawLine(Pens::Black, (int)(x1*mx + w / 2), (int)(h / 2 - y1 * my), (int)(x*mx + w / 2), (int)(h / 2 - y * my));
			x1 = x;
			y1 = y;
			x += dx;
		}

		
		x1 = -3.14; // from
		x2 = 3.14; // to
		dx = 0.001; // step
		y1 = 1 / tan(x1);
		y2 = 1 / tan(x2);
		x = x1;

		while (x <= x2)
		{
			y = pow(x, 2);
			if (y < y1) y1 = y;
			if (y > y2) y2 = y;
			x += dx;
		}


		my = 0.5*h / (y2 - y1); // mashtab po osi y
		mx = w / (x2 - x1); // mashtab po osi x
		x = x1;
		y1 = 1 / tan(x1);
		x += dx;
		// График
		while (x <= x2)
		{
			double denominator;
			if (abs(tan(x)) > 0.000000001) {
				denominator = tan(x);
			}
			else {
				x += dx;
				continue;
			}
			y = 1 / denominator;
			e->Graphics->DrawLine(Pens::Red, (int)(x1*mx + w / 2), (int)(h / 2 - y1 * my), (int)(x*mx + w / 2), (int)(h / 2 - y * my));
			x1 = x;
			y1 = y;
			x += dx;
		}
		
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
};
}