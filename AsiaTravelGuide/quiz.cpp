#include "quiz.h"

#include "ui_quiz.h"

Quiz::Quiz(QWidget *parent) : QWidget(parent),
                              ui(new Ui::Quiz)
{
    ui->setupUi(this);
    ui->nextButton->hide();

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
    option3 = "To allow royal ladies to observe street activities without being seen";  // Correct
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

    // Create random set of colors for confetti
    generateConfettiColors();

    // Set up Box2D world
    b2Vec2 neg(0.0f, -20.0f);
    b2Vec2 pos(0.0f, 20.0f);
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

    // QTimer::singleShot(1000, this, &Quiz::closePaint);
    closePaint();
}

void Quiz::closeEvent(QCloseEvent *bar)
{
    quesIndex = 0;
}

void Quiz::closePaint()
{
    for (int i = 0; i < confettiPieces.size(); i++)
    {
        top->DestroyBody(confettiPieces[i]);
        bottom->DestroyBody(confettiPieces2[i]);
    }

    confettiPieces.clear();
    confettiPieces2.clear();

    update();
}

void Quiz::generateConfettiColors()
{
    for (int i = 0; i < 100; ++i)
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

        b2BodyDef confettiBodyDef2;
        confettiBodyDef2.type = b2_dynamicBody;
        confettiBodyDef2.position.Set(width() / 2, height() / 2);


        b2Vec2 initialVelocity(0.0f, -1500.0f);
        confettiBodyDef.linearVelocity = initialVelocity;

        b2Vec2 initialVelocity2(0.0f, 1500.0f);
        confettiBodyDef2.linearVelocity = initialVelocity2;


        b2Body *confettiPiece1 = top->CreateBody(&confettiBodyDef);
        b2Body *confettiPiece2 = bottom->CreateBody(&confettiBodyDef2);

        b2PolygonShape confettiShape;
        confettiShape.SetAsBox(0.1f, 0.1f);  // Adjust the size as needed

        b2FixtureDef confettiFixtureDef;
        confettiFixtureDef.shape = &confettiShape;
        confettiFixtureDef.density = 1.0f;
        confettiFixtureDef.friction = 0.3f;
        confettiFixtureDef.restitution = 1.0f;

        confettiPiece1->CreateFixture(&confettiFixtureDef);
        confettiPieces.push_back(confettiPiece1);

        confettiPiece2->CreateFixture(&confettiFixtureDef);
        confettiPieces2.push_back(confettiPiece2);
    }
    qDebug() << "Height: " << height() / 2;
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

void Quiz::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // Paint the scene
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw confetti pieces
    for (int i = 0; i < confettiPieces.size(); i++)
    {
        // Set the brush to the pre-generated color and no outline
        painter.setBrush(QBrush(confettiColors[i]));
        painter.setPen(Qt::NoPen);  // Set no outline

        b2Vec2 position = confettiPieces[i]->GetPosition();
        painter.drawRect(QRectF(position.x, position.y, 5, 5));
        position = confettiPieces2[i]->GetPosition();
        painter.drawRect(QRectF(position.x, position.y, 5, 5));

        //        if (position.y >= 500)
        //        {
        //            //touchedGround = true;
        //        }
        //        if (touchedGround)
        //        {
        //            painter.drawRect(QRectF(position.x, position.y, 5, 5)); // Adjust size as needed
        //        }
    }
    // touchedGround = false;
}

void Quiz::updateWorld()
{
    // It is generally best to keep the time step and iterations fixed.
    top->Step(1.0 / 60.0, 6, 2);
    bottom->Step(1.0 / 60.0, 6, 2);
    update();
}
