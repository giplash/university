#include <stdio.h>      
#include <math.h> 

#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LibVis3a::MyForm form;
	Application::Run(%form);
}
