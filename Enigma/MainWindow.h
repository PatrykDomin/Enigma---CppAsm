#pragma once

#include <string>
#include <chrono>
#include <algorithm>
#include <Windows.h>

void moveRotors(char arr1[26], char arr2[26]) {
	char tmp[26] = {};
	char tmp2[26] = {};
	tmp[0] = arr1[25];
	tmp2[25] = arr2[0];

	for (int i = 0; i < 26; i++) {
		if (i != 25) {
			tmp[i + 1] = arr1[i];
			tmp2[i] = arr2[i + 1];
		}
	}
	strncpy(arr1, tmp, 26);
	strncpy(arr2, tmp2, 26);
}

int getposition(char arr[26], char character) {
	for (int i = 0; i < 26; ++i) {
		if (arr[i] == character) {
			return i;
			break;
		}
	}
}


namespace Enigma {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	char startingArr[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char rotor1baseArr[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
	char rotor2baseArr[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
	char rotor3baseArr[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
	char reflectorArr[26] = { 'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T' };

	
	std::string starting = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string rotor1base = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	std::string rotor2base = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	std::string rotor3base = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
	std::string reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

	/// <summary>
	/// Podsumowanie informacji o MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  userInput1;
	private: System::Windows::Forms::Label^  outText;

	private: System::Windows::Forms::Label^  usrInpt1Label;
	private: System::Windows::Forms::Label^  usrInpt2Label;



	private: System::Windows::Forms::Label^  enigmaText;
	private: System::Windows::Forms::Label^  rotor1;
	private: System::Windows::Forms::Label^  rotor2;
	private: System::Windows::Forms::Label^  rotor3;
	private: System::Windows::Forms::Button^  encDecr;
	private: System::Windows::Forms::RadioButton^  asmButton;
	private: System::Windows::Forms::RadioButton^  cppButton;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Label^  time;
	private: System::Windows::Forms::Button^  upRotor1;
	private: System::Windows::Forms::Button^  downRotor1;
	private: System::Windows::Forms::Button^  upRotor2;
	private: System::Windows::Forms::Button^  downRotor2;
	private: System::Windows::Forms::Button^  upRotor3;
	private: System::Windows::Forms::Button^  downRotor3;

			 /// <summary>
			 /// Wymagana zmienna projektanta.
			 /// </summary>
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
			 /// jej zawartoœci w edytorze kodu.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->userInput1 = (gcnew System::Windows::Forms::TextBox());
				 this->usrInpt1Label = (gcnew System::Windows::Forms::Label());
				 this->usrInpt2Label = (gcnew System::Windows::Forms::Label());
				 this->enigmaText = (gcnew System::Windows::Forms::Label());
				 this->rotor1 = (gcnew System::Windows::Forms::Label());
				 this->rotor2 = (gcnew System::Windows::Forms::Label());
				 this->rotor3 = (gcnew System::Windows::Forms::Label());
				 this->outText = (gcnew System::Windows::Forms::Label());
				 this->encDecr = (gcnew System::Windows::Forms::Button());
				 this->asmButton = (gcnew System::Windows::Forms::RadioButton());
				 this->cppButton = (gcnew System::Windows::Forms::RadioButton());
				 this->startButton = (gcnew System::Windows::Forms::Button());
				 this->time = (gcnew System::Windows::Forms::Label());
				 this->upRotor1 = (gcnew System::Windows::Forms::Button());
				 this->downRotor1 = (gcnew System::Windows::Forms::Button());
				 this->upRotor2 = (gcnew System::Windows::Forms::Button());
				 this->upRotor3 = (gcnew System::Windows::Forms::Button());
				 this->downRotor3 = (gcnew System::Windows::Forms::Button());
				 this->downRotor2 = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // userInput1
				 // 
				 this->userInput1->Location = System::Drawing::Point(12, 127);
				 this->userInput1->Multiline = true;
				 this->userInput1->Name = L"userInput1";
				 this->userInput1->Size = System::Drawing::Size(310, 140);
				 this->userInput1->TabIndex = 1;
				 // 
				 // usrInpt1Label
				 // 
				 this->usrInpt1Label->AutoSize = true;
				 this->usrInpt1Label->Location = System::Drawing::Point(12, 104);
				 this->usrInpt1Label->Name = L"usrInpt1Label";
				 this->usrInpt1Label->Size = System::Drawing::Size(78, 17);
				 this->usrInpt1Label->TabIndex = 2;
				 this->usrInpt1Label->Text = L"Podaj tekst";
				 // 
				 // usrInpt2Label
				 // 
				 this->usrInpt2Label->AutoSize = true;
				 this->usrInpt2Label->Location = System::Drawing::Point(12, 288);
				 this->usrInpt2Label->Name = L"usrInpt2Label";
				 this->usrInpt2Label->Size = System::Drawing::Size(56, 17);
				 this->usrInpt2Label->TabIndex = 4;
				 this->usrInpt2Label->Text = L"Wyjœcie";
				 // 
				 // enigmaText
				 // 
				 this->enigmaText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->enigmaText->Location = System::Drawing::Point(12, 28);
				 this->enigmaText->Name = L"enigmaText";
				 this->enigmaText->Size = System::Drawing::Size(664, 47);
				 this->enigmaText->TabIndex = 5;
				 this->enigmaText->Text = L"Enigma";
				 this->enigmaText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // rotor1
				 // 
				 this->rotor1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->rotor1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->rotor1->Location = System::Drawing::Point(387, 139);
				 this->rotor1->Margin = System::Windows::Forms::Padding(0);
				 this->rotor1->Name = L"rotor1";
				 this->rotor1->Size = System::Drawing::Size(79, 57);
				 this->rotor1->TabIndex = 6;
				 this->rotor1->Text = L"E";
				 this->rotor1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // rotor2
				 // 
				 this->rotor2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->rotor2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->rotor2->Location = System::Drawing::Point(475, 139);
				 this->rotor2->Margin = System::Windows::Forms::Padding(0);
				 this->rotor2->Name = L"rotor2";
				 this->rotor2->Size = System::Drawing::Size(76, 57);
				 this->rotor2->TabIndex = 7;
				 this->rotor2->Text = L"A";
				 this->rotor2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // rotor3
				 // 
				 this->rotor3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->rotor3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->rotor3->Location = System::Drawing::Point(564, 139);
				 this->rotor3->Margin = System::Windows::Forms::Padding(0);
				 this->rotor3->Name = L"rotor3";
				 this->rotor3->Size = System::Drawing::Size(76, 57);
				 this->rotor3->TabIndex = 8;
				 this->rotor3->Text = L"B";
				 this->rotor3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // outText
				 // 
				 this->outText->BackColor = System::Drawing::SystemColors::Control;
				 this->outText->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->outText->Location = System::Drawing::Point(12, 313);
				 this->outText->Name = L"outText";
				 this->outText->Size = System::Drawing::Size(310, 207);
				 this->outText->TabIndex = 9;
				 this->outText->Text = L"output";
				 // 
				 // encDecr
				 // 
				 this->encDecr->Location = System::Drawing::Point(387, 277);
				 this->encDecr->Name = L"encDecr";
				 this->encDecr->Size = System::Drawing::Size(120, 67);
				 this->encDecr->TabIndex = 10;
				 this->encDecr->Text = L"Szyfrowanie";
				 this->encDecr->UseVisualStyleBackColor = true;
				 this->encDecr->Click += gcnew System::EventHandler(this, &MainWindow::encDecr_Click);
				 // 
				 // asmButton
				 // 
				 this->asmButton->AutoSize = true;
				 this->asmButton->Location = System::Drawing::Point(545, 286);
				 this->asmButton->Name = L"asmButton";
				 this->asmButton->Size = System::Drawing::Size(95, 21);
				 this->asmButton->TabIndex = 11;
				 this->asmButton->TabStop = true;
				 this->asmButton->Text = L"Assembler";
				 this->asmButton->UseVisualStyleBackColor = true;
				 // 
				 // cppButton
				 // 
				 this->cppButton->AutoSize = true;
				 this->cppButton->Checked = true;
				 this->cppButton->Location = System::Drawing::Point(545, 313);
				 this->cppButton->Name = L"cppButton";
				 this->cppButton->Size = System::Drawing::Size(54, 21);
				 this->cppButton->TabIndex = 12;
				 this->cppButton->TabStop = true;
				 this->cppButton->Text = L"C++";
				 this->cppButton->UseVisualStyleBackColor = true;
				 // 
				 // startButton
				 // 
				 this->startButton->Location = System::Drawing::Point(245, 273);
				 this->startButton->Name = L"startButton";
				 this->startButton->Size = System::Drawing::Size(77, 34);
				 this->startButton->TabIndex = 13;
				 this->startButton->Text = L"Start";
				 this->startButton->UseVisualStyleBackColor = true;
				 this->startButton->Click += gcnew System::EventHandler(this, &MainWindow::startButton_Click);
				 // 
				 // time
				 // 
				 this->time->BackColor = System::Drawing::SystemColors::Control;
				 this->time->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->time->Location = System::Drawing::Point(198, 557);
				 this->time->Name = L"time";
				 this->time->Size = System::Drawing::Size(284, 28);
				 this->time->TabIndex = 14;
				 this->time->Text = L"Time: ";
				 // 
				 // upRotor1
				 // 
				 this->upRotor1->Location = System::Drawing::Point(407, 104);
				 this->upRotor1->Name = L"upRotor1";
				 this->upRotor1->Size = System::Drawing::Size(35, 32);
				 this->upRotor1->TabIndex = 15;
				 this->upRotor1->Text = L"/\\";
				 this->upRotor1->UseVisualStyleBackColor = true;
				 this->upRotor1->Click += gcnew System::EventHandler(this, &MainWindow::upRotor1_Click);
				 // 
				 // downRotor1
				 // 
				 this->downRotor1->Location = System::Drawing::Point(407, 199);
				 this->downRotor1->Name = L"downRotor1";
				 this->downRotor1->Size = System::Drawing::Size(35, 32);
				 this->downRotor1->TabIndex = 16;
				 this->downRotor1->Text = L"\\/";
				 this->downRotor1->UseVisualStyleBackColor = true;
				 this->downRotor1->Click += gcnew System::EventHandler(this, &MainWindow::downRotor1_Click);
				 // 
				 // upRotor2
				 // 
				 this->upRotor2->Location = System::Drawing::Point(496, 104);
				 this->upRotor2->Name = L"upRotor2";
				 this->upRotor2->Size = System::Drawing::Size(35, 32);
				 this->upRotor2->TabIndex = 17;
				 this->upRotor2->Text = L"/\\";
				 this->upRotor2->UseVisualStyleBackColor = true;
				 this->upRotor2->Click += gcnew System::EventHandler(this, &MainWindow::upRotor2_Click);
				 // 
				 // upRotor3
				 // 
				 this->upRotor3->Location = System::Drawing::Point(584, 104);
				 this->upRotor3->Name = L"upRotor3";
				 this->upRotor3->Size = System::Drawing::Size(35, 32);
				 this->upRotor3->TabIndex = 18;
				 this->upRotor3->Text = L"/\\";
				 this->upRotor3->UseVisualStyleBackColor = true;
				 this->upRotor3->Click += gcnew System::EventHandler(this, &MainWindow::upRotor3_Click);
				 // 
				 // downRotor3
				 // 
				 this->downRotor3->Location = System::Drawing::Point(584, 199);
				 this->downRotor3->Name = L"downRotor3";
				 this->downRotor3->Size = System::Drawing::Size(35, 32);
				 this->downRotor3->TabIndex = 19;
				 this->downRotor3->Text = L"\\/";
				 this->downRotor3->UseVisualStyleBackColor = true;
				 this->downRotor3->Click += gcnew System::EventHandler(this, &MainWindow::downRotor3_Click);
				 // 
				 // downRotor2
				 // 
				 this->downRotor2->Location = System::Drawing::Point(496, 199);
				 this->downRotor2->Name = L"downRotor2";
				 this->downRotor2->Size = System::Drawing::Size(35, 32);
				 this->downRotor2->TabIndex = 20;
				 this->downRotor2->Text = L"\\/";
				 this->downRotor2->UseVisualStyleBackColor = true;
				 this->downRotor2->Click += gcnew System::EventHandler(this, &MainWindow::downRotor2_Click);
				 // 
				 // MainWindow
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(685, 594);
				 this->Controls->Add(this->downRotor2);
				 this->Controls->Add(this->downRotor3);
				 this->Controls->Add(this->upRotor3);
				 this->Controls->Add(this->upRotor2);
				 this->Controls->Add(this->downRotor1);
				 this->Controls->Add(this->upRotor1);
				 this->Controls->Add(this->time);
				 this->Controls->Add(this->startButton);
				 this->Controls->Add(this->cppButton);
				 this->Controls->Add(this->asmButton);
				 this->Controls->Add(this->encDecr);
				 this->Controls->Add(this->outText);
				 this->Controls->Add(this->rotor3);
				 this->Controls->Add(this->rotor2);
				 this->Controls->Add(this->rotor1);
				 this->Controls->Add(this->enigmaText);
				 this->Controls->Add(this->usrInpt2Label);
				 this->Controls->Add(this->usrInpt1Label);
				 this->Controls->Add(this->userInput1);
				 this->Name = L"MainWindow";
				 this->Text = L"Enigma";
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private: System::Void encDecr_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->encDecr->Text == "Szyfrowanie") {
			this->encDecr->Text = "Odszyfrowanie";
		}
		else {
			this->encDecr->Text = "Szyfrowanie";
		}
	}
	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) {
		auto start = std::chrono::steady_clock::now();
		this->time->Text = L"Time: ";

		typedef char(_stdcall *enigmaCpp)(char[], char[], char[], char);
		HINSTANCE cppDll = LoadLibraryA("cppdll");
		enigmaCpp enigmacpp;
		enigmacpp = (enigmaCpp)GetProcAddress(cppDll, "enigma");
		typedef char(_stdcall *enigmaAsm)(int, int);
		HINSTANCE asmDll = LoadLibraryA("asmdll");
		enigmaAsm enigmaasm;
		enigmaasm = (enigmaAsm)GetProcAddress(asmDll, "enigmaAsm");


		std::string outputText;
		char letter;

		char startingArr[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
		char rotor1baseArr[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J' };
		char rotor2baseArr[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
		char rotor3baseArr[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };

		String^ userInputText = this->userInput1->Text->ToUpper();
		
		if (this->cppButton->Checked == true) {
			for (int i = 0; i < userInputText->Length; i++) { //DLA A \/
				if (userInputText[i] == L' ') {
					letter = ' ';
				}
				else {
					letter = enigmacpp(rotor1baseArr, rotor2baseArr, rotor3baseArr, userInputText[i]);
				}
				outputText += letter; //to tutaj
				moveRotors(rotor1baseArr, rotor3baseArr); //to tutaj
			}
		}
		else {
			for (int i = 0; i < userInputText->Length; i++) { //DLA A \/
				if (userInputText[i] == L' ') {
					letter = ' ';
				}
				else {
					int zmienna = enigmaasm(2, 3); //assembler
				}
				outputText += letter; //to tutaj
				moveRotors(rotor1baseArr, rotor3baseArr); //to tutaj
			}
		}


		this->outText->Text = gcnew String(outputText.c_str());
		auto end = std::chrono::steady_clock::now();
		auto diffChrono = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		this->time->Text = this->time->Text + diffChrono + L"µs";
	}
	private: System::Void upRotor1_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string rotor1Change;
		rotor1Change = rotor1base[25];
		rotor1base.erase(25, 1);
		rotor1base.insert(0, rotor1Change);
		rotor1Change = rotor1base[0];
		this->rotor1->Text = gcnew String(rotor1Change.c_str());
	}
	private: System::Void downRotor1_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string rotor1Change;
		rotor1Change = rotor1base[0];
		rotor1base.erase(0, 1);
		rotor1base.insert(25, rotor1Change);
		rotor1Change = rotor1base[0];
		this->rotor1->Text = gcnew String(rotor1Change.c_str());
	}
	private: System::Void upRotor2_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string rotor2Change;
		rotor2Change = rotor2base[25];
		rotor2base.erase(25, 1);
		rotor2base.insert(0, rotor2Change);
		rotor2Change = rotor2base[0];
		this->rotor2->Text = gcnew String(rotor2Change.c_str());
	}
	private: System::Void downRotor2_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string rotor2Change;
		rotor2Change = rotor2base[0];
		rotor2base.erase(0, 1);
		rotor2base.insert(25, rotor2Change);
		rotor2Change = rotor2base[0];
		this->rotor2->Text = gcnew String(rotor2Change.c_str());
	}
	private: System::Void upRotor3_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string rotor3Change;
		rotor3Change = rotor3base[25];
		rotor3base.erase(25, 1);
		rotor3base.insert(0, rotor3Change);
		rotor3Change = rotor3base[0];
		this->rotor3->Text = gcnew String(rotor3Change.c_str());
	}
	private: System::Void downRotor3_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string rotor3Change;
		rotor3Change = rotor3base[0];
		rotor3base.erase(0, 1);
		rotor3base.insert(25, rotor3Change);
		rotor3Change = rotor3base[0];
		this->rotor3->Text = gcnew String(rotor3Change.c_str());
	}
	};
}