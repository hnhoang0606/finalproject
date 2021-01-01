#include "DepartmentData.h"
#include<fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

DepartmentData::DepartmentData(){
    _maxId = 0;
    _data.resize(0);
}

DepartmentData::DepartmentData(string fileName){
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        Department p(
            j["Id"],
            j["DName"],
            j["MgrSSN"],
            j["MgrStartDate"],
            j["Dnumber"]
        );
        _data.push_back(p);
    }
    inFile.close();
}

int DepartmentData::GetMaxId(){
    return _maxId;
}

int DepartmentData::PushBack(Department department){
    _maxId++;
    department.Id = _maxId;
    _data.push_back(department);
    return _maxId;
}

Department* DepartmentData::GetPointer(int i){
    Department* department = nullptr;
    if( i >= 0 && (_data.size()) ) department = &_data[i];
    return department;
}

int DepartmentData::GetSize(){
    return _data.size();
}

Department DepartmentData::Get(int i){
    string s("index out bound");
    if(i < 0) throw s;
    if( i >= _data.size() ) throw s;
    return _data[i];
}

int DepartmentData::ExportToFile(string fileName ){
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(Department p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}

void DepartmentData :: Edit_Table ()
{
    Ui ui;
    int i;
    Department department;
    DepartmentData departmentData("Department.data");
    i = ui.ChooseToEdit();
    department = departmentData._data[i];
    departmentData._data[i] = EnterDepartmentInfor(department);
    departmentData.ExportToFile("Department.data");
}

// bool DepartmentData::AddMember(Company* company){
//     _maxId++;
//     Department* department = (Department*)company;
//     department->Id = _maxId;
//     _data.push_back(*department);
//     return true;
// }

// bool DepartmentData::DeleteMember(int i){
//     if(i < 0){
//         return false;
//     }else{
//         for(int index=i; index<_data.size()-1; ++index){
//             _data[index].Id = _data[index+1].Id - 1;
//             _data[index].DName = _data[index+1].DName;
//             _data[index].MgrSSN = _data[index+1].MgrSSN;
//             _data[index].MgrStartDate = _data[index+1].MgrStartDate;
//             _data[index].Dnumber = _data[index+1].Dnumber;
//         }
//         _data.pop_back();
//     return true;   
//     }
// }
