#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsOpacityEffect>
#include <QMainWindow>
#include <QLabel>
#include "model.h"
#include "form.h"

QT_BEGIN_NAMESPACE
namespace Ui { class view; }
QT_END_NAMESPACE

class view : public QMainWindow
{
    Q_OBJECT
    QString previousState;

public:
    view(Model& model, QWidget *parent = nullptr);
    ~view();

private slots:

    void on_playButton_clicked();
    void on_backButton_clicked();
    void on_indiaButton_clicked();
    void updateState(QString state);

    void on_hawaMahal_clicked();

    void on_tajMahal_clicked();

    void on_paniPuri_clicked();

    void on_biryani_clicked();

private:
    Ui::view *ui;

    QLabel *backgroundLabel;

    Form indiaWindow;

    // widgets fade in/out
    void fadeInWelcomeLabel();
    void fadeOutWelcomeLabel();
    void fadeInPlayButton();
    void fadeOutPlayButton();
    void fadeInBackArrow();
    void fadeOutBackArrow();
    void fadeInMarkers();
    void fadeOutMarkers();
    void fadeInLandMarks();
    void hideLandMarks();
    void fadeEffect(double startValue, double endValue, int duration, QString widget);
    void setWidgetGraphicsEffect(QString name, QGraphicsOpacityEffect *eff);

    void fadeInBackgroundLabel();
    void fadeOutBackgroundLabel();
    void setBgLabel(QPixmap background);
    void setBgLabelOpacity();

    void disableButtons();
    void enableButtonsAndCheck();
    int count;
signals:
    void hideWidgets();
    void changedState(QString state);

    void informModelToSend(QString name);
};
#endif // VIEW_H
