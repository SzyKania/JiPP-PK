#include "lab4/SKmacierze.hpp"

macierz::macierz(int x, int y){
    cols_count=y;
    rows_count=x;
    moja_macierz.resize(x);
    for(int i=0; i<moja_macierz.size(); i++)
        moja_macierz[i].resize(y, 0);
    //print();
}

macierz::macierz(int x){
    cols_count=x;
    rows_count=x;
    moja_macierz.resize(x);
    for(int i=0; i<moja_macierz.size(); i++)
        moja_macierz[i].resize(x, 0);
    //print();
}

macierz::macierz(std::string path){
    ifstream myfile (path);
    if(myfile.is_open()){
        myfile >> cols_count >> rows_count;
        moja_macierz.resize(rows_count);
        for(int i=0; i<moja_macierz.size(); i++)
            moja_macierz[i].resize(cols_count, 0);
        for(int i=0; i<rows_count; i++)
            for(int j=0; j<cols_count; j++)
                myfile >> moja_macierz[i][j];
        myfile.close();
    }
    else
        exit (1);
}

macierz::~macierz(){}

void macierz::set(int a, int b, double val){
    moja_macierz[a][b]=val;
    //print();
}

double macierz::get(int n, int m){
    return moja_macierz[n][m];
}

macierz macierz::add(macierz m2){
    if(m2.rows() != rows_count or m2.cols() != cols_count)
        exit (1);
    else{
        macierz nowa(rows_count, cols_count);
        for(int i=0; i<rows_count; i++)
            for(int j=0; j<cols_count; j++)
                nowa.moja_macierz[i][j]=moja_macierz[i][j]+m2.moja_macierz[i][j];
        return nowa;
    }
}

macierz macierz::subtract(macierz m2){
    if(m2.rows() != rows_count or m2.cols() != cols_count)
        exit (1);
    else{
        macierz nowa(rows_count, cols_count);
        for(int i=0; i<rows_count; i++)
            for(int j=0; j<cols_count; j++)
                nowa.moja_macierz[i][j]=moja_macierz[i][j]-m2.moja_macierz[i][j];
        return nowa;
    }
}

macierz macierz::multiply(macierz m2){
       macierz mnozenie(rows_count,m2.cols());
    if(cols_count==m2.rows()){
        double temp=0.0;
        for(int i=0; i<rows_count; i++){
            for(int j=0; j<m2.cols(); j++){
                temp=0.0;
                for (int k=0; k<cols_count; k++){
                    temp += moja_macierz[i][k] * m2.moja_macierz[k][j];
                }
                mnozenie.moja_macierz[i][j] = temp;
            }
        }
        return mnozenie;
    }
    else
        exit (1);
}

int macierz::cols(){
    return cols_count;
}

int macierz::rows(){
    return rows_count;
}

void macierz::print(){
    for(int i=0; i<rows_count; i++){
        for(int j=0; j<cols_count; j++)
            cout << moja_macierz[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void macierz::store(std::string filename, std::string path){
    ofstream myfile;
    myfile.open(path+filename);
    myfile << cols_count << " " << rows_count << endl;
    for(int i=0; i<rows_count; i++){
        for(int j=0; j<cols_count; j++)
            myfile << moja_macierz[i][j] << " ";
        myfile << endl;
    }
    myfile.close();
}

int macierz::main(){
    macierz pierwsza(4);

    macierz druga(4,4);
    pierwsza.set(3,0,10);
    cout << "Pierwsza macierz:" << endl;
    pierwsza.print();
    cout << "Element na pozycji 3,0 macierzy pierwsza wynosi " <<  pierwsza.get(3,0) << endl;
    druga=pierwsza.add(druga);
    cout << "Druga macierz po dodaniu do niej pierwszej:" << endl;
    druga.print();
    druga=druga.subtract(pierwsza);
    cout << "Druga macierz po odjeciu od niej pierwszej:" << endl;
    druga.print();
    druga.set(0,3,10);
    druga=druga.multiply(pierwsza);
    cout << "Druga macierz po przemnozeniu przez pierwszą:" << endl;
    druga.print();
    cout << "Ilosc kolumn drugiej macierzy: " << druga.cols() << endl;
    cout << "Ilosc wierszy pierwszej kolumny: " << pierwsza.rows() << endl;
    string path="";
    string filename="macierzdruga.txt";
    druga.store(filename,path);
    macierz trzecia("macierzdruga.txt");
    cout << "Trzecia macierz wczytana z zapisu drugiej:" << endl;
    trzecia.print();
    return 0;
}