#ifndef VILLE_H_INCLUDED
#define VILLE_H_INCLUDED

#include<QWidget>
#include<string>
#include<random>

#include<vector>
#include<fstream>
#include<iostream>

#include"Villageoi.h"
#include"maison.h"
class Villageoi;
class Maison;

class Ville : public QWidget
{
    Q_OBJECT

    public:

        Ville(int nbVil, std::string nom);
        void newVil(Maison* maison);
        void mortVil(int nVil);
        void anIncr();
        void upDate();
        void addMaison(Villageoi* parent1,Villageoi* parent,int posX,int posY);
        void addConstruction(Maison* maison);
        void removeConstruction(Maison* maison);
        void consommeBois(int a);

        void direInfoVil();
        void direInfo();
        void ecrireInfoVil(std::ofstream &flux);
        void ecrireInfo(std::ofstream &flux);

       bool vilMange(int a);
       void vilProd(int a);


       int nbVil();
       int nbMaison();
       int nbBois();
       int nbNourriture();
       int nbFemme();
       int nbHomme();
       int nbEnfant();
       int nbAdult();
       int nourriture();
       int age();
       double pourCentMarie();
       double enfantParFemme();

       Villageoi *villageoi(int i);

signals:
       void ageModif(int age);
       void nbVilModif(int nbVillageois);
       void nbFemmeModif(int nbFemme);
       void nbHommeModif(int nbHomme);
       void nbEnfantModif(int nbEnfant);
       void nbAdultModif(int nbAdult);
       void nbMaisonModif(int nbMaison);
       void nbBoisModif(int nbBois);
       void nbNourritureModif(int nbNourriture);
    private:

        std::string m_nom;
        int m_age;
        int m_nbVil;
        int m_nbMaison;
        int m_nbAdult;
        int m_nbFemme;
        int m_nbHomme;
        int m_nbEnfant;
        int m_nbMarie;
        int m_nourriture;
        int m_bois;
        std::vector<Maison*> m_maisons;
        std::vector<Villageoi*> m_villageois;
        std::vector<Maison*> m_constructions;
        double m_pourCentMarie;
        double m_enfantParFemme;



};



#endif // VILLE_H_INCLUDED
