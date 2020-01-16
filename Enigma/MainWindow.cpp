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