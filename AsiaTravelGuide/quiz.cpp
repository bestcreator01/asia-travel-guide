#include "quiz.h"
#include "ui_quiz.h"

Quiz::Quiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Quiz)
{
    ui->setupUi(this);
    // first question
    question = "The Taj Mahal is renowned for its distinctive features, "
               "including a large, white, domed mausoleum surrounded by four minarets. "
               "What is the meaning of the name \"Taj Mahal\" in Urdu and Persian?";
    option1 = "Monument of Eternal Love";
    option2 = "Ivory Marvel";
    option3 = "Crown of Palaces"; // Correct
    option4 = "Pearl of Agra";
    questionBank[question] = {option1, option2, option3, option4};
    // second quesiton
    question = "What was the original purpose of the intricate latticework and "
               "numerous small windows (Jharokhas) in the design of Hawa Mahal?";
    option1 = "To serve as decorative elements for the palace's exterior";
    option2 = "To create a honeycomb-like pattern for aesthetic appeal";
    option3 = "To allow royal ladies to observe street activities without being seen"; // Correct
    option4 = "To enhance the structural stability of the palace";
    questionBank[question] = {option1, option2, option3, option4};

    // third question
    question = "Pani Puri is a common street food in the Indian subcontinent."
               "What makes the ingredients of Pani Puri as a snack in India?";
    option1 = "deep-fried and breaded exterior";
    option2 = "yogurt, ginger, garlic, and herbs";
    option3 = "chili powder, chaat masala, potato mash, and chickpeas"; // Correct
    option4 = "peppers, turmeric, coriander, and cumin";
    questionBank[question] = {option1, option2, option3, option4};

    // fourth question
    question = "What cooking method is most commonly used to prepare Biryani, "
               "involving sealing food in a round, heavy-bottomed pot and slow cooking it over a low flame?";
    option1 = "Grilling";
    option2 = "Boiling";
    option3 = "Dum method"; // Correct
    option4 = "Stir-frying";
    questionBank[question] = {option1, option2, option3, option4};

}

Quiz::~Quiz()
{
    delete ui;
}
