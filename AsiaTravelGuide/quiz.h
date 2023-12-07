#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <QMap>
#include <QList>
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
    void setValues(QMap<QString, QList<QString>> &questionBank, QList<QString> &questions);
    void setRandomOptions(QList<int> &numbers);

signals:
    void randomizeOption();

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
    QList<int> numbers;
    QList<QString> questions;
    QMap<QString, QList<QString>> questionBank;
    int quesIndex = 0, correct = 2;
    void disableOptionButtons();

    void generateConfettiColors();
    void createConfetti();
    void createGround(float, float);
    void updateWorld();
    void applyExplosionForce(b2Vec2, float);
    void randomizeSelection(QList<int> numbers);

    QTimer timer;

    b2World *top;
    b2World *bottom;
    QVector<QColor> confettiColors;
    QList<b2Body*> confettiPieces;
};

#endif // QUIZ_H
