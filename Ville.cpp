#include<string>
#include<random>
#include"Villageoi.h"
#include"Ville.h"
#include"maison.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<QDebug>

using namespace std;

Ville::Ville(int nbVil, string nom) : QWidget(),m_nbMaison(1), m_age(0),m_nbVil(0), m_pourCentMarie(0), m_enfantParFemme(0), m_nbAdult(0), m_nbEnfant(0),m_nbHomme(0), m_nbFemme(0), m_nbMarie(0) , m_nourriture(50000), m_nom(nom)
{

    Maison *maison0(0);
    maison0 = new Maison();
    m_maisons.push_back(maison0);
    m_nbMaison=m_maisons.size();
    for (int i(1);i<nbVil+1;i++)
    {
        this->newVil(i);
        m_maisons[0]->addEnfant(m_villageois.back());

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
    if(m_villageois[i]->age()>18*12)
    {
    m_nbAdult=m_nbAdult-1;

    if(m_villageois[i]->estMarie())
    {
        m_nbMarie-=1;

        m_villageois[i]->plusMarie();

    }
    else{}
    if(m_villageois[i]->estFemme())
    {m_nbFemme-=1;}
    else{}
    }else{}

    m_villageois[i]->mort();
    delete m_villageois[i];
    m_villageois.erase(m_villageois.begin()+i);



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
            qDebug() << "mort villageoi" << i;
            this->mortVil(i);    
        }
        else{
    uniform_int_distribution<int> distribution(0,m_villageois.size());

        if(m_villageois[i]->age()==18*12)
        {
            if(m_villageois[i]->estFemme())
            {
                m_nbFemme++;
            }
            m_nbAdult++;
            m_nbEnfant--;


        }
        else{}
        if(m_villageois[i]->age()>=18*12 && m_villageois[i]->age()<=45*12 )
        {
    int rand1(distribution(generator));
    m_villageois[i]->travail(*this);
    if(m_villageois[i]->testMarriage(*m_villageois[rand1]))
    {
        qDebug() << "Marriage" << i << rand1 ;
        m_villageois[i]->marriage(m_villageois[rand1]);
        m_nbMarie+=2;

        Maison *ptrMaison(0);
        ptrMaison = new Maison(m_villageois[rand1],m_villageois[i],0,0);
        m_maisons.push_back(ptrMaison);
        m_nbMaison=m_maisons.size();
    }
    else{}

    if(m_villageois[i]->testNaissance())
    {
       m_villageois[i]->naissance();
       qDebug() << "Naissance" << i ;
       this->newVil(m_villageois.size()+1);
       (m_villageois[i]->getMaison())->addEnfant(m_villageois.back());
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
    emit nbMaisonModif(m_nbMaison);
    emit ageModif(m_age/12);
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


int Ville::nbMaison()
{
    return m_nbMaison;
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
