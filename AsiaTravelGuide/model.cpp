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
        setIndia();

    }
    else if(country == "Thailand")
    {
        //TODO: fill out questions
    }
    else if(country == "Korea")
    {
        //TODO: fill out questions
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
    questionBank[question1] = {option1, option2, option3, option4};
    questions.push_back(question1);
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
    questions.push_back(question2);
    // third question
    question3 =
        "Pani Puri is a common street food in the Indian subcontinent."
        "\nWhat makes the ingredients of Pani Puri as a snack in India?";
    option1 = "deep-fried and breaded exterior";
    option2 = "yogurt, ginger, garlic, and herbs";
    option3 = "chili powder, chaat masala, potato mash, and chickpeas";  // Correct
    option4 = "peppers, turmeric, coriander, and cumin";
    questionBank[question3] = {option1, option2, option3, option4};
    questions.push_back(question3);
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
    questions.push_back(question4);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(questions.begin(), questions.end(), g);

}

//void Model::receiveSignalToSendTextIndia(QString name)
//{
//    landMarkInfo[0] = "Hawa Mahal is a palace in the city of Jaipur, India. Built from red and pink sandstone, "
//                      "it is on the edge of the City Palace, Jaipur. The structure was built in 1799 by the Maharaja Sawai Pratap Singh. "
//                      "Its five-floor exterior is akin to a honeycomb with its 953 small windows called Jharokhas decorated with intricate latticework. "
//                      "The original intent of the lattice design was to allow royal ladies to observe everyday life and festivals celebrated in the street "
//                      "below without being seen. This architectural feature also allowed cool air from the Venturi effect to pass through, "
//                      "thus making the whole area more pleasant during the high temperatures in summer. This amazing ventilation that the palace enjoys "
//                      "is the reason why it was named as the Hawa Mahal, which literally translates into the “Palace of the Winds”. "
//                      "It is the tallest building in the world that has been built without a foundation. "
//                      "It has a curved architecture that leans at an 87-degree angle, and a pyramidal shape which has helped it stay erect for centuries.";

//    landMarkInfo[1] = "Taj Mahal is an ivory-white marble mausoleum on the right bank of the river Yamuna in Agra, Uttar Pradesh, India. "
//                      "It was commissioned in 1631 by the fifth Mughal emperor, Shah Jahan (r. 1628–1658) to house the tomb of his beloved wife, "
//                      "Mumtaz Mahal; it also houses the tomb of Shah Jahan himself. The Taj Mahal took 22 years to build. "
//                      "More than 22,000 laborers worked in the construction of the Taj Mahal. "
//                      "It is believed that around INR 32 million was spent to complete the construction of this white mausoleum (in 1653). "
//                      "Today, the cost of building the Taj would be somewhere around INR 70 billion (nearly $1 billion). "
//                      "Various Precious stones were brought from various countries for the building of the Taj Mahal. "
//                      "It is one of the 7 wonders of the world. “Taj Mahal” means “crown of palaces” in Urdu and Persian. "
//                      "The most recognizable feature of the Taj Mahal is the large, white, domed mausoleum, which is surrounded by four tall minarets on each corner. "
//                      "The color of the monument keeps changing throughout the day";

//    restaurantInfo[0] = "Pani Puri is a famous snack in India which is a  deep-fried breaded sphere filled with a mixture of spicy water, "
//                        "tamarind chutney, chili powder, chaat masala, potato mash, onion, or chickpeas. It is a common street food in the Indian subcontinent. "
//                        "The combination of different flavors and textures - crispy, soft, spicy, tangy, and sweet - is what makes Pani Puri so popular. "
//                        "Additionally, the interactive nature of eating Pani Puri makes each one chooses the way they want, be it the filling, or the water. "
//                        "It is also a very affordable snack and can be found in various parts of India, sold by street vendors and in restaurants. "
//                        "Overall, Pani Puri is a delicious and enjoyable snack that has gained popularity not just in India, but in other parts of the world as well.";

//    restaurantInfo[1] = "Biryani is a mixed rice dish which is very popular in India. It is made with rice, some type of meat (chicken, beef, goat, lamb, prawn, or fish) "
//                        "and spices. To cater to vegetarians, in some cases, it is prepared without any meat, substituting vegetables for the meat. "
//                        "Sometimes eggs and/or potatoes, are added. Biryani is one of the most popular dishes in South Asia, "
//                        "as well as among the diaspora from the region. Similar dishes are also prepared in other parts of the world such as in Iraq, "
//                        "Myanmar, Thailand, and Malaysia. Biryani is the single most-ordered dish on Indian online food ordering and delivery services, "
//                        "and has been labelled as the most popular dish overall in India. The most popular way to prepare Biryani is by using the Dum method, "
//                        "which involves cooking over a low flame. This procedure involves sealing food in a round, heavy-bottomed pot, preferably a handi (clay pot), "
//                        "and slowly cooking it. The dish may be served with chutney or raita, and salad.";

//    if (name == "HawaMahal")
//    {
//        emit sendDescriptions(landMarkInfo[0]);
//    }
//    else if (name == "TajMahal")
//    {
//        emit sendDescriptions(landMarkInfo[1]);
//    }
//    else if (name == "PaniPuri")
//    {
//        emit sendDescriptions(restaurantInfo[0]);
//    }
//    else if (name == "Biryani")
//    {
//        emit sendDescriptions(restaurantInfo[1]);
//    }
//}
