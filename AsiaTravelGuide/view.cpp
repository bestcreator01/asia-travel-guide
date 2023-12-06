#include "view.h"
#include "ui_view.h"
#include "model.h"
#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPalette>

view::view(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::view)
{
    ui->setupUi(this);

    this->setWindowTitle("Asia Travel Guide");

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



    // quiz button
    ui->quizButton->setText("");
    ui->quizButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->quizButton->setIconSize(QSize(70,70));
    ui->quizButton->setIcon(quizIcon);
    ui->quizButton->hide();
    // TODO

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
    ui->grandPalaceCheckLabel->hide();

    // Background label
    backgroundLabel = new QLabel(this);
    QPixmap background(":/icons/asia-map.png");
    setBgLabel(background);

    // Set initial background opacity
    setBgLabelOpacity();

    connect(this, &view::changedState, &model, &Model::changeState);
    connect(&model, &Model::changedScreenState, this, &view::updateState);

    connect(this, &view::informModelToSend, &indiaWindow, &Form::receiveSignalToSetTextIndia);

    connect(&indiaWindow, &Form::windowClosed, this, &view::enableButtonsAndCheck);

    connect(this, &view::generateRandomQuestion, &quizWindow, &Quiz::showRandomQuestion);
    connect(this, &view::resetButtons, &quizWindow, &Quiz::resetButtons);
}

view::~view()
{
    delete ui;
}

void view::closeEvent(QCloseEvent *)
{
    indiaWindow.closeWindow();
    quizWindow.closeWindow();
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
    // WatMuang
    // TomYum
    // StickyRice

}

void view::fadeInBackgroundLabel()
{
    backgroundLabel->show();
    fadeEffect(0.0, 1.0, 1000, "backgroundLabel");
}

void view::fadeInWelcomeLabel()
{
    ui->welcomeLabel->show();
    fadeEffect(0.0, 1.0, 1000, "welcomeLabel");
}

void view::fadeOutWelcomeLabel()
{
    fadeEffect(1.0, 0.0, 1000, "welcomeLabel");
    QTimer::singleShot(1000, this, [this] {ui->welcomeLabel->hide();});
}

void view::fadeInPlayButton()
{
    ui->playButton->show();
    fadeEffect(0.0, 1.0, 1000, "playButton");
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
        fadeEffect(0.0, 1.0, 1500, "grandPalaceButton");
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


    // checkmark labels
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

    ui->indiaButton->hide();
    ui->koreaButton->hide();
    ui->thailandButton->hide();
    ui->koreaLabel->hide();
    ui->indiaLabel->hide();
    ui->thailandLabel->hide();
}

void view::fadeInCountryLabels(){
    ui->indiaLabel->show();
    ui->koreaLabel->show();
    ui->thailandLabel->show();

    fadeEffect(0.0, 1.0, 1500, "indiaLabel");
    fadeEffect(0.0, 1.0, 1500, "koreaLabel");
    fadeEffect(0.0, 1.0, 1500, "thailandLabel");
}

void view::fadeOutCountryLabels(){
    fadeEffect(1.0, 0.0, 1500, "indiaLabel");
    fadeEffect(1.0, 0.0, 1500, "koreaLabel");
    fadeEffect(1.0, 0.0, 1500, "thailandLabel");
}

void view::fadeInCheckmarks(Country country){

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
        if (koreaCompleteList.contains(Gyeongbokgung)){
            ui->gyeongbokgungCheckLabel->show();
        }
        if (koreaCompleteList.contains(Bulguksa)){
            ui->bulguksaCheckLabel->show();
        }
        if (koreaCompleteList.contains(Tteokbokki)){
            ui->tteokbokkiCheckLabel->show();
        }
        if (koreaCompleteList.contains(Bossam)){
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
        if (ThailandCompleteList.contains(GrandPalace)){
            ui->grandPalaceCheckLabel->show();
        }
        if (ThailandCompleteList.contains(WatMuang)){
            ui->bulguksaCheckLabel->show();
        }
        if (ThailandCompleteList.contains(TomYum)){
            ui->tteokbokkiCheckLabel->show();
        }
        if (ThailandCompleteList.contains(StickyRice)){
            ui->bossamCheckLabel->show();
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
    ui->tajMahal->setDisabled(true);
    ui->hawaMahal->setDisabled(true);
    ui->paniPuri->setDisabled(true);
    ui->biryani->setDisabled(true);
}

void view::showInfo(QString info)
{
    indiaWindow.show();
    emit informModelToSend(info);
    disableButtons();
}

void view::on_hawaMahal_clicked()
{
    showInfo("HawaMahal");

    ui->hawaMahalCheckLabel->show();
    indiaCompleteList.insert(HawaMaha);
    if (indiaCompleteList.size() == 4){
        ui->quizButton->show();
    }
}


void view::on_tajMahal_clicked()
{
    showInfo("TajMahal");

    ui->tajMahalCheckLabel->show();
    indiaCompleteList.insert(TajMahal);
    if (indiaCompleteList.size() == 4){
        ui->quizButton->show();
    }
}


void view::on_paniPuri_clicked()
{
    showInfo("PaniPuri");

    ui->paniPuriCheckLabel->show();
    indiaCompleteList.insert(PaniPuri);
    if (indiaCompleteList.size() == 4){
        ui->quizButton->show();
    }
}


void view::on_biryani_clicked()
{
    showInfo("Biryani");

    ui->biryaniCheckLabel->show();
    indiaCompleteList.insert(Biryani);
    if (indiaCompleteList.size() == 4){
        ui->quizButton->show();
    }
}

void view::on_quizButton_clicked()
{
    quizWindow.show();
    emit generateRandomQuestion();
    emit resetButtons();
}

void view::enableButtonsAndCheck()
{
    ui->hawaMahal->setEnabled(true);
    ui->tajMahal->setEnabled(true);
    ui->paniPuri->setEnabled(true);
    ui->biryani->setEnabled(true);
    ui->backButton->setEnabled(true);
}



void view::on_bulguksaButton_clicked()
{
//    showInfo("Bulguksa");

    ui->bulguksaCheckLabel->show();
    koreaCompleteList.insert(Bulguksa);
    if (koreaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_gyeongbokgungButton_clicked()
{
    //    showInfo("Gyeongbokgung");

    ui->gyeongbokgungCheckLabel->show();
    koreaCompleteList.insert(Gyeongbokgung);
    if (koreaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_tteokbokkiButton_clicked()
{
    //    showInfo("Tteokbokki");

    ui->tteokbokkiCheckLabel->show();
    koreaCompleteList.insert(Tteokbokki);
    if (koreaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_bossamButton_clicked()
{
    //    showInfo("Bossam");

    ui->bossamCheckLabel->show();
    koreaCompleteList.insert(Bossam);
    if (koreaCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}


void view::on_grandPalaceButton_clicked()
{
    //    showInfo("GrandPalace");

    ui->grandPalaceCheckLabel->show();
    ThailandCompleteList.insert(GrandPalace);
    if (ThailandCompleteList.size() == 4)
    {
        ui->quizButton->show();
    }
}

