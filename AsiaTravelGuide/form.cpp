#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QMovie>
#include <QTimer>

Form::Form(QWidget *parent) :
    QWidget(parent)
    , ui(new Ui::Form)
    , musicPlayer(new QMediaPlayer)
    , musicOutput(new QAudioOutput)
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

    ui->playMusic->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->stopMusic->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    ui->playMusic->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->stopMusic->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->musicSlider->setSliderPosition(50);
    connect(ui->musicSlider, &QSlider::valueChanged, this, &Form::updateVolume);

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
    thailandLandMarkInfo[0] = "The Thailand Grand Palace, a dazzling architectural masterpiece situated in the heart of Bangkok, "
                              "\nstands as a testament to the nation's rich cultural heritage. Constructed in 1782 during the reign of King Rama I, "
                              "\nthe palace served as the royal residence for generations of Thai monarchs. "
                              "\nIts intricate design reflects a fusion of Thai, Chinese, and European influences, "
                              "\nfeaturing gilded spires, vibrant murals, and ornate sculptures.";

    thailandLandMarkInfo[1] = "Notably, the palace houses the revered Emerald Buddha, a sacred icon carved from a single piece of jade. "
                              "\nOver the centuries, it has been the backdrop for significant royal events and ceremonies. "
                              "\nThe Grand Palace complex spans over 200,000 square meters and includes various halls, pavilions, and courtyards. "
                              "\nWhile the royal family no longer resides here, the palace remains a symbol of Thailand's enduring cultural legacy and "
                              "\ncontinues to captivate visitors with its grandeur and historical significance.";

    thailandLandMarkInfo[2] = "The Great Buddha of Thailand, an awe-inspiring testament to Buddhist devotion and engineering marvel,"
                            "\nstands prominently in Wat Muang. Erected in 1990, this colossal statue reaches a height of 92 meters, "
                            "\nmaking it one of the tallest Buddha statues in the world. The serene giant, known locally as Luangpho Yai, "
                            "\nis positioned in a seated meditative posture, exuding tranquility and grace. "
                            "\nWhat sets this monument apart is the surrounding complex, offering visitors a"
                            "\nglimpse into Thai Buddhist artistry and culture. ";


    thailandLandMarkInfo[3] = "The statue's construction involved a meticulous combination of concrete and golden paint, "
                              "\nsymbolizing both spiritual enlightenment and earthly prosperity. As visitors ascend the "
                              "\nstairs to the Buddha's base, "
                              "\nthey are greeted by panoramic views of the surrounding landscape,"
                              "\nenhancing the overall experience and making Wat Muang a captivating destination for spiritual "
                              "\nreflection and cultural exploration.";

    thailandRestaurantInfo[0] ="Tom Yum Kung, a quintessential Thai soup, boasts a rich history and a tantalizing blend of flavors."
                                "\nOriginating in Central Thailand, it is believed to have been created in the 19th century during the "
                                "\nreign of King Rama IV. "
                                "\nThe name \"Tom Yum\" translates to \"sour and spicy\", capturing the essence of the dish. "
                                "\nThe key ingredients include fragrant lemongrass, kaffir lime leaves, galangal, fish sauce, and a fiery"
                                "\nkick from Thai bird's eye chilies. ";

    thailandRestaurantInfo[1] = "The soup is typically enriched with succulent shrimp, mushrooms, and a splash of lime juice, creating a "
                                "\nharmonious interplay of tanginess, heat, and umami."
                                "\nTraditionally enjoyed as a starter, Tom Yum Kung is favored during cooler seasons, providing a "
                                "\ncomforting warmth to the palate."
                                "\nThis iconic Thai creation can be savored in street food stalls, upscale restaurants, and household "
                                "\nkitchens alike, showcasing its widespread popularity and integral role in Thai culinary culture.";

    thailandRestaurantInfo[2] = "Mango Sticky Rice, a beloved Thai dessert, has a sweet tale rooted in Southeast Asian culinary traditions."
                                "\nOriginating in Thailand, this delectable treat gained popularity during the mango season, typically from "
                                "\nMarch to June. The dish's history is intertwined with the cultivation of glutinous rice, reflecting the "
                                "\nagricultural practices of the region. "
                                "\nTo create this indulgent dessert, sticky rice is soaked, steamed, and then paired with ripe, fragrant mango slices. ";

    thailandRestaurantInfo[3] = "The rice is infused with coconut milk, imparting a creamy texture and subtle sweetness. "
                                "\nThe ensemble is further elevated with a drizzle of coconut cream and a sprinkle of toasted "
                                "\nsesame seeds or mung beans. "
                                "\nMango Sticky Rice is a seasonal delight, often relished during Thai festivals and special occasions, "
                                "\ncelebrating the harmony of textures and flavors unique to this tropical delicacy. Whether purchased "
                                "\nfrom street vendors, "
                                "\nenjoyed in local eateries, or prepared at home, this dessert encapsulates the essence of Thai culinary "
                                "\ningenuity and the celebration of seasonal bounty.";

    // Korea descriptions
    koreaLandMarkInfo[0] = "Gyeongbokgung, the primary royal palace of the Joseon dynasty in Seoul, South Korea, was built in 1395. "
                           "\nDespite suffering damage and abandonment for two centuries after the Imjin War, "
                           "\na comprehensive restoration in the 19th century, led by Prince Regent Heungseon, "
                           "\nrevived the palace's 7,700 rooms and 500 buildings.";

    koreaLandMarkInfo[1] = "However, in the early 20th century, Imperial Japan dismantled parts of the palace during its occupation. "
                           "\nDesignated a cultural property in 1963, ongoing restoration efforts since the 1990s aim "
                           "\nto restore Gyeongbokgung, now housing the National Palace Museum and the National Folk Museum, "
                           "\npreserving Korea's historical legacy.";

    koreaLandMarkInfo[2] = "Bulguksa, located in Gyeongju, South Korea, "
                           "\nis a key Jogye Order Buddhist temple and a UNESCO World Heritage site since 1995. "
                           "\nNotable for housing six National Treasures, including stone pagodas and gilt-bronze Buddha statues, "
                           "\nBulguksa is considered a masterpiece of Silla kingdom Buddhist art. ";

    koreaLandMarkInfo[3] = "Serving as the head temple of the 11th district of the Jogye Order, it also revealed one of "
                           "\nthe world's earliest woodblock prints—a Dharani sutra dating between 704 and 751. "
                           "\nThis historical treasure, printed on a 8 cm × 630 cm mulberry paper scroll, adds to Bulguksa's cultural significance.";


    koreaRestaurantInfo[0] = "Tteokbokki, a beloved Korean dish, features small rice cakes simmered in either spicy gochujang "
                             "\nor non-spicy ganjang-based sauce. Accompanied by fish cakes, boiled eggs, "
                             "\nand scallions, it comes in variations like curry-tteokbokki and seafood-tteokbokki.";

    koreaRestaurantInfo[1] = "Easily found at snack bars, street stalls, and specialty restaurants, tteokbokki has also become a popular "
                             "\nhomemade dish using pre-packaged rice cakes."
                             "\nThe dish's evolution includes versions like cream sauce-tteokbokki and jajang-tteokbokki, adding to its diverse appeal.";

    koreaRestaurantInfo[2] = "Bossam, a staple in Korean cuisine, features boiled and thinly sliced pork shoulder seasoned with spices. "
                             "\nServed with an array of side dishes like spicy radish salad, sliced raw garlic, ssamjang (wrap sauce), "
                             "\nsaeu-jeot (salted shrimp), kimchi, and various ssam (wrap) vegetables including lettuce, "
                             "\nkkaennip (perilla leaves), and inner leaves of napa cabbage, it is a flavorful ensemble.";

    koreaRestaurantInfo[3] = "Widely enjoyed in South Korea, Bossam is commonly served as anju, complementing alcoholic drinks. "
                             "\nThe dining experience involves wrapping the meat and side dishes in ssam vegetables, "
                             "\naligning with the dish's literal meaning of 'wrapped' or 'packaged'";
    }

Form::~Form()
{
    delete ui;
    delete musicPlayer;
    delete musicOutput;
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
    // india
    if (name == "HawaMahal")
    {
        setLandmarkIndiaHelper(0, ":/images/hawa-mahal_Image.jpg");
        currentCountry = "India";
    }
    else if (name == "TajMahal")
    {
        setLandmarkIndiaHelper(2, ":/images/taj-mahal_Image.png");
        currentCountry = "India";
    }
    else if (name == "PaniPuri")
    {        
        setRestaurantIndiaHelper(0, ":/images/pani-puri_Image.jpg");
        currentCountry = "India";
    }
    else if (name == "Biryani")
    {
        setRestaurantIndiaHelper(2, ":/images/biryani_Image.jpg");
        currentCountry = "India";
    }
    // thailand
    else if (name == "GrandPalace")
    {
        setLandmarkThailandHelper(0, ":/images/Grand-Palace_Image.png");
        currentCountry = "Thailand";
    }
    else if (name == "BigBuddha")
    {
        setLandmarkThailandHelper(2, ":/images/Big-Buddha_Image.png");
        currentCountry = "Thailand";
    }
    else if (name == "TomYumKung")
    {
        setRestaurantThailandHelper(0, ":/images/Tom-Yum_Image.png");
        currentCountry = "Thailand";
    }
    else if (name == "MangoStickyRice")
    {
        setRestaurantThailandHelper(2, ":/images/Mango-Rice_Image.png");
        currentCountry = "Thailand";
    }
    // korea
    else if (name == "Gyeongbokgung")
    {
        setLandmarkKoreaHelper(0, ":/images/Gyeongbokgung_Image.jpg");
        currentCountry = "Korea";
    }
    else if (name == "Bulguksa")
    {
        setLandmarkKoreaHelper(2, ":/images/bulguksa_Image.jpg");
        currentCountry = "Korea";
    }
    else if (name == "Tteokbokki")
    {
        setRestaurantKoreaHelper(0, ":/images/tteokbokki_Image.jpg");
        currentCountry = "Korea";
    }
    else if (name == "Bossam")
    {
        setRestaurantKoreaHelper(2, ":/images/bossam_Image.jpg");
        currentCountry = "Korea";
    }

    setMusic(currentCountry);

    this->setWindowTitle(name);
    ui->description->setText("");
    timer->start(10);
    ui->backButton->hide();
}

void Form::setMusic(QString countryName)
{
    musicPlayer->setAudioOutput(musicOutput);
    if (countryName == "India")
    {
        musicPlayer->setSource(QUrl("qrc:/music/bgm_India.wav"));
    }
    else if (countryName == "Korea")
    {
        musicPlayer->setSource(QUrl("qrc:/music/bgm_Korea.mp4"));
    }
    else if (countryName == "Thailand")
    {
        musicPlayer->setSource(QUrl("qrc:/music/bgm_Thailand.mp3"));
    }
    musicPlayer->play();
    musicOutput->setVolume(0.5);
}

void Form::updateVolume(int volume)
{
    musicOutput->setVolume(volume/100.0);
}

void Form::on_playMusic_clicked()
{
    musicPlayer->play();
}


void Form::on_stopMusic_clicked()
{
    musicPlayer->pause();
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
    ui->musicSlider->setSliderPosition(50);
    musicPlayer->stop();
    emit windowClosed();
}

/*
 * HELPER METHODS
 */

void Form::setLandmarkKoreaHelper(int currentNum, QString image)
{
    current = currentNum;
    flag = true;
    QPixmap pixmap(image);
    ui->image->setPixmap(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    splittedText = koreaLandMarkInfo[current].split("");
    firstNextClicked = true;
}

void Form::setRestaurantKoreaHelper(int currentNum, QString image)
{
    current = currentNum;
    flag = false;
    QPixmap pixmap(image);
    ui->image->setPixmap(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    splittedText = koreaRestaurantInfo[current].split("");
    firstNextClicked = true;
}

void Form::setLandmarkThailandHelper(int currentNum, QString image)
{
    current = currentNum;
    flag = true;
    QPixmap pixmap(image);
    ui->image->setPixmap(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    splittedText = thailandLandMarkInfo[current].split("");
    firstNextClicked = true;
}

void Form::setRestaurantThailandHelper(int currentNum, QString image)
{
    current = currentNum;
    flag = false;
    QPixmap pixmap(image);
    ui->image->setPixmap(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    splittedText = thailandRestaurantInfo[current].split("");
    firstNextClicked = true;
}

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
            if(currentCountry == "India")
            {
                nextButtonHelper(indiaLandMarkInfo);
            }
            else if(currentCountry == "Thailand")
            {
                nextButtonHelper(thailandLandMarkInfo);
            }
            else if(currentCountry == "Korea")
            {
                nextButtonHelper(koreaLandMarkInfo);
            }
        }
        else
        {
            if(currentCountry == "India")
            {
                backButtonHelper(indiaLandMarkInfo);
            }
            else if(currentCountry == "Thailand")
            {
                backButtonHelper(thailandLandMarkInfo);
            }
            else if(currentCountry == "Korea")
            {
                backButtonHelper(koreaLandMarkInfo);
            }
        }
    }
    else
    {
        if (isNextButton)
        {
            if(currentCountry == "India")
            {
                nextButtonHelper(indiaRestaurantInfo);
            }
            else if(currentCountry == "Thailand")
            {
                nextButtonHelper(thailandRestaurantInfo);
            }
            else if(currentCountry == "Korea")
            {
                nextButtonHelper(koreaRestaurantInfo);
            }
        }
        else
        {
            if(currentCountry == "India")
            {
                backButtonHelper(indiaRestaurantInfo);
            }
            else if(currentCountry == "Thailand")
            {
                backButtonHelper(thailandRestaurantInfo);
            }
            else if(currentCountry == "Korea")
            {
                backButtonHelper(koreaRestaurantInfo);
            }
        }
    }

    ui->nextButton->setVisible(!isNextButton);
    ui->backButton->setVisible(isNextButton);
}
