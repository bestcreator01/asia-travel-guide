#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsOpacityEffect>
#include <QMainWindow>
#include <QLabel>

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

    void on_playButton_clicked();

    void on_backButton_clicked();

private:
    Ui::view *ui;

    QLabel *backgroundLabel;

    // widgets fade in/out
    void fadeInWelcomeLabel();
    void fadeOutWelcomeLabel();
    void fadeInPlayButton();
    void fadeOutPlayButton();
    void fadeInBackArrow();
    void fadeOutBackArrow();
    void fadeInMarkers();
    void fadeOutMarkers();
    void fadeEffect(double startValue, double endValue, QString widget);
    void setWidgetGraphicsEffect(QString name, QGraphicsOpacityEffect *eff);

signals:
    void hideWidgets();
};
#endif // VIEW_H
