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

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ t;
	private: System::Windows::Forms::ColumnHeader^ h;

	private: System::Windows::Forms::ColumnHeader^ v2;
	private: System::Windows::Forms::ColumnHeader^ u1;
	private: System::Windows::Forms::ColumnHeader^ u2;
	private: System::Windows::Forms::ColumnHeader^ E1;
	private: System::Windows::Forms::ColumnHeader^ E2;
	private: System::Windows::Forms::ColumnHeader^ v1;
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
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->t = (gcnew System::Windows::Forms::ColumnHeader());
			this->h = (gcnew System::Windows::Forms::ColumnHeader());
			this->v1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->v2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->u1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->u2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->E1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->E2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1002, 605);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Рассчитать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(3, 8);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1095, 591);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->chart1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1087, 565);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"График";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// chart1
			// 
			chartArea1->AxisX->IsMarginVisible = false;
			chartArea1->AxisX->IsMarksNextToAxis = false;
			chartArea1->AxisY->IsMarginVisible = false;
			chartArea1->AxisY->IsStartedFromZero = false;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(-4, 0);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->MarkerSize = 20;
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->MarkerSize = 15;
			series2->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series2->Name = L"Series2";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Legend = L"Legend1";
			series3->MarkerSize = 10;
			series3->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series3->Name = L"Series3";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(1085, 562);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::Chart1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->listView1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1087, 565);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Таблица";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->t, this->h, this->v1,
					this->v2, this->u1, this->u2, this->E1, this->E2
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(-4, 2);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(1088, 560);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// t
			// 
			this->t->Text = L"t";
			this->t->Width = 50;
			// 
			// h
			// 
			this->h->Text = L"h";
			// 
			// v1
			// 
			this->v1->Text = L"v1";
			this->v1->Width = 120;
			// 
			// v2
			// 
			this->v2->Text = L"v2";
			this->v2->Width = 120;
			// 
			// u1
			// 
			this->u1->Text = L"u1";
			this->u1->Width = 120;
			// 
			// u2
			// 
			this->u2->Text = L"u2";
			this->u2->Width = 120;
			// 
			// E1
			// 
			this->E1->Text = L"E1";
			this->E1->Width = 160;
			// 
			// E2
			// 
			this->E2->Text = L"E2";
			this->E2->Width = 160;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1110, 651);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		listView1->Items->Clear();
		array<String^>^ ms = gcnew array< System::String^ >(11);
		chart1->Series["Series1"]->Points->Clear();
		chart1->Series["Series2"]->Points->Clear();
		double E1, E2;
		double k1, k2, m1, m2;
		double h = 0.0001;
		double t = 0;
		double v1 = 7;
		double v2 = 13;
		int step = 0;
		double u1 = 7;
		double u2 = 13;
		double sepx=0;
		double sepy=0;
		ms[0] = t.ToString();
		ms[1] = h.ToString();
		ms[2] = v1.ToString();
		ms[3] = v2.ToString();
		ms[4] = u1.ToString();
		ms[5] = u2.ToString();
		ListViewItem^ listViewItem0 = gcnew ListViewItem(ms);
		listView1->Items->Add(listViewItem0);
		chart1->Series["Series1"]->Points->AddXY(t, v2);
		chart1->Series["Series2"]->Points->AddXY(t, v1);
		//cout << setw(10) << "t" << setw(12) << "h" << setw(12) << "v1" << setw(12) << "v2" << setw(12) << "u1" << setw(12) << "u2" << setw(15) << "E1" << setw(15) << "E2" << endl;
		//cout << setw(10) << t << setw(12) << h << setw(12) << v1 << setw(12) << v2 << setw(12) << u1 << setw(12) << u2 << endl;
		while (abs(v1-v2)> 0.000000001)
		{
			
			
			gauss(h, v1, v2, &k1, &k2, &m1, &m2);
			RK3(&t, &v1, &v2, h, k1, k2, m1, m2);
			true_solution(t, &u1, &u2);
			E1 = u1 - v1;
			E2 = u2 - v2;
			//sepy = sep(sepx);
			//sepx += h;
			chart1->Series["Series1"]->Points->AddXY(t, v2);
			chart1->Series["Series2"]->Points->AddXY(t, v1);
			//chart1->Series["Series3"]->Points->AddXY(sepx,sepy);
			ms[0] = t.ToString();
			ms[1] = h.ToString();
			ms[2] = v1.ToString();
			ms[3] = v2.ToString();
			ms[4] = u1.ToString();
			ms[5] = u2.ToString();
			ms[6] = E1.ToString();
			ms[7] = E2.ToString();
			listViewItem0 = gcnew ListViewItem(ms);
			listView1->Items->Add(listViewItem0);
			//cout << setw(10) << t << setw(12) << h << setw(12) << v1 << setw(12) << v2 << setw(12) << u1 << setw(12) << u2 << setw(15) << E1 << setw(15) << E2 << endl;
			step += 1;
		}
			
		
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
