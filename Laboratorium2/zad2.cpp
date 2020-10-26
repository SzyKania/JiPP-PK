#include <iostream>
using namespace std;
void swap2(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int a=5, b=10;
    swap2(a,b);
    cout << "Po wykonaniu funkcji zmienna a wynosi " << a << endl << "Zmienna b wynosi " << b;
    return 0;
}
