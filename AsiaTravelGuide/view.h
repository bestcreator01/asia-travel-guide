#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsOpacityEffect>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class view; }
QT_END_NAMESPACE

class view : public QMainWindow
{
    Q_OBJECT
    enum Widgets {backButton, welcomeButton, playButton};


public:
    view(QWidget *parent = nullptr);
    ~view();

private slots:
//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

    void on_playButton_clicked();

    void on_backButton_clicked();

private:
    Ui::view *ui;
    void fadeOutLabel();
    void hideStuff();
    void hideAll();
    void fadeInLabel();
//    void showStuff();
    //    void showAll();
    void fadeInBackArrow();
    void fadeEffect(double startValue, double endValue, QString widget);
    void currentAnimationWidget(QString name, QGraphicsOpacityEffect *eff);
signals:
    void hideWidgets();
    //void showWidgets();
};
#endif // VIEW_H
