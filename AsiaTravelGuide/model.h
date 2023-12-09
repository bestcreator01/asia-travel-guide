/**
 * Author:     Crazy Broke Asians
 * Date:       Dec-08-2023
 * Course:     CS 3505, University of Utah
 * Assignment: A9: An Educational App
 * File Contents
 *      It contains all necessary information needed to form a model class.
*/

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
    QString question1, question2, question3, question4;
    QString option1, option2, option3, option4;
    QList<int> numbers = {0, 1, 2, 3};
    QList<QString> questions;
    QMap<QString, QList<QString>> questionBank;

public:
    Model(QObject *parent = nullptr);

public slots:

    ///
    /// \brief changeState update the previous state based on the current state
    /// \param state current state
    ///
    void changeState(QString state);
    void showQuizInfo(QString Country);
    void randomizeOption();


signals:
    void changedScreenState(QString state);
    void sendQuiz(QMap<QString, QList<QString>> &questionbank, QList<QString> &questions);
    void sendOptions(QList<int> &numbers);
    void sendCountryForBgImage(QString country);

private:
    void setIndia();
    void setThailand();
    void setKorea();
    void putQuestionInQuestionBank(QString question);
    void randomizeQuestions();
};

#endif // MODEL_H
