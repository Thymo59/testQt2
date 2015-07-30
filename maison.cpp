#include "maison.h"
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

Maison::Maison(Ville* ville,Villageoi* parent1, Villageoi* parent2, int posX, int posY) : m_construction(0)
{
   m_ville=ville;
   ville->addConstruction(this);
   m_habitants.push_back(parent1);
   parent1->setMaison(this);
   m_habitants.push_back(parent2);
   parent2->setMaison(this);
   m_posX=posX;
   m_posY=posY;
   ville->consommeBois(5);
   qDebug() << "creation Maison";
}

Maison::Maison(Ville* ville): m_posX(0), m_posY(0), m_construction(0)
{
    m_ville=ville;
    ville->addConstruction(this);
    ville->consommeBois(5);
    qDebug() << "creation Maison";
}

void Maison::addEnfant(Villageoi *enfant)
{
 m_habitants.push_back(enfant);
 enfant->setMaison(this);
 qDebug() << "addEnfant";
}

void Maison::removeHabitant(Villageoi *habitant)
{
 qDebug() << "removeHabitant";
    for(int i(0);i<m_habitants.size();i++)
    {

       if(m_habitants[i] == habitant)
       {

           m_habitants[i]->setMaison(0);
           m_habitants.erase(m_habitants.begin()+i);
       }
       else
       {
       }
    }
}

void Maison::upDate()
{
    m_construction++;
            if(m_construction>6)
    {
        m_ville->removeConstruction(this);
        qDebug() << "fin Construction";
    }
}

