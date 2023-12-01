#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <QMap>
#include <QList>

namespace Ui {
class Quiz;
}

class Quiz : public QWidget
{
    Q_OBJECT

public:
    explicit Quiz(QWidget *parent = nullptr);
    ~Quiz();

private:
    Ui::Quiz *ui;

    QMap<QString, QList<QString>> questionBank;
};

#endif // QUIZ_H
