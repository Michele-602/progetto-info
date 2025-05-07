#include <iostream>
using namespace std;
void stampamenu() {
    cout << "*************************************************\n";
    cout << "* I - caricamento dei dati                      *\n";
    cout << "* P - visualizzazione                           *\n";
    cout << "* M - ricerca biglietti per spettacolo          *\n";
    cout << "* Z - inserimento nuovi biglietti per spettacolo*\n";
    cout << "* H - cancellazione biglietti                   *\n";
    cout << "* L - salvataggio dei dati                      *\n";
    cout << "* X - Esci                                      *\n";
    cout << "*************************************************\n";
}
int main()
{
    bool finito = false;
    char ch;

    while (!finito) {
        stampamenu();
        cin >> ch;

        switch (ch) {

            case 'I':
                carica1(head);
                carica2(head2);
                break;

            case 'P':
                stampa(head);
                stampa2(head2);
                break;

            case 'M':
                cout<<"inserisci lo spettacolo da cercare"<<endl;
                cin>>s;
                ricerca_per_spettacolo(head2,s);
                break;

            case 'Z':
                cout<<"inserisci la nuova data"<<endl;
                cin>>data;
                cout<<"inserisci il nuovo codice"<<endl;
                cin>>codice;
                cout<<"inserisci la nuova fila"<<endl;
                cin>>fila;
                cout<<"inserisci il nuovo posto"<<endl;
                cin>>posto;
                cout<<"inserisci il nuovo prezzo"<<endl;
                cin>>prezzo;
                cout<<"inserisci il titolo"<<endl;
                cin>>titolo;
                ins_nuovo_biglietto(head,data,codice,fila,posto,prezzo);
                ins_nuovo_spettacolo(head2,codice,titolo);
                break;

            case 'H':
                cout<<"inserisci il biglietto da cancellare"<<endl;
                cin>>codice;
                canc(head,codice);
                canc2(head2,codice);
                break;

            case 'L':
                salvataggio1(head);
                salvataggio2(head2);
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
