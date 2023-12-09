#include "quiz.h"
#include "ui_quiz.h"
#include <QMovie>

Quiz::Quiz(QWidget *parent) : QWidget(parent),
                              ui(new Ui::Quiz)
{
    ui->setupUi(this);
    ui->nextButton->hide();
    this->setWindowTitle("QUIZ");
    backgroundLabel = new QLabel(this);
//    QMovie *movie = new QMovie(":/icons/clouds.gif");
//    movie->setScaledSize(this->size());
//    backgroundLabel->setMovie(movie);
    backgroundLabel->setGeometry(0, 0, this->width(), this->height());  // Set to cover the entire window
    backgroundLabel->lower();
//    movie->start();

    // Set up Box2D world
    b2Vec2 neg(0.0f, -30.0f);
    b2Vec2 pos(0.0f, 30.0f);
    top = new b2World(neg);
    bottom = new b2World(pos);

    // Create ground
    createGround(-7.0f, height() + 5.0f);

    connect(&timer, &QTimer::timeout, this, &Quiz::updateWorld);
    timer.start(3);
    ui->option1Button->setEnabled(true);
    ui->option2Button->setEnabled(true);
    ui->option3Button->setEnabled(true);
    ui->option4Button->setEnabled(true);

}

Quiz::~Quiz()
{
    delete ui;
    delete top;
    delete bottom;
}

void Quiz::setValues(QMap<QString, QList<QString>> &questionBank, QList<QString> &questions)
{
    this->questionBank = questionBank;
    this->questions = questions;
}

void Quiz::setRandomOptions(QList<int> &numbers)
{
    this->numbers = numbers;
}

void Quiz::showRandomQuestion()
{
    quesIndex = 0;
    randomQuestion = questions[quesIndex];
    ui->question->setText(randomQuestion);
    // randomize
    emit randomizeOption();
    randomizeSelection(numbers);
}

void Quiz::resetButtons()
{
    ui->option1Button->setEnabled(true);
    ui->option2Button->setEnabled(true);
    ui->option3Button->setEnabled(true);
    ui->option4Button->setEnabled(true);

    ui->option1Button->setStyleSheet("");
    ui->option2Button->setStyleSheet("");
    ui->option3Button->setStyleSheet("");
    ui->option4Button->setStyleSheet("");
}

void Quiz::disableOptionButtons()
{
    // disable all the option buttons
    ui->option1Button->setDisabled(true);
    ui->option2Button->setDisabled(true);
    ui->option3Button->setDisabled(true);
    ui->option4Button->setDisabled(true);
    if (quesIndex != 3)
        ui->nextButton->show();
}

void Quiz::on_option1Button_clicked()
{
    handleOptionButtonClick(ui->option1Button);
}

void Quiz::on_option2Button_clicked()
{
    handleOptionButtonClick(ui->option2Button);
}

void Quiz::on_option3Button_clicked()
{
    handleOptionButtonClick(ui->option3Button);
}

void Quiz::on_option4Button_clicked()
{
    handleOptionButtonClick(ui->option4Button);
}

void Quiz::handleOptionButtonClick(QPushButton *button)
{
    QString selectedOption = button->text();
    QString correctOption = questionBank[randomQuestion][correct];

    if (selectedOption != correctOption)
    {
        button->setStyleSheet("background-color: red");
        button->setDisabled(true);
    }
    else
    {
        button->setStyleSheet("background-color: green");
        disableOptionButtons();
        createConfetti();
    }
}

void Quiz::on_nextButton_clicked()
{
    ui->nextButton->hide();
    randomQuestion = questions[++quesIndex];
    ui->question->setText(randomQuestion);

    // randomize
    emit randomizeOption();
    randomizeSelection(numbers);

    resetButtons();
    if (quesIndex == questions.size() - 1)
        ui->nextButton->hide();

    closePaint();
}

void Quiz::randomizeSelection(QList<int> numbers)
{
    ui->option1Button->setText(questionBank[randomQuestion][numbers[0]]);
    ui->option2Button->setText(questionBank[randomQuestion][numbers[1]]);
    ui->option3Button->setText(questionBank[randomQuestion][numbers[2]]);
    ui->option4Button->setText(questionBank[randomQuestion][numbers[3]]);
    update();
}

void Quiz::closeEvent(QCloseEvent *bar)
{
    quesIndex = 0;
    closePaint();
}

void Quiz::closePaint()
{
    for (int i = 0; i < confettiPieces.size(); i += 2)
    {
        top->DestroyBody(confettiPieces[i]);
        bottom->DestroyBody(confettiPieces[i + 1]);
    }

    confettiPieces.clear();
    confettiColors.clear();

    update();
}

void Quiz::generateConfettiColors()
{
    for (int i = 0; i < confettiPieces.size(); i++)
    {
        QColor randomColor = QColor::fromRgb(rand() % 256, rand() % 256, rand() % 256);
        confettiColors.push_back(randomColor);
    }
}

void Quiz::createConfetti()
{
    // Create confetti pieces
    for (int i = 0; i < 100; ++i)
    {
        b2BodyDef confettiBodyDef;
        confettiBodyDef.type = b2_dynamicBody;
        confettiBodyDef.position.Set(width() / 2, height() / 2);

        b2Body *topConfettiPiece = top->CreateBody(&confettiBodyDef);
        b2Body *bottomConfettiPiece = bottom->CreateBody(&confettiBodyDef);

        b2PolygonShape confettiShape;
        confettiShape.SetAsBox(0.1f, 0.1f);  // Adjust the size as needed

        b2FixtureDef confettiFixtureDef;
        confettiFixtureDef.shape = &confettiShape;
        confettiFixtureDef.density = 1.0f;
        confettiFixtureDef.friction = 0.3f;
        confettiFixtureDef.restitution = 0.5f;

        topConfettiPiece->CreateFixture(&confettiFixtureDef);
        confettiPieces.push_back(topConfettiPiece);

        bottomConfettiPiece->CreateFixture(&confettiFixtureDef);
        confettiPieces.push_back(bottomConfettiPiece);
    }
    // Create random set of colors for confetti
    generateConfettiColors();
}

void Quiz::createGround(float neg, float pos)
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, neg);
    b2Body *groundBody = top->CreateBody(&groundBodyDef);
    groundBodyDef.position.Set(0.0f, pos);
    b2Body *groundBody1 = bottom->CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(width(), 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
    groundBody1->CreateFixture(&groundBox, 0.0f);
}

void Quiz::closeWindow()
{
    this->close();
}

void Quiz::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // Paint the scene
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw confetti pieces
    for (int i = 0; i < confettiPieces.size(); i += 2)
    {
        // Set the brush to the pre-generated color and no outline
        painter.setBrush(QBrush(confettiColors[i]));
        painter.setPen(Qt::NoPen);  // Set no outline

        b2Vec2 topPosition = confettiPieces[i]->GetPosition();
        b2Vec2 bottomPosition = confettiPieces[i + 1]->GetPosition();

        confettiPieces[75]->ApplyForce(b2Vec2(0.0f, 10000.0f), topPosition, true);
        confettiPieces[100]->ApplyForce(b2Vec2(0.0f, 10000.0f), bottomPosition, true);

        painter.drawRect(QRectF(topPosition.x, topPosition.y, 5, 5));
        painter.drawRect(QRectF(bottomPosition.x, bottomPosition.y, 5, 5));
    }
}

void Quiz::updateWorld()
{
    top->Step(1.0 / 60.0, 6, 2);
    bottom->Step(1.0 / 60.0, 6, 2);
    update();
}
