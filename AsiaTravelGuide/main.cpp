#include "view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    Form f;
    view w(m, f);
    w.show();
    return a.exec();
}
