#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <string>
#include "../libs/json.hpp"

using json = nlohmann::json;
using namespace std;

class Project
{
    int Id;
    string PName;
    int PNumber;
    string PLocation;
    int DNum;

public:
    friend class ProjectData;
    // Default Contructor
    Project();
    // Contructor with paramaters
    Project(int , string ,string ,int ,int );
    string ToString();
    json ToJson();
};
#endif