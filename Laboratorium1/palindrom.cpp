#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]){
    int x=strlen(argv[1]);
    bool t=true;
    for(int i=0;i<x/2;i++)
        if(argv[1][i]!=argv[1][x-i-1]){
            t=false;
            break;
        }
    if(t==true)
        cout << "Argument jest palindromem";
    else
        cout << "Argument nie jest palindromem";
    return 0;
}