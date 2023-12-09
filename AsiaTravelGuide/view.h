/**
 * Author:     Crazy Broke Asians
 * Date:       Dec-08-2023
 * Course:     CS 3505, University of Utah
 * Assignment: A9: An Educational App
 * File Contents
 *      It contains all necessary information needed to form a zoomed-in/out popup.
*/

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

    ///
    /// \brief The Country enum represents three countries
    ///
    enum Country {India, Korea, Thailand};

    ///
    /// \brief The IndiaPlace enum represents four places in India
    ///
    enum IndiaPlace{HawaMaha, TajMahal, PaniPuri, Biryani};

    ///
    /// \brief indiaCompleteList contains visited places in India
    ///
    QSet<IndiaPlace> indiaCompleteList;

    ///
    /// \brief The KoreaPlace enum represents four places in Korea
    ///
    enum KoreaPlace{Gyeongbokgung, Bulguksa, Tteokbokki, Bossam};

    ///
    /// \brief koreaCompleteList contains visited places in Korea
    ///
    QSet<KoreaPlace> koreaCompleteList;

    ///
    /// \brief The ThailandPlace enum represents four places in Thailand
    ///
    enum ThailandPlace{GrandPalace, WatMuang, TomYum, StickyRice};

    ///
    /// \brief ThailandCompleteList contains visited places in Thailand
    ///
    QSet<ThailandPlace> ThailandCompleteList;

    ///
    /// \brief backgroundLabel a pointer to background label of window
    ///
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

    ///
    /// \brief fadeInLandMarks fades in buttons for landmarks based on a specified country
    /// \param country the country whose landmarks will be faded in
    ///
    void fadeInLandMarks(Country country);

    ///
    /// \brief hideLandMarks hide the landmarks/foods of all countries
    ///
    void hideLandMarks();

    ///
    /// \brief hideCheckMarks hide checkmarks of landmarks/foods
    ///
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

    ///
    /// \brief fadeInBackgroundLabel applies fade-in affect to the background label
    ///
    void fadeInBackgroundLabel();

    ///
    /// \brief setBgLabel sets the background label to the given QPixmap
    /// \param background new background image
    ///
    void setBgLabel(QPixmap background);

    ///
    /// \brief setBgLabelOpacity sets the background label opacity to 0.5
    ///
    void setBgLabelOpacity();

    ///
    /// \brief disableButtons disables landmark/food buttons. called when a popup window is displaying
    ///
    void disableButtons();

    ///
    /// \brief enableButtonsAndCheck enable landmark/food buttons and checkmark labels
    ///
    void enableButtonsAndCheck();

    void showInfo(QString);
    int count;
    QString country = "";

    ///
    /// \brief fadeInCountryLabels fades in country name labels
    ///
    void fadeInCountryLabels();

    ///
    /// \brief fadeOutCountryLabels fades out country name labels
    ///
    void fadeOutCountryLabels();

    ///
    /// \brief fadeInCheckmarks fades in checkmarks for landmarks/food related to a specified country
    /// \param country the country for which to show checkmarks
    ///
    void fadeInCheckmarks(Country country);

signals:

    void changedState(QString state);

    void informModelToSend(QString name);

    void generateRandomQuestion();
    void resetButtons();
    void sendQuizInfo(QString country);
};
#endif // VIEW_H
