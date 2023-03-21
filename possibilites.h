#ifndef POSSIBILITES_H
#define POSSIBILITES_H

#include <QDialog>

namespace Ui {
class Possibilites;
}

class Possibilites : public QDialog
{
    Q_OBJECT

public:
    explicit Possibilites(QWidget *parent = nullptr);
    ~Possibilites();

private:
    Ui::Possibilites *ui;
};

#endif // POSSIBILITES_H
