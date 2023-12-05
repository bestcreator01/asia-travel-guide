#include "quiz.h"
#include <QLabel>
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
    // first question
    question1 =
        "The Taj Mahal is renowned for its distinctive features, "
        "\nincluding a large, white, domed mausoleum surrounded by four minarets. "
        "\nWhat is the meaning of the name \"Taj Mahal\" in Urdu and Persian?";
    option1 = "Monument of Eternal Love";
    option2 = "Ivory Marvel";
    option3 = "Crown of Palaces";  // Correct
    option4 = "Pearl of Agra";
    questionBank[question1] = {option1, option2, option3, option4};
    // second quesiton
    question2 =
        "What was the original purpose of the intricate latticework and "
        "\nnumerous small windows (Jharokhas) in the design of Hawa Mahal?";
    option1 = "To serve as decorative elements for the palace's exterior";
    option2 = "To create a honeycomb-like pattern for aesthetic appeal";
    option3 = "To allow royal ladies to observe street activities without "
              "\nbeing seen";  // Correct
    option4 = "To enhance the structural stability of the palace";
    questionBank[question2] = {option1, option2, option3, option4};

    // third question
    question3 =
        "Pani Puri is a common street food in the Indian subcontinent."
        "\nWhat makes the ingredients of Pani Puri as a snack in India?";
    option1 = "deep-fried and breaded exterior";
    option2 = "yogurt, ginger, garlic, and herbs";
    option3 = "chili powder, chaat masala, potato mash, and chickpeas";  // Correct
    option4 = "peppers, turmeric, coriander, and cumin";
    questionBank[question3] = {option1, option2, option3, option4};

    // fourth question
    question4 =
        "What cooking method is most commonly used to prepare Biryani, "
        "\ninvolving sealing food in a round, heavy-bottomed pot "
        "\nand slow cooking it over a low flame?";
    option1 = "Grilling";
    option2 = "Boiling";
    option3 = "Dum method";  // Correct
    option4 = "Stir-frying";
    questionBank[question4] = {option1, option2, option3, option4};
    questions.push_back(question1);
    questions.push_back(question2);
    questions.push_back(question3);
    questions.push_back(question4);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(questions.begin(), questions.end(), g);

    // Set up Box2D world
    b2Vec2 neg(0.0f, -30.0f);
    b2Vec2 pos(0.0f, 30.0f);
    top = new b2World(neg);
    bottom = new b2World(pos);

    // Create ground
    createGround(-7.0f, height() + 5.0f);

    connect(&timer, &QTimer::timeout, this, &Quiz::updateWorld);
    timer.start(3);
}

Quiz::~Quiz()
{
    delete ui;
    delete top;
    delete bottom;
}

void Quiz::showRandomQuestion()
{
    quesIndex = 0;
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(questions.begin(), questions.end(), g);
    // randomize
    randomQuestion = questions[quesIndex];
    ui->question->setText(randomQuestion);
    update();

    std::shuffle(numbers.begin(), numbers.end(), g);

    ui->option1Button->setText(questionBank[randomQuestion][numbers[0]]);
    ui->option2Button->setText(questionBank[randomQuestion][numbers[1]]);
    ui->option3Button->setText(questionBank[randomQuestion][numbers[2]]);
    ui->option4Button->setText(questionBank[randomQuestion][numbers[3]]);
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
    if (ui->option1Button->text() != questionBank[randomQuestion][2])
    {
        ui->option1Button->setStyleSheet("background-color: red");
        ui->option1Button->setDisabled(true);
    }
    else
    {
        ui->option1Button->setStyleSheet("background-color: green");
        disableOptionButtons();
        createConfetti();
    }
}

void Quiz::on_option2Button_clicked()
{
    if (ui->option2Button->text() != questionBank[randomQuestion][2])
    {
        ui->option2Button->setStyleSheet("background-color: red");
        ui->option2Button->setDisabled(true);
    }
    else
    {
        ui->option2Button->setStyleSheet("background-color: green");
        disableOptionButtons();
        createConfetti();
    }
}

void Quiz::on_option3Button_clicked()
{
    if (ui->option3Button->text() != questionBank[randomQuestion][2])
    {
        ui->option3Button->setStyleSheet("background-color: red");
        ui->option3Button->setDisabled(true);
    }
    else
    {
        ui->option3Button->setStyleSheet("background-color: green");
        disableOptionButtons();
        createConfetti();
    }
}

void Quiz::on_option4Button_clicked()
{
    if (ui->option4Button->text() != questionBank[randomQuestion][2])
    {
        ui->option4Button->setStyleSheet("background-color: red");
        ui->option4Button->setDisabled(true);
    }
    else
    {
        ui->option4Button->setStyleSheet("background-color: green");
        disableOptionButtons();
        createConfetti();
    }
}

void Quiz::on_nextButton_clicked()
{
    ui->nextButton->hide();
    randomQuestion = questions[++quesIndex];
    ui->question->setText(randomQuestion);
    update();

    // randomize
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(numbers.begin(), numbers.end(), g);

    ui->option1Button->setText(questionBank[randomQuestion][numbers[0]]);
    ui->option2Button->setText(questionBank[randomQuestion][numbers[1]]);
    ui->option3Button->setText(questionBank[randomQuestion][numbers[2]]);
    ui->option4Button->setText(questionBank[randomQuestion][numbers[3]]);

    resetButtons();
    if (quesIndex == 3)
        ui->nextButton->hide();

    closePaint();
}

void Quiz::closeEvent(QCloseEvent *bar)
{
    quesIndex = 0;
    closePaint();
}

void Quiz::closePaint()
{
    for (int i = 0; i < topConfettiPieces.size(); i++)
    {
        top->DestroyBody(topConfettiPieces[i]);
        bottom->DestroyBody(bottomConfettiPieces[i]);
    }

    topConfettiPieces.clear();
    bottomConfettiPieces.clear();
    confettiColors.clear();

    update();
}

void Quiz::generateConfettiColors()
{
    for (int i = 0; i < 100; ++i)
    {
        QColor randomColor = QColor::fromRgb(arc4random() % 256, arc4random() % 256, arc4random() % 256);
        confettiColors.push_back(randomColor);
    }
}

void Quiz::createConfetti()
{
    // Create random set of colors for confetti
    generateConfettiColors();

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
        topConfettiPieces.push_back(topConfettiPiece);

        bottomConfettiPiece->CreateFixture(&confettiFixtureDef);
        bottomConfettiPieces.push_back(bottomConfettiPiece);
    }
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
    for (int i = 0; i < topConfettiPieces.size(); i++)
    {
        // Set the brush to the pre-generated color and no outline
        painter.setBrush(QBrush(confettiColors[i]));
        painter.setPen(Qt::NoPen);  // Set no outline

        b2Vec2 topPosition = topConfettiPieces[i]->GetPosition();
        b2Vec2 bottomPosition = bottomConfettiPieces[i]->GetPosition();

//        if (topPosition.y <= 0 && bottomPosition.y >= height())
//        {
//            topTouchedGround = true;
//            bottomTouchedGround = true;
//        }
//        else
//        {
            bottomConfettiPieces[50]->ApplyForce(b2Vec2(0.0f, 10000.0f), bottomPosition, true);
            topConfettiPieces[50]->ApplyForce(b2Vec2(0.0f, 10000.0f), topPosition, true);
        //}

//        if (topTouchedGround && bottomTouchedGround)
//        {
            painter.drawRect(QRectF(topPosition.x, topPosition.y, 5, 5));
            painter.drawRect(QRectF(bottomPosition.x, bottomPosition.y, 5, 5));
        //}
    }

    topTouchedGround = false;
    bottomTouchedGround = false;
}

void Quiz::updateWorld()
{
    top->Step(1.0 / 60.0, 6, 2);
    bottom->Step(1.0 / 60.0, 6, 2);
    update();
}
