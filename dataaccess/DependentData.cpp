#include "DependentData.h"
#include <string>
#include <fstream>
using namespace std;

DependentData::DependentData(){
    _maxId = 0;
    _data.resize(0);
}
int DependentData::GetMaxId(){
    return _maxId;
}
int DependentData::PushBack(Dependent d){
    if (_maxId < d.GetId()){
        _maxId = d.GetId();
    }
    _data.push_back(d);
    return _maxId;
}
//Employee EmployeeData::Get(int i){}
Dependent* DependentData::GetPointer(int i){
    Dependent* e = nullptr;
    if (i >= 0 && i<_data.size())
        e = &_data[i];
    return e;
}

int DependentData :: GetSize()
{
    return _data.size();
}

Dependent DependentData:: Get(int i)
{
    string s("index out of bound");
    if(i<0) throw s;
    if(i> _data.size()) throw s;
    return _data [i];
}

DependentData::DependentData(string filename)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Dependent d(
            j["Id"],
            j["ESSN"],
            j["DependentName"], 
            ((string)j["Sex"])[0],
            j["BDate"], 
            j["Relationship"]
        );
        _data.push_back(d);
        _maxId ++;
    }
    inFile.close();
}

int DependentData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Dependent e:_data)
    {
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

void DependentData :: Edit_Table()
{
    Ui ui;
    int i;
    Dependent dependent;
    DependentData dependentData("Dependent.data");
    i = ui.ChooseToEdit();
    dependent = dependentData._data[i];
    dependentData._data[i] = EnterDependentInfor(dependent);
    dependentData.ExportToFile("Dependent.data");
}


