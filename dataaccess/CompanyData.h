#ifndef _dataaccess_Company_Data_H_
#define _dataaccess_Company_Data_H_
#include "../businessobject/Employee.h"
#include<vector>
using namespace std;


class CompanyData
{
     public:
          virtual void Edit_Table()=0;
};

#endif