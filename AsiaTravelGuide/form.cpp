#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QMovie>
#include <QTimer>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Form::startTyping);
    //ui->bgImage->setGeometry(0, 0, this->width(), this->height());  // Set to cover the entire window
    ui->image->lower();

    backgroundLabel = new QLabel(this);
    QMovie *movie = new QMovie(":/icons/clouds.gif");
    movie->setScaledSize(this->size());
    backgroundLabel->setMovie(movie);
    backgroundLabel->setGeometry(0, 0, this->width(), this->height());  // Set to cover the entire window
    backgroundLabel->lower();
    movie->start();

    ui->nextButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->backButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");

    //india descriptions
    indiaLandMarkInfo[0] = "Hawa Mahal is a palace in the city of Jaipur, India. Built from red and pink sandstone, "
                      "\nit is on the edge of the City Palace, Jaipur. "
                      "\nThe structure was built in 1799 by the Maharaja Sawai Pratap Singh. "
                      "\nIts five-floor exterior is akin to a honeycomb with its 953 small windows "
                      "\ncalled Jharokhas decorated with intricate latticework. "
                      "\nThe original intent of the lattice design was to allow royal "
                      "\nladies to observe everyday life and festivals celebrated in the street below without being seen.";

    indiaLandMarkInfo[1] = "This architectural feature also allowed cool air from the Venturi effect to pass through, "
                      "\nthus making the whole area more pleasant during the high temperatures in summer. "
                      "\nThis amazing ventilation that the palace enjoys is the reason why it was named as the Hawa Mahal, "
                      "\nwhich literally translates into the “Palace of the Winds”. "
                      "\nIt is the tallest building in the world that has been built without a foundation. "
                      "\nIt has a curved architecture that leans at an 87-degree angle, "
                      "\nand a pyramidal shape which has helped it stay erect for centuries.";

    indiaLandMarkInfo[2] = "Taj Mahal is an ivory-white marble mausoleum on the right bank of the river Yamuna in Agra, Uttar Pradesh, India. "
                      "\nIt was commissioned in 1631 by the fifth Mughal emperor, "
                      "\nShah Jahan (r. 1628–1658) to house the tomb of his beloved wife, "
                      "\nMumtaz Mahal; it also houses the tomb of Shah Jahan himself. The Taj Mahal took 22 years to build. "
                      "\nMore than 22,000 laborers worked in the construction of the Taj Mahal. ";

    indiaLandMarkInfo[3] = "It is believed that around INR 32 million was spent to complete the construction of this white mausoleum (in 1653). "
                      "\nToday, the cost of building the Taj would be somewhere around INR 70 billion (nearly $1 billion). "
                      "\nVarious Precious stones were brought from various countries for the building of the Taj Mahal. "
                      "\nIt is one of the 7 wonders of the world. “Taj Mahal” means “crown of palaces” in Urdu and Persian. "
                      "\nThe most recognizable feature of the Taj Mahal is the large, white, domed mausoleum, "
                      "\nwhich is surrounded by four tall minarets on each corner. "
                      "\nThe color of the monument keeps changing throughout the day.";

    indiaRestaurantInfo[0] = "Pani Puri is a famous snack in India which is a  "
                        "\ndeep-fried breaded sphere filled with a mixture of spicy water, "
                        "\ntamarind chutney, chili powder, chaat masala, potato mash, onion, or chickpeas. "
                        "\nIt is a common street food in the Indian subcontinent. "
                        "\nThe combination of different flavors and textures "
                        "\n- crispy, soft, spicy, tangy, and sweet - is what makes Pani Puri so popular. ";


    indiaRestaurantInfo[1] = "Additionally, the interactive nature of eating Pani Puri "
                        "\nmakes each one chooses the way they want, be it the filling, or the water. "
                        "\nIt is also a very affordable snack and can be found in various parts of India, "
                        "\nsold by street vendors and in restaurants. "
                        "\nOverall, Pani Puri is a delicious and enjoyable snack that has gained popularity not just in India, "
                        "\nbut in other parts of the world as well.";

    indiaRestaurantInfo[2] = "Biryani is a mixed rice dish which is very popular in India. "
                        "\nIt is made with rice, some type of meat (chicken, beef, goat, lamb, prawn, or fish) and spices."
                        "\nTo cater to vegetarians, in some cases, it is prepared without any meat, substituting vegetables for the meat. "
                        "\nSometimes eggs and/or potatoes, are added. Biryani is one of the most popular dishes in South Asia, "
                        "\nas well as among the diaspora from the region. "
                        "\nSimilar dishes are also prepared in other parts of the world such as in Iraq, Myanmar, Thailand, and Malaysia." ;

    indiaRestaurantInfo[3] = "Biryani is the single most-ordered dish on Indian online food ordering and delivery services, "
                        "\nand has been labelled as the most popular dish overall in India. "
                        "\nThe most popular way to prepare Biryani is by using the Dum method, "
                        "\nwhich involves cooking over a low flame. This procedure involves sealing food in a round, "
                        "\nheavy-bottomed pot, preferably a handi (clay pot), "
                        "\nand slowly cooking it. The dish may be served with chutney or raita, and salad.";

    //thailand descriptions
    thailandLandMarkInfo[0] = "The Thailand Grand Palace, an iconic symbol of Thai royalty and architectural grandeur, "
                                "\nstands as a testament to the rich cultural heritage of the nation. Constructed in 1782, "
                                "\nduring the reign of King Rama I, the palace serves as the official residence of the Kings of Siam. ";

    thailandLandMarkInfo[1] = "The latter houses a meticulously carved Buddha statue made from a single piece of jade, "
                              "\nshowcasing the craftsmanship of Thai artisans. The Grand Palace has witnessed historical events, "
                              "\nincluding the abolition of absolute monarchy in 1932, yet continues to be a dazzling spectacle for visitors, "
                              "\ndrawing them into a mesmerizing world of opulence and cultural significance.";

    thailandLandMarkInfo[2] = "The Great Buddha of Thailand, an awe-inspiring testament to Buddhist devotion and engineering marvel,"
                            "\nstands prominently in Wat Muang. Erected in 1990, this colossal statue reaches a height of 92 meters, "
                            "\nmaking it one of the tallest Buddha statues in the world. The serene giant, known locally as Luangpho Yai, "
                            "\nis positioned in a seated meditative posture, exuding tranquility and grace. "
                            "\nWhat sets this monument apart is the surrounding complex, offering visitors a glimpse into Thai Buddhist artistry and culture. ";


    thailandLandMarkInfo[3] = "The statue's construction involved a meticulous combination of concrete and golden paint, "
                              "\nsymbolizing both spiritual enlightenment and earthly prosperity. As visitors ascend the stairs to the Buddha's base, "
                              "\nthey are greeted by panoramic views of the surrounding landscape,"
                              "\nenhancing the overall experience and making Wat Muang a captivating destination for spiritual reflection and cultural exploration.";

    thailandRestaurantInfo[0] ="Tom Yum Kung, a quintessential Thai soup, boasts a rich history and a tantalizing blend of flavors."
                                "\nOriginating in Central Thailand, it is believed to have been created in the 19th century during the reign of King Rama IV. "
                                "\nThe name \"Tom Yum\" translates to \"sour and spicy\", capturing the essence of the dish. "
                                "\nThe key ingredients include fragrant lemongrass, kaffir lime leaves, galangal, fish sauce, and a fiery kick from Thai bird's eye chilies. ";

    thailandRestaurantInfo[1] = "The soup is typically enriched with succulent shrimp, mushrooms, and a splash of lime juice, creating a harmonious interplay of tanginess, heat, and umami."
                              "\nTraditionally enjoyed as a starter, Tom Yum Kung is favored during cooler seasons, providing a comforting warmth to the palate."
                              "\nThis iconic Thai creation can be savored in street food stalls, upscale restaurants, and household kitchens alike, "
                              "\nshowcasing its widespread popularity and integral role in Thai culinary culture.";

    thailandRestaurantInfo[2] = "Mango Sticky Rice, a beloved Thai dessert, has a sweet tale rooted in Southeast Asian culinary traditions."
                                "\nOriginating in Thailand, this delectable treat gained popularity during the mango season, typically from March to June. "
                                "\nThe dish's history is intertwined with the cultivation of glutinous rice, reflecting the agricultural practices of the region. "
                                "\nTo create this indulgent dessert, sticky rice is soaked, steamed, and then paired with ripe, fragrant mango slices. ";

    thailandRestaurantInfo[3] = "The rice is infused with coconut milk, imparting a creamy texture and subtle sweetness. "
                                "\nThe ensemble is further elevated with a drizzle of coconut cream and a sprinkle of toasted sesame seeds or mung beans. "
                                "\nMango Sticky Rice is a seasonal delight, often relished during Thai festivals and special occasions, "
                                "\ncelebrating the harmony of textures and flavors unique to this tropical delicacy. Whether purchased from street vendors, "
                                "\nenjoyed in local eateries, or prepared at home, this dessert encapsulates the essence of Thai culinary ingenuity and the celebration of seasonal bounty.";
    }

Form::~Form()
{
    delete ui;
}

void Form::startTyping()
{
    ui->nextButton->hide();
    ui->backButton->hide();
    ui->description->setText(ui->description->text()+splittedText[now]);
    ++now;
    if(splittedText.length() == now)
    {
        timer->stop();
        now = 0;
        currentText = ui->description->text();
        if(current == 0 || current == 2)
        {
            ui->nextButton->show();
        }
        else
        {
            ui->backButton->show();
        }
    }
}

void Form::receiveSignalToSetTextIndia(QString name)
{
    if (name == "HawaMahal")
    {
        setLandmarkIndiaHelper(0, ":/icons/hawa-mahal_Image.jpg");
    }
    else if (name == "TajMahal")
    {
        setLandmarkIndiaHelper(2, ":/icons/taj-mahal_Image.png");
    }
    else if (name == "PaniPuri")
    {        
        setRestaurantIndiaHelper(0, ":/icons/pani-puri_Image.jpg");
    }
    else if (name == "Biryani")
    {
        setRestaurantIndiaHelper(2, ":/icons/biryani_Image.jpg");

    }
    this->setWindowTitle(name);
    ui->description->setText("");
    timer->start(10);
    ui->backButton->hide();
}

void Form::on_nextButton_clicked()
{
    buttonHelper(true);
}

void Form::on_backButton_clicked()
{
    buttonHelper(false);
}


void Form::closeWindow()
{
    this->close();
}

void Form::closeEvent(QCloseEvent *bar)
{
    currentText = "";
    now = 0;
    firstBackClicked = false;
    firstNextClicked = false;
    timer->stop();
    emit windowClosed();
}

/*
 * HELPER METHODS
 */

void Form::setLandmarkIndiaHelper(int currentNum, QString image)
{
    current = currentNum;
    flag = true;
    QPixmap pixmap(image);
    ui->image->setPixmap(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    splittedText = indiaLandMarkInfo[current].split("");
    firstNextClicked = true;
}

void Form::setRestaurantIndiaHelper(int currentNum, QString image)
{
    current = currentNum;
    flag = false;
    QPixmap pixmap(image);
    ui->image->setPixmap(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    splittedText = indiaRestaurantInfo[current].split("");
    firstNextClicked = true;
}

void Form::nextButtonHelper(QString info[])
{
    if (firstNextClicked)
    {
        splittedText = info[++current].split("");
        ui->description->setText("");
        timer->start(10);
        firstNextClicked = false;
        firstBackClicked = true;
    }
    else
    {
        ui->description->setText(currentText);
        firstBackClicked = false;
    }
}

void Form::backButtonHelper(QString info[])
{
    if(firstBackClicked)
    {
        ui->description->setText(info[--current]);
    }
    else
    {
        ui->description->setText(info[current]);
    }
}

void Form::buttonHelper(bool isNextButton)
{
    if (flag)
    {
        if (isNextButton)
        {
            nextButtonHelper(indiaLandMarkInfo);
        }
        else
        {
            backButtonHelper(indiaLandMarkInfo);
        }
    }
    else
    {
        if (isNextButton)
        {
            nextButtonHelper(indiaRestaurantInfo);
        }
        else
        {
            backButtonHelper(indiaRestaurantInfo);
        }
    }

    ui->nextButton->setVisible(!isNextButton);
    ui->backButton->setVisible(isNextButton);
}

