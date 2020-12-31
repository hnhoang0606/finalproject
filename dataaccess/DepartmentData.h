#ifndef Project_dataaccess_Department_Data_H_
#define Project_dataaccess_Department_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
//#include "../businessobject/Company.h"
#include "../businessobject/Department.h"

using namespace std;

class DepartmentData : public CompanyData{
private:
    vector<Department> _data;
    int _maxId;

public:

    DepartmentData();
    DepartmentData(string fileName);
    int GetMaxId();
    int PushBack(Department);
    Department* GetPointer(int i);
    int GetSize();
    Department Get(int i);
    int ExportToFile(string );
    // bool AddMember(Company* ) override;
    // bool DeleteMember(int ) override;
    
};
#endif