#include <iostream>
using namespace std;
void swap3(int &a, int *b){
    int temp = a;
    a=*b;
    *b=temp;
}
int main(){
    int a=5,b=10;
    int *bp=&b;
    swap3(a,bp);
    cout << "Po wykonaniu funkcji zmienna a wynosi " << a << endl << "Zmienna b wynosi " << b;
    return 0;
}
