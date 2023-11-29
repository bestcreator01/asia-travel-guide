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
    QIcon taj(":/icons/taj.png");
    QIcon hawa(":/icons/hawa-mahal.png");
    QIcon biryani(":/icons/biryani.png");
    QIcon panipuri(":/icons/panipuri.png");

    ui->backButton->setIcon(backArrowIcon);
    ui->backButton->hide();
    ui->indiaButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->tajMahal->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->hawaMahal->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->paniPuri->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->biryani->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->indiaButton->setIconSize(QSize(50, 50));
    ui->tajMahal->setIconSize(QSize(50, 50));
    ui->hawaMahal->setIconSize(QSize(50, 50));
    ui->paniPuri->setIconSize(QSize(50, 50));
    ui->biryani->setIconSize(QSize(50, 50));
    ui->indiaButton->setIcon(markerIcon);
    ui->tajMahal->setIcon(taj);
    ui->hawaMahal->setIcon(hawa);
    ui->paniPuri->setIcon(panipuri);
    ui->biryani->setIcon(biryani);
    ui->indiaButton->hide();
    // landmark spots
    ui->tajMahal->hide();
    ui->hawaMahal->hide();
    ui->paniPuri->hide();
    ui->biryani->hide();

    // Background label
    backgroundLabel = new QLabel(this);
    QPixmap background(":/icons/asia-map.png");
    setBgLabel(background);

    // Set initial background opacity
    setBgLabelOpacity();

    connect(this, &view::changedState, &model, &Model::changeState);
    connect(&model, &Model::changedScreenState, this, &view::updateState);
}

view::~view()
{
    delete ui;
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
    if(previousState == "Welcome")
    {
        emit changedState("Welcome");
        fadeInWelcomeLabel();
        fadeInPlayButton();
        fadeOutBackArrow();
        fadeOutMarkers();
        setBgLabelOpacity();
    }
    else if(previousState == "AsiaMap")
    {
        emit changedState("AsiaMap");
        fadeInMarkers();
        QPixmap background(":/icons/asia-map.png");
        setBgLabel(background);
        fadeInBackgroundLabel();
    }
}

void view::fadeInBackgroundLabel()
{
    backgroundLabel->show();
    fadeEffect(0.0, 1.0, "backgroundLabel");
}

void view::fadeOutBackgroundLabel()
{
    QTimer::singleShot(1000, this, [this] {QPixmap background(":/icons/india-map.png"); setBgLabel(background);});
    fadeEffect(1.0, 0.0, "backgroundLabel");
}

void view::fadeInWelcomeLabel()
{
    ui->welcomeLabel->show();
    fadeEffect(0.0, 1.0, "welcomeLabel");
}

void view::fadeOutWelcomeLabel()
{
    fadeEffect(1.0, 0.0, "welcomeLabel");
    QTimer::singleShot(1000, this, [this] {ui->welcomeLabel->hide();});
}

void view::fadeInPlayButton()
{
    ui->playButton->show();
    fadeEffect(0.0, 1.0, "playButton");
}

void view::fadeOutPlayButton()
{
    fadeEffect(1.0, 0.0, "playButton");
    QTimer::singleShot(1000, this, [this] {ui->playButton->hide();});
}

void view::fadeInBackArrow()
{
    ui->backButton->show();
    fadeEffect(0.0, 1.0, "backButton");
}

void view::fadeOutBackArrow()
{
    fadeEffect(1.0, 0.0, "backButton");
    QTimer::singleShot(1000, this, [this] {ui->backButton->hide();});
}

void view::fadeInMarkers()
{
    ui->indiaButton->show();
    fadeEffect(0.0, 1.0, "indiaButton");
}

void view::fadeOutMarkers()
{
    fadeEffect(1.0, 0.0, "indiaButton");
    QTimer::singleShot(1000, this, [this] {ui->indiaButton->hide();});
}

void view::fadeInLandMarks()
{
    ui->tajMahal->show();
    ui->hawaMahal->show();
    ui->paniPuri->show();
    ui->biryani->show();
    fadeEffect(0.0, 1.0, "landMarksButton");

}

void view::fadeOutLandMarks()
{
    fadeEffect(1.0, 0.0, "landMarksButton");
    QTimer::singleShot(1000, this, [this] { ui->tajMahal->hide();
                                            ui->hawaMahal->hide();
                                            ui->paniPuri->hide();
                                            ui->biryani->hide();});
}

void view::fadeEffect(double startValue, double endValue, QString widget)
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    setWidgetGraphicsEffect(widget, eff);
    QPropertyAnimation *animation = new QPropertyAnimation(eff,"opacity");
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);

    animation->setDuration(1000);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void view::setWidgetGraphicsEffect(QString name, QGraphicsOpacityEffect *eff)
{
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
    else if(name == "indiaButton")
    {
        ui->indiaButton->setGraphicsEffect(eff);
    }
    else if(name == "backgroundLabel")
    {
        backgroundLabel->setGraphicsEffect(eff);
    }
    else if (name == "landMarksButton")
    {
        ui->tajMahal->setGraphicsEffect(eff);
        ui->hawaMahal->setGraphicsEffect(eff);
        ui->paniPuri->setGraphicsEffect(eff);
        ui->biryani->setGraphicsEffect(eff);
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
    ui->indiaButton->hide();
    QPixmap background(":/icons/india-map.png");
    setBgLabel(background);
    fadeOutBackgroundLabel();
    fadeInBackgroundLabel();
    fadeInLandMarks();
}

