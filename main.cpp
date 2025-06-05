#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX = 1000;

int main()
{
    string *naziv = new string[MAX];
    double *cijena = new double[MAX];
    int *kolicina = new int[MAX];
    int brojArtikala = 0;

    int *kosaricaIndeksi = new int[MAX];
    int *kosaricaKolicine = new int[MAX];
    int brojKosarica = 0;

    int brojRacuna = 1;
    int izbor;

    ifstream katalog("katalog.txt");
    if (katalog.is_open())
    {
        while (brojArtikala < MAX && getline(katalog, naziv[brojArtikala]))
        {
            katalog >> cijena[brojArtikala];
            katalog >> kolicina[brojArtikala];
            katalog.ignore();
            brojArtikala++;
        }
        katalog.close();
    }
