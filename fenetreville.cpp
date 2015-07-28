#include "fenetreville.h"
#include<QLabel>
#include<QIntValidator>



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


    m_strAge.setNum(m_ville->age());
    m_labAge = new QLabel(m_strAge);

    m_strNbFemme.setNum(m_ville->nbFemme());
    m_labNbFemme = new QLabel(m_strNbFemme);

    m_strNbHomme.setNum(m_ville->nbHomme());
    m_labNbHomme = new QLabel(m_strNbHomme);

    m_strNbEnfant.setNum(m_ville->nbEnfant());
    m_labNbEnfant = new QLabel(m_strNbEnfant);

    m_strNbAdult.setNum(m_ville->nbAdult());
    m_labNbAdult = new QLabel(m_strNbAdult);

    m_strNbFamille.setNum(m_ville->nbFamille());
    m_labNbFamille = new QLabel(m_strNbFamille);

    m_formLayout= new QFormLayout;
    m_formLayout->addRow("Nom de la ville: ", m_labNomQ);
    m_formLayout->addRow("Nonbre de villageois: ", m_labNbVil);
    m_formLayout->addRow("Nonbre de Familles: ", m_labNbFamille);
      m_formLayout->addRow("-Adults :",m_labNbAdult);
        m_formLayout->addRow("--femmes :",m_labNbFemme);
        m_formLayout->addRow("--hommes :",m_labNbHomme);
      m_formLayout->addRow("-enfants :",m_labNbEnfant);
    m_formLayout->addRow("Age de la ville: ", m_labAge);
    m_formLayout->addRow("Nombre d'années a passer: ", m_editAgeIncr);




    m_boutonAgeIncr = new QPushButton("go");

    m_vBoxLayout = new QVBoxLayout(this);
    m_vBoxLayout->addLayout(m_formLayout);
    m_vBoxLayout->addWidget(m_boutonAgeIncr);


    QObject::connect(m_boutonAgeIncr,SIGNAL(clicked()),this,SLOT(ageIncr()));
    QObject::connect(m_ville,SIGNAL(nbVilModif(int)),m_labNbVil,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(ageModif(int)),m_labAge,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbFemmeModif(int)),m_labNbFemme,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbHommeModif(int)),m_labNbHomme,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbEnfantModif(int)),m_labNbEnfant,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbAdultModif(int)),m_labNbAdult,SLOT(setNum(int)));
    QObject::connect(m_ville,SIGNAL(nbFamilleModif(int)),m_labNbFamille,SLOT(setNum(int)));
}

void FenetreVille::ageIncr()
{
    QString nbIncr = m_editAgeIncr->text();

        int intNbIncr(0);
        intNbIncr = nbIncr.toInt();
        for(int i(0); i<intNbIncr; i++)
        {
            m_ville->anIncr();
            m_ville->upDate();

        }

}

