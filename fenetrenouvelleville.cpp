#include "FenetreNouvelleVille.h"
#include "fenetreville.h"
#include <QFormLayout>
FenetreNouvelleVille::FenetreNouvelleVille() : QWidget()
{

setFixedSize(400,100);


m_lineNbInit = new QLineEdit(this);
QValidator *validint = new QIntValidator(0,1000,this);
m_lineNbInit->setValidator(validint);

m_lineNom = new QLineEdit(this);

m_formLayout1 = new QFormLayout;
m_formLayout1->addRow("Nom de la ville: ",m_lineNom);
m_formLayout1->addRow("Nombre de villageios initial: ",m_lineNbInit);


m_layoutPrincipal = new QVBoxLayout;
m_layoutPrincipal->addLayout(m_formLayout1);

m_boutonGo = new QPushButton("Go");
m_boutonGo->setFixedWidth(200);
m_boutonGo->move(100,0);
m_layoutPrincipal->addWidget(m_boutonGo);
QObject::connect(m_boutonGo,SIGNAL(clicked()),this,SLOT(creationVille()));


this->setLayout(m_layoutPrincipal);

}

void FenetreNouvelleVille::creationVille()
{
    QString text1 = m_lineNbInit->text();
    int NbVil = text1.toInt(0,10);
    QString text2 = m_lineNom->text();

    if(!text1.isEmpty() && !text2.isEmpty() )
    {
        FenetreVille *ville1 = new FenetreVille(NbVil,text2.toStdString());
        ville1->show();
    }
    else
    {
        QMessageBox::critical(this, " creationVille ","Veuiller remplire tout les champs");
    }


}





