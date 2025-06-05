#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX = 1000;

int main()
{
    std::cout << "██████████████████████████████████████████████████████████████████████████████\n"
                 "█▌                                                                          ▐█\n"
                 "█▌ ████████╗██████╗  ██████╗  ██████╗ ██╗   ██╗██╗███╗   ██╗ █████╗         ▐█\n"
                 "█▌ ╚══██╔══╝██╔══██╗██╔════╝ ██╔═══██╗██║   ██║██║████╗  ██║██╔══██╗        ▐█\n"
                 "█▌    ██║   ██████╔╝██║  ███╗██║   ██║██║   ██║██║██╔██╗ ██║███████║        ▐█\n"
                 "█▌    ██║   ██╔══██╗██║   ██║██║   ██║╚██╗ ██╔╝██║██║╚██╗██║██╔══██║        ▐█\n"
                 "█▌    ██║   ██║  ██║╚██████╔╝╚██████╔╝ ╚████╔╝ ██║██║ ╚████║██║  ██║        ▐█\n"
                 "█▌    ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝   ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝        ▐█\n"
                 "█▌                                                                          ▐█\n"
                 "█▌ ███╗   ███╗██╗███╗   ██╗██╗    ███████╗██╗      █████╗      ██╗ ██████╗  ▐█\n"
                 "█▌ ████╗ ████║██║████╗  ██║██║    ╚══███╔╝██║     ██╔══██╗     ██║██╔═══██╗ ▐█\n"
                 "█▌ ██╔████╔██║██║██╔██╗ ██║██║      ███╔╝ ██║     ███████║     ██║██║   ██║ ▐█\n"
                 "█▌ ██║╚██╔╝██║██║██║╚██╗██║██║     ███╔╝  ██║     ██╔══██║██   ██║██║   ██║ ▐█\n"
                 "█▌ ██║ ╚═╝ ██║██║██║ ╚████║██║    ███████╗███████╗██║  ██║╚█████╔╝╚██████╔╝ ▐█\n"
                 "█▌ ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ╚══════╝╚══════╝╚═╝  ╚═╝ ╚════╝  ╚═════╝  ▐█\n"
                 "█▌                                                                          ▐█\n"
                 "██████████████████████████████████████████████████████████████████████████████\n";

    string *naziv = new string[MAX];
    double *cijena = new double[MAX];
    int *kolicina = new int[MAX];
    int brojArtikala = 0;

    int *kosaricaIndeksi = new int[MAX];
    int *kosaricaKolicine = new int[MAX];
    int brojKosarica = 0;
    const int sirinaNaziva = 20;

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
    while (true)
    {
        cout << "\n1. Unos novog artikla\n2. Katalog\n3. Izbrisi artikal\n4. Kosarica\n5. Ispis racuna\n6. Ucitaj racun\n7. Izlaz\n\nIzbor: ";
        cin >> izbor;

        if (izbor == 1)
        {
            if (brojArtikala < MAX)
            {
                cout << "Naziv: ";
                cin.ignore();
                getline(cin, naziv[brojArtikala]);
                cout << "Cijena: ";
                cin >> cijena[brojArtikala];
                cout << "Kolicina: ";
                cin >> kolicina[brojArtikala];
                brojArtikala++;
            }
        }
        else if (izbor == 2)
        {
            cout << "\nKatalog artikala:\n";
            for (int i = 0; i < brojArtikala; i++)
            {
                cout << i + 1 << ". ";
                cout << naziv[i];
                int razmak = sirinaNaziva - naziv[i].length();
                for (int j = 0; j < razmak; j++)
                {
                    cout << ' ';
                }
                cout << fixed << setprecision(2) << cijena[i] << " EUR ";
                cout << "(na stanju: " << kolicina[i] << ")" << endl;
            }
        }
    
    }
}    
