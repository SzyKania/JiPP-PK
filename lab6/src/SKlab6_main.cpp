#include "lab6/SKlab6.hpp"

using namespace std;

int main(){
    HRMS database;
    Employee employees[10]={{"Jan","Kowalski","wozny","1"},{"Kamil","Makowski","elektryk","2"},{"Teodor","Szulc","mechanik","3"},{"Felicja","Rogowska","ksiegowa","4"},{"Alan","Borkowy","stazysta","5"},{"Gustaw","Tusk","wiceprezes","6"},{"Ryszard","Sliwa","prezes","7"},{"Szymon","Kowal","programista","8"},{"Marianna","Nowak","frontend","9"},{"Marek","Rutek","backend","10"}};
    database.add(employees[0],"konserwacja",2500.11);
    database.add(employees[1],"konserwacja",2700.9);
    database.add(employees[2],"konserwacja",2600.8); 
    database.add(employees[3],"zarzadzanie",3500.7);
    database.add(employees[4],"zarzadzanie",2900.6);
    database.add(employees[5],"zarzadzanie",4100.5);
    database.add(employees[6],"zarzadzanie",5000.4);
    database.add(employees[7],"development",1234.3);
    database.add(employees[8],"development",4321.2);
    database.add(employees[9],"development",1010.1);
    database.printDepartment("konserwacja");
    database.printSalaries();
    database.changeSalary("3",9999.99);
    database.printSalariesSorted();
}