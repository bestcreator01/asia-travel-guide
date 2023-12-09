#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <QMap>
#include <QList>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QPainter>
#include <QLabel>

namespace Ui {
class Quiz;
}

class Quiz : public QWidget
{
    Q_OBJECT
    QLabel *backgroundLabel;

public:
    explicit Quiz(QWidget *parent = nullptr);
    ~Quiz();

    ///
    /// \brief showRandomQuestion
    /// Displays a randomly selected question from the question bank.
    ///
    void showRandomQuestion();

    ///
    /// \brief resetButtons
    /// Resets the state of buttons
    ///
    void resetButtons();

    ///
    /// \brief closeWindow
    /// Closes the current window or dialog.
    ///
    void closeWindow();

    ///
    /// \brief setValues
    /// Sets the initial values for the question bank and list of questions.
    /// \param questionBank - A QMap representing the question bank with categories as keys and corresponding lists of questions.
    /// \param questions - A QList containing the questions to be used in the quiz.
    ///
    void setValues(QMap<QString, QList<QString>> &questionBank, QList<QString> &questions);

    ///
    /// \brief setRandomOptions
    /// Randomizes the order of options by shuffling the provided list of numbers.
    /// \param numbers - A QList of integers representing option indices.
    ///
    void setRandomOptions(QList<int> &numbers);

signals:
    ///
    /// \brief randomizeOption
    /// Randomizes the order of answer options for the current question.
    ///
    void randomizeOption();

private slots:
    ///
    /// \brief on_option1Button_clicked
    /// Slot function triggered when the first option button is clicked.
    ///
    void on_option1Button_clicked();

    ///
    /// \brief on_option2Button_clicked
    /// Slot function triggered when the second option button is clicked.
    ///
    void on_option2Button_clicked();

    ///
    /// \brief on_option3Button_clicked
    /// Slot function triggered when the third option button is clicked.
    ///
    void on_option3Button_clicked();

    ///
    /// \brief on_option4Button_clicked
    /// Slot function triggered when the fourth option button is clicked.
    ///
    void on_option4Button_clicked();

    ///
    /// \brief on_nextButton_clicked
    /// Slot function triggered when the "Next" button is clicked.
    ///
    void on_nextButton_clicked();

    ///
    /// \brief closeEvent
    /// Overridden method called when the window close event occurs.
    /// \param bar - A QCloseEvent parameter representing the close event.
    ///
    void closeEvent(QCloseEvent *bar);

    ///
    /// \brief closePaint
    /// Closes the paint-related functionality or window.
    ///
    void closePaint();

protected:
    ///
    /// \brief paintEvent
    /// Overridden method called when the widget needs to be repainted.
    /// \param event - A QPaintEvent parameter representing the paint event
    ///
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Quiz *ui;
    QString randomQuestion;
    QList<int> numbers;
    QList<QString> questions;
    QMap<QString, QList<QString>> questionBank;
    int quesIndex = 0, correct = 2;

    ///
    /// \brief disableOptionButtons
    /// Disables the option buttons, typically used to prevent user interaction during certain game events.
    ///
    void disableOptionButtons();

    ///
    /// \brief generateConfettiColors
    /// Generates colors for confetti particles, ensuring a diverse and visually appealing appearance.
    ///
    void generateConfettiColors();

    ///
    /// \brief createConfetti
    /// Creates and initializes confetti particles for a celebratory effect.
    ///
    void createConfetti();

    ///
    /// \brief createGround - Creates a ground object with specified dimensions.
    /// \param neg
    /// \param pos
    ///
    void createGround(float neg, float pos);

    ///
    /// \brief updateWorld
    /// Updates the confetti painting.
    ///
    void updateWorld();

    ///
    /// \brief randomizeSelection
    /// Randomizes the selection order based on the provided list of numbers.
    /// \param numbers - A QList of integers representing the options to be randomized.
    ///
    void randomizeSelection(QList<int> numbers);

    QTimer timer;

    // confetti stuff
    b2World *top;
    b2World *bottom;
    QVector<QColor> confettiColors;
    QList<b2Body*> confettiPieces;
};

#endif // QUIZ_H
