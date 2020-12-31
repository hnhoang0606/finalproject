#ifndef _WORK_ON_H_
#define _WORK_ON_H_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "../dataaccess/CompanyData.h"
using namespace std;
using nlohmann::json;

class Work_on{
    int Id;
    long ESSN;
    int PNO;
    float Hours;
public:
    // Default Contructor
    Work_on();
    // Contructor with paramaters
    Work_on(int Id,long eSSN,int pno,int hours);
    int GetId();
    string ToString();
    json ToJson();
    friend Work_on EnterWork_onInfor(Work_on &Work_on);
};
#endif