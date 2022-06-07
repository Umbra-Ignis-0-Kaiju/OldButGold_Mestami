#pragma once

namespace Projecttt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Emgu::CV::UI::ImageBox^ imageBox1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->imageBox1 = (gcnew Emgu::CV::UI::ImageBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// imageBox1
			// 
			this->imageBox1->Location = System::Drawing::Point(12, 12);
			this->imageBox1->Name = L"imageBox1";
			this->imageBox1->Size = System::Drawing::Size(391, 356);
			this->imageBox1->TabIndex = 2;
			this->imageBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(978, 538);
			this->Controls->Add(this->imageBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
