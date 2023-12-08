#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsOpacityEffect>
#include <QMainWindow>
#include <QLabel>
#include <QSet>
#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPalette>
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

    ///
    /// \brief on_playButton_clicked will fade in the background and 3 country clickable markers. With this
    /// it will fade out the labels and the button itself.
    ///
    void on_playButton_clicked();

    ///
    /// \brief on_backButton_clicked the user can go back to the previous state of the window. Keeps track
    /// of the current window the user is on and fades in/out the screen as per the current state.
    ///
    void on_backButton_clicked();
    void on_quizButton_clicked();
    void updateState(QString state);

    ///
    /// \brief on_indiaButton_clicked will fade out the Asia country map and zoom in to the India's map
    /// and hide/unhide and fade in/out all necessary buttons.
    ///
    void on_indiaButton_clicked();
    void on_hawaMahal_clicked();
    void on_tajMahal_clicked();
    void on_paniPuri_clicked();
    void on_biryani_clicked();

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

    // shadow effect on text
    void applyShadowEffect(QWidget *widget);
    void showShadowEffect();
    void showShadowPlayButton();

    // widgets fade in/out
    ///
    /// \brief fadeInWelcomeLabel fades in the welcome screen's labels
    ///
    void fadeInWelcomeLabel();

    ///
    /// \brief fadeOutWelcomeLabel fades out the welcome screen's labels
    ///
    void fadeOutWelcomeLabel();

    ///
    /// \brief fadeInPlayButton fades in the play button on the welcome screen
    ///
    void fadeInPlayButton();

    ///
    /// \brief fadeOutPlayButton fades out the play button when pressed on the welcome screen
    ///
    void fadeOutPlayButton();
    ///
    /// \brief fadeInBackArrow fades in the back arrow
    ///
    void fadeInBackArrow();
    ///
    /// \brief fadeOutBackArrow fades out the back arrow
    ///
    void fadeOutBackArrow();
    ///
    /// \brief fadeInMarkers fades in all the country's markers on the Asia country map
    ///
    void fadeInMarkers();
    ///
    /// \brief fadeOutMarkers fades out all the country's markers on the Asia country map
    ///
    void fadeOutMarkers();
    void fadeInLandMarks(Country country);
    void hideLandMarks();
    void hideCheckMarks();
    ///
    /// \brief fadeEffect Gives the effect of fading in and out on widgets like labels and buttons
    /// on our window
    /// \param startValue the starting opacity value of the widget to start the fade effect
    /// \param endValue the ending opacity value of the widget to start the fade effect
    /// \param duration the amount of the time the fade effect will occur for
    /// \param widget on which widget the fade effect is applied for
    ///
    void fadeEffect(double startValue, double endValue, int duration, QString widget);

    ///
    /// \brief setWidgetGraphicsEffect specifies on which widget we want the fade effect to occur on
    /// \param name the name of the widget
    /// \param eff the opacity effect to be applied on a widget
    ///
    void setWidgetGraphicsEffect(QString name, QGraphicsOpacityEffect *eff);

    void fadeInBackgroundLabel();
    void setBgLabel(QPixmap background);
    void setBgLabelOpacity();

    void disableButtons();
    void enableButtonsAndCheck();
    void showInfo(QString);
    int count;
    QString country = "";

    void fadeInCountryLabels();
    void fadeOutCountryLabels();
    void fadeInCheckmarks(Country country);

signals:
    void hideWidgets();
    void changedState(QString state);

    void informModelToSend(QString name);

    void generateRandomQuestion();
    void resetButtons();
    void sendQuizInfo(QString country);
};
#endif // VIEW_H
