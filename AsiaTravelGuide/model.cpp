/**
 * Author:     Crazy Broke Asians
 * Date:       Dec-08-2023
 * Course:     CS 3505, University of Utah
 * Assignment: A9: An Educational App
 * File Contents
 *      It contains all necessary codes needed to form a model class.
*/

#include "model.h"

Model::Model(QObject *parent) : QObject(parent)
{

}

void Model::changeState(QString state)
{
    if (state == "AsiaMap")
    {
        emit changedScreenState("Welcome");
    }
    else if(state == "CountryMap")
    {
        emit changedScreenState("AsiaMap");
    }
}

void Model::showQuizInfo(QString country)
{
    questionBank.clear();
    questions.clear();
    if (country == "India")
    {
        emit sendCountryForBgImage("India");
        setIndia();
    }
    else if(country == "Thailand")
    {
        emit sendCountryForBgImage("Thailand");
        setThailand();
    }
    else if(country == "Korea")
    {
        emit sendCountryForBgImage("Korea");
        setKorea();
    }
    emit sendQuiz(questionBank, questions);
}

void Model::randomizeOption()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(numbers.begin(), numbers.end(), g);
    emit sendOptions(numbers);
}

void Model::setIndia()
{
    question1 =
        "The Taj Mahal is renowned for its distinctive features, "
        "\nincluding a large, white, domed mausoleum surrounded by four minarets. "
        "\nWhat is the meaning of the name \"Taj Mahal\" in Urdu and Persian?";
    option1 = "Monument of Eternal Love";
    option2 = "Ivory Marvel";
    option3 = "Crown of Palaces";  // Correct
    option4 = "Pearl of Agra";
    putQuestionInQuestionBank(question1);

    // second quesiton
    question2 =
        "What was the original purpose of the intricate latticework and "
        "\nnumerous small windows (Jharokhas) in the design of Hawa Mahal?";
    option1 = "To serve as decorative "
              "\nelements for the palace's exterior";
    option2 = "To create a honeycomb-like "
              "\npattern for aesthetic appeal";
    option3 = "To allow royal ladies to "
              "\nobserve street activities without "
              "\nbeing seen";  // Correct
    option4 = "To enhance the structural "
              "\nstability of the palace";
    putQuestionInQuestionBank(question2);

    // third question
    question3 =
        "Pani Puri is a common street food in the Indian subcontinent."
        "\nWhat makes the ingredients of Pani Puri as a snack in India?";
    option1 = "butter, frosting, sugar syrup";
    option2 = "yogurt, ginger, chicken, "
              "\nand herbs";
    option3 = "chili powder, chaat masala, "
              "\npotato mash, and chickpeas";  // Correct
    option4 = "rice flour, corn flour, oil";
    putQuestionInQuestionBank(question3);

    // fourth question
    question4 =
        "What cooking method is most commonly used to prepare Biryani, "
        "\ninvolving sealing food in a round, heavy-bottomed pot "
        "\nand slow cooking it over a low flame?";
    option1 = "Grilling";
    option2 = "Boiling";
    option3 = "Dum method";  // Correct
    option4 = "Stir-frying";
    putQuestionInQuestionBank(question4);

    randomizeQuestions();
}

void Model::setThailand()
{
    question1 =
        "Being a complex of buildings at the heart of Bangkok, Thailand."
        "\nIn which year was the Thailand Grand Palace constructed, "
        "\nand during whose reign was it built?";
    option1 = "1682, King Rama II";
    option2 = "1882, King Rama III";
    option3 = "1782, King Rama I";  // Correct
    option4 = "1982, King Bhumibol Adulyadej";
    putQuestionInQuestionBank(question1);

    // second quesiton
    question2 =
        "What is the local name for the Great Buddha of Thailand, "
        "\nand what unique feature sets it apart from other statues?";
    option1 = "Golden Enlightenment, its panoramic views";
    option2 = "Wat Muang, its serene expression";
    option3 = "Luangpho Yai, "
              "\nits construction materials ";  // Correct
    option4 = "Buddha Rama, its colossal size";
    putQuestionInQuestionBank(question2);

    // third question
    question3 =
        "Originating from central Thailand and a quintessential Thai soup,"
        "\nWhat is the English translation of \"Tom Yum\"?";
    option1 = "Spicy Delight";
    option2 = "Tasty Heat";
    option3 = "Hot and Sour";  // Correct
    option4 = "Flavorful Zest";
    putQuestionInQuestionBank(question3);

    // fourth question
    question4 =
        "What is the key ingredient used to impart a creamy texture "
        "\nand subtle sweetness to Mango Sticky Rice,"
        "\nand during which months does this dessert typically get eaten?";
    option1 = "Condensed Milk, "
              "\nJuly to September";
    option2 = "Almond Milk, "
              "\nOctober to December";
    option3 = "Coconut Milk, "
              "\nMarch to June";  // Correct
    option4 = "Evaporated Milk, "
              "\nJanuary to February";
    putQuestionInQuestionBank(question4);

    randomizeQuestions();
}

void Model::setKorea()
{
    question1 =
        "During which war did Gyeongbokgung suffer damage and abandonment "
        "\nfor two centuries before its comprehensive restoration"
        "\nin the 19th century?";
    option1 = "World War I";
    option2 = "Korean War";
    option3 = "Imjin War";  // Correct
    option4 = "Vietnam War";
    putQuestionInQuestionBank(question1);

    // second quesiton
    question2 =
        "Bulguksa, a UNESCO World Heritage site in South Korea, "
        "\nis known for housing one of the world's earliest woodblock prints."
        "\n What is the content of this historical woodblock print?";
    option1 = "Royal decrees";
    option2 = "Landscape paintings";
    option3 = "Buddhist scriptures";  // Correct
    option4 = "Architectural blueprints";
    putQuestionInQuestionBank(question2);

    // third question
    question3 =
        "Apart from rice cakes, what are two common accompaniments "
        "\nin a traditional serving of Tteokbokki?";
    option1 = "Tofu and Kimchi";
    option2 = "Fish cakes and Boiled eggs";
    option3 = "Seaweed and Radishes";  // Correct
    option4 = "Pork and Bean sprouts";
    putQuestionInQuestionBank(question3);

    // fourth question
    question4 =
        "In addition to pork shoulder, what is a key component of "
        "\nthe side dishes served with Bossam in Korean cuisine?";
    option1 = "Sliced Raw Beef";
    option2 = "Fried Chicken";
    option3 = "Spicy Radish Salad";  // Correct
    option4 = "Steamed Vegetables";
    putQuestionInQuestionBank(question4);

    randomizeQuestions();
}

void Model::putQuestionInQuestionBank(QString question)
{
    questionBank[question] = {option1, option2, option3, option4};
    questions.push_back(question);
}

void Model::randomizeQuestions()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(questions.begin(), questions.end(), g);
}
