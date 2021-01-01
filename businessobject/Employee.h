#ifndef _businessobject_Employee_h_
#define _businessobject_Employee_h_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "Company.h"
#include "../dataaccess/CompanyData.h"
using namespace std;
using nlohmann::json;

class Employee: public Company{
    int Id; //id is increasing number
    string FName, MInit, LName;
    long SSN;
    string BDate, Address;
    char Sex;
    int Salary;
    long SuperSSN;
    int DNO;

public:
    friend class EmployeeData;
    Employee();
    Employee(int id, string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno);
    int GetId();
    string ToString();
    json ToJson();
    

    // string GetFName();
    // // void ReadTable();
    // void SetFname(string );
    // void SetMInit(string);
    // void SetLName(string);
    // void SetSSN(long);
    // void SetBDate(string);
    // void SetAddress(string);
    // void SetSex(char);
    // void SetSalary(int);
    // void SetSuperSSN(long);
    // void SetDNO(int);
    friend Employee EnterEmployeeInfor(Employee &employee);
};
#endif