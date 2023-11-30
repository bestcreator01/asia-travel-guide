#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "model.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Ui::Form *ui;
    explicit Form(QWidget *parent = nullptr);
    ~Form();
public slots:
    void receiveSignalToSetTextIndia(QString name);

private:
    //Ui::Form *ui;

    QString landMarkInfo[2];
    QString restaurantInfo[2];
};

#endif // FORM_H
