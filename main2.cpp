#include <iostream>
#include<string>
#include <vector>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<random>

#include"Villageoi.h"
#include"Ville.h"

using namespace std;

int main()
{

    //initialisation du flux sortie
    string const nomFichier("fichiers/resultat.txt");
    ofstream flux(nomFichier.c_str());



    if(flux)
    {
        cout << "ouverture fichier : ok" << endl;
    }
    else
    {
        cout << "ERREUR: pb ouveerture fichier" << endl;
    }

    //initialisation des paramètres
    srand(time(0));
    int  nbAn(0);
    int nbAn2(1);
    int const nbVillageoisInit(10); //nombre de vilageaois initiaux

    Ville Ville1(nbVillageoisInit);
    Ville1.direInfo();



int an(0);

//while( an<18  )
//{
//    cout << "année : " << an << endl;
//    Ville1.anIncr();
//    Ville1.upDate();
//    an++;
//
//}
//
//    Ville1.ecrireInfo(flux);
//    Ville1.ecrireInfoVil(flux);
//Ville1.direInfo();

an =0;
cout << "Combien d'années voulez vous passez? (egale ou inf a 0 pour fermer): " << endl;
cin >> nbAn;

while(nbAn2>=1 && Ville1.nbVil()>0)
{
while( an<nbAn && Ville1.nbVil()>0 )
{

    cout << "année : " << an << endl;
    Ville1.anIncr();
    Ville1.upDate();
    an++;
    Ville1.ecrireInfo(flux);
}
    cout << an<< endl;
    Ville1.direInfo();

    cout <<"Combien d'années voulez vous passez? (egale ou inf a 0 pour fermer): " << endl;

    cin >> nbAn2;
    nbAn+=nbAn2;



}



    return 0;
}
