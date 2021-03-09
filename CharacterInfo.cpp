// in charifowindow.h add this include
#include <exception>


//replace CharInfoWindow in charinfowindow.cpp with the new version
bool CharInfoWindow::validateText(QString toValidate) {
    bool valid = false;
    try {

    QRegExp rx("[A-Za-z]*");
    QRegExpValidator validator(rx, 0);
    int pos = 0;
    string validText;

    if(validator.validate(toValidate, pos) && 0 != toValidate.compare("")) {
        valid = true;

    }
    throw valid; // user defined exception
}
    catch  (bool valid ){
      return valid;
    }
    }
