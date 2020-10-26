#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
void funkcja (void *a, void *b,size_t s){
    void *c=malloc(s);
    memcpy(c,a,s);
    memcpy(a,b,s);
    memcpy(b,c,s);
    free(c);
}
int main(){
    int ai=1;
    int bi=22;
    void *ap=&ai;
    void *bp=&bi;
    funkcja(ap,bp,sizeof(ai));

    float af=1.1;
    float bf=22.2;
    ap=&af;
    bp=&bf;
    funkcja(ap,bp,sizeof(af));

    char ach='a';
    char bch='b';
    ap=&ach;
    bp=&bch;
    funkcja(ap,bp,sizeof(ach));

    string as="1napis1";
    string bs="2napis2";
    funkcja(&as[0],&bs[0],as.length()+1);

    cout << ai << "\t" << bi << endl;
    cout << af << "\t" << bf << endl;
    cout << ach << "\t" << bch << endl;
    cout << as << "\t" << bs << endl;
}
