#include "EmployeeData.h"
#include <string>
#include <fstream>
using namespace std;

EmployeeData::EmployeeData(){
    _maxId = 0;
    _data.resize(0);
}

int EmployeeData::GetMaxId(){
    return _maxId;
}

int EmployeeData::PushBack(Employee e){
    if (_maxId < e.GetId()){
        _maxId = e.GetId();
    }
    _data.push_back(e);
    return _maxId;
}


Employee* EmployeeData::GetPointer(int i){
    Employee* e = nullptr;
    if (i >= 0 && i<_data.size())
        e = &_data[i];
    return e;
}

int EmployeeData :: GetSize()
{
    return _data.size();
}

Employee EmployeeData:: Get(int i)
{
    string s("index out of bound");
    if(i<0) throw s;
    if(i> _data.size()) throw s;
    return _data [i];
}

EmployeeData::EmployeeData(string filename)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Employee e(

            j["Id"],
            j["FName"],
            j["MInit"], 
            j["LName"],
            j["SSN"],
            j["BDate"], 
            j["Address"],
            ((string)j["Sex"])[0],
            j["Salary"], 
            j["SuperSSN"],
            j["DNO"]

        );
        _data.push_back(e);
        _maxId ++;

    }
    inFile.close();
}

int EmployeeData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Employee e:_data){
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

void EmployeeData :: Read_From_File()
{
        EmployeeData employeeData("Employee.data");
        for(int i=0; i< employeeData.GetSize(); i++)
        {   
            Employee e = employeeData.Get(i);
            cout<< e.ToString() <<endl;
        }
}

void EmployeeData ::Edit_Table()
{
    Ui ui;
    int i;
    Employee employee1;
    EmployeeData employeeData("Employee.data");
    i = ui.ChooseToEdit();
    employee1 = employeeData._data[i];
    employeeData._data[i] = EnterEmployeeInfor(employee1);
    employeeData.ExportToFile("Employee.data");
}

bool EmployeeData::AddMember(Company* company){
    _maxId++; // _maxId = 7 
    Employee* employee =(Employee*) company;
    employee->Id = _maxId;
    _data.push_back(*employee);
    return true;
}

bool EmployeeData::DeleteMember(int i){
    if(i < 0){
        return false;
    }else{
        for(int index=i; index<_data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].FName = _data[index+1].FName;
            _data[index].MInit = _data[index+1].MInit;
            _data[index].LName = _data[index+1].LName;
            _data[index].SSN = _data[index+1].SSN;
            _data[index].BDate = _data[index+1].BDate;
            _data[index].Address = _data[index+1].Address;
            _data[index].Sex =_data[index+1].Sex;
            _data[index].Salary =_data[index+1].SuperSSN;
            _data[index].SuperSSN = _data[index+1].SuperSSN;
            _data[index].DNO = _data[index+1].DNO;  
        }
        _data.pop_back();
    return true;   
    }
}


string EmployeeData::Restructure(string supervisorName){
    long ssn = -1;
    string employeeList = " "; 
    for(int i = 0; i < _data.size(); ++i){
        string s = ( (_data[i].FName) + (_data[i].LName) ); 
        if( s == supervisorName ){
            ssn = _data[i].SSN;
            break;
        }
    }
    // if(ssn == -1) return " ";
    for(int i = 0; i < _data.size(); ++i){
        if((_data[i].SuperSSN - ssn) == 0){
            employeeList = employeeList + " ";
            employeeList = employeeList + _data[i].FName;
        }
    }
    return employeeList;
}

float EmployeeData::CalculateSalary(long mgrSSN){
    float averageSalary = 0;
    float countEmployee = 0;
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].SuperSSN == mgrSSN){
            averageSalary += _data[i].Salary;
            ++countEmployee;
        }
    }
    averageSalary /= float(countEmployee);

    return averageSalary;
}

// int EmployeeData::Update(int i, Products p){
//     if (i < 0) return -1;
//     if (i >= _data.size()) return -1;
//     _data[i] = p;
//     //assume p.ProductId = 5 and maxId = 4, then maxId = 5
//     if (maxId < p.ProductId) maxId = p.ProductId;
//     return maxId;
// }



// void EmployeeData :: Edit_Table ()
// {
//     EmployeeData employeeData("Employee.data");
//     for(int i =0; i< employeeData.GetSize(); i++)
//         {   
//             Employee e = employeeData.Get(i);
//             cout<< e.ToString() <<endl;
//         }
//     cout<<"|** Please enter the row in the table you want to edit **|" <<endl;
//     cout<<"Row__";
//     int n; cin >>n;
//     Employee e2 = employeeData.Get(n);
//     cout<<e2.ToString()<<endl;
 
//     cout<<"|**Please choose the item you want to edit in the table **|"<<endl;
//     cout<<"|** 1. FName **|"<<endl;
//     cout<<"|** 2. MInit **|"<<endl;
//     cout<<"|** 3. LName **|"<<endl;
//     cout<<"|** 4. SSN **|"<<endl;
//     cout<<"|** 5. BDate **|"<<endl;
//     cout<<"|** 6. Address **|"<<endl;
//     cout<<"|** 7. Sex **|"<<endl;
//     cout<<"|** 8. Salary **|"<<endl;
//     cout<<"|** 9. SuperSSN **|"<<endl;
//     cout<<"|** 10. DNO **|"<<endl;

//     int n2;
//     cin>>n2;
//     switch (n2)
//     {
//     case 1:
//         cout<<"Please enter your content to change.";
//         string s1;
//         cin>>s1;
//         e2.SetFname(s1);
//         cout<<"LName d doi " << e2.GetFName()<<endl;

//         employeeData._data[1] = e2;
//         //employeeData.PushBack(e2);
//         employeeData.ExportToFile("Employee.data");
//         cout<<endl;
//         cout<<"Data has changed"<<endl;
        
//         break;
    
//     }

// }



