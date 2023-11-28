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

    // set background
    QPixmap background(":/icons/asia_map.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, background.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

//    QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(this);
//    opacityEffect->setOpacity(0.6);
//    this->centralWidget()->setGraphicsEffect(opacityEffect);
    this->centralWidget()->setAutoFillBackground(true);
    this->centralWidget()->setPalette(palette);

    ui->backButton->setIcon(backArrowIcon);
    ui->backButton->hide();
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

}

void view::hideStuff()
{
    QTimer::singleShot(1000, this, &view::fadeOutWelcomeLabel);
    QTimer::singleShot(1000, this, &view::fadeOutPlayButton);

    ui->backButton->show();
}

void view::fadeOutWelcomeLabel(){
    fadeEffect(1.0, 0.0, "welcomeLabel");
    ui->welcomeLabel->hide();
}

void view::fadeOutPlayButton(){
    fadeEffect(1.0, 0.0, "playButton");
    ui->playButton->hide();
}

void view::fadeInBackArrow()
{
    ui->backButton->show();
    fadeEffect(0.0, 1.0, "backButton");
}

void view::on_backButton_clicked()
{
    ui->welcomeLabel->show();
    ui->playButton->show();
    ui->backButton->hide();

    fadeEffect(0.0, 1.0, "playButton");
    fadeEffect(0.0, 1.0, "welcomeLabel");
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
}
