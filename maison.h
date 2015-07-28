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

class Maison
{
public:
    Maison();
    Maison(Villageoi* parent1, Villageoi* parent2, int posX, int posY);
    void addEnfant(Villageoi* enfant);
    void removeHabitant(Villageoi* habitant);

private:
    int m_posX;
    int m_posY;
    std::vector<Villageoi*> m_habitants;
};

#endif // MAISON_H
