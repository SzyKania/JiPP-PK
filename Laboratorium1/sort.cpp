#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[]){
    bool t = false;
    int temp, i;
    int tab[argc-1];
    for(i=1;i<argc;i++)
        tab[i-1]=atoi(argv[i]);
    while(t==false){
        t=true;
        for(i=0;i<argc-2;i++){
            if(tab[i]>tab[i+1]){
                temp=tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=temp;
                t=false;
            }
        }
    }
    for(i=0;i<argc-1;i++)
        cout << tab[i] << " ";
    return 0;
}