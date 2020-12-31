#include <iostream>
#include "businessobject/Employee.h"
#include "dataaccess/EmployeeData.h"
#include "libs/json.hpp"
#include <fstream>
#include <stdio.h>
#include "dataaccess/CompanyData.h"
#include "ui/ui.h"
#include<vector>
using namespace std;
using json = nlohmann::json;

void Write_Employee_to_file()
{
    Employee e1(1,"John", "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", 'M', 30000, 333445555, 5);
    Employee e2(2,"Franklin", "T", "Wong", 333445555, "1955-12-08", "638’vbss, Houston, TX", 'M', 40000, 888665555, 5);
    Employee e3(3,"Alida", "J", "Zelaya", 999887777, "1968-07-19", "3321 Castle, Spring. TX", 'F', 25000, 987654321, 4);
    Employee e4(4,"Jennifer", "S", "Wallace", 987654321, "1941-06-20", "291 Berry Bellaire. TX", 'F', 43000, 888665555, 4);
    Employee e5(5,"Ramesh", "K", "Narayan", 666884444, "1962-09-15", "975 Fire Oak, Huml* TX", 'M', 38000, 333445555, 5);
    Employee e6(6,"Joyce", "A", "English", 453453453, "1972-07-31", "5631 Rice, Houston, TX", 'F', 25000, 333445555, 5);
    Employee e7(7,"Ahmad", "V", "Jabbar", 987987987, "1969-03-29", "980 Dallas. Houston, TX", 'M', 25000, 987654321, 4);
    Employee e8(8,"James", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    Employee e9(9,"thomas", "E", "Borg", 888665555, "1937-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    Employee e10(10,"khkhkhkh", "E", "Borg", 888665555, "d5-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    Employee e11(11,"khkhkhkh", "E", "Borg", 888665555, "d5-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);
    Employee e12(12,"khkhkhkh", "E", "Borg", 888665555, "d5-11-10", "450 Stone, Houston, TX", 'M', 55000, -1, 1);

    EmployeeData employeeData;

    employeeData.PushBack(e1);
    employeeData.PushBack(e2);
    employeeData.PushBack(e3);
    employeeData.PushBack(e4);
    employeeData.PushBack(e5);
    employeeData.PushBack(e6);
    employeeData.PushBack(e7);
    employeeData.PushBack(e8);
    employeeData.PushBack(e9);
    employeeData.PushBack(e10);
    employeeData.PushBack(e11);
    employeeData.PushBack(e12);

    // for(int i = 0; i < employeeData.GetSize() ; i++)
    //     {
    //         Employee *e = employeeData.GetPointer(i);
    //         cout << e->ToString() << endl;
    //     }
    employeeData.ExportToFile("Employee.data");
}



void Read_Employee_from_file()
    {
        EmployeeData employeeData("Employee.data");
        for(int i =0; i< employeeData.GetSize(); i++)
        {   
            Employee p = employeeData.Get(i);
            cout<< p.ToString() <<endl;
        }
    }

void write_Project_To_File()
{
    Project p(6, "nguyenvan" ,"ha huy tap" ,7889990 ,898);
    ProjectData projectdata;
    projectdata.PushBack(p);
    projectdata.ExportToFile("Project.data");
}







int main()
{   
    // write_Project_To_File();
    // cout<<" file has been create";
    Ui ui;
    ui.MainInterface();

    //ui.ChooseToEdit();
    // Company *c1;
    // EmployeeData ea1;

    // c1 = &ea1;

    // int a;
    // cout<<" Choose the Table that you want to display in Screen"<<endl;
    // cout<<"**************************"<<endl;
    // cout<<"1. Employee table"<<endl;
    // cout<<"2. Department table"<<endl;
    // cout<<"3. Dept_Location table"<<endl;
    // cout<<"4. Project table"<<endl;
    // cout<<"5. Work_on table"<<endl;
    // cout<<"6. Dependent table"<<endl;
    // cout<<"***************************"<<endl;

    // cin>>a;

    // c1->Read_From_File();
    // c1->Edit_Table();



    cout<<"oke roi";








    // if (a==1)
    // {   EmployeeData ea2;
    //     ea2 = c1->Read_Employee_From_File();

    //     for(int i =0; i< ea2.GetSize(); i++)
    //     {   
    //             Employee p = ea2.Get(i);
    //             cout<< p.ToString() <<endl;
    //     }
    // }

    



    
    //     {   cout<<"da vao";
    //         Employee *e = employeeData.GetPointer(i);
    //         cout << e->ToString() << endl;
    //     }

    

    // EmployeeData employeeData("Employee.data");

    // for(int i = 0; i < employeeData.GetSize() ; i++)
    //     {
    //         Employee *e = employeeData.GetPointer(i);
    //         cout << e->ToString() << endl;
    //     }

    //Read_Employee_from_file();
    return 0;
}


    // for(int i = 0; i < 8; i++)
    // {
    //     Employee *e = employeeData.GetPointer(i);
    //     cout << e->ToString() << endl;
    // }
 
//     Employee* e = employeeData.GetPointer(2);
//     if (e == nullptr){
//         cout << "can not get Employee" << endl;
//     }
//     else{
//         cout << e->GetId() << endl;
//     }
//     return 0;
// }

