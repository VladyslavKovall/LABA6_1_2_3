#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);

   LABA7::MyForm^ form = gcnew LABA7::MyForm();
   Application::Run(form);
   return 0;
}
