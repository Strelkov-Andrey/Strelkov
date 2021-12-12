#pragma once
#include "RK3.cpp"

namespace programm3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(-1, 0);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->MarkerSize = 15;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->MarkerSize = 15;
			series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(856, 512);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(759, 518);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Рассчитать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(896, 560);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		chart1->Series["Series1"]->Points->Clear();
		chart1->Series["Series2"]->Points->Clear();
		double E1, E2;
		double k1, k2, m1, m2;
		double h = 0.005;
		double t = 0;
		double v1 = 7;
		double v2 = 13;
		int step = 0;
		double u1 = 7;
		double u2 = 13;
		//cout << setw(10) << "t" << setw(12) << "h" << setw(12) << "v1" << setw(12) << "v2" << setw(12) << "u1" << setw(12) << "u2" << setw(15) << "E1" << setw(15) << "E2" << endl;
		//cout << setw(10) << t << setw(12) << h << setw(12) << v1 << setw(12) << v2 << setw(12) << u1 << setw(12) << u2 << endl;
		while (step < 100)
		{
			gauss(h, v1, v2, &k1, &k2, &m1, &m2);
			RK3(&t, &v1, &v2, h, k1, k2, m1, m2);
			true_solution(t, &u1, &u2);
			E1 = u1 - v1;
			E2 = u2 - v2;
			chart1->Series["Series1"]->Points->AddXY(t, v2);
			chart1->Series["Series2"]->Points->AddXY(t, v1);
			//cout << setw(10) << t << setw(12) << h << setw(12) << v1 << setw(12) << v2 << setw(12) << u1 << setw(12) << u2 << setw(15) << E1 << setw(15) << E2 << endl;
			step += 1;
		}
			
		
	}
	};
}
