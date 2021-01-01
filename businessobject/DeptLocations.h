#ifndef _businessobject_DeptLocations_H_
#define _businessobject_DeptLocations_H_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "Company.h"
#include "../dataaccess/CompanyData.h"
using json = nlohmann::json;
using namespace std;

class DeptLocations : public Company{
    int Id;
    int DNumber;
    string DLocation;

public:
    friend class DeptLocationsData;
    // Default Contructor
    DeptLocations();
    // Contructor with paramaters
    DeptLocations(int id, int dNumber, string dLocation);
    string ToString();
    json ToJson();
    friend DeptLocations EnterDeptLocationInfor(DeptLocations &deptLocations);
};

#endif