#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char *argv[]){
    float masa_ciala = atof(argv[1]);
    float wzrost = atof(argv[2]);
    float bmi=masa_ciala/(wzrost*wzrost);
    cout << "BMI WYNOSI " << bmi << endl;
    if(bmi<16)
        cout << "Wyglodzenie";
    else if(bmi<17)
        cout << "Wychudzenie";
    else if(bmi<18.5)
        cout << "Niedowaga";
    else if(bmi<25)
        cout << "Wartosc prawidlowa";
    else if(bmi<30)
        cout << "Nadwaga";
    else if(bmi<35)
        cout << "I stopien otylosci";
    else if(bmi<40)
        cout << "II stopien otylosci";
    else
        cout << "Otylosc skrajna";
    return 0;
}