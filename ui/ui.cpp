#include"ui.h"

void Ui::DisplayEmployee()
{
    EmployeeData employeeData("Employee.data");
    for(int i =0;i<employeeData.GetSize();i++)
    {
        Employee employee = employeeData.Get(i);
        cout<< employee.ToString()<<endl;
    }
}

void Ui::DisplayDependent()
{
    DependentData dependentData("Dependent.data");
    for(int i = 0; i<dependentData.GetSize() ; i++)
    {
        Dependent dependent = dependentData.Get(i);
        cout<< dependent.ToString()<<endl;
        cout<<endl;
    }
}

// void Ui::DisplayProject()
// {
//     ProjectData projectData("Project.data");
//     for(int i = 0; i<projectData.GetSize() ; i++)
//     {
//         Project project = projectData.Get(i);
//         cout<< project.ToString()<<endl;
//         cout<<endl;
//     }
// }

// void Ui::DisplayWork_on()
// {
//     Work_onData work_onData("Work_on.data");
//     for(int i =0;i<work_onData.GetSize();i++)
//     {
//         Work_on work_on = work_onData.Get(i);
//         cout<< work_on.ToString()<<endl;
//     }
// }

// void Ui::DisplayWork_on()
// {
//     Work_onData mwork_onData("Work_on.data");
//     for( int i = 0; i < mwork_onData.GetSize(); i++ )
//     {
//         Work_on work_on = mwork_onData.Get(i);
//         cout<< work_on.ToString()<<endl;
//         cout<<endl;
//     }
// }

void Ui::MainInterface()
{
    bool Iscontinue = true;
    do{ 
        int Choice;
        cout<<"========================================"<<endl;
        cout<<"**Choose funtion that you want to use **"<<endl;
        cout<<"1. Display/..................."<<endl;
        cout<<"========================================"<<endl;
        cout<<"your Choice_"; cin >> Choice;
       
        switch (Choice) // choose sentence
        {
        case 1:
            ChooseTable();
            break;
        default:
            system("cls");
            cout<<"please Enter Again"<<endl;
            break;
        }
    }while (Iscontinue ==true); 
}


void Ui::ChooseTable()
{   bool Iscontinue = true;
    do 
    {
        int SubChoice;
        cout<<"**************************************************************"<<endl;
        cout<<"#####         select the Table you want to use          ######"<<endl;
        cout<<"                     ******************                       "<<endl;
        cout<<"1. Employee table"<<endl;
        cout<<"2. Department table"<<endl;
        cout<<"3. Dept_Location table"<<endl;
        cout<<"4. Project table"<<endl;
        cout<<"5. Work_on table"<<endl;
        cout<<"6. Dependent table"<<endl;
        cout<<"0. Stop"<<endl;
        cout<<"***************************************************************"<<endl;
        cout<<"Your choice_"; cin >> SubChoice;
        switch (SubChoice)
        {
        case 1:
            ChooseFuntion(SubChoice);
        break;
        
        default:
            break;
        }
    }
    while(Iscontinue==true);
}

void Ui:: ChooseFuntion(int Subchoice)
{   bool Iscontinue = true;
    do
    {
    
        int Subchoice2;
        cout<<"**************************************************************"<<endl;
        cout<<"#####          select the function you want to use      ######"<<endl;
        cout<<"                       ******************                     "<<endl;
        cout<<" 1. Display the Table"<<endl;
        cout<<" 2. Edit the content of the table"<<endl;
        cout<<" 3. Add elements to the table"<<endl;
        cout<<" 4. Delete elements from the table"<<endl;
        cout<<" 0. Stop"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<"Your choice__"; cin>> Subchoice2;
        switch (Subchoice2)
        {
        case 1:
            if(Subchoice ==1)
            {
                //DisplayProject();
                //DisplayEmployee();
                //DisplayDependent();
            }
            break;
        case 2:
            if(Subchoice = 1)
            {   
                EmployeeData employeeData;
                employeeData.Edit_Table();
            }
            if(Subchoice == 6)
            {
                DependentData dependentData;
                dependentData.Edit_Table();
            }
            break;
        }
    }
    while(Iscontinue==true );
};


Employee EnterEmployeeInfor(Employee &employee)
{   
    int n;
    cout<<"Choose Information that you want to edit"<<endl;
    cout<<"1.FName: "<<endl;
    cout<<"2.MInit_: "<<endl;
    cout<<"3.LName_: "<<endl;
    cout<<"4.SSN_: "<<endl;
    cout<<"5.BDate_: "<<endl;
    cout<<"6.Address_: "<<endl;
    cout<<"7.Salary_: "<<endl;
    cout<<"8.SuperSSN_: "<<endl;
    cout<<"9.DNO_: "<<endl;
    cout<<"10.SEX_: "<<endl;
    cout<<"0. Stop"<<endl;
    cout<<"Your Choice: ";
    cin >> n;
    switch (n)
    {
    case 1:
        cout<<"Enter FName: ";
        cin >> employee.FName;
        break;
    case 2: 
        cout<<"Enter MInit_: ";
        cin >> employee.MInit;
        break;
    case 3: 
        cout<<"Enter LName_: ";
        cin >> employee.LName;
        break;
    case 4: 
        cout<<"Enter SSN_: ";
        cin >> employee.SSN;
        break;
    case 5: 
        cout<<"Enter BDate_: ";
        cin >> employee.BDate;
        break;
    case 6: 
        cout<<"Enter Address_: ";
        cin >> employee.Address;
        break;
    case 7: 
        cout<<"Enter Salary_: ";
        cin >> employee.Salary;
        break;
    case 8: 
        cout<<"Enter SuperSSN_: ";
        cin >> employee.SuperSSN;
        break;
    case 9: 
        cout<<"Enter DNO_: ";
        cin >> employee.DNO;
        break;
    case 10: 
        cout<<"Enter SEX_: ";
        cin >> employee.Sex;
        break;
    
    default:
    cout<<" please Enter Again";
        break;
    }

    return employee;
}


Dependent EnterDependentInfor(Dependent &dependent)
{   
    int n;
    cout<<"Choose Information that you want to edit"<<endl;
    cout<<"1.ESSN : "<<endl;
    cout<<"2.DependentName : "<<endl;
    cout<<"3.Sex : "<<endl;
    cout<<"4.BDate : "<<endl;
    cout<<"5.Relationship: "<<endl;
    cout<<"0. Stop"<<endl;
    cout<<"Your Choice: ";
    cin >> n;
    switch (n)
    {
    case 1:
        cout<<"Enter ESSN: ";
        cin >> dependent.ESSN;
        break;
    case 2: 
        cout<<"Enter DependentName: ";
        cin >> dependent.DependentName;
        break;
    case 3: 
        cout<<"Enter Sex: ";
        cin >> dependent.Sex;
        break;
    case 4: 
        cout<<"Enter BDate: ";
        cin >> dependent.BDate;
        break;
    case 5: 
        cout<<"Enter Relationship: ";
        cin >> dependent.Relationship;
        break;
    default:
    cout<<" please Enter Again";
        break;
    }
    return dependent;
}

Work_on EnterWork_onInfor(Work_on &work_on)
{   
    int n;
    cout<<"Choose Information that you want to edit"<<endl;
    cout<<"1. ESSN : "<<endl;
    cout<<"2. PNO : "<<endl;
    cout<<"3. Hours : "<<endl;
    cout<<"0. Stop"<<endl;
    cout<<"Your Choice: ";
    cin >> n;
    switch (n)
    {
    case 1:
        cout<<"Enter ESSN: ";
        cin >> work_on.ESSN;
        break;
    case 2: 
        cout<<"Enter PNO: ";
        cin >> work_on.PNO;
        break;
    case 3: 
        cout<<"Enter Hours: ";
        cin >> work_on.Hours;
        break;
    default:
    cout<<" please Enter Again";
        break;
    }
    return work_on;
}

int Ui::ChooseToEdit()
{ 
    cout<<"|** Please enter the Id of the Table that you want to edit **|" <<endl;
    cout<<" ID: "; 
    int n;
    cin >> n;
    return n;
}







