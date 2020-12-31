#ifndef _dataaccess_Employee_Data_H_
#define _dataaccess_Employee_Data_H_
#include <vector>
#include "../businessobject/Employee.h"
#include <string>
#include "CompanyData.h"
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
    int ExportToFile(string filename);
    void Read_From_File();
    void Edit_Table();
   
};
#endif