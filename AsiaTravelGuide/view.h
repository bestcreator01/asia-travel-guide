#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsOpacityEffect>
#include <QMainWindow>
#include <QLabel>
#include <QSet>
#include "model.h"
#include "form.h"
#include "quiz.h"

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

    void closeEvent(QCloseEvent *event);
private slots:

    void on_playButton_clicked();
    void on_backButton_clicked();
    void on_indiaButton_clicked();
    void updateState(QString state);

    void on_hawaMahal_clicked();

    void on_tajMahal_clicked();

    void on_paniPuri_clicked();

    void on_biryani_clicked();

    void on_quizButton_clicked();

    void on_koreaButton_clicked();

    void on_bulguksaButton_clicked();

    void on_gyeongbokgungButton_clicked();

    void on_tteokbokkiButton_clicked();

    void on_bossamButton_clicked();

    void on_thailandButton_clicked();

    void on_grandPalaceButton_clicked();

    void on_watMuangButton_clicked();

    void on_tomYumButton_clicked();

    void on_stickyRiceButton_clicked();

private:
    Ui::view *ui;

    enum Country {India, Korea, Thailand};

    enum IndiaPlace{HawaMaha, TajMahal, PaniPuri, Biryani};
    QSet<IndiaPlace> indiaCompleteList;

    enum KoreaPlace{Gyeongbokgung, Bulguksa, Tteokbokki, Bossam};
    QSet<KoreaPlace> koreaCompleteList;

    enum ThailandPlace{GrandPalace, WatMuang, TomYum, StickyRice};
    QSet<ThailandPlace> ThailandCompleteList;

    QLabel *backgroundLabel;

    Form indiaWindow;
    Quiz quizWindow;

    // widgets fade in/out
    void fadeInWelcomeLabel();
    void fadeOutWelcomeLabel();
    void fadeInPlayButton();
    void fadeOutPlayButton();
    void fadeInBackArrow();
    void fadeOutBackArrow();
    void fadeInMarkers();
    void fadeOutMarkers();
    void fadeInLandMarks(Country country);
    void hideLandMarks();
    void hideCheckMarks();
    void fadeEffect(double startValue, double endValue, int duration, QString widget);
    void setWidgetGraphicsEffect(QString name, QGraphicsOpacityEffect *eff);

    void fadeInBackgroundLabel();
    void setBgLabel(QPixmap background);
    void setBgLabelOpacity();

    void disableButtons();
    void enableButtonsAndCheck();
    void showInfo(QString);
    int count;

    void fadeInCountryLabels();
    void fadeOutCountryLabels();
    void fadeInCheckmarks(Country country);

signals:
    void hideWidgets();
    void changedState(QString state);

    void informModelToSend(QString name);

    void generateRandomQuestion();
    void resetButtons();
};
#endif // VIEW_H
