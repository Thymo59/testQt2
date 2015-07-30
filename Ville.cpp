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

Ville::Ville(int nbVil, string nom) : QWidget() ,m_bois (500),m_nbMaison(1), m_age(0),m_nbVil(0), m_pourCentMarie(0), m_enfantParFemme(0), m_nbAdult(0), m_nbEnfant(0),m_nbHomme(0), m_nbFemme(0), m_nbMarie(0) , m_nourriture(20000), m_nom(nom)
{

    Maison *maison0(0);
    maison0 = new Maison(this);
    m_maisons.push_back(maison0);
    m_nbMaison=m_maisons.size();
    for (int i(1);i<nbVil+1;i++)
    {
        this->newVil(m_maisons[0]);
    }
}

void Ville::newVil(Maison* maison)
{
        Villageoi *ptrVil(0);
        ptrVil = new Villageoi(m_nbVil+1,this);
        m_villageois.push_back(ptrVil);
        m_nbEnfant++;
        m_nbVil=m_villageois.size();
        maison->addEnfant(m_villageois.back());

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
  qDebug() << "début update" << m_age;
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
        m_villageois[i]->levelUp();

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
        this->addMaison(m_villageois[rand1],m_villageois[i],0,0);

    }
    else{}

    if(m_villageois[i]->testNaissance())
    {
       m_villageois[i]->setEnceinte();


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

    int j(0);
    while (j<m_constructions.size())
    {
        m_constructions[j]->upDate();
        j++;
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
    emit nbBoisModif(m_bois);
    emit nbNourritureModif(m_nourriture);

    qDebug() << "fin update";
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

int Ville::nbBois()
{
    return m_bois;
}
int Ville::nbNourriture()
{
    return m_nourriture;
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

void Ville::consommeBois(int a)
{
    m_bois = m_bois-a;
}

void Ville::addMaison(Villageoi* parent1,Villageoi* parent2,int posX,int posY)
{

    Maison *ptrMaison(0);
    ptrMaison = new Maison(this,parent1,parent2, posX , posY);
    m_maisons.push_back(ptrMaison);
    m_nbMaison=m_maisons.size();
}
void Ville::removeConstruction(Maison *maison)
{
for(int i(0);i<m_constructions.size();i++)
{

   if(m_constructions[i] == maison)
   {
       m_constructions.erase(m_constructions.begin()+i);
   }
   else{}
}
}

void Ville::addConstruction(Maison *maison)
{
    m_constructions.push_back(maison);
}
