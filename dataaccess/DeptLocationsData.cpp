#include "DeptLocationsData.h"
#include <fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

DeptLocationsData::DeptLocationsData(){
    _maxId = 0;
    _data.resize(0);
}

DeptLocationsData::DeptLocationsData(string fileName){
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        DeptLocations p(
            j["Id"],
            j["DNumber"],
            j["DLocation"]
            );
        _data.push_back(p);
    }
    inFile.close();
}

int DeptLocationsData::GetMaxId(){
    return _maxId;
}

int DeptLocationsData::PushBack(DeptLocations deptLocations){
    _maxId++;
    deptLocations.Id = _maxId;
    _data.push_back(deptLocations);
    return _maxId;
}

DeptLocations* DeptLocationsData::GetPointer(int i){
    DeptLocations* deptLocations = nullptr;
    if( i >= 0 && (_data.size()) ) deptLocations = &_data[i];
    return deptLocations;
}

int DeptLocationsData::GetSize(){
    return _data.size();
}

DeptLocations DeptLocationsData::Get(int i){
    string s("index out bound");
    if(i < 0) throw s;
    if( i >= _data.size() ) throw s;
    return _data[i];
}

int DeptLocationsData::ExportToFile(string fileName ){
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(DeptLocations p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}

bool DeptLocationsData::AddMember(Company* company){
    _maxId++;
    DeptLocations* deptLocations = (DeptLocations*)company;
    deptLocations->Id = _maxId;
    _data.push_back(*deptLocations);
    return true;
}

bool DeptLocationsData::DeleteMember(int i){
    if(i < 0){
        return false;
    }else{
        for(int index=i; index<_data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].DNumber = _data[index+1].DNumber;
            _data[index].DLocation = _data[index+1].DLocation;
        }
        _data.pop_back();
    return true;   
    }
}

void DeptLocationsData :: Edit_Table ()
{
    Ui ui;
    int i;
    DeptLocations deptLocations;
    DeptLocationsData deptLocationsData("DeptLocations.data");
    i = ui.ChooseToEdit();
    deptLocations = deptLocationsData._data[i];
    deptLocationsData._data[i] = EnterDeptLocationInfor(deptLocations);
    deptLocationsData.ExportToFile("DeptLocations.data");
}

