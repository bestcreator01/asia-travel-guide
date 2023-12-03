#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <QMap>
#include <QList>
#include <QRandomGenerator>
#include <algorithm>
#include <random>
#include <Box2D/Box2D.h>
#include <vector>
#include <QTimer>
#include <QPainter>

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

    void on_nextButton_clicked();

    void closeEvent(QCloseEvent *bar);

    void closePaint();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Quiz *ui;
    QString randomQuestion;
    QString question1, question2, question3, question4;
    QString option1, option2, option3, option4;
    QList<int> numbers = {0, 1, 2, 3};
    QList<QString> questions;
    int quesIndex = 0;

    QMap<QString, QList<QString>> questionBank;
    void disableOptionButtons();

    void createConfetti();
    void createGround();
    void updateWorld();

    QTimer timer;

    b2World *world;
    std::vector<b2Body*> confettiPieces;

    bool touchedGround;
};

#endif // QUIZ_H
