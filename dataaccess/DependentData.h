#ifndef _dataaccess_Dependent_Data_H_
#define _dataaccess_Dependent_Data_H_
#include <vector>
#include <string>
#include "CompanyData.h"
#include "../ui/ui.h"
#include "../businessobject/Dependent.h"
using namespace std;

class DependentData: public CompanyData{
private:
    vector<Dependent> _data;
    int _maxId;
public:
    DependentData();
    DependentData(string);
    int GetMaxId();
    int PushBack(Dependent);
    Dependent* GetPointer(int i);
    int GetSize();
    Dependent Get(int);
    int ExportToFile(string filename);
    void Edit_Table();
};
#endif