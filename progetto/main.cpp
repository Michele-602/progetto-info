#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void stampamenu() {
    cout << "*************************************************\n";
    cout << "* 0 - carica dati da file                       *\n";
    cout << "* 1 - cerca corsi di uno studente(matricola)    *\n";
    cout << "* 2 - cerca corsi di uno studente(cognome)      *\n";
    cout << "* 3 - elenca studenti iscritti ad un corso      *\n";
    cout << "* 4 - stampa dati di un esame di un corso       *\n";
    cout << "* 5 - numero di studenti per corso              *\n";
    cout << "* 6 - numero di materie per corso               *\n";
    cout << "* 7 - cerca materie per descrizione             *\n";
    cout << "* 8 - inserisci nuovo studente                  *\n";
    cout << "* 9 - salva dati su file                        *\n";
    cout << "* X - esci                                      *\n";
    cout << "*************************************************\n";

}
struct uni {
 string codice_corso;
 string descrizione_corso;
 string codice_materia;
 string descrizione_materia;
 string matricola_studente;
 string cognome_studente;
 string nome_studente;
};
void carica_dati (   vector<uni> &registro){
     string a;
     int i=0;
   ifstream fin("corsi_studenti.csv");
   while(!fin.eof()){
    getline(fin,a,',');
    uni tmp;

    tmp.codice_corso=a;

    getline(fin,a,',');
    tmp.descrizione_corso=a;

    getline(fin,a,',');
    tmp.codice_materia=a;

    getline(fin,a,',');
    tmp.descrizione_materia=a;

    getline(fin,a,',');
    tmp.matricola_studente=a;

    getline(fin,a,',');
    tmp.cognome_studente=a;

    getline(fin,a);
    tmp.nome_studente=a;

    registro.push_back(tmp);
   }

   fin.close();



}
int main()
{
    bool finito = false;
    int ch;
    vector<uni> registro;

    while (!finito) {
        stampamenu();
        cin >> ch;

        switch (ch) {
               case '0':
                    carica_dati(registro);
                break;


            case '1':

                break;

            case '2':
                break;

            case '3':
                break;

            case '4':
                break;

            case '5':
                break;

            case '6':
                break;

            case '7':
                break;

            case '8':
                break;

            case '9':
                break;

            case 'X':
                finito = true;
                break;

            default:
                cout << "Opzione non valida\n";

        }

    }
    return 0;
}
