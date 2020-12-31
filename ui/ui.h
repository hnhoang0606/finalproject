#ifndef _ui_ui_H
#define _ui_ui_H
#include<iostream>
#include"../businessobject/Employee.h"
#include "../businessobject/Dependent.h"
#include "../businessobject/Work_on.h"
#include "../businessobject/Project.h"
#include "../businessobject/Department.h"
#include "../dataaccess/EmployeeData.h"
#include "../dataaccess/DependentData.h"
#include "../dataaccess/Work_onData.h"
#include "../dataaccess/ProjectData.h"
#include "../dataaccess/DepartmentData.h"

//#include "../dataaccess/Work_onData.h"
using namespace std;

class Ui 
 {   
    public:
        void getEmployee();
        void MainInterface();
        void ChooseFuntion(int &a);
        void ChooseTable();
        void ChooseOption();
        int ChooseToEdit();
        void DisplayEmployee();
        void DisplayDependent();
        void DisplayWork_on();
        void DisplayProject();
        void DisplayDepartment();
};

Employee EnterEmployeeInfor(Employee &employee);
Dependent EnterDependentInfor(Dependent &dependent);
Work_on EnterWork_onInfor(Work_on &Work_on);
Project EnterProjectInfor(Project &project);

#endif