#ifndef _dataaccess_Employee_Data_H_
#define _dataaccess_Employee_Data_H_
#include <string>
#include <vector>
#include "CompanyData.h"
#include "../businessobject/Employee.h"
#include "../businessobject/Company.h"
#include "../ui/ui.h"
using namespace std;

class EmployeeData: public CompanyData{
private:
    vector <Employee> _data;
    int _maxId;
public:
    EmployeeData();
    int GetMaxId();
    int PushBack(Employee);
    //Employee Get(int i);
    Employee* GetPointer(int i);
    int GetSize();
    Employee Get (int);
    EmployeeData(string);
    int ExportToFile(string filename) override;
    void Read_From_File();
    void Edit_Table();

    bool AddMember(Company* ) override; // Q1
    bool DeleteMember(int ); // Q2

    string Restructure(string supervisorName);
    float CalculateSalary(long );

   
};
#endif