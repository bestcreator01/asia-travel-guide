#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    QTimer *timer;

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
    QString currentText;
    bool firstNextClicked = false;
    bool firstBackClicked = false;
//    void splitLandMarkText();
//    void splitRestaurentText();
    int now = 0;
    void startTyping();
    QStringList splittedText;
};

#endif // FORM_H
