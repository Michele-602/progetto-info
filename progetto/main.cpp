#include <iostream>
#include <vector>
#include <map>
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
    cout << "* 10 - esci                                      *\n";
    cout << "*************************************************\n";

}

struct corso {
 string codice_corso;
 string descrizione_corso;

};
struct materia {
 string codice_materia;
 string descrizione_materia;
 string codice_corso;

};
struct studente {
 string matricola_studente;
 string cognome_studente;
 string nome_studente;
 string codice_corso;

};


void carica_dati (   vector<corso> &corsov,vector<materia> &materiav,vector<studente> &studentev){
     string a;
     int i=0;
   ifstream fin("corsi_studenti.csv");
   while(!fin.eof()){
    getline(fin,a,',');
    corso tmp;
    materia tmp1;
    studente tmp2;

    tmp.codice_corso=a;
    tmp1.codice_corso=a;
    tmp2.codice_corso=a;

    getline(fin,a,',');
    tmp.descrizione_corso=a;

    getline(fin,a,',');
    tmp1.codice_materia=a;

    getline(fin,a,',');
    tmp1.descrizione_materia=a;

    getline(fin,a,',');
    tmp2.matricola_studente=a;

    getline(fin,a,',');
    tmp2.cognome_studente=a;

    getline(fin,a);
    tmp2.nome_studente=a;

    corsov.push_back(tmp);
     materiav.push_back(tmp1);
      studentev.push_back(tmp2);
   }

   fin.close();


}
string cercaPerMatricola(vector<studente> studentev,string matricola,vector<corso> corsov){
    string cm;
       /* funzione se la parte di ricerca della descrizione la volgiamo nel main
       for(int i=0;i<studentev.size();i++){
        if(studentev[i].matricola_studente==matricola){
            cm=studentev[i].codice_corso;
            return cm;

        }*/
    for(int i=0;i<studentev.size();i++){
        if(studentev[i].matricola_studente==matricola){
            cm=studentev[i].codice_corso;

        }
    }
    for(int i=0;i<corsov.size();i++){
        if(corsov[i].codice_corso==cm){
            return corsov[i].descrizione_corso;

        }
    }
}
string cercaPerCognome(vector<studente> studentev,string cognome,vector<corso> corsov){
    string cc;
       /* funzione se la parte di ricerca della descrizione la volgiamo nel main
       for(int i=0;i<studentev.size();i++){
        if(studentev[i].matricola_studente==matricola){
            cc=studentev[i].codice_corso;
            return cc;

        }*/
    for(int i=0;i<studentev.size();i++){
        if(studentev[i].cognome_studente==cognome){
            cc=studentev[i].codice_corso;

        }
    }
    for(int i=0;i<corsov.size();i++){
        if(corsov[i].codice_corso==cc){
            return corsov[i].descrizione_corso;

        }
    }
}
void studentiIscrittiCorso(vector<studente> studentev,string corsoSIC,vector<studente> &SIC,vector<corso> corsov){
//prendo in input codice corso
    for(int i=0;i<studentev.size();i++){
        if(studentev[i].codice_corso==corsoSIC){
            SIC.push_back(studentev[i]);

        }
    }


}
void numeroStudentiCorso(vector<corso> corsov, map<string,int> &csc){
        for(int i=0;i<corsov.size();i++){
           csc[corsov[i].codice_corso]++;
        }
}



int main()
{

    int ch;

    vector<corso> corsov;
     vector<materia> materiav;
      vector<studente> studentev;
    vector<studente> SIC;
    map<string,int> csc;
      string matricola,cm,cc,corsoSIC,cognome;
        stampamenu();

        cin >> ch;
    while (ch<10) {

        switch (ch) {
               case 0:
                    carica_dati(corsov,materiav,studentev);
                    cout<<"ciao";

                break;


            case 1:
                cout<<"inserisci la matricola di cui vuoi sapere i corsi : ";
                cin>>matricola;
                cout<<endl;
                cout<<cercaPerMatricola(studentev, matricola,corsov)<<endl;
                /*funzione se la parte di ricerca della descrizione la volgiamo nel main

                cm=cercaPerMatricola(studentev, matricola);
                  for(int i=0;i<corsov.size();i++){
                        if(corsov[i].codice_corso==cm){
                            cout<<corsov[i].descrizione_corso<<endl;
                            break;

                        }
                    }*/



                break;

            case 2:
                 cout<<"inserisci il cognome di cui vuoi sapere i corsi : ";
                cin>>cognome;
                cout<<endl;
                cout<<cercaPerCognome(studentev, cognome,corsov)<<endl;
                /*funzione se la parte di ricerca della descrizione la volgiamo nel main

                cc=cercaPercognome(studentev, cognome);
                  for(int i=0;i<corsov.size();i++){
                        if(corsov[i].codice_corso==cc){
                            cout<<corsov[i].descrizione_corso<<endl;
                            break;

                        }
                    }*/
                break;

            case 3:
                 cout<<"inserisci il codice del corso di cui vuoi sapere gli iscritti : ";
                cin>>corsoSIC;

                SIC.clear();
                studentiIscrittiCorso( studentev, corsoSIC, SIC,corsov);
                for(auto c: SIC){
                    cout<<c.nome_studente<<"  "<<c.cognome_studente<<"  "<<c.matricola_studente<<endl;
                }
                break;

            case 4:
                break;

            case 5:
                numeroStudentiCorso( corsov,csc);
                for(auto c : csc){
                    cout<<c.first<<" "<<c.second<<endl;
                }
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;




        }
     stampamenu();
        cin >> ch;
    }
    return 0;
}
