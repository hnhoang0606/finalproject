#ifndef _DEPARTRMENT_H_
#define _DEPARTRMENT_H_
#include <string>
#include "../libs/json.hpp"
//#include "Company.h"

using json = nlohmann::json;
using namespace std;

class Department {
    int Id;
    string DName;
    long MgrSSN;
    string MgrStartDate;
    int Dnumber;

public:
    friend class DepartmentData;

    //Default Contructor
    Department();
    // Contructor with paramaters
    Department(int id, string dName, long mgrSSN, string mgrStartDate,int dNumber);
    string ToString();
    json ToJson();
};

#endif 