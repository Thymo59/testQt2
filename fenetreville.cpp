#include "fenetreville.h"
#include<QLabel>
#include<QIntValidator>
#include <QTimer>

FenetreVille::FenetreVille(int NbVil , std::string nom ) : QWidget()
{


    m_ville = new Ville(NbVil,nom);


    QString nomQ(nom.c_str());
    m_labNomQ = new QLabel(nomQ);

    m_strNbVil.setNum(m_ville->nbVil());
    m_labNbVil = new QLabel(m_strNbVil);

    m_strAge.setNum(m_ville->age());
    m_labAge = new QLabel(m_strAge);

    m_editAgeIncr = new QLineEdit;
    QValidator *validint2 = new QIntValidator(0,500,this);
    m_editAgeIncr->setValidator(validint2);


    m_strNbFemme.setNum(m_ville->nbFemme());
    m_labNbFemme = new QLabel(m_strNbFemme);

    m_strNbHomme.setNum(m_ville->nbHomme());
    m_labNbHomme = new QLabel(m_strNbHomme);

    m_strNbEnfant.setNum(m_ville->nbEnfant());
    m_labNbEnfant = new QLabel(m_strNbEnfant);

    m_strNbAdult.setNum(m_ville->nbAdult());
    m_labNbAdult = new QLabel(m_strNbAdult);

    m_strNbNourriture.setNum(m_ville->nbNourriture());
    m_labNbNourriture = new QLabel(m_strNbNourriture);

    m_strNbBois.setNum(m_ville->nbBois());
    m_labNbBois = new QLabel(m_strNbBois);

    m_strNbMaison.setNum(m_ville->nbMaison());
    m_labNbMaison = new QLabel(m_strNbMaison);

    m_formLayout= new QFormLayout;

    m_formLayout->addRow("Nom de la ville: ", m_labNomQ);
    m_formLayout->addRow("Nonbre de villageois: ", m_labNbVil);
    m_formLayout->addRow("Nombre de Maisons: ",m_labNbMaison);
    m_formLayout->addRow("Nourriture: ",m_labNbNourriture);
    m_formLayout->addRow("Bois: ",m_labNbBois);
    m_formLayout->addRow("-Adults :",m_labNbAdult);
    m_formLayout->addRow("--femmes :",m_labNbFemme);
    m_formLayout->addRow("--hommes :",m_labNbHomme);
    m_formLayout->addRow("-enfants :",m_labNbEnfant);
    m_formLayout->addRow("Age de la ville: ", m_labAge);

    m_formLayout->addRow("Vitesse : ", m_editAgeIncr);
    m_boutonAgeIncr = new QPushButton("Go!");

    m_vBoxLayout = new QVBoxLayout(this);
    m_vBoxLayout->addLayout(m_formLayout);
    m_vBoxLayout->addWidget(m_boutonAgeIncr);


    QObject::connect(m_boutonAgeIncr,SIGNAL(clicked()),this,SLOT(goIncr()));
    QObject::connect(m_ville,SIGNAL(nbVilModif(int)),m_labNbVil,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(ageModif(int)),m_labAge,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbFemmeModif(int)),m_labNbFemme,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbHommeModif(int)),m_labNbHomme,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbEnfantModif(int)),m_labNbEnfant,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbAdultModif(int)),m_labNbAdult,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbMaisonModif(int)),m_labNbMaison,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbNourritureModif(int)),m_labNbNourriture,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbBoisModif(int)),m_labNbBois,SLOT(setNum(int)));
}

void FenetreVille::goIncr()
{
    QString nbIncr = m_editAgeIncr->text();
    int intNbIncr(0);
    intNbIncr = nbIncr.toInt();

    QTimer *timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(ageIncr()));
    timer->start(intNbIncr*1000);
}

void FenetreVille::ageIncr()
{


        while(m_ville->nbVil()!=0)
        {
            m_ville->anIncr();
            m_ville->upDate();    
        }

}

