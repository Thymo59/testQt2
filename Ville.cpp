#include<string>
#include<random>
#include"Villageoi.h"
#include"Ville.h"
#include"famille.h"
#include<vector>
#include<fstream>
#include<iostream>

using namespace std;

Ville::Ville(int nbVil, string nom) : QWidget(),m_nbFamille(0), m_age(0),m_nbVil(0), m_pourCentMarie(0), m_enfantParFemme(0), m_nbAdult(0), m_nbEnfant(0),m_nbHomme(0), m_nbFemme(0), m_nbMarie(0) , m_nourriture(50000), m_nom(nom)
{

    for (int i(1);i<nbVil+1;i++)
    {
        this->newVil(i);
    }

}

void Ville::newVil(int i)
{
        Villageoi *ptrVil(0);
        ptrVil = new Villageoi(i);
        m_villageois.push_back(ptrVil);
        m_nbEnfant++;
        m_nbVil=m_villageois.size();

}

void Ville::mortVil(int i)
{
    m_nbVil-=1;
    if(m_villageois[i]->age()>18)
    {
    m_nbAdult=m_nbAdult-1;

    if(m_villageois[i]->estMarie())
    {
        m_nbMarie-=1;

        m_villageois[i]->plusMarie();
        m_nbFamille=m_familles.size();
    }
    else{}
    if(m_villageois[i]->estFemme())
    {m_nbFemme-=1;}
    else{}
    }else{}

    delete m_villageois[i];
    m_villageois.erase(m_villageois.begin()+i);

}

void Ville::direInfoVil()
{
    cout << endl;
   cout << "j'ai " << m_nbVil << " Villageois :" << endl;
   for (int i(0);i<m_nbVil;i++)
    {
        cout << endl;
        m_villageois[i]->direInfo();
    }

}

void Ville::direInfo()
{
   cout << endl;
   cout << "Ville de: " << m_nbVil << " Villageois" << endl;
   cout << "dont " << m_nbFemme << " Femmes et " << (m_nbAdult-m_nbFemme) << " Hommes ainsi que " << (m_nbVil-m_nbAdult) <<" enfants" << endl;

   cout << m_pourCentMarie << " \% des Villageois adultes sont marié" << endl;
   cout << "Il y a " << m_enfantParFemme << " enfants par Femme." << endl;
   cout << "nouriture en stock :  "<< m_nourriture << endl;
   cout << endl;

}

void Ville::ecrireInfo(ofstream &flux)
{
   flux << "Ville de: " << m_nbVil << " Villageois" << endl;
   flux << "dont " << m_nbFemme << " Femmes et " << (m_nbAdult-m_nbFemme) << " Hommes ainsi que " << (m_nbVil-m_nbAdult) <<" enfants" << endl;

   flux << m_pourCentMarie << " \% des Villageois adultes sont marié" << endl;
   flux << "Il y a " << m_enfantParFemme << " enfants par Femme." << endl;

}


void Ville::ecrireInfoVil(ofstream &flux)
{

       for (int i(0);i<m_villageois.size();i++)
    {

        m_villageois[i]->ecrireInfo(flux);
    }
}

int Ville::nbVil()
{
    return m_villageois.size();
}

void Ville::anIncr()
{
        m_age++;
          for(int i(0);i<m_villageois.size();i++)
    {

        m_villageois[i]->ageIncr();

    }
}

void Ville::upDate()
{
  default_random_engine generator;
    int nbenfant_Tmp(0);

    int i(0);
    while (i<m_villageois.size())
    {
        m_villageois[i]->mange(*this);
        if(m_villageois[i]->testMort())
        {
            m_villageois[i]->mort();
            this->mortVil(i);
            //cout << "Mort" << endl;

        }
        else{
    uniform_int_distribution<int> distribution(0,m_villageois.size());

        if(m_villageois[i]->age()==18)
        {
            if(m_villageois[i]->estFemme())
            {
                m_nbFemme++;
            }
            m_nbAdult++;
            m_nbEnfant--;


        }
        else{}
        if(m_villageois[i]->age()>=18 && m_villageois[i]->age()<=45 )
        {
    int rand1(distribution(generator));
    m_villageois[i]->travail(*this);
    if(m_villageois[i]->testMarriage(*m_villageois[rand1]))
    {
        m_villageois[i]->marriage(m_villageois[rand1]);
        m_nbMarie+=2;


        Famille *ptrFamille(0);
        ptrFamille = new Famille(i,rand1,*this);
        m_familles.push_back(ptrFamille);
        m_nbFamille=m_familles.size();
        m_villageois[i]->setFamille(ptrFamille);
        m_villageois[rand1]->setFamille(ptrFamille);

       // cout << "marriage" << endl;
    }
    else{}

    if(m_villageois[i]->testNaissance())
    {
       m_villageois[i]->naissance();
       this->newVil(m_nbVil+1);
        bool sex(m_villageois[m_nbVil-1]->estFemme());
      // cout << m_villageois[i].nom()<< "donne naissance, sex : " << sex << endl;


    }
    else{}

    nbenfant_Tmp=nbenfant_Tmp+m_villageois[i]->nbEnfant();
        }
        i++;
    }
        if (m_nbFemme>0){m_enfantParFemme=(float)nbenfant_Tmp/(float)m_nbFemme;}
        else{}

        if (m_nbAdult>0){m_pourCentMarie=100*((float)m_nbMarie/(float)m_nbAdult);}
        else{}


    }
    int nbHomme(m_nbAdult-m_nbFemme);
    int nbEnfant(m_nbVil-m_nbAdult);
    emit nbVilModif(m_nbVil);
    emit nbFemmeModif(m_nbFemme);
    emit nbHommeModif(nbHomme);
    emit nbEnfantModif(nbEnfant);
    emit nbAdultModif(m_nbAdult);
    emit nbFamilleModif(m_nbFamille);

    emit ageModif(m_age);
}

bool Ville::vilMange(int a)
{
    if(a>m_nourriture){return 0;}
    else{m_nourriture-=a;return 1;}


}

void Ville::vilProd(int a)
{

    m_nourriture+=a;


}

int Ville::nbAdult()
{
    return m_nbAdult;
}

int Ville::nourriture()
{
 return m_nourriture;
}

int Ville::nbFemme()
{
    return m_nbFemme;
}

int Ville::nbHomme()
{
    return m_nbHomme;
}

int Ville::nbEnfant()
{
    return m_nbEnfant;
}

int Ville::nbFamille()
{
    return m_nbFamille;
}

double Ville::pourCentMarie()
{
    return m_pourCentMarie;
}

double Ville::enfantParFemme()
{
 return m_enfantParFemme;
}

int Ville::age()
{
    return m_age;
}

Villageoi* Ville::villageoi(int i)
{
    return m_villageois[i];
}
