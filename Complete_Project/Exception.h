#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <exception>
#include "charinfowindow.h"
#include <QRegExpValidator>
#include <QValidator>
using namespace std;
class MyException : public exception{
    public:
         bool validateText(QString toValidate) const throw()
        {
             bool valid = false;

                 QRegExp rx("[A-Za-z]*");
                 QRegExpValidator validator(rx, 0);
                 int pos = 0;
                 string validText;

                 if(validator.validate(toValidate, pos) && 0 != toValidate.compare("")) {
                     valid = true;
                 }
                 return valid;
}
};

#endif // EXCEPTION_H
