#ifndef FORM_H
#define FORM_H

#include <QLabel>
#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    QTimer *timer;
    QLabel *backgroundLabel;

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void closeWindow();

public slots:
    void receiveSignalToSetTextIndia(QString name);

private slots:
    void on_nextButton_clicked();

    void on_backButton_clicked();

    void closeEvent(QCloseEvent *bar);

signals:
    void windowClosed();
    void stopTimer();

private:
    Ui::Form *ui;

    int current = 0;
    bool flag = true;
    QString landMarkInfo[4];
    QString restaurantInfo[4];
    QString currentText;
    bool firstNextClicked = false;
    bool firstBackClicked = false;
    int now = 0;
    void startTyping();
    QStringList splittedText;

    void setLandmarkIndiaHelper(int currentNum, QString image);
    void setRestaurantIndiaHelper(int currentNum, QString image);
    void nextButtonHelper(QString info[]);
    void backButtonHelper(QString info[]);
    void buttonHelper(bool isNextButton);
};

#endif // FORM_H
