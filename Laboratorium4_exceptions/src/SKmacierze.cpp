#include "lab4/SKmacierze.hpp"

macierz::macierz(int x, int y){
    try{
        if(x<1)
            throw 1;
        if(y<1)
            throw 2;
    cols_count=y;
    rows_count=x;
    moja_macierz.resize(x);
    for(int i=0; i<moja_macierz.size(); i++)
        moja_macierz[i].resize(y, 0);
    //print();
    }
    catch(int e){
        if(e==1)
            cout << "Ilosc wierszy musi byc wieksza od 0\n";
        if(e==2)
            cout << "Ilosc kolumn musi byc wieksza od 0\n";
    }
}

macierz::macierz(int x){
    try{
        if(x<1)
            throw 1;
    cols_count=x;
    rows_count=x;
    moja_macierz.resize(x);
    for(int i=0; i<moja_macierz.size(); i++)
        moja_macierz[i].resize(x, 0);
    //print();
    }
    catch(int x){
        if(x==1)
            cout << "Bok macierzy musi byc wiekszy od 0\n";
    }
}

macierz::macierz(std::string path){
    ifstream myfile (path);
    try{
        if(myfile.is_open()){
            myfile >> cols_count >> rows_count;
            if(cols_count < 1)
                throw 2;
            if(rows_count < 1)
                throw 3;
            moja_macierz.resize(rows_count);    
            for(int i=0; i<moja_macierz.size(); i++)
                moja_macierz[i].resize(cols_count, 0);
            for(int i=0; i<rows_count; i++)
                for(int j=0; j<cols_count; j++)
                    myfile >> moja_macierz[i][j];
            myfile.close();
        }
        else
        {
            throw 1;
        }
    }
    catch(int x){
        if(x==1)
            cout << "Nie udalo sie otworzyc pliku\n";
        if(x==2)
            cout << "W pliku niepoprawna ilosc kolumn\n";
        if(x==3)
            cout << "W pliku niepoprawna ilosc wierszy\n";
        exit (1);
    }
}

macierz::~macierz(){}

void macierz::set(int a, int b, double val){
    try{
        if(a>rows_count-1 or a<0)
            throw 1;
        if(b>cols_count-1 or b<0)
            throw 2;
    moja_macierz[a][b]=val;
    }
    catch(int x){
        if(x==1)
            cout << "Niepoprawna wartosc kolumny\n";
        if(x==2)
            cout << "Niepoprawna wartosc wiersza\n";
        exit (1);
    }
    //print();
}

double macierz::get(int n, int m){
    try{
        if(n>rows_count-1 or n<0)
            throw 1;
        if(m>cols_count-1 or m<0)
            throw 2;
        return moja_macierz[n][m];
    }
    catch(int x){
        if(x==1)
            cout << "Niepoprawna wartosc kolumny\n";
        if(x==2)
            cout << "Niepoprawna wartosc wiersza\n";
        return 0;
    }
    
}

macierz macierz::add(macierz m2){
    try{
        if(m2.rows() != rows_count)
            throw 1;
        if(m2.cols() != cols_count)
            throw 2;
        macierz nowa(rows_count, cols_count);
        for(int i=0; i<rows_count; i++)
            for(int j=0; j<cols_count; j++)
                nowa.moja_macierz[i][j]=moja_macierz[i][j]+m2.moja_macierz[i][j];
        return nowa;
    }
    catch(int x){
        if(x==1)
            cout << "Nierowna ilosc wierszy\n";
        if(x==2)
            cout << "Nierowna wartosc kolumn\n";
        exit (1);
    }
}

macierz macierz::subtract(macierz m2){
    macierz nowa(rows_count, cols_count);
    try{
        if(m2.rows() != rows_count)
            throw 1;
        if(m2.cols() != cols_count)
            throw 2;
        for(int i=0; i<rows_count; i++)
            for(int j=0; j<cols_count; j++)
                nowa.moja_macierz[i][j]=moja_macierz[i][j]-m2.moja_macierz[i][j];
        return nowa;
    }
    catch(int x){
        if(x==1)
            cout << "Nierowna ilosc wierszy\n";
        if(x==2)
            cout << "Nierowna wartosc kolumn\n";
        exit (1);
    }
}

macierz macierz::multiply(macierz m2){
    try{
        if(m2.rows()!=cols_count)
            throw 1;
        macierz mnozenie(rows_count,m2.cols());
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
    catch(int x){
        if(x==1)
            cout << "Wiersze drugiej nierowne kolumnom pierwszej\n";
        exit (1);
    }
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
    try{
        ofstream myfile;
        myfile.open(path+filename);
        if(myfile.is_open()==false)
            throw 1;
        myfile << cols_count << " " << rows_count << endl;
        for(int i=0; i<rows_count; i++){
            for(int j=0; j<cols_count; j++)
                myfile << moja_macierz[i][j] << " ";
            myfile << endl;
        }
        myfile.close();
    }
    catch(int x){
        if(x==1)
            cout << "Nie udalo sie otworzyc pliku\n";
    }
}

int macierz::main(){
    macierz pierwsza(-1);
    macierz druga(4,4);
    druga.get(-1,100);
    druga.store("","");
}

/*int macierz::oldmain(){
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
}*/