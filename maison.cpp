#include "maison.h"
#include "famille.h"
#include"Villageoi.h"
#include"Ville.h"
#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<random>
#include<vector>
#include <array>

Maison::Maison(Famille& famille, int posX, int posY)
{
 m_famille = &famille;
 m_posX=posX;
 m_posY=posY;
}

