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
//    void receiveSignalToSendTextIndia(QString name);


signals:
    void changedScreenState(QString state);
//    void sendDescriptions(QString description);

private:
//    QString landMarkInfo[2];
//    QString restaurantInfo[2];

//    enum Country{India, Korea, Thailand};
//    enum Place{Restaurant, Landmark};

//    Country currentCountry;
//    Place currentPlace;





};

#endif // MODEL_H
