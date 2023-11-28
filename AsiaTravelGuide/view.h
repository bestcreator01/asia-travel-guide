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

public:
    view(QWidget *parent = nullptr);
    ~view();

private slots:

    ///
    /// \brief hide play button, welcome lable
    /// and display next screen (map, markers)
    ///
    void on_playButton_clicked();

    void on_backButton_clicked();

private:
    Ui::view *ui;

    // play button clicked

    void fadeOutWelcomeLabel();
    void fadeOutPlayButton();
    void hideStuff();
    void hideAll();
    void fadeInLabel();
    void fadeInBackArrow();
    void fadeEffect(double startValue, double endValue, QString widget);
    void setWidgetGraphicsEffect(QString name, QGraphicsOpacityEffect *eff);
signals:
    void hideWidgets();
    //void showWidgets();
};
#endif // VIEW_H
