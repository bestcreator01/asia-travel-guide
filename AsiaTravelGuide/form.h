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
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    void receiveSignalToSetTextIndia(QString name);

private slots:
    void on_nextButton_clicked();

    void on_backButton_clicked();

    //void on_backToMapButton_clicked();

    void closeEvent(QCloseEvent *bar);

signals:
    void windowClosed();

private:
    Ui::Form *ui;

    int current = 0;
    bool flag = true;
    QString landMarkInfo[4];
    QString restaurantInfo[4];
};

#endif // FORM_H
