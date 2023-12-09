/**
 * Author:     Crazy Broke Asians
 * Date:       Dec-08-2023
 * Course:     CS 3505, University of Utah
 * Assignment: A9: An Educational App
 * File Contents
 *      It contains all necessary information needed to form a description popup.
*/

#ifndef FORM_H
#define FORM_H

#include <QLabel>
#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QStyle>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    ///
    /// \brief closeWindow closes the current popup window
    ///
    void closeWindow();

public slots:
    ///
    /// \brief receiveSignalToSetTextIndia updates the popup window according to the button clicked
    /// on the main window and sets the background, description and music as per the button clicked.
    /// \param name the landmark name
    ///
    void receiveSignalToSetTextIndia(QString name);

private slots:
    ///
    /// \brief on_nextButton_clicked goes to the next page of description
    ///
    void on_nextButton_clicked();
    ///
    /// \brief on_backButton_clicked goes to the previous page of description
    ///
    void on_backButton_clicked();
    ///
    /// \brief closeEvent
    /// \param bar
    ///
    void closeEvent(QCloseEvent *bar);
    ///
    /// \brief on_playMusic_clicked
    ///
    void on_playMusic_clicked();
    ///
    /// \brief on_stopMusic_clicked
    ///
    void on_stopMusic_clicked();

signals:
    void windowClosed();
    void stopTimer();

private:
    Ui::Form *ui;

    QTimer *timer;
    QLabel *backgroundLabel;

    QString indiaLandMarkInfo[4];
    QString indiaRestaurantInfo[4];
    QString koreaLandMarkInfo[4];
    QString koreaRestaurantInfo[4];
    QString thailandLandMarkInfo[4];
    QString thailandRestaurantInfo[4];
    QString currentText;
    QString currentCountry;
    QStringList splittedText;

    QMediaPlayer *musicPlayer;
    QAudioOutput *musicOutput;

    bool firstNextClicked = false;
    bool firstBackClicked = false;
    bool landMarkFlag = true;

    int current = 0;
    int now = 0;
    ///
    /// \brief startTyping starts showing the letters of the descriptions letter by letter with a help of
    /// a QTimer and shows the next and back button accordingly. Once all text is typed out it does not
    /// type the same thing again unless the window is opened again.
    ///
    void startTyping(); 
    ///
    /// \brief nextButtonHelper when next button is clicked on the popup, updates the description to further
    /// information in addition to have the typing feature to it. Checks if the button is clicked for the
    /// first button or not and updates information accordingly. This is done to check whether the
    /// typing feature should be applied again to information that has already been shown.
    /// \param info
    ///
    void nextButtonHelper(QString info[]);
    ///
    /// \brief backButtonHelper when back button is clicked on the popup, updates the descrption to previous
    /// information.
    /// \param info
    ///
    void backButtonHelper(QString info[]);
    ///
    /// \brief buttonHelper if the isNextButton is true, means the user clicked next for more information
    /// so updates the window with remaining information of the current architecture/restaurent. Else
    /// if it is false, measns the user clicked back for previous information so updates the window with
    /// the previous information of the current architecture/restaurent.
    /// \param isNextButton checks if the next button was clicked or not.
    ///
    void buttonHelper(bool isNextButton);

    void setMusic(QString countryName);
    void updateVolume(int volume);

    // All the helper methods below do the exact same thing mentioned in the below header comment
    ///
    /// \brief setLandmarkIndiaHelper updates the popup window's background image and text according to the
    /// button that was clicked by the user. Also sets the firstNextClicked to true since this is the very
    /// first part of the information being displayed to the user.
    /// \param currentNum the current information to display from the architecture/restaurent arrays.
    /// \param image the image to display in the background of the popup
    ///
    void setLandmarkIndiaHelper(int currentNum, QString image);
    void setRestaurantIndiaHelper(int currentNum, QString image);
    void setLandmarkThailandHelper(int currentNum, QString image);
    void setRestaurantThailandHelper(int currentNum, QString image);
    void setRestaurantKoreaHelper(int currentNum, QString image);
    void setLandmarkKoreaHelper(int currentNum, QString image);
};

#endif // FORM_H
