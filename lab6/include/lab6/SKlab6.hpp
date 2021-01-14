#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

class Employee{
    private:
        string name;
        string surname;
        string departmentId;
        string position;
        string id;
    public:
        Employee(string,string,string,string);
        Employee();
        string get_id();
        void set_department(string);
        void empprint();
};

class HRMS{
    private:
        map <string, Employee> employees;
        map <string, vector <string> > dep_emp;
        map <string, double> salaries;
    public:
        void add(Employee employee, string depId, double salary);
        void printDepartment(string);
        void changeSalary(string employeeId, double salary);
        void printSalaries();
        void printSalariesSorted();
};