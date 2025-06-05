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
        else if (izbor == 3)
        {
            string trazeni;
            cin.ignore();
            cout << "Unesite naziv artikla za brisanje: ";
            getline(cin, trazeni);
            int i;
            for (i = 0; i < brojArtikala; i++)
            {
                if (naziv[i] == trazeni)
                    break;
            }
            if (i < brojArtikala)
            {
                for (int j = i; j < brojArtikala - 1; j++)
                {
                    naziv[j] = naziv[j + 1];
                    cijena[j] = cijena[j + 1];
                    kolicina[j] = kolicina[j + 1];
                }
                brojArtikala--;
                cout << "Artikal obrisan.\n";
            }
            else
            {
                cout << "Artikal nije pronadjen.\n";
            }
        }
        else if (izbor == 4)
        {
            string unosNaziv;
            int komada;

            cout << "\nUnesite naziv artikla iz kataloga (ili 'kraj' za izlaz): ";
            cin.ignore();

            while (true)
            {
                getline(cin, unosNaziv);

                if (unosNaziv == "kraj")
                    break;

                bool pronadjen = false;
                int indeksArtikla = -1;

                for (int i = 0; i < brojArtikala; i++)
                {
                    if (naziv[i] == unosNaziv)
                    {
                        pronadjen = true;
                        indeksArtikla = i;
                        break;
                    }
                }

                if (!pronadjen)
                {
                    cout << "Artikal nije pronađen. Pokušajte ponovo: ";
                    continue;
                }

                cout << "Kolicina: ";
                cin >> komada;
                cin.ignore();

                if (komada <= kolicina[indeksArtikla])
                {
                    kosaricaIndeksi[brojKosarica] = indeksArtikla;
                    kosaricaKolicine[brojKosarica] = komada;
                    kolicina[indeksArtikla] -= komada;
                    brojKosarica++;
                }
                else
                {
                    cout << "Nema dovoljno na stanju.\n";
                }

                cout << "Dodaj jos (unesi naziv artikla ili 'kraj' za kraj): ";
            }
        }

        else if (izbor == 5) //Pomogo Pero (plaćen u kavama)
        {
            if (brojKosarica == 0)
            {
                cout << "Kosarica je prazna.\n";
                continue;
            }

            double ukupno = 0;
            cout << "\nRacun #" << brojRacuna << ":\n";
            cout << "Naziv               Kolicina  Cijena    Ukupno\n";

            ofstream racuni("racuni.txt", ios::app);
            racuni << "Racun #" << brojRacuna << "\n";

            for (int i = 0; i < brojKosarica; i++)
            {
                int idx = kosaricaIndeksi[i];
                int kol = kosaricaKolicine[i];
                double iznos = kol * cijena[idx];
                ukupno += iznos;

                string nazivArtikla = naziv[idx];
                int razmak = 20 - nazivArtikla.length();
                cout << nazivArtikla;
                for (int j = 0; j < razmak; j++)
                    cout << ' ';

                cout << kol;
                if (kol < 10)
                    cout << "         ";
                else if (kol < 100)
                    cout << "        ";
                else
                    cout << "       ";

                cout << fixed << setprecision(2) << cijena[idx];
                if (cijena[idx] < 10)
                    cout << "      ";
                else if (cijena[idx] < 100)
                    cout << "     ";
                else
                    cout << "    ";

                cout << fixed << setprecision(2) << iznos << endl;

                racuni << naziv[idx] << "," << cijena[idx] << "," << kol << "\n";
            }

            cout << "\nUkupno za platiti: " << fixed << setprecision(2) << ukupno << " EUR\n";
            racuni << "Ukupno: " << fixed << setprecision(2) << ukupno << "\n";
            racuni << "###\n";

            brojRacuna++;
            brojKosarica = 0;
            racuni.close();
        }
    }
}    
    