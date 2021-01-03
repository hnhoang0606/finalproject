#ifndef _dataaccess_Workon_Data_H_
#define _dataaccess_Workon_Data_H_
#include <vector>
#include <string>
#include "CompanyData.h"
#include "../ui/ui.h"
#include "../businessobject/Company.h"
#include "../businessobject/Work_on.h"
using namespace std;

class Work_onData : public CompanyData{
private:
    vector <Work_on> _data;
    int _maxId;
public:
    Work_onData();
    int GetMaxId();
    int PushBack(Work_on);
    Work_on* GetPointer(int i);
    int GetSize();
    Work_on Get(int);
    Work_onData(string);
    int ExportToFile(string filename);
    bool AddMember(Company* ) override;
    bool DeleteMember(int ) override;
    void Edit_Table();
    float GetHoursProject(int );
};
#endif