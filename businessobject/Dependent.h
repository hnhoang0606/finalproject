#ifndef _businessobject_Dependent_h_
#define _businessobject_Dependent_h_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "Company.h"
#include "../dataaccess/CompanyData.h"

using namespace std;
using nlohmann::json;

class Dependent : public Company{
    int Id;
    long ESSN;
    std::string DependentName;
    char Sex;
    std::string BDate;
    std::string Relationship;

public:
    friend class DependentData;
    Dependent();
    Dependent(int Id, long eSSN,std::string dependentName,char sex,std::string bDate,std::string relationship);
    int GetId();
    string ToString();
    json ToJson();
    friend Dependent EnterDependentInfor(Dependent &dependent);
    string GetRelationship();
    long GetESSN();
};
#endif