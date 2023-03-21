#include "possibilites.h"
#include "ui_possibilites.h"

Possibilites::Possibilites(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Possibilites)
{
    ui->setupUi(this);
}

Possibilites::~Possibilites()
{
    delete ui;
}
