#include <iostream>
using namespace std;
void swap1(int *a, int *b){
    if(*b<*a){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
}
int main(){
    int a=32, b=12;
    int *ap=&a;
    int *bp=&b;
    swap1(ap,bp);
    cout << "Po wykonaniu funkcji zmienna a wynosi " << a << endl << "Zmienna b wynosi " << b;
    return 0;
}