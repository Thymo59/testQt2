#ifndef FENETREVILLE_H
#define FENETREVILLE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QFormLayout>
#include <string>
#include <QFormLayout>
#include "Ville.h"


class FenetreVille : public QWidget
{
    Q_OBJECT

public:

    FenetreVille(int NbVil, std::string nom);

public slots:

    void ageIncr();

private:

    Ville *m_ville;
    QFormLayout *m_formLayout;
    QVBoxLayout *m_vBoxLayout;
    QString m_strNbVil;
    QString m_strAge;
    QLabel *m_labNbVil;
    QLabel *m_labAge;
    QLabel *m_labNomQ;
    QLineEdit *m_editAgeIncr;
    QPushButton *m_boutonAgeIncr;
    QString m_strNbFemme;
    QLabel *m_labNbFemme;
    QString m_strNbHomme;
    QLabel *m_labNbHomme;
    QString m_strNbEnfant;
    QLabel *m_labNbEnfant;
    QString m_strNbAdult;
    QLabel *m_labNbAdult;
    QString m_strNbFamille;
    QLabel *m_labNbFamille;

};

#endif // FENETREVILLE_H
