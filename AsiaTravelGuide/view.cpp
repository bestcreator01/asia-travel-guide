#include "view.h"
#include "ui_view.h"

#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPalette>

view::view(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::view)
{
    ui->setupUi(this);

    this->setWindowTitle("Asia Travel Guide");

    QIcon backArrowIcon(":/icons/left-arrow.png");
    QIcon markerIcon(":/icons/marker.png");

    ui->backButton->setIcon(backArrowIcon);
    ui->backButton->hide();
    ui->indiaButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->indiaButton->setIcon(markerIcon);
    ui->indiaButton->setIconSize(QSize(50, 50));
    ui->indiaButton->setText("");
    ui->indiaButton->hide();

    // Background label
    backgroundLabel = new QLabel(this);
    QPixmap background(":/icons/asia_map.jpg");
    backgroundLabel->setPixmap(background.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    backgroundLabel->setGeometry(0, 0, this->width(), this->height());  // Set to cover the entire window
    backgroundLabel->lower();

    // Set initial background opacity
    QGraphicsOpacityEffect *backgroundOpacityEffect = new QGraphicsOpacityEffect(backgroundLabel);
    backgroundOpacityEffect->setOpacity(0.5);
    backgroundLabel->setGraphicsEffect(backgroundOpacityEffect);
}

view::~view()
{
    delete ui;
}

void view::on_playButton_clicked()
{
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
    fadeInWelcomeLabel();
    fadeInPlayButton();
    fadeOutBackArrow();
    fadeOutMarkers();

    // background opacity 100% -> 50%
    QGraphicsOpacityEffect *effect = dynamic_cast<QGraphicsOpacityEffect*>(backgroundLabel->graphicsEffect());
    QPropertyAnimation *opacityAnimation = new QPropertyAnimation(effect, "opacity");
    opacityAnimation->setDuration(1000);
    opacityAnimation->setStartValue(effect->opacity());
    opacityAnimation->setEndValue(0.5);
    opacityAnimation->start(QPropertyAnimation::DeleteWhenStopped);
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
}
