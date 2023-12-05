#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <QMap>
#include <QList>
#include <QRandomGenerator>
#include <algorithm>
#include <random>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QPainter>
#include <QLabel>

namespace Ui {
class Quiz;
}

class Quiz : public QWidget
{
    Q_OBJECT
    QLabel *backgroundLabel;

public:
    explicit Quiz(QWidget *parent = nullptr);
    ~Quiz();

    void showRandomQuestion();
    void resetButtons();
    void closeWindow();
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

    void generateConfettiColors();
    void createConfetti();
    void createGround(float, float);
    void updateWorld();
    void applyExplosionForce(b2Vec2, float);

    QTimer timer;

    b2World *top;
    b2World *bottom;
    QVector<QColor> confettiColors;
    QList<b2Body*> topConfettiPieces;
    QList<b2Body*> bottomConfettiPieces;

    bool topTouchedGround;
    bool bottomTouchedGround;
};

#endif // QUIZ_H
