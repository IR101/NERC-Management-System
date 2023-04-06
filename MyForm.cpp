#include "MyForm.h"
#include "acc.h"
#include "Forget.h"
#include "permission.h"
#include "regform.h"
using namespace System;
using namespace System::Windows::Forms;
int main() {
	iff obj;
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew  DSnOOPwindowsapp::MyForm());  // Create and pass a handle to an instance of loginform to Application::Run
	if (obj.permission_create()){
		Application::Run(gcnew  DSnOOPwindowsapp::acc());
	}
	if (obj.permission_forget()) {
		Application::Run(gcnew  DSnOOPwindowsapp::Forget());
	}
	if (obj.permission_reg()) {
		Application::Run(gcnew  DSnOOPwindowsapp::regform());
	}

	return 0;
}