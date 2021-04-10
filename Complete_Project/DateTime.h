//DateTime.h
#ifndef DATETIME_H
#define DATETIME_H
#include <QDate>
#include <QTime>

class DateTime: public QDate, public QTime
{
private:
    QDate *date;
    QTime *time;
public:
    DateTime();
    QString getStartDateTime();
    ~DateTime();
};

#endif // DATETIME_H
