#include "MainWindow.h"
#include <Windows.h>


using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Enigma::MainWindow form;
	Application::Run(%form);
}

void moveRotorUp(char arr[26]) {
	char tmp[26];
	tmp[0] = arr[25];
	for (int i = 0; i < 26; i++) {
		if (i != 25) {
			tmp[i + 1] = arr[i];
		}
	}
	strncpy(arr, tmp, 26);
}


void moveRotorDown(char arr[26]) {
	char tmp;
	tmp = arr[0];
	for (int i = 0; i < 26; i++) {
		if (i != 25) {
			arr[i] = arr[i + 1];
		}
	}
	arr[25] = tmp;
}

void updateRotor(System::Windows::Forms::Label^ rot, char arr[26]) {
	std::string tmp;
	tmp.push_back(arr[0]);
	rot->Text = gcnew String(tmp.c_str());
}