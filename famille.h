#ifndef FAMILLE_H
#define FAMILLE_H

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

class Famille
{
public:
    Famille(int i, int j, Ville& ville);

private:

    int m_nbEnfant;
    Villageoi *m_parent1;
    Villageoi *m_parent2;
    Ville *m_ville;
};

#endif // FAMILLE_H
