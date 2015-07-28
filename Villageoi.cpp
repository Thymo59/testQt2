#include"Villageoi.h"
#include"Ville.h"
#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<random>
#include<vector>
#include <array>
#include<QDebug>

using namespace std;
default_random_engine generator;
Villageoi::Villageoi(int i) : m_age(0), m_estMarie(0), m_nbEnfant(0), m_estVivant(1) , m_faim(0) , m_force(0) ,m_sante(1) , m_travail(0), m_intel(0)
{

array<double,7> intervals {0, 20*12,30*12,40*12, 45*12 ,70*12 ,80*12};
array<double,7> weights {10, 10, 15,50, 100,100,10};
piecewise_linear_distribution<double>
distribution (intervals.begin(),intervals.end(),weights.begin());

  int rand1 = rand() % 100;
    if (rand1 > 50)
    {
      m_estFemme=0;
    }
    else
        {
        m_estFemme=1;
        }
int rand2(distribution(generator));
    m_espVie=rand2;
    m_nom="Villageoi ";
    char iChar[4];
    sprintf(iChar,"%d ",i+1);
    m_nom+=iChar;
    m_conjoint=0;
    m_maison=0;

    qDebug()<< "creation Villageoi" ;

}

int Villageoi::age()
{
    return m_age;
}

bool Villageoi::estFemme()
{
    return m_estFemme;
}

bool Villageoi::estVivant()
{
    return m_estVivant;
}

bool Villageoi::estMarie()
{
 return m_estMarie;
}
bool Villageoi::testMort()
{

    if (m_age>m_espVie || m_faim>7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Villageoi::mort()
{
 m_estVivant=0;
 m_maison->removeHabitant(this);
}

bool Villageoi::testNaissance()
{


    int nbRand = rand() % 100;


    if ( m_estFemme==1 && m_estMarie==1 && m_age<60*12)
    {
        if (nbRand>50+(m_age-18*12)*2)
        {
            return 1;
        }
            else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void Villageoi::naissance()
{
    m_nbEnfant++;
}

bool Villageoi::testMarriage(Villageoi &cible)
{
    bool cibleEstFemme(cible.estFemme());
    bool cibleEstMarie(cible.estMarie());
    int cibleAge(cible.age());
    if (m_estFemme!=cibleEstFemme && m_age>18*12 && cibleAge>18*12 && m_estMarie==0 && cibleEstMarie==0)
    {
            return 1;
    }
        else
    {
        return 0;
    }
}
void Villageoi::marriage(Villageoi* cible)
{
    m_estMarie=1;
    m_conjoint=cible;
    m_maison->removeHabitant(this);
    cible->marriage2(this);


}

void Villageoi::marriage2(Villageoi* source)
{
    m_estMarie=1;
    m_conjoint=source;
    m_maison->removeHabitant(this);

}

void Villageoi::ageIncr()
{
    m_age++;
    m_faim++;
    if(m_age==18*12)
    {
        m_force=5;
        m_travail=1;
    }
    else if(m_age>45*12)
    {
        int tmp(m_force--);
        if(tmp>0)
        {
        m_force=tmp;
        }  else{ m_force=0;}


    }else{}
}

void Villageoi::travail(Ville &cible)
{

if (m_travail=1)
{
    cible.vilProd((m_force)*m_sante);
    m_force++;
}
else{}


}


int Villageoi::nbEnfant()
{
   return m_nbEnfant;
}

string Villageoi::nom()
{
     return m_nom;
}

void Villageoi::mange(Ville &cible)
{

    if(m_age>18)
    {
            if(cible.vilMange(10))
            {
                m_faim=-1;

            }

            else{}
    }
    else
    {
        if(cible.vilMange(5)){m_faim=-1; }
        else{}

    }

}

void Villageoi::plusMarie()
{
    m_estMarie=0;
    m_conjoint->plusMarie2();

}

void Villageoi::plusMarie2()
{
    m_estMarie=0;
}

void Villageoi::setMaison(Maison* maison)
{
    m_maison = maison;
}

Maison* Villageoi::getMaison()
{
    return m_maison;
}
