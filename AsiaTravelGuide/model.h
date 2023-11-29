#ifndef MODEL_H
#define MODEL_H

#include <QObject>


class Model : public QObject
{
    Q_OBJECT
    //enum State{Welcome, AsiaMap, CountryMap};

public:
    Model(QObject *parent = nullptr);


public slots:
    void changeState(QString state);


signals:
    void changedScreenState(QString state);


private:

//    enum Country{India, Korea, Thailand};
//    enum Place{Restaurant, Landmark};

//    Country currentCountry;
//    Place currentPlace;





};

#endif // MODEL_H
