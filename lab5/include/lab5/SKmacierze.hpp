#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class macierz{
    private:
        int rows_count;
        int cols_count;
        vector <vector<double>> moja_macierz;
    public:
        macierz(int, int);
        macierz(int);
        macierz(std::string path);
        ~macierz();
        void set(int n, int m, double val);
        double get(int n, int m);
        macierz operator+(macierz m2);
        macierz operator-(macierz m2);
        macierz operator*(macierz m2);
        friend ostream& operator<<(ostream& output, const macierz& m2);
        bool operator==(macierz m2);
        bool operator!=(macierz m2);
        void operator++();
        void operator--();
        vector <double> operator[](int i);
        int cols();
        int rows();
        void print();
        int main();
        void store(std::string filename, std::string path);
};