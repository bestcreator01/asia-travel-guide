#include "view.h"
#include "ui_view.h"

#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QTimer>

view::view(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::view)
{
    ui->setupUi(this);

    this->setWindowTitle("Asia Travel Guide");
    connect(this, &view::hideWidgets, this, &view::hideStuff);
    //connect(this, &view::showWidgets, this, &view::showStuff);
    QIcon backArrowIcon(":/icons/left-arrow.png");

    ui->backButton->setIcon(backArrowIcon);
    ui->backButton->hide();

// This code below was for trying to put the label and button in the center

    //    ui->pushButton->setSizePolicy(QSizePolicy::Expanding,
    //                                  QSizePolicy::Expanding);
    //    ui->label->setSizePolicy(QSizePolicy::Expanding,
    //                             QSizePolicy::Expanding);
//        QGridLayout* grid = new QGridLayout;
//    QHBoxLayout* layout = new QHBoxLayout(this);
//    layout->addWidget(ui->pushButton);
//    layout->addWidget(ui->label);
//     setLayout(layout);


//        grid->setColumnStretch(0,1);
//        grid->setRowStretch(0,3);
//        grid->setRowStretch(1,1);
//        grid->addWidget(ui->label,0,0, Qt::AlignJustify);
//        grid->addWidget(ui->pushButton, 1, 0, Qt::AlignCenter);

//        QFrame* frame = new QFrame();
//        frame->setFrameShape(QFrame::NoFrame);
//        frame->setLayout(grid);
//        setCentralWidget(frame);
//        show();
        //this->setLayout(layout);

    // w is your widget

    // now implement a slot called hideThisWidget() to do
    // things like hide any background dimmer, etc.

}

view::~view()
{
    delete ui;
}


void view::on_playButton_clicked()
{   
    fadeEffect(1.0, 0.0, "playButton");
    fadeEffect(1.0, 0.0, "welcomeLabel");
    fadeInBackArrow();
    emit hideWidgets();
}

void view::hideStuff()
{
    QTimer::singleShot(1000, this, &view::hideAll);
    ui->backButton->show();
}

void view::hideAll()
{
    ui->welcomeLabel->hide();
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
    //emit showWidgets();
}

void view::fadeEffect(double startValue, double endValue, QString widget)
{
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    currentAnimationWidget(widget, eff);
    QPropertyAnimation *animation = new QPropertyAnimation(eff,"opacity");
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);

    animation->setDuration(1000);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void view::currentAnimationWidget(QString name, QGraphicsOpacityEffect *eff)
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

//void view::showStuff()
//{
//    //QTimer::singleShot(1000, this, &view::showAll);
//}

//void view::showAll()
//{
//    ui->label->show();
//    ui->pushButton->show();
//    ui->pushButton_2->hide();
//}

