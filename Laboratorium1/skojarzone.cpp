#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char *argv[]){
    int a=atoi(argv[1]);
    int b=atoi(argv[2]);
    int a_dziel=1;
    int b_dziel=1;
    int i;
    for(i=2;i<=a/2;i++)
        if(a%i==0)
            a_dziel+=i;
    for(i=2;i<=b/2;i++)
        if(b%i==0)
            b_dziel+=i;
    if(a_dziel==b+1&&b_dziel==a+1)
        cout << "Liczby " << a << " i " << b << " sa skojarzone";
    else
        cout <<"Liczby " << a << " i " << b << " nie sa skojarzone";
    return 0;
}