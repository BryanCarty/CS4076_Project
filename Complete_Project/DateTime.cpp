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
    return "Your Shipwreck Date and Time:\nTime: "+currentTime+"\nDate: "+currentDate;
}

DateTime::~DateTime()
{
    delete date;
    delete time;
}
