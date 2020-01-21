#include "MainWindow.h"
#include <Windows.h>
#include <string>


using namespace System;
using namespace System::Windows::Forms;
typedef char(_stdcall *enigmaCpp)(char[], char[], char[], char);
typedef char(_stdcall *enigmaAsm)(char*, char*, char*, char*, char*, char);

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

void updateAllRotors(System::Windows::Forms::Label^ r1, System::Windows::Forms::Label^ r2, System::Windows::Forms::Label^ r3, char arr1[26], char arr2[26], char arr3[26]) {
	updateRotor(r1, arr1);
	updateRotor(r2, arr2);
	updateRotor(r3, arr3);
}

std::string enigmaMachineCPP(System::String^ userInputText, char arr1[26], char arr2[26], char arr3[26]) {
	std::string outputText;
	char letter;
	HINSTANCE cppDll = LoadLibraryA("cppdll");
	enigmaCpp enigmacpp = (enigmaCpp)GetProcAddress(cppDll, "enigma");
	for (int i = 0; i < userInputText->Length; i++) {
		if (userInputText[i] == L' ') {
			letter = ' ';
		}
		else {
			letter = enigmacpp(arr1, arr2, arr3, userInputText[i]);
		}
		outputText += letter;
		moveRotorUp(arr1);
		moveRotorUp(arr2);
		moveRotorUp(arr2);
		moveRotorDown(arr3);
	}
	return outputText;
}

std::string enigmaMachineASM(System::String^ userInputText, char startArr[26], char arr1[26], char arr2[26], char arr3[26], char refl[26])
{
	char* start = startArr;
	char* r1 = arr1;
	char* r2 = arr2;
	char* r3 = arr3;
	char* ref = refl;
	std::string outputText;
	char letter;
	HINSTANCE asmDll = LoadLibraryA("asmdll");
	enigmaAsm enigmaasm = (enigmaAsm)GetProcAddress(asmDll, "enigmaAsm");
	for (int i = 0; i < userInputText->Length; i++) {
		if (userInputText[i] == L' ') {
			letter = ' ';
		}
		else {
			letter = enigmaasm(start, r1, r2, r3, ref, userInputText[i]); //assembler
		}
		outputText += letter;
		moveRotorUp(arr1);
		moveRotorUp(arr2);
		moveRotorUp(arr2);
		moveRotorDown(arr3);
	}
	return outputText;
}

