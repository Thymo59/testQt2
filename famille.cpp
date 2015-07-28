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



using namespace std;
Famille::Famille(int i, int j , Ville& ville) : m_nbEnfant(0)
{
    m_ville= &ville;
    m_parent1 = m_ville->villageoi(i);
    m_parent2 = m_ville->villageoi(j);
}

