#ifndef VILLAGEOI_H_INCLUDED
#define VILLAGEOI_H_INCLUDED

#include<string>
#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"Ville.h"
#include<vector>

class Ville;
class Famille;

class Villageoi
{
public:
    Villageoi(int i);

    bool testNaissance();
    void naissance();

    bool testMort();
    void mort();

    bool testMarriage(Villageoi &cible);
    void marriage(Villageoi* cible);
    void marriage2(Villageoi* source);

    int nbEnfant();

    std::string nom();

    int age();
    bool estFemme();
    bool estMarie();
    void ageIncr();
    bool estVivant();

    void mange(Ville &cible);

    void direInfo();
    void ecrireInfo(std::ofstream &flux);
    void travail(Ville &cible);
    void plusMarie();
    void plusMarie2();
    void setFamille(Famille* famille);

private:

    int m_age;
    int m_espVie;
    bool m_estVivant;
    bool m_estFemme;
    bool m_estMarie;
    int m_nbEnfant;
    int m_faim;
    std::string m_nom;
    int m_force;
    int m_intel;
    int m_sante;
    int m_travail;
    Villageoi *m_conjoint;
    Famille *m_famille;

};

#endif // VILLAGEOI_H_INCLUDED
