#include "lab6/SKlab6.hpp"
 
bool sortBySalary(pair <string, double> &a, pair <string, double> &b){
    return(a.second > b.second);
}

Employee::Employee(string newname, string newsur, string newpos, string newid){
    name=newname;
    surname=newsur;
    departmentId="";
    position=newpos;
    id=newid;
}

Employee::Employee(){}

string Employee::get_id(){
    return id;
}

void Employee::set_department(string depId){
    departmentId=depId;
}

void Employee::empprint(){
    cout << "Name: " << name << "\tDepId: " << surname << "\tPosition: " << position << "\tId: " << id << endl;
}

void HRMS::add(Employee employee, string depId, double salary){
    employee.set_department(depId);
    employees[employee.get_id()]=employee;
    dep_emp[depId].push_back(employee.get_id());
    salaries[employee.get_id()]=salary;
}

void HRMS::printDepartment(string depId){
    cout << "Pracownicy dzialu " << depId << endl;
    for(size_t i=0;i<dep_emp[depId].size();i++)
        employees[dep_emp[depId][i]].empprint();
    cout << endl;
}

void HRMS::changeSalary(string employeeId, double salary){
    salaries[employeeId]=salary;
}

void HRMS::printSalaries(){
    cout << "Wyplaty pracownikow: " << endl;
    for(auto iterator=salaries.begin(); iterator != salaries.end(); ++iterator){
        employees[iterator->first].empprint();
        cout << "Salary: " << iterator->second << endl;
    }
    cout << endl;
}


void HRMS::printSalariesSorted(){
    cout << "Wyplaty pracownikow posortowane: " << endl;
    vector <pair <string, double>> tempvec;
    for(auto iterator=salaries.begin(); iterator != salaries.end(); ++iterator)
        tempvec.push_back(make_pair(iterator->first,iterator->second));
    sort(tempvec.begin(),tempvec.end(),sortBySalary);
    for(size_t i=0;i<tempvec.size();i++){
       employees[tempvec[i].first].empprint();
       cout << "Salary: " << tempvec[i].second << endl;
    }
    cout << endl;
}