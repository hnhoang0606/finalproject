#ifndef _ui_ui_H
#define _ui_ui_H
#include<iostream>
#include"../businessobject/Employee.h"
#include "../businessobject/Dependent.h"
#include "../businessobject/Work_on.h"
#include "../businessobject/Project.h"
#include "../businessobject/Department.h"
#include "../businessobject/DeptLocations.h"
#include "../dataaccess/EmployeeData.h"
#include "../dataaccess/DependentData.h"
#include "../dataaccess/Work_onData.h"
#include "../dataaccess/ProjectData.h"
#include "../dataaccess/DepartmentData.h"
#include "../dataaccess/DeptLocationsData.h"

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
        void DisplayDeptLocations();

        void CreateEmployee();
        void CreateDepartment();
        void CreateProject();
        void CreateWork_on();
        void CreateDependent();
        void CreateDeptLocations();

        void DeleteEmployee();
        void DeleteProject();
        void DeleteDepartment();
        void DeleteWork_on();
        void DeleteDependent();
        void DeleteDeptLocations();

        void RestructureCompany(); //cau2
        void EmployeeHaveChild();// cau3
        void GetNameProjectHours(); // cau4
        void EmployeeDontHaveProject();//cau 5
        void AverageSalaryOfDeparment(); // cau 6
        void AverageSalaryByGender();// cau7
        void LastNameOfManager();//cau 8

};

Employee EnterEmployeeInfor(Employee &employee);
Dependent EnterDependentInfor(Dependent &dependent);
Work_on EnterWork_onInfor(Work_on &Work_on);
Project EnterProjectInfor(Project &project);
Department EnterDepartmentInfor(Department &department);
DeptLocations EnterDeptLocationInfor(DeptLocations &deptLocations);

#endif