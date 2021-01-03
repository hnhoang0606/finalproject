#include "ProjectData.h"
#include <fstream>

using json = nlohmann::json;

ProjectData::ProjectData()
{
    _maxId = 0;
    _data.resize(0);
}

ProjectData::ProjectData(string fileName)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        Project p(
            j["Id"],
            j["PName"],
            j["PLocation"],
            j["PNumber"],
            j["DNum"]
        );
        _data.push_back(p);
    }
    inFile.close();
}

int ProjectData::GetMaxId()
{
    return _maxId;
}

int ProjectData::PushBack(Project project)
{
    _maxId++;
    project.Id = _maxId;
    _data.push_back(project);
    return _maxId;
}

Project* ProjectData::GetPointer(int i)
{
    Project* project = nullptr;
    if( i >= 0 && (_data.size()) ) project = &_data[i];
    return project;
}

int ProjectData::GetSize()
{
    return _data.size();
}

Project ProjectData::Get(int i)
{
    string s("index out bound");
    if(i < 0) throw s;
    if( i >= _data.size() ) throw s;
    return _data[i];
}

int ProjectData::ExportToFile(string fileName)
{
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(Project p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}

void ProjectData::Edit_Table()
{
    Ui ui;
    int i;
    Project project;
    ProjectData projectData("Project.data");
    i = ui.ChooseToEdit();
    project = projectData._data[i];
    projectData._data[i] = EnterProjectInfor(project);
    projectData.ExportToFile("Project.data");
}

bool ProjectData::AddMember(Company* company)
{
    _maxId++;
    Project* project = (Project*)company;
    project->Id = _maxId;
    _data.push_back(*project);
    return true;
}
bool ProjectData::DeleteMember(int i)
{
    if(i < 0){
        return false;
    }else{
        for(int index = i; index < _data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].PName = _data[index+1].PName;
            _data[index].PNumber = _data[index+1].PNumber;
            _data[index].PLocation = _data[index+1].PLocation;
            _data[index].DNum = _data[index+1].DNum;
        }
        _data.pop_back();
    return true;   
    }
}

string ProjectData::GetProjectName(int projectNumber){
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].PNumber == projectNumber){
            return _data[i].PName;
        }
    }
    return " ";
}