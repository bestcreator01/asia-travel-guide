#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <QMap>
#include <QList>
#include <QRandomGenerator>
#include <algorithm>
#include <random>

namespace Ui {
class Quiz;
}

class Quiz : public QWidget
{
    Q_OBJECT

public:
    explicit Quiz(QWidget *parent = nullptr);
    ~Quiz();

    void showRandomQuestion();
    void resetButtons();

private slots:
    void on_option1Button_clicked();

    void on_option2Button_clicked();

    void on_option3Button_clicked();

    void on_option4Button_clicked();

private:
    Ui::Quiz *ui;
    QString randomQuestion;
    QString question1, question2, question3, question4;
    QString option1, option2, option3, option4;
    QList<int> numbers = {0, 1, 2, 3};

    QMap<QString, QList<QString>> questionBank;
    void disableOptionButtons();
};

#endif // QUIZ_H
