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

Maison::Maison(Villageoi* parent1, Villageoi* parent2, int posX, int posY)
{
   m_habitants.push_back(parent1);
   m_habitants.push_back(parent2);
   m_posX=posX;
   m_posY=posY;
}

Maison::Maison(): m_posX(0), m_posY(0)
{

}

void Maison::addEnfant(Villageoi *enfant)
{
 m_habitants.push_back(enfant);
}

void Maison::removeHabitant(Villageoi *habitant)
{
    for(int i(0);i<m_habitants.size();i++)
    {
       if(m_habitants[i] == habitant)
       {
           m_habitants.erase(m_habitants.begin()+i);
       }
       else{}
    }
}

