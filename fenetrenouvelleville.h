#ifndef FenetreNouvelleVille_H
#define FenetreNouvelleVille_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QIntValidator>
#include <QFormLayout>
#include <QVBoxLayout>
class FenetreNouvelleVille : public QWidget
{

    Q_OBJECT

public:

    FenetreNouvelleVille();

public slots:

    void creationVille();

private:

    QPushButton *m_boutonGo;
    QLineEdit *m_lineNbInit;
    QLineEdit *m_lineNom;
    QLabel *m_label1;
    QLabel *m_label2;
    QFormLayout *m_formLayout1;
    QVBoxLayout *m_layoutPrincipal;
};

#endif // FenetreNouvelleVille_H
