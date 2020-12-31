#ifndef _businessobject_Dependent_h_
#define _businessobject_Dependent_h_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "../dataaccess/CompanyData.h"
using namespace std;
using nlohmann::json;

class Dependent{
    int Id;
    long ESSN;
    std::string DependentName;
    char Sex;
    std::string BDate;
    std::string Relationship;

public:
    Dependent();
    Dependent(int Id, long eSSN,std::string dependentName,char sex,std::string bDate,std::string relationship);
    int GetId();
    string ToString();
    json ToJson();
    friend Dependent EnterDependentInfor(Dependent &dependent);
};
#endif