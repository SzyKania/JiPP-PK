#include <iostream>
using namespace std;
int main(){
    int mac1[2][3];
    int mac2[2][3];
    int i,j;
    cout << "Podaj 6 liczb pierwszej macierzy" << endl;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            cin >> mac1[i][j];
    cout << "Podaj 6 liczb drugiej macierzy" << endl;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            cin >> mac2[i][j];
    cout << endl << "Pierwsza macierz:" << endl;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++)        
            cout << mac1[i][j] << "\t";
        cout << endl;
    }
    cout << endl << "Druga macierz" << endl;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++)        
            cout << mac2[i][j] << "\t";
        cout << endl;
    }
    cout << endl << "Suma macierzy" << endl;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){        
            mac1[i][j]+=mac2[i][j];
            cout << mac1[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
