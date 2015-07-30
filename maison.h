#ifndef MAISON_H
#define MAISON_H

#include<string>
#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"Ville.h"
#include"Villageoi.h"
#include<vector>
class Villageoi;
class Ville;

class Maison
{
public:
    Maison(Ville* ville);
    Maison(Ville* ville,Villageoi* parent1, Villageoi* parent2, int posX, int posY);
    void addEnfant(Villageoi* enfant);
    void removeHabitant(Villageoi* habitant);
    void upDate();

private:
    Ville *m_ville;
    int m_posX;
    int m_posY;
    std::vector<Villageoi*> m_habitants;
    int m_construction;
};

#endif // MAISON_H
