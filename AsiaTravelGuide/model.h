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
#include <random>
#include <QTimer>

class Model : public QObject
{
    Q_OBJECT

    // Member variables for storing questions, options, and related data
    QString question1, question2, question3, question4;
    QString option1, option2, option3, option4;
    QList<int> numbers = {0, 1, 2, 3};
    QList<QString> questions;
    QMap<QString, QList<QString>> questionBank;

public:
    ///
    /// \brief Model
    ///     Constructor.
    /// \param parent - The parent object.
    ///
    Model(QObject *parent = nullptr);

public slots:
    ///
    /// \brief changeState
    ///     Update the previous state based on the current state. This is used for back button
    ///     to keep track of on which screen the current user is on.
    /// \param state - The current state.
    ///
    void changeState(QString state);

    ///
    /// \brief ShowQuizInfo
    ///     Clears the existing question bank and questions, sets the questions and options
    ///     based on the selected country, and emits signals to send the quiz information to the UI.
    /// \param country - The selected country for the quiz.
    ///
    void showQuizInfo(QString country);

    ///
    /// \brief andomizeOption
    ///     Generates a random order for the options and emits a signal to send the
    ///     randomized order to the UI.
    ///
    void randomizeOption();

signals:
    /*
     * The following methods below inform the mainwindow that the current state is changed.
     */
    void changedScreenState(QString state);
    void sendQuiz(QMap<QString, QList<QString>> &questionbank, QList<QString> &questions);
    void sendOptions(QList<int> &numbers);
    void sendCountryForBgImage(QString country);

private:
    ///
    /// \brief setIndia
    /// Sets the questions and options for the India quiz.
    ///
    void setIndia();

    ///
    /// \brief setThailand
    /// Sets the questions and options for the Thailand quiz.
    ///
    void setThailand();

    ///
    /// \brief setKorea
    /// Sets the questions and options for the Korea quiz.
    ///
    void setKorea();

    ///
    /// \brief putQuestionInQuestionBank
    ///     Adds a question and its options to the question bank.
    /// \param question - The question to be added.
    ///
    void putQuestionInQuestionBank(QString question);

    ///
    /// \brief randomizeQuestions
    ///     Shuffles the order of questions and emits a signal to send the
    ///     randomized order to the UI.
    ///
    void randomizeQuestions();
};

#endif // MODEL_H
