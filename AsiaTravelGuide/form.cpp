#include "form.h"
#include "ui_form.h"
#include <QDebug>
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

    ui->nextButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");
    ui->backButton->setStyleSheet("QPushButton { background-color: transparent; border: none; }");

    landMarkInfo[0] = "Hawa Mahal is a palace in the city of Jaipur, India. Built from red and pink sandstone, "
                      "\nit is on the edge of the City Palace, Jaipur. "
                      "\nThe structure was built in 1799 by the Maharaja Sawai Pratap Singh. "
                      "\nIts five-floor exterior is akin to a honeycomb with its 953 small windows "
                      "\ncalled Jharokhas decorated with intricate latticework. "
                      "\nThe original intent of the lattice design was to allow royal "
                      "\nladies to observe everyday life and festivals celebrated in the street below without being seen.";

    landMarkInfo[1] = "This architectural feature also allowed cool air from the Venturi effect to pass through, "
                      "\nthus making the whole area more pleasant during the high temperatures in summer. "
                      "\nThis amazing ventilation that the palace enjoys is the reason why it was named as the Hawa Mahal, "
                      "\nwhich literally translates into the “Palace of the Winds”. "
                      "\nIt is the tallest building in the world that has been built without a foundation. "
                      "\nIt has a curved architecture that leans at an 87-degree angle, "
                      "\nand a pyramidal shape which has helped it stay erect for centuries.";

    landMarkInfo[2] = "Taj Mahal is an ivory-white marble mausoleum on the right bank of the river Yamuna in Agra, Uttar Pradesh, India. "
                      "\nIt was commissioned in 1631 by the fifth Mughal emperor, "
                      "\nShah Jahan (r. 1628–1658) to house the tomb of his beloved wife, "
                      "\nMumtaz Mahal; it also houses the tomb of Shah Jahan himself. The Taj Mahal took 22 years to build. "
                      "\nMore than 22,000 laborers worked in the construction of the Taj Mahal. ";

    landMarkInfo[3] = "It is believed that around INR 32 million was spent to complete the construction of this white mausoleum (in 1653). "
                      "\nToday, the cost of building the Taj would be somewhere around INR 70 billion (nearly $1 billion). "
                      "\nVarious Precious stones were brought from various countries for the building of the Taj Mahal. "
                      "\nIt is one of the 7 wonders of the world. “Taj Mahal” means “crown of palaces” in Urdu and Persian. "
                      "\nThe most recognizable feature of the Taj Mahal is the large, white, domed mausoleum, "
                      "\nwhich is surrounded by four tall minarets on each corner. "
                      "\nThe color of the monument keeps changing throughout the day.";

    restaurantInfo[0] = "Pani Puri is a famous snack in India which is a  "
                        "\ndeep-fried breaded sphere filled with a mixture of spicy water, "
                        "\ntamarind chutney, chili powder, chaat masala, potato mash, onion, or chickpeas. "
                        "\nIt is a common street food in the Indian subcontinent. "
                        "\nThe combination of different flavors and textures "
                        "\n- crispy, soft, spicy, tangy, and sweet - is what makes Pani Puri so popular. ";


    restaurantInfo[1] = "Additionally, the interactive nature of eating Pani Puri "
                        "\nmakes each one chooses the way they want, be it the filling, or the water. "
                        "\nIt is also a very affordable snack and can be found in various parts of India, "
                        "\nsold by street vendors and in restaurants. "
                        "\nOverall, Pani Puri is a delicious and enjoyable snack that has gained popularity not just in India, "
                        "\nbut in other parts of the world as well.";

    restaurantInfo[2] = "Biryani is a mixed rice dish which is very popular in India. "
                        "\nIt is made with rice, some type of meat (chicken, beef, goat, lamb, prawn, or fish) and spices."
                        "\nTo cater to vegetarians, in some cases, it is prepared without any meat, substituting vegetables for the meat. "
                        "\nSometimes eggs and/or potatoes, are added. Biryani is one of the most popular dishes in South Asia, "
                        "\nas well as among the diaspora from the region. "
                        "\nSimilar dishes are also prepared in other parts of the world such as in Iraq, Myanmar, Thailand, and Malaysia." ;

    restaurantInfo[3] = "Biryani is the single most-ordered dish on Indian online food ordering and delivery services, "
                        "\nand has been labelled as the most popular dish overall in India. "
                        "\nThe most popular way to prepare Biryani is by using the Dum method, "
                        "\nwhich involves cooking over a low flame. This procedure involves sealing food in a round, "
                        "\nheavy-bottomed pot, preferably a handi (clay pot), "
                        "\nand slowly cooking it. The dish may be served with chutney or raita, and salad.";

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
        current = 0;
        flag = true;
        QPixmap hawaMahal(":/icons/hawa-mahal_Image.jpg");
        ui->image->setPixmap(hawaMahal.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        splittedText = landMarkInfo[current].split("");
        firstNextClicked = true;
    }
    else if (name == "TajMahal")
    {
        current = 2;
        flag = true;
        QPixmap tajMahal(":/icons/taj-mahal_Image.png");
        ui->image->setPixmap(tajMahal.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        splittedText = landMarkInfo[current].split("");
        firstNextClicked = true;
    }
    else if (name == "PaniPuri")
    {
        current = 0;
        flag = false;
        QPixmap paniPuri(":/icons/pani-puri_Image.jpg");
        ui->image->setPixmap(paniPuri.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        splittedText = restaurantInfo[current].split("");
        firstNextClicked = true;
    }
    else if (name == "Biryani")
    {
        current = 2;
        flag = false;
        QPixmap biryani(":/icons/biryani_Image.jpg");
        ui->image->setPixmap(biryani.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        splittedText = restaurantInfo[current].split("");
        firstNextClicked = true;
    }
    this->setWindowTitle(name);
    ui->description->setText("");
    timer->start(10);
    ui->backButton->hide();
}

void Form::on_nextButton_clicked()
{
    if (flag)
    {
        if(firstNextClicked)
        {
            splittedText = landMarkInfo[++current].split("");
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
    else
    {
        if(firstNextClicked)
        {
            splittedText = restaurantInfo[++current].split("");
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
    ui->nextButton->hide();
    ui->backButton->show();
}


void Form::on_backButton_clicked()
{
    if (flag)
    {
        if(firstBackClicked)
        {
            ui->description->setText(landMarkInfo[--current]);
        }
        else
        {
            ui->description->setText(landMarkInfo[current]);
        }
    }
    else
    {
        if(firstBackClicked)
        {
            ui->description->setText(restaurantInfo[--current]);
        }
        else
        {
            ui->description->setText(restaurantInfo[current]);
        }
    }
    ui->nextButton->show();
    ui->backButton->hide();
}


//void Form::on_backToMapButton_clicked()
//{
//    this->hide();
//    emit windowClosed();
//}

void Form::closeEvent(QCloseEvent *bar)
{
    currentText = "";
    now = 0;
    firstBackClicked = false;
    firstNextClicked = false;
    timer->stop();
    emit windowClosed();
}

