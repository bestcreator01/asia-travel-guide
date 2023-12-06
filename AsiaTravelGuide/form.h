#ifndef FORM_H
#define FORM_H

#include <QLabel>
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    QTimer *timer;
    QLabel *backgroundLabel;

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void closeWindow();

public slots:
    void receiveSignalToSetTextIndia(QString name);

private slots:
    void on_nextButton_clicked();

    void on_backButton_clicked();

    void closeEvent(QCloseEvent *bar);

signals:
    void windowClosed();
    void stopTimer();

private:
    Ui::Form *ui;

    int current = 0;
    bool flag = true;
    QString indiaLandMarkInfo[4];
    QString indiaRestaurantInfo[4];
    QString koreaLandMarkInfo[4];
    QString koreaRestaurantInfo[4];
    QString thailandLandMarkInfo[4];
    QString thailandRestaurantInfo[4];
    QString currentText;
    QString currentCountry;
    bool firstNextClicked = false;
    bool firstBackClicked = false;
    int now = 0;
    void startTyping();
    QStringList splittedText;

    void setLandmarkIndiaHelper(int currentNum, QString image);
    void setRestaurantIndiaHelper(int currentNum, QString image);
    void nextButtonHelper(QString info[]);
    void backButtonHelper(QString info[]);
    void buttonHelper(bool isNextButton);
    void setLandmarkThailandHelper(int currentNum, QString image);
    void setRestaurantThailandHelper(int currentNum, QString image);
    void setRestaurantKoreaHelper(int currentNum, QString image);
    void setLandmarkKoreaHelper(int currentNum, QString image);
};

#endif // FORM_H
