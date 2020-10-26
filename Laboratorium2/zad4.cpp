#include <iostream>
using namespace std;
int ilosum(int &a, int &b, int &s){
    s=a+b;
    return a*b;
}
int main(){
    int a=5, b=10,s;
    int ilo=ilosum(a,b,s);
    cout << "Iloczyn wynosi " << ilo << endl << "Suma wynosi " << s;
    return 0;
}