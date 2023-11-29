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
