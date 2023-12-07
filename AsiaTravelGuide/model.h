#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QRandomGenerator>
//#include <algorithm>
#include <random>
#include <QTimer>

class Model : public QObject
{
    Q_OBJECT
    //enum State{Welcome, AsiaMap, CountryMap};
    QString question1, question2, question3, question4;
    QString option1, option2, option3, option4;
    QList<int> numbers = {0, 1, 2, 3};
    QList<QString> questions;
    QMap<QString, QList<QString>> questionBank;

public:
    Model(QObject *parent = nullptr);

public slots:
    void changeState(QString state);
    void showQuizInfo(QString Country);
    void randomizeOption();
//    void receiveSignalToSendTextIndia(QString name);


signals:
    void changedScreenState(QString state);
    void sendQuiz(QMap<QString, QList<QString>> &questionbank, QList<QString> &questions);
    void sendOptions(QList<int> &numbers);
//    void sendDescriptions(QString description);

private:
    void setIndia();
    void setThailand();
    void setKorea();
//    QString landMarkInfo[2];
//    QString restaurantInfo[2];

//    enum Country{India, Korea, Thailand};
//    enum Place{Restaurant, Landmark};

//    Country currentCountry;
//    Place currentPlace;





};

#endif // MODEL_H
