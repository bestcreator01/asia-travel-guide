/**
 * Author:     Crazy Broke Asians
 * Date:       Dec-08-2023
 * Course:     CS 3505, University of Utah
 * Assignment: A9: An Educational App
 * File Contents
 *      It contains all necessary codes needed to form a zoomed-in/out popup.
*/

#include "view.h"
#include "ui_view.h"
#include "model.h"

view::view(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::view)
{
    ui->setupUi(this);

    this->setWindowTitle("Asia Travel Guide");

    showShadowEffect();
    showShadowPlayButton();

    ui->playButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");

    QIcon backArrowIcon(":/icons/left-arrow.png");
    QIcon markerIcon(":/icons/marker.png");

    // india place icons
    QIcon taj(":/icons/taj.png");
    QIcon hawa(":/icons/hawa-mahal.png");
    QIcon biryani(":/icons/biryani.png");
    QIcon panipuri(":/icons/panipuri.png");
    QIcon quizIcon(":/icons/quiz.png");

    // korea place icons
    QIcon gbgIcon(":/icons/gyeongbokgung.png");
    QIcon bgsIcon(":/icons/bulguksa.png");
    QIcon tbkIcon(":/icons/tteokbokki.png");
    QIcon bssIcon(":/icons/bossam.png");

    // thailand place icons
    QIcon gplIcon(":/icons/grand_palace.png");
    QIcon wmgIcon(":/icons/great_buddha.png");
    QIcon tymIcon(":/icons/tomyum.png");
    QIcon strIcon(":/icons/sticky_rice.png");

    QPixmap checkPixmap(":/icons/check.png");
    QPixmap scaledPixmap = checkPixmap.scaled(ui->biryaniCheckLabel->size(), Qt::KeepAspectRatio);

    // back button
    ui->backButton->setIcon(backArrowIcon);
    ui->backButton->hide();

    // country buttons/labels
    ui->indiaButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->indiaButton->setIconSize(QSize(50, 50));
    ui->indiaButton->setIcon(markerIcon);
    ui->indiaButton->hide();
    ui->indiaLabel->hide();

    ui->koreaButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->koreaButton->setIconSize(QSize(50, 50));
    ui->koreaButton->setIcon(markerIcon);
    ui->koreaButton->hide();
    ui->koreaLabel->hide();

    ui->thailandButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->thailandButton->setIconSize(QSize(50, 50));
    ui->thailandButton->setIcon(markerIcon);
    ui->thailandButton->hide();
    ui->thailandLabel->hide();

    // india place buttons
    ui->tajMahal->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->hawaMahal->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->paniPuri->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->biryani->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->tajMahal->setIconSize(QSize(50, 50));
    ui->hawaMahal->setIconSize(QSize(50, 50));
    ui->paniPuri->setIconSize(QSize(50, 50));
    ui->biryani->setIconSize(QSize(50, 50));
    ui->tajMahal->setIcon(taj);
    ui->hawaMahal->setIcon(hawa);
    ui->paniPuri->setIcon(panipuri);
    ui->biryani->setIcon(biryani);
    ui->tajMahal->setText("");
    ui->hawaMahal->setText("");
    ui->paniPuri->setText("");
    ui->biryani->setText("");
    ui->tajMahal->hide();
    ui->hawaMahal->hide();
    ui->paniPuri->hide();
    ui->biryani->hide();

    // korea place buttons
    ui->gyeongbokgungButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->gyeongbokgungButton->setIconSize(QSize(60, 60));
    ui->gyeongbokgungButton->setIcon(gbgIcon);
    ui->gyeongbokgungButton->setText("");
    ui->gyeongbokgungButton->hide();
    ui->bulguksaButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->bulguksaButton->setIconSize(QSize(60, 60));
    ui->bulguksaButton->setIcon(bgsIcon);
    ui->bulguksaButton->setText("");
    ui->bulguksaButton->hide();
    ui->tteokbokkiButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->tteokbokkiButton->setIconSize(QSize(60, 60));
    ui->tteokbokkiButton->setIcon(tbkIcon);
    ui->tteokbokkiButton->setText("");
    ui->tteokbokkiButton->hide();
    ui->bossamButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->bossamButton->setIconSize(QSize(60, 60));
    ui->bossamButton->setIcon(bssIcon);
    ui->bossamButton->setText("");
    ui->bossamButton->hide();

    // thailand place buttons
    ui->grandPalaceButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->grandPalaceButton->setIconSize(QSize(60, 60));
    ui->grandPalaceButton->setIcon(gplIcon);
    ui->grandPalaceButton->setText("");
    ui->grandPalaceButton->hide();
    ui->watMuangButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->watMuangButton->setIconSize(QSize(60, 60));
    ui->watMuangButton->setIcon(wmgIcon);
    ui->watMuangButton->setText("");
    ui->watMuangButton->hide();
    ui->tomYumButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->tomYumButton->setIconSize(QSize(60, 60));
    ui->tomYumButton->setIcon(tymIcon);
    ui->tomYumButton->setText("");
    ui->tomYumButton->hide();
    ui->stickyRiceButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->stickyRiceButton->setIconSize(QSize(60, 60));
    ui->stickyRiceButton->setIcon(strIcon);
    ui->stickyRiceButton->setText("");
    ui->stickyRiceButton->hide();

    // quiz button
    ui->quizButton->setText("");
    ui->quizButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->quizButton->setIconSize(QSize(70,70));
    ui->quizButton->setIcon(quizIcon);
    ui->quizButton->hide();

    // india checkmarks
    ui->biryaniCheckLabel->setPixmap(scaledPixmap);
    ui->hawaMahalCheckLabel->setPixmap(scaledPixmap);
    ui->tajMahalCheckLabel->setPixmap(scaledPixmap);
    ui->paniPuriCheckLabel->setPixmap(scaledPixmap);
    ui->biryaniCheckLabel->hide();
    ui->hawaMahalCheckLabel->hide();
    ui->tajMahalCheckLabel->hide();
    ui->paniPuriCheckLabel->hide();

    // korea checkmarks
    ui->gyeongbokgungCheckLabel->setPixmap(scaledPixmap);
    ui->bulguksaCheckLabel->setPixmap(scaledPixmap);
    ui->tteokbokkiCheckLabel->setPixmap(scaledPixmap);
    ui->bossamCheckLabel->setPixmap(scaledPixmap);
    ui->gyeongbokgungCheckLabel->hide();
    ui->bulguksaCheckLabel->hide();
    ui->tteokbokkiCheckLabel->hide();
    ui->bossamCheckLabel->hide();

    // thailand checkmarks
    ui->grandPalaceCheckLabel->setPixmap(scaledPixmap);
    ui->watMuangCheckLabel->setPixmap(scaledPixmap);
    ui->tomYumCheckLabel->setPixmap(scaledPixmap);
    ui->stickyRiceCheckLabel->setPixmap(scaledPixmap);

    ui->grandPalaceCheckLabel->hide();
    ui->watMuangCheckLabel->hide();
    ui->tomYumCheckLabel->hide();
    ui->stickyRiceCheckLabel->hide();

    // Background label
    backgroundLabel = new QLabel(this);
    QPixmap background(":/icons/asia-map.png");
    setBgLabel(background);

    // Set initial background opacity
    setBgLabelOpacity();

    connect(this, &view::changedState, &model, &Model::changeState);
    connect(&model, &Model::changedScreenState, this, &view::updateState);
    connect(&model, &Model::sendQuiz, &quizWindow, &Quiz::setValues);

    // send random to model, model randomize selection, send back to quiz window
    connect(&quizWindow, &Quiz::randomizeOption, &model, &Model::randomizeOption);
    connect(&model, &Model::sendOptions, &quizWindow, &Quiz::setRandomOptions);

    // send country status to set up the background image in quiz window
    connect(&model, &Model::sendCountryForBgImage, &quizWindow, &Quiz::setBgImage);

    connect(this, &view::informModelToSend, &popUpWindow, &PopUpWindow::receiveSignalToSetTextCountry);

    connect(&popUpWindow, &PopUpWindow::windowClosed, this, &view::enableButtonsAndCheck);

    connect(this, &view::generateRandomQuestion, &quizWindow, &Quiz::showRandomQuestion);
    connect(this, &view::resetButtons, &quizWindow, &Quiz::resetButtons);
    connect(this, &view::sendQuizInfo, &model, &Model::showQuizInfo);
}

view::~view()
{
    delete ui;
}

void view::closeEvent(QCloseEvent *)
{
    popUpWindow.closeWindow();
    quizWindow.closeWindow();
}

void view::applyShadowEffect(QWidget *widget) {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(4);
    shadow->setColor(QColor(0, 0, 0, 150));
    shadow->setOffset(2, 2);

    widget->setGraphicsEffect(shadow);
}

void view::showShadowEffect()
{
    applyShadowEffect(ui->welcomeAsia);
    applyShadowEffect(ui->welcomeTravel);
    applyShadowEffect(ui->welcomeAdventure);
    applyShadowEffect(ui->welcomeEmoji);
    applyShadowEffect(ui->welcomeLabel);

    applyShadowEffect(ui->indiaLabel);
    applyShadowEffect(ui->koreaLabel);
    applyShadowEffect(ui->thailandLabel);
}

void view::showShadowPlayButton()
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(30);
    shadow->setColor(QColor(255, 255, 0, 150));
    shadow->setOffset(3, 3);
    ui->playButton->setGraphicsEffect(shadow);
}

void view::setBgLabelOpacity()
{
    QGraphicsOpacityEffect *backgroundOpacityEffect = new QGraphicsOpacityEffect(backgroundLabel);
    backgroundOpacityEffect->setOpacity(0.5);
    backgroundLabel->setGraphicsEffect(backgroundOpacityEffect);
}

void view::updateState(QString state)
{
    previousState = state;
}

void view::on_playButton_clicked()
{
    emit changedState("AsiaMap");
    fadeOutPlayButton();
    fadeOutWelcomeLabel();
    fadeInBackArrow();
    fadeInMarkers();
    fadeInCountryLabels();

    // background opacity 50% -> 100%
    QGraphicsOpacityEffect *effect = dynamic_cast<QGraphicsOpacityEffect*>(backgroundLabel->graphicsEffect());
    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(effect, "opacity");
    opacityAnimation->setDuration(1000);
    opacityAnimation->setStartValue(effect->opacity());
    opacityAnimation->setEndValue(1.0);
    opacityAnimation->start(QPropertyAnimation::DeleteWhenStopped);
}

void view::on_backButton_clicked()
{
    // currentState == "AsiaMap"
    if(previousState == "Welcome")
    {
        emit changedState("Welcome");
        fadeInWelcomeLabel();
        fadeInPlayButton();
        fadeOutBackArrow();
        fadeOutMarkers();
        setBgLabelOpacity();
        fadeOutCountryLabels();
    }
    // currentState == "CountryMap"
    else if(previousState == "AsiaMap")
    {
        emit changedState("AsiaMap");
        QPixmap background(":/icons/asia-map.png");
        setBgLabel(background);

        fadeInBackgroundLabel();
        fadeInMarkers();
        fadeInCountryLabels();

        hideLandMarks();
        hideCheckMarks();
        ui->quizButton->hide();
    }
}

void view::hideCheckMarks(){

    // india
    ui->biryaniCheckLabel->hide();
    ui->tajMahalCheckLabel->hide();
    ui->hawaMahalCheckLabel->hide();
    ui->paniPuriCheckLabel->hide();

    // korea
    ui->gyeongbokgungCheckLabel->hide();
    ui->bulguksaCheckLabel->hide();
    ui->tteokbokkiCheckLabel->hide();
    ui->bossamCheckLabel->hide();

    // thailand
    ui->grandPalaceCheckLabel->hide();
    ui->watMuangCheckLabel->hide();
    ui->tomYumCheckLabel->hide();
    ui->stickyRiceCheckLabel->hide();
}

void view::fadeInBackgroundLabel()
{
    backgroundLabel->show();
    fadeEffect(0.0, 1.0, 1000, "backgroundLabel");
}

void view::fadeInWelcomeLabel()
{
    ui->welcomeLabel->show();
    ui->welcomeAsia->show();
    ui->welcomeTravel->show();
    ui->welcomeAdventure->show();
    ui->welcomeEmoji->show();

    fadeEffect(0.0, 1.0, 1000, "welcomeLabel");
    fadeEffect(0.0, 1.0, 1000, "welcomeAsia");
    fadeEffect(0.0, 1.0, 1000, "welcomeTravel");
    fadeEffect(0.0, 1.0, 1000, "welcomeAdventure");
    fadeEffect(0.0, 1.0, 1000, "welcomeEmoji");

    showShadowEffect();
}

void view::fadeOutWelcomeLabel()
{
    fadeEffect(1.0, 0.0, 1000, "welcomeLabel");
    fadeEffect(1.0, 0.0, 1000, "welcomeAsia");
    fadeEffect(1.0, 0.0, 1000, "welcomeTravel");
    fadeEffect(1.0, 0.0, 1000, "welcomeAdventure");
    fadeEffect(1.0, 0.0, 1000, "welcomeEmoji");

    QTimer::singleShot(1000, this, [this] {ui->welcomeLabel->hide();
                                           ui->welcomeAsia->hide();
                                           ui->welcomeTravel->hide();
                                           ui->welcomeAdventure->hide();
                                           ui->welcomeEmoji->hide();});
}

void view::fadeInPlayButton()
{
    ui->playButton->show();
    fadeEffect(0.0, 1.0, 1000, "playButton");

    showShadowPlayButton();
}

void view::fadeOutPlayButton()
{
    fadeEffect(1.0, 0.0, 1000, "playButton");
    QTimer::singleShot(1000, this, [this] {ui->playButton->hide();});
}

void view::fadeInBackArrow()
{
    ui->backButton->show();
    fadeEffect(0.0, 1.0, 1000, "backButton");
}

void view::fadeOutBackArrow()
{
    fadeEffect(1.0, 0.0, 1000, "backButton");
    QTimer::singleShot(1000, this, [this] {ui->backButton->hide();});
}

void view::fadeInMarkers()
{
    ui->indiaButton->show();
    ui->koreaButton->show();
    ui->thailandButton->show();
    fadeEffect(0.0, 1.0, 1000, "indiaButton");
    fadeEffect(0.0, 1.0, 1000, "koreaButton");
    fadeEffect(0.0, 1.0, 1000, "thailandButton");
}

void view::fadeOutMarkers()
{
    fadeEffect(1.0, 0.0, 1000, "indiaButton");
    fadeEffect(1.0, 0.0, 1000, "koreaButton");
    fadeEffect(1.0, 0.0, 1000, "thailandButton");

    QTimer::singleShot(1000, this, [this] {ui->indiaButton->hide();});
    QTimer::singleShot(1000, this, [this] {ui->koreaButton->hide();});
    QTimer::singleShot(1000, this, [this] {ui->thailandButton->hide();});
}

void view::fadeInLandMarks(Country country)
{
    if (country == India)
    {
        ui->tajMahal->show();
        ui->hawaMahal->show();
        ui->paniPuri->show();
        ui->biryani->show();
        fadeEffect(0.0, 1.0, 1500, "tajMahalButton");
        fadeEffect(0.0, 1.0, 1500, "hawaMahalButton");
        fadeEffect(0.0, 1.0, 1500, "paniPuriButton");
        fadeEffect(0.0, 1.0, 1500, "biryaniButton");
    }
    else if (country == Korea)
    {
        ui->gyeongbokgungButton->show();
        ui->bulguksaButton->show();
        ui->tteokbokkiButton->show();
        ui->bossamButton->show();
        fadeEffect(0.0, 1.0, 1500, "gyeongbokgungButton");
        fadeEffect(0.0, 1.0, 1500, "bulguksaButton");
        fadeEffect(0.0, 1.0, 1500, "tteokbokkiButton");
        fadeEffect(0.0, 1.0, 1500, "bossamButton");
    }
    else if (country == Thailand)
    {
        ui->grandPalaceButton->show();
        ui->watMuangButton->show();
        ui->tomYumButton->show();
        ui->stickyRiceButton->show();

        fadeEffect(0.0, 1.0, 1500, "grandPalaceButton");
        fadeEffect(0.0, 1.0, 1500, "watMuangButton");
        fadeEffect(0.0, 1.0, 1500, "tomYumButton");
        fadeEffect(0.0, 1.0, 1500, "stickyRiceButton");
    }
}

void view::hideLandMarks()
{
    // india
    ui->tajMahal->hide();
    ui->hawaMahal->hide();
    ui->paniPuri->hide();
    ui->biryani->hide();

    // korea
    ui->gyeongbokgungButton->hide();
    ui->bulguksaButton->hide();
    ui->tteokbokkiButton->hide();
    ui->bossamButton->hide();

    // thailand
    ui->grandPalaceButton->hide();
    ui->watMuangButton->hide();
    ui->tomYumButton->hide();
    ui->stickyRiceButton->hide();
}

void view::fadeEffect(double startValue, double endValue, int duration, QString widget)
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    setWidgetGraphicsEffect(widget, eff);
    QPropertyAnimation *animation = new QPropertyAnimation(eff,"opacity");
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);

    animation->setDuration(duration);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void view::setWidgetGraphicsEffect(QString name, QGraphicsOpacityEffect *eff)
{
    // system
    if(name == "backButton")
    {
        ui->backButton->setGraphicsEffect(eff);
    }
    else if(name == "playButton")
    {
        ui->playButton->setGraphicsEffect(eff);
    }
    else if(name == "welcomeLabel")
    {
        ui->welcomeLabel->setGraphicsEffect(eff);
    }
    else if(name == "welcomeAsia")
    {
        ui->welcomeAsia->setGraphicsEffect(eff);
    }
    else if(name == "welcomeTravel")
    {
        ui->welcomeTravel->setGraphicsEffect(eff);
    }
    else if(name == "welcomeAdventure")
    {
        ui->welcomeAdventure->setGraphicsEffect(eff);
    }
    else if(name == "welcomeEmoji")
    {
        ui->welcomeEmoji->setGraphicsEffect(eff);
    }
    else if(name == "backgroundLabel")
    {
        backgroundLabel->setGraphicsEffect(eff);
    }

    // country buttons
    else if(name == "indiaButton")
    {
        ui->indiaButton->setGraphicsEffect(eff);
    }
    else if(name == "koreaButton")
    {
        ui->koreaButton->setGraphicsEffect(eff);
    }
    else if(name == "thailandButton")
    {
        ui->thailandButton->setGraphicsEffect(eff);
    }

    // country labels
    else if(name == "indiaLabel")
    {
        ui->indiaLabel->setGraphicsEffect(eff);
    }
    else if(name == "koreaLabel")
    {
        ui->koreaLabel->setGraphicsEffect(eff);
    }
    else if(name == "thailandLabel")
    {
        ui->thailandLabel->setGraphicsEffect(eff);
    }

    // india place buttons
    else if(name == "tajMahalButton")
    {
        ui->tajMahal->setGraphicsEffect(eff);
    }
    else if(name == "hawaMahalButton")
    {
        ui->hawaMahal->setGraphicsEffect(eff);
    }
    else if(name == "paniPuriButton")
    {
        ui->paniPuri->setGraphicsEffect(eff);
    }
    else if(name == "biryaniButton")
    {
        ui->biryani->setGraphicsEffect(eff);
    }

    // korea place buttons
    else if(name == "gyeongbokgungButton")
    {
        ui->gyeongbokgungButton->setGraphicsEffect(eff);
    }
    else if(name == "bulguksaButton")
    {
        ui->bulguksaButton->setGraphicsEffect(eff);
    }
    else if(name == "tteokbokkiButton")
    {
        ui->tteokbokkiButton->setGraphicsEffect(eff);
    }
    else if(name == "bossamButton")
    {
        ui->bossamButton->setGraphicsEffect(eff);
    }

    // thailand place buttons
    else if(name == "grandPalaceButton")
    {
        ui->grandPalaceButton->setGraphicsEffect(eff);
    }
    else if(name == "watMuangButton")
    {
        ui->watMuangButton->setGraphicsEffect(eff);
    }
    else if(name == "tomYumButton")
    {
        ui->tomYumButton->setGraphicsEffect(eff);
    }
    else if(name == "stickyRiceButton")
    {
        ui->stickyRiceButton->setGraphicsEffect(eff);
    }

    // india checkmark labels
    else if(name == "tajMahalCheckLabel")
    {
        ui->tajMahalCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "hawaMahalCheckLabel")
    {
        ui->hawaMahalCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "paniPuriCheckLabel")
    {
        ui->paniPuriCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "biryaniCheckLabel")
    {
        ui->biryaniCheckLabel->setGraphicsEffect(eff);
    }

    // korea checkmark labels
    else if(name == "gyeongbokgungCheckLabel")
    {
        ui->gyeongbokgungCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "bulguksaCheckLabel")
    {
        ui->bulguksaCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "tteokbokkiCheckLabel")
    {
        ui->tteokbokkiCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "bossamCheckLabel")
    {
        ui->bossamCheckLabel->setGraphicsEffect(eff);
    }

    // thailand checkmark labels
    else if(name == "grandPalaceCheckLabel")
    {
        ui->grandPalaceCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "watMuangCheckLabel")
    {
        ui->watMuangCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "tomYumCheckLabel")
    {
        ui->tomYumCheckLabel->setGraphicsEffect(eff);
    }
    else if(name == "stickyRiceCheckLabel")
    {
        ui->stickyRiceCheckLabel->setGraphicsEffect(eff);
    }

    // quiz button
    else if(name == "quizButton")
    {
        ui->quizButton->setGraphicsEffect(eff);
    }
}

void view::setBgLabel(QPixmap background)
{
    backgroundLabel->setPixmap(background.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    backgroundLabel->setGeometry(0, 0, this->width(), this->height());  // Set to cover the entire window
    backgroundLabel->lower();
}

void view::on_indiaButton_clicked()
{
    emit changedState("CountryMap");

    QPixmap background(":/icons/india-map.png");
    setBgLabel(background);
    fadeInBackgroundLabel();
    fadeInLandMarks(India);
    fadeInCheckmarks(India);

    country = "India";

    ui->indiaButton->hide();
    ui->koreaButton->hide();
    ui->thailandButton->hide();
    ui->koreaLabel->hide();
    ui->indiaLabel->hide();
    ui->thailandLabel->hide();
}

void view::on_koreaButton_clicked()
{
    emit changedState("CountryMap");

    QPixmap background(":/icons/korea_map.png");
    setBgLabel(background);
    fadeInBackgroundLabel();
    fadeInLandMarks(Korea);
    fadeInCheckmarks(Korea);

    country = "Korea";

    ui->indiaButton->hide();
    ui->koreaButton->hide();
    ui->thailandButton->hide();
    ui->koreaLabel->hide();
    ui->indiaLabel->hide();
    ui->thailandLabel->hide();
}


void view::on_thailandButton_clicked()
{
    emit changedState("CountryMap");

    QPixmap background(":/icons/thailand_map.png");
    setBgLabel(background);
    fadeInBackgroundLabel();
    fadeInLandMarks(Thailand);
    fadeInCheckmarks(Thailand);

    country = "Thailand";

    ui->indiaButton->hide();
    ui->koreaButton->hide();
    ui->thailandButton->hide();
    ui->koreaLabel->hide();
    ui->indiaLabel->hide();
    ui->thailandLabel->hide();
}

void view::fadeInCountryLabels()
{
    ui->indiaLabel->show();
    ui->koreaLabel->show();
    ui->thailandLabel->show();

    fadeEffect(0.0, 1.0, 1500, "indiaLabel");
    fadeEffect(0.0, 1.0, 1500, "koreaLabel");
    fadeEffect(0.0, 1.0, 1500, "thailandLabel");
}

void view::fadeOutCountryLabels()
{
    fadeEffect(1.0, 0.0, 1500, "indiaLabel");
    fadeEffect(1.0, 0.0, 1500, "koreaLabel");
    fadeEffect(1.0, 0.0, 1500, "thailandLabel");
}

void view::fadeInCheckmarks(Country country)
{

    if (country == India)
    {
        if (indiaCompleteList.contains(TajMahal))
        {
            ui->tajMahalCheckLabel->show();
            fadeEffect(0.0, 1.0, 1500, "tajMahalCheckLabel");
        }
        if (indiaCompleteList.contains(HawaMaha))
        {
            ui->hawaMahalCheckLabel->show();
            fadeEffect(0.0, 1.0, 1500, "hawaMahalCheckLabel");
        }
        if (indiaCompleteList.contains(PaniPuri))
        {
            ui->paniPuriCheckLabel->show();
            fadeEffect(0.0, 1.0, 1500, "paniPuriCheckLabel");
        }
        if (indiaCompleteList.contains(Biryani))
        {
            ui->biryaniCheckLabel->show();
            fadeEffect(0.0, 1.0, 1500, "biryaniCheckLabel");
        }
        if (indiaCompleteList.size() == 4)
        {
            ui->quizButton->show();
            fadeEffect(0.0, 1.0, 1500, "quizButton");
        }
    }
    else if (country == Korea)
    {
        if (koreaCompleteList.contains(Gyeongbokgung))
        {
            ui->gyeongbokgungCheckLabel->show();
        }
        if (koreaCompleteList.contains(Bulguksa))
        {
            ui->bulguksaCheckLabel->show();
        }
        if (koreaCompleteList.contains(Tteokbokki))
        {
            ui->tteokbokkiCheckLabel->show();
        }
        if (koreaCompleteList.contains(Bossam))
        {
            ui->bossamCheckLabel->show();
        }
        if (koreaCompleteList.size() == 4)
        {
            ui->quizButton->show();
            fadeEffect(0.0, 1.0, 1500, "quizButton");
        }
    }
    else if (country == Thailand)
    {
        if (ThailandCompleteList.contains(GrandPalace))
        {
            ui->grandPalaceCheckLabel->show();
        }
        if (ThailandCompleteList.contains(WatMuang))
        {
            ui->watMuangCheckLabel->show();
        }
        if (ThailandCompleteList.contains(TomYum))
        {
            ui->tomYumCheckLabel->show();
        }
        if (ThailandCompleteList.contains(StickyRice))
        {
            ui->stickyRiceCheckLabel->show();
        }
        if (ThailandCompleteList.size() == 4)
        {
            ui->quizButton->show();
            fadeEffect(0.0, 1.0, 1500, "quizButton");
        }
    }
}

void view::disableButtons()
{
    ui->backButton->setDisabled(true);
    //india
    ui->tajMahal->setDisabled(true);
    ui->hawaMahal->setDisabled(true);
    ui->paniPuri->setDisabled(true);
    ui->biryani->setDisabled(true);
    //thailand
    ui->grandPalaceButton->setDisabled(true);
    ui->watMuangButton->setDisabled(true);
    ui->stickyRiceButton->setDisabled(true);
    ui->tomYumButton->setDisabled(true);
    //korea
    ui->bossamButton->setDisabled(true);
    ui->bulguksaButton->setDisabled(true);
    ui->gyeongbokgungButton->setDisabled(true);
    ui->tteokbokkiButton->setDisabled(true);
}

void view::showInfo(QString info)
{
    popUpWindow.show();
    emit informModelToSend(info);
    disableButtons();
}

void view::on_hawaMahal_clicked()
{
    showInfo("HawaMahal");

    ui->hawaMahalCheckLabel->show();
    indiaCompleteList.insert(HawaMaha);
    if (indiaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_tajMahal_clicked()
{
    showInfo("TajMahal");

    ui->tajMahalCheckLabel->show();
    indiaCompleteList.insert(TajMahal);
    if (indiaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_paniPuri_clicked()
{
    showInfo("PaniPuri");

    ui->paniPuriCheckLabel->show();
    indiaCompleteList.insert(PaniPuri);
    if (indiaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_biryani_clicked()
{
    showInfo("Biryani");

    ui->biryaniCheckLabel->show();
    indiaCompleteList.insert(Biryani);
    if (indiaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}

void view::on_quizButton_clicked()
{
    quizWindow.show();
    emit sendQuizInfo(country);
    emit generateRandomQuestion();
    emit resetButtons();
}

void view::enableButtonsAndCheck()
{
    ui->backButton->setEnabled(true);
    //india
    ui->hawaMahal->setEnabled(true);
    ui->tajMahal->setEnabled(true);
    ui->paniPuri->setEnabled(true);
    ui->biryani->setEnabled(true);
    //thailand
    ui->grandPalaceButton->setEnabled(true);
    ui->watMuangButton->setEnabled(true);
    ui->stickyRiceButton->setEnabled(true);
    ui->tomYumButton->setEnabled(true);
    //korea
    ui->bossamButton->setEnabled(true);
    ui->bulguksaButton->setEnabled(true);
    ui->gyeongbokgungButton->setEnabled(true);
    ui->tteokbokkiButton->setEnabled(true);
}


void view::on_bulguksaButton_clicked()
{
    showInfo("Bulguksa");

    ui->bulguksaCheckLabel->show();
    koreaCompleteList.insert(Bulguksa);
    if (koreaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_gyeongbokgungButton_clicked()
{
    showInfo("Gyeongbokgung");

    ui->gyeongbokgungCheckLabel->show();
    koreaCompleteList.insert(Gyeongbokgung);
    if (koreaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_tteokbokkiButton_clicked()
{
    showInfo("Tteokbokki");

    ui->tteokbokkiCheckLabel->show();
    koreaCompleteList.insert(Tteokbokki);
    if (koreaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_bossamButton_clicked()
{
    showInfo("Bossam");

    ui->bossamCheckLabel->show();
    koreaCompleteList.insert(Bossam);
    if (koreaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_grandPalaceButton_clicked()
{
    showInfo("GrandPalace");

    ui->grandPalaceCheckLabel->show();
    ThailandCompleteList.insert(GrandPalace);
    if (ThailandCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_watMuangButton_clicked()
{
    showInfo("BigBuddha");

    ui->watMuangCheckLabel->show();
    ThailandCompleteList.insert(WatMuang);
    if (ThailandCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_tomYumButton_clicked()
{
    showInfo("TomYumKung");

    ui->tomYumCheckLabel->show();
    ThailandCompleteList.insert(TomYum);
    if (ThailandCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_stickyRiceButton_clicked()
{
    showInfo("MangoStickyRice");

    ui->stickyRiceCheckLabel->show();
    ThailandCompleteList.insert(StickyRice);
    if (ThailandCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}
