#include "MyForm.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;



using namespace System;
using namespace System::Windows::Forms;
using namespace Open::CV;

[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Projecttt::MyForm frm;
    Application::Run(% frm);

    

}