//Add Union under includes in playWindow.cpp

typedef union color4bTag
    {
    unsigned int      c;    // packed representation of colour
    struct argbTag          // component-wise representation
        {
        unsigned char b;    // (reversed for intel storage order)

        unsigned char g;
        unsigned char r;
        unsigned char a;
        } argb;
    } COLOR4B;



//Add implementation to first few lines of playWindow.cpp constructor - Note: Can change when we decide a color scheme.

    color4bTag color;
    color.c = 0x00FF1717;//initially setting colour to red.

    //stylesheet
    QString styleSheet(
      "QMainWindow{background-color: %1;}"
      "QLabel{color: %2;}"
    );

    //Setting and manipulating colours with use of union.
    color.argb.r=0x17;//change 'R' portion of the hexadecimal so colour is now black.
    QString varBGColour = QColor(color.c).name();
    color.c=0x0000FFFF;//changing colour to cyan
    color.argb.r=0xFF;//change 'r' portion of hexadecimal so colour is now white
    QString textColour = QColor(color.c).name();

    setStyleSheet(styleSheet.arg(varBGColour).arg(textColour));
