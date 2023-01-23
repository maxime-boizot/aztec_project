#include "moncanvas.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

void MonCanvas::setPlateau(Plateau *newPlateau)
{
    m_plateau = newPlateau;
}

QPointF MonCanvas::changeCoo(QPointF p)
{

    return QPointF(p.x()*deltaX+margex, p.y()*deltaY+margeY);
}

MonCanvas::MonCanvas(QWidget *parent)
    : QWidget{parent}
{
    fond = new QImage(":/images/grille.png");
}

void MonCanvas::paintEvent(QPaintEvent *)
{
    if(m_plateau != nullptr) {
        QPainter painter(this);
        painter.drawImage(0, 0, *fond);
        QFont *police = new QFont("Arial", 40, QFont::Bold);
        painter.setFont(*police);
        for(int l=0;l<9; l++) {
            for(int c=0;c<9;c++) {
                int v = m_plateau->getValeur(l, c);
                if(v!=0) {
                    //qDebug() <<"Ligne "<<l<<", colonne "<<c<<" : valeur "<<v;
                    painter.drawText(changeCoo(QPointF(c, l)), QString::number(v));
                }
            }
        }
    }
}

/*
 * colonnes : 22, 111, 204
 * lignes : 10, 100, 190
 *
 */

void MonCanvas::mousePressEvent(QMouseEvent *event)
{
    int c = (event->position().x()-22)/90;
    int l = (event->position().y()-10)/90;
    qDebug() <<"Ligne "<<l<<", colonne "<<c<<", forme "<<m_plateau->getValeur(l, c);

    /*
     * Okok la on va coder mon pote
     * Du coup l'idée de base du calcule c'est de chopper la ligne et la colone de la ou ca à cliquer
     * Parcourir la ligne et la colone en stoquant les chiffres qu'elle contient
     * Ensuite afficher les chiffre (de 1-9) qui ne sont ni sur la ligne ni sur la colone
     *
     * Va falloire gerer les zonne pour ne pas afficher un chiffre qui en fait partie
     *
     * Comme on est des bg on va rendre ca multithreader ce qui fait que la liste des chiffres afficher sera calculer en continue et en arrière plan
     * Ce qui permet de ne pas faire attendre le user dès qu'il clique vu que l'op est lourde quand même
     * On va lui rajouter la possibilitè de jouer quand même c'est cool
     *
     * C'est tout en vrais ca passe de ouf.
     *
    */

    if(m_plateau->quelleForme(l,c) == 0) {
        return;
    }

    int tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < 9; i++) {
        int colform = m_plateau->getValeur(i, c);
        int ligform = m_plateau->getValeur(l, i);

        tab[colform] = colform;
        tab[ligform] = ligform;
    }

    for(int i = 1; i < 10; i ++) {
        if(tab[i]==0) {
            qDebug() <<i;
        }
    }
}
