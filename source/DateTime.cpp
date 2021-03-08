//DateTime.cpp
#include "DateTime.h"

DateTime::DateTime()
{
    date = new QDate;
    time = new QTime();
}

QString DateTime::getStartDateTime()
{
    QString currentDate = date->currentDate().toString();
    QString currentTime = time->currentTime().toString();
    return "Start DateTime:\nTime: "+currentTime+"\nDate: "+currentDate;
}

DateTime::~DateTime()
{
    delete date;
    delete time;
}
