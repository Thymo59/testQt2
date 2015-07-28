#ifndef MAISON_H
#define MAISON_H

#include<string>
#include <iostream>
#include <string>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"Ville.h"
#include"Famille.h"
#include"Villageoi.h"
#include<vector>

class Maison
{
public:
    Maison(Famille& famille, int posX, int posY);

private:
    int m_posX;
    int m_posY;
    Famille *m_famille;
};

#endif // MAISON_H
